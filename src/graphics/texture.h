#pragma once

#include <cstddef>
#include <utility>

#include <GLFL/glfl.h>

#include "graphics/image.h"
#include "utils/finally.h"
#include "utils/mat.h"
#include "utils/resource_allocator.h"

namespace Graphics
{
    enum InterpolationMode
    {
        nearest,
        linear,
        min_nearest_mag_linear,
        min_linear_mag_nearest,
    };

    enum WrapMode
    {
        clamp  = GL_CLAMP_TO_EDGE,
        mirror = GL_MIRRORED_REPEAT,
        repeat = GL_REPEAT,
        OnPC(
        fill   = GL_CLAMP_TO_BORDER,
        )
    };

    class Texture
    {
        struct Data
        {
            GLuint handle = 0;
        };

        Data data;

      public:
        explicit Texture(decltype(nullptr)) {}

        Texture()
        {
            glGenTextures(1, &data.handle);
            if (!data.handle)
                Program::Error("Unable to create a texture.");
            // Not needed because since there is no code below this point: FINALLY_ON_THROW( glDeleteTextures(1, &data.handle); )
        }

        Texture(Texture &&other) noexcept : data(std::exchange(other.data, {})) {}
        Texture &operator=(Texture &&other) noexcept
        {
            std::swap(data, other.data);
            return *this;
        }

        ~Texture()
        {
            // Deleting a texture unbinds it.
            glDeleteTextures(1, &data.handle); // Deleting 0 is a no-op.
        }

        explicit operator bool() const
        {
            return bool(data.handle);
        }

        GLuint Handle() const
        {
            return data.handle;
        }
    };

    class TexUnit
    {
        using res_alloc_t = ResourceAllocator<int>;

        static res_alloc_t &Allocator() // Not sure if it's necessary, but the intent of wrapping it into a function is prevent the static init order fiasco.
        {
            static res_alloc_t ret(64);
            return ret;
        }

        struct Data
        {
            int index = res_alloc_t::none;
            GLuint handle = 0;
        };

        Data data;

        inline static int active_index = 0;

      public:
        TexUnit()
        {
            data.index = Allocator().Alloc();
            if (!*this)
                Program::Error("No free texture units.");
        }
        explicit TexUnit(GLuint handle) : TexUnit()
        {
            AttachHandle(handle);
        }
        explicit TexUnit(const Texture &texture) : TexUnit()
        {
            Attach(texture);
        }

        TexUnit(TexUnit &&other) noexcept : data(std::exchange(other.data, {})) {}
        TexUnit &operator=(TexUnit &&other) noexcept
        {
            std::swap(data, other.data);
            return *this;
        }

        ~TexUnit()
        {
            Allocator().Free(data.index); // Freeing an invalid index is a no-op.
        }

        explicit operator bool() const
        {
            return data.index != res_alloc_t::none;
        }

        int Index() const
        {
            return data.index;
        }

        static void ActivateIndex(int index)
        {
            if (active_index == index)
                return;
            glActiveTexture(GL_TEXTURE0 + index);
            active_index = index;
        }
        void Activate()
        {
            if (!*this)
                return;
            ActivateIndex(data.index);
        }
        [[nodiscard]] bool Active()
        {
            return bool(*this) && active_index == data.index;
        }

        TexUnit &&AttachHandle(GLuint handle)
        {
            if (!*this)
                return std::move(*this);

            Activate();
            data.handle = handle;
            glBindTexture(GL_TEXTURE_2D, handle);
            return std::move(*this);
        }
        TexUnit &&Attach(const Texture &texture)
        {
            AttachHandle(texture.Handle());
            return std::move(*this);
        }
        TexUnit &&Detach()
        {
            AttachHandle(0);
            return std::move(*this);
        }

        TexUnit &&Interpolation(InterpolationMode mode)
        {
            if (!data.handle)
                return std::move(*this);

            Activate();

            GLenum min_mode = (mode == nearest || mode == min_nearest_mag_linear ? GL_NEAREST : GL_LINEAR);
            GLenum mag_mode = (mode == nearest || mode == min_linear_mag_nearest ? GL_NEAREST : GL_LINEAR);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_mode);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_mode);

            return std::move(*this);
        }

        TexUnit &&WrapX(WrapMode mode)
        {
            if (!data.handle)
                return std::move(*this);

            Activate();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GLuint(mode));
            return std::move(*this);
        }
        TexUnit &&WrapY(WrapMode mode)
        {
            if (!data.handle)
                return std::move(*this);

            Activate();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GLuint(mode));
            return std::move(*this);
        }
        TexUnit &&Wrap(WrapMode mode)
        {
            WrapX(mode);
            WrapY(mode);
            return std::move(*this);
        }

        TexUnit &&SetData(ivec2 size, const uint8_t *pixels = 0)
        {
            SetData(OnPC(GL_RGBA8) OnMobile(GL_RGBA), GL_RGBA, GL_UNSIGNED_BYTE, size, pixels);
            return std::move(*this);
        }
        TexUnit &&SetData(GLenum internal_format, GLenum format, GLenum type, ivec2 size, const uint8_t *pixels = 0)
        {
            if (!data.handle)
                return std::move(*this);

            Activate();
            glTexImage2D(GL_TEXTURE_2D, 0, internal_format, size.x, size.y, 0, format, type, pixels);
            return std::move(*this);
        }
        TexUnit &&SetData(const Image &image)
        {
            SetData(image.Size(), image.Data());
            return std::move(*this);
        }

        TexUnit &&SetDataPart(ivec2 pos, ivec2 size, const uint8_t *pixels)
        {
            SetDataPart(GL_RGBA, GL_UNSIGNED_BYTE, pos, size, pixels);
            return std::move(*this);
        }
        TexUnit &&SetDataPart(GLenum format, GLenum type, ivec2 pos, ivec2 size, const uint8_t *pixels)
        {
            if (!data.handle)
                return std::move(*this);

            Activate();
            glTexSubImage2D(GL_TEXTURE_2D, 0, pos.x, pos.y, size.x, size.y, format, type, pixels);
            return std::move(*this);
        }
    };
}