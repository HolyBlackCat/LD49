// macro.h
// Preprocessor utils
// Version 1.1.2
// Autogenerated, don't touch.

#pragma once

// Stops the compilation with a specific error message.
// `msg` should be a string literal.
// This implementation works on both GCC and Clang.
#define MA_ABORT(msg) MA_ABORT_impl(GCC error msg)
#define MA_ABORT_impl(msg) _Pragma(MA_STR(msg))

// Stringifies `...`, while expanding any macros in it.
#define MA_STR(...) MA_STR_impl(__VA_ARGS__)
#define MA_STR_impl(...) #__VA_ARGS__

// Concatenates all parameters, expanding any macros in them. The expansions can't contain commas.
#define MA_CAT(p1,p2) MA_CAT_impl(p1,p2)
#define MA_CAT3(p1,p2,p3) MA_CAT3_impl(p1,p2,p3)
#define MA_CAT4(p1,p2,p3,p4) MA_CAT4_impl(p1,p2,p3,p4)
#define MA_CAT5(p1,p2,p3,p4,p5) MA_CAT5_impl(p1,p2,p3,p4,p5)
#define MA_CAT6(p1,p2,p3,p4,p5,p6) MA_CAT6_impl(p1,p2,p3,p4,p5,p6)
#define MA_CAT7(p1,p2,p3,p4,p5,p6,p7) MA_CAT7_impl(p1,p2,p3,p4,p5,p6,p7)
#define MA_CAT8(p1,p2,p3,p4,p5,p6,p7,p8) MA_CAT8_impl(p1,p2,p3,p4,p5,p6,p7,p8)
#define MA_CAT_impl(p1,p2) p1##p2
#define MA_CAT3_impl(p1,p2,p3) p1##p2##p3
#define MA_CAT4_impl(p1,p2,p3,p4) p1##p2##p3##p4
#define MA_CAT5_impl(p1,p2,p3,p4,p5) p1##p2##p3##p4##p5
#define MA_CAT6_impl(p1,p2,p3,p4,p5,p6) p1##p2##p3##p4##p5##p6
#define MA_CAT7_impl(p1,p2,p3,p4,p5,p6,p7) p1##p2##p3##p4##p5##p6##p7
#define MA_CAT8_impl(p1,p2,p3,p4,p5,p6,p7,p8) p1##p2##p3##p4##p5##p6##p7##p8

// Concatenates `...` and `x`. Note that the parameters are in a different order.
#define MA_APPEND_TO_VA_END(x,...) MA_APPEND_TO_VA_END_impl(x,__VA_ARGS__)
#define MA_APPEND_TO_VA_END_impl(x,...) __VA_ARGS__##x

// Causes an error if the argument is not empty. Expands to nothing.
#define MA_EXPECT_EMPTY(...) MA_EXPECT_EMPTY_impl(__VA_ARGS__)
#define MA_EXPECT_EMPTY_impl()

// Expands to nothing.
#define MA_NULL(...)

// Expands to `...`.
#define MA_IDENTITY(...) __VA_ARGS__
#define MA_IDENTITY2(...) __VA_ARGS__
#define MA_IDENTITY3(...) __VA_ARGS__
#define MA_IDENTITY4(...) __VA_ARGS__

// Expand to some basic symbols.
#define MA_COMMA(...) ,
#define MA_SEMICOLON(...) ;
#define MA_PLUS(...) +

// If `...` is not empty, adds a trailing comma to it.
#define MA_TR_C(...) __VA_OPT__(__VA_ARGS__,)
// If `...` is not empty, adds a leading comma to it.
#define MA_LE_C(...) __VA_OPT__(,__VA_ARGS__)

// Calls `m<i>(...)`, where `<i>` is the amount of comma-separated elements in `...`.
#define MA_OVERLOAD(m,...) MA_CAT(m, MA_VA_SIZE(__VA_ARGS__))(__VA_ARGS__)

// Expands to `a`, if `...` is not empty.
#define MA_IF_NOT_EMPTY(a,...) __VA_OPT__(a)

// Expands to `a`, if `...` is not empty. Otherwise expands to `b`.
#define MA_IF_NOT_EMPTY_ELSE(a,b,...) MA_IF_NOT_EMPTY_ELSE_impl##__VA_OPT__(_a)(a,b)
#define MA_IF_NOT_EMPTY_ELSE_impl(a,b) b
#define MA_IF_NOT_EMPTY_ELSE_impl_a(a,b) a

// If `a` is not empty, expands to `a`. Otherwise expands to `b`.
#define MA_REPLACE_IF_EMPTY(a, b) MA_IF_NOT_EMPTY_ELSE(a, b, a)

// If `...` is empty, expands to `x`, otherwise expands to nothing.
#define MA_INVERT_EMPTINESS(...) MA_INVERT_EMPTINESS_impl##__VA_OPT__(_a)
#define MA_INVERT_EMPTINESS_impl x
#define MA_INVERT_EMPTINESS_impl_a

// Expands to `a`, if `...` has at least one comma in it after expansion.
#define MA_IF_COMMA(a,...) MA_IF_COMMA_impl(a,__VA_ARGS__,)
#define MA_IF_COMMA_impl(a,unused,...) __VA_OPT__(a)

// Expands to `a`, if `...` has at least one comma in it after expansion. Otherwise expands to `b`.
#define MA_IF_COMMA_ELSE(a,b,...) MA_IF_COMMA_ELSE_impl(a,b,__VA_ARGS__,)
#define MA_IF_COMMA_ELSE_impl(a,b,unused,...) MA_IF_COMMA_ELSE_impl_low##__VA_OPT__(_a)(a,b)
#define MA_IF_COMMA_ELSE_impl_low(a,b) b
#define MA_IF_COMMA_ELSE_impl_low_a(a,b) a

// Same as `m(...)`, except `...` is expanded early, so any commas in it act as argument separators.
#define MA_CALL(m, ...) m(__VA_ARGS__)

// Expands to the first comma-separated element of `...`.
#define MA_VA_FIRST(...) MA_VA_FIRST_impl(__VA_ARGS__,)
#define MA_VA_FIRST_impl(x, ...) x

// Expands to `...` with the first comma-separated element removed.
#define MA_VA_NO_FIRST(x, ...) __VA_ARGS__

// `...` has to start with `(..)`. Expands to whatever is between the parens.
#define MA_SEQ_FIRST(...) MA_SEQ_FIRST_impl __VA_ARGS__ )
#define MA_SEQ_FIRST_impl(...) __VA_ARGS__ MA_NULL(

// `...` has to start with `(..)`. Removes this pair of parens, and inserts a comma after them.
#define MA_SEQ_SEP_FIRST(...) __VA_ARGS__,

// `...` has to start with `(..)`. Inserts a comma after that `(..)`.
#define MA_SEQ_SEP_FIRST_P(...) (__VA_ARGS__),

// `...` has to start with `(..)`. Expands to `...` with this part removed.
#define MA_SEQ_NO_FIRST(seq) MA_NULL seq

// `seq` has to be a sequence, like `(a)(b)(c)`. Converts it to a variadic list, like `a,b,c`.
#define MA_SEQ_TO_VA(seq) MA_APPEND_TO_VA_END(_end, MA_SEQ_TO_VA_impl_0 seq)
#define MA_SEQ_TO_VA_impl_0(...)  __VA_ARGS__ MA_SEQ_TO_VA_impl_a
#define MA_SEQ_TO_VA_impl_a(...) ,__VA_ARGS__ MA_SEQ_TO_VA_impl_b
#define MA_SEQ_TO_VA_impl_b(...) ,__VA_ARGS__ MA_SEQ_TO_VA_impl_a
#define MA_SEQ_TO_VA_impl_0_end
#define MA_SEQ_TO_VA_impl_a_end
#define MA_SEQ_TO_VA_impl_b_end

// `seq` has to be a sequence, like `(a)(b)(c)`. Converts it to a variadic list without removing parens, like `(a),(b),(c)`.
#define MA_SEQ_TO_VA_P(seq) MA_APPEND_TO_VA_END(_end, MA_SEQ_TO_VA_P_impl_0 seq)
#define MA_SEQ_TO_VA_P_impl_0(...)  (__VA_ARGS__) MA_SEQ_TO_VA_P_impl_a
#define MA_SEQ_TO_VA_P_impl_a(...) ,(__VA_ARGS__) MA_SEQ_TO_VA_P_impl_b
#define MA_SEQ_TO_VA_P_impl_b(...) ,(__VA_ARGS__) MA_SEQ_TO_VA_P_impl_a
#define MA_SEQ_TO_VA_P_impl_0_end
#define MA_SEQ_TO_VA_P_impl_a_end
#define MA_SEQ_TO_VA_P_impl_b_end

// `...` has to be a comma-separated list. Expands the size of the list. (If the list is empty, expands to 1.)
#define MA_VA_SIZE(...) MA_VA_SIZE_impl(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define MA_VA_SIZE_impl(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,size,...) size

// `seq` has to be a sequence, like `(a)(b)(c)`. Returns the number of elements in it, which can be 0.
#define MA_SEQ_SIZE(seq) MA_CAT(MA_SEQ_SIZE_impl_0 seq, _val)
#define MA_SEQ_SIZE_impl_0(...) MA_SEQ_SIZE_impl_1
#define MA_SEQ_SIZE_impl_1(...) MA_SEQ_SIZE_impl_2
#define MA_SEQ_SIZE_impl_2(...) MA_SEQ_SIZE_impl_3
#define MA_SEQ_SIZE_impl_3(...) MA_SEQ_SIZE_impl_4
#define MA_SEQ_SIZE_impl_4(...) MA_SEQ_SIZE_impl_5
#define MA_SEQ_SIZE_impl_5(...) MA_SEQ_SIZE_impl_6
#define MA_SEQ_SIZE_impl_6(...) MA_SEQ_SIZE_impl_7
#define MA_SEQ_SIZE_impl_7(...) MA_SEQ_SIZE_impl_8
#define MA_SEQ_SIZE_impl_8(...) MA_SEQ_SIZE_impl_9
#define MA_SEQ_SIZE_impl_9(...) MA_SEQ_SIZE_impl_10
#define MA_SEQ_SIZE_impl_10(...) MA_SEQ_SIZE_impl_11
#define MA_SEQ_SIZE_impl_11(...) MA_SEQ_SIZE_impl_12
#define MA_SEQ_SIZE_impl_12(...) MA_SEQ_SIZE_impl_13
#define MA_SEQ_SIZE_impl_13(...) MA_SEQ_SIZE_impl_14
#define MA_SEQ_SIZE_impl_14(...) MA_SEQ_SIZE_impl_15
#define MA_SEQ_SIZE_impl_15(...) MA_SEQ_SIZE_impl_16
#define MA_SEQ_SIZE_impl_16(...) MA_SEQ_SIZE_impl_17
#define MA_SEQ_SIZE_impl_0_val 0
#define MA_SEQ_SIZE_impl_1_val 1
#define MA_SEQ_SIZE_impl_2_val 2
#define MA_SEQ_SIZE_impl_3_val 3
#define MA_SEQ_SIZE_impl_4_val 4
#define MA_SEQ_SIZE_impl_5_val 5
#define MA_SEQ_SIZE_impl_6_val 6
#define MA_SEQ_SIZE_impl_7_val 7
#define MA_SEQ_SIZE_impl_8_val 8
#define MA_SEQ_SIZE_impl_9_val 9
#define MA_SEQ_SIZE_impl_10_val 10
#define MA_SEQ_SIZE_impl_11_val 11
#define MA_SEQ_SIZE_impl_12_val 12
#define MA_SEQ_SIZE_impl_13_val 13
#define MA_SEQ_SIZE_impl_14_val 14
#define MA_SEQ_SIZE_impl_15_val 15
#define MA_SEQ_SIZE_impl_16_val 16

// Applies macro `m` to each comma-separated element in `...`.
// A trailing comma in `...` is mandatory, not adding it causes an immediate error.
// If your list doesn't have a trailing comma, wrap it in `MA_TR_C(...)`.
// (Alternatively, you can add the comma manually. But in thsi case, if the list is empty, you'll get one unwanted iteration.)
// `m` will be called as `m(d,i,x)`, where `d` is arbitrary user data, `i` is 0-based index, `x` is current element.
// Is not reentrant (i.e. can't be nested in itself).
#define MA_VA_FOR_EACH(d,m,...) __VA_OPT__(MA_VA_FOR_EACH_impl_minus1(d,m,__VA_ARGS__))
// Nested loops. Similar to the regular version, but the indices start from `i+1` rather than `0`. (To start from `0`, pass `minus1`.)
// `i` should be passed from the enclosing loop.
#define MA_VA_FOR_EACH_1(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_2(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_3(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_4(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_5(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_6(i,d,m,...) __VA_OPT__(MA_CAT(MA_VA_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))

#define MA_VA_FOR_EACH_impl_minus1(d,m,x,...) m(d,0,x) __VA_OPT__(MA_VA_FOR_EACH_impl_0(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_0(d,m,x,...) m(d,1,x) __VA_OPT__(MA_VA_FOR_EACH_impl_1(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_1(d,m,x,...) m(d,2,x) __VA_OPT__(MA_VA_FOR_EACH_impl_2(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_2(d,m,x,...) m(d,3,x) __VA_OPT__(MA_VA_FOR_EACH_impl_3(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_3(d,m,x,...) m(d,4,x) __VA_OPT__(MA_VA_FOR_EACH_impl_4(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_4(d,m,x,...) m(d,5,x) __VA_OPT__(MA_VA_FOR_EACH_impl_5(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_5(d,m,x,...) m(d,6,x) __VA_OPT__(MA_VA_FOR_EACH_impl_6(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_6(d,m,x,...) m(d,7,x) __VA_OPT__(MA_VA_FOR_EACH_impl_7(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_7(d,m,x,...) m(d,8,x) __VA_OPT__(MA_VA_FOR_EACH_impl_8(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_8(d,m,x,...) m(d,9,x) __VA_OPT__(MA_VA_FOR_EACH_impl_9(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_9(d,m,x,...) m(d,10,x) __VA_OPT__(MA_VA_FOR_EACH_impl_10(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_10(d,m,x,...) m(d,11,x) __VA_OPT__(MA_VA_FOR_EACH_impl_11(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_11(d,m,x,...) m(d,12,x) __VA_OPT__(MA_VA_FOR_EACH_impl_12(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_12(d,m,x,...) m(d,13,x) __VA_OPT__(MA_VA_FOR_EACH_impl_13(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_13(d,m,x,...) m(d,14,x) __VA_OPT__(MA_VA_FOR_EACH_impl_14(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_14(d,m,x,...) m(d,15,x) __VA_OPT__(MA_VA_FOR_EACH_impl_15(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_15(d,m,x,...) m(d,16,x) __VA_OPT__(MA_VA_FOR_EACH_impl_16(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_16(d,m,x,...) m(d,17,x) __VA_OPT__(MA_VA_FOR_EACH_impl_17(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_17(d,m,x,...) m(d,18,x) __VA_OPT__(MA_VA_FOR_EACH_impl_18(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_18(d,m,x,...) m(d,19,x) __VA_OPT__(MA_VA_FOR_EACH_impl_19(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_19(d,m,x,...) m(d,20,x) __VA_OPT__(MA_VA_FOR_EACH_impl_20(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_20(d,m,x,...) m(d,21,x) __VA_OPT__(MA_VA_FOR_EACH_impl_21(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_21(d,m,x,...) m(d,22,x) __VA_OPT__(MA_VA_FOR_EACH_impl_22(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_22(d,m,x,...) m(d,23,x) __VA_OPT__(MA_VA_FOR_EACH_impl_23(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_23(d,m,x,...) m(d,24,x) __VA_OPT__(MA_VA_FOR_EACH_impl_24(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_24(d,m,x,...) m(d,25,x) __VA_OPT__(MA_VA_FOR_EACH_impl_25(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_25(d,m,x,...) m(d,26,x) __VA_OPT__(MA_VA_FOR_EACH_impl_26(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_26(d,m,x,...) m(d,27,x) __VA_OPT__(MA_VA_FOR_EACH_impl_27(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_27(d,m,x,...) m(d,28,x) __VA_OPT__(MA_VA_FOR_EACH_impl_28(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_28(d,m,x,...) m(d,29,x) __VA_OPT__(MA_VA_FOR_EACH_impl_29(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_29(d,m,x,...) m(d,30,x) __VA_OPT__(MA_VA_FOR_EACH_impl_30(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_30(d,m,x,...) m(d,31,x) __VA_OPT__(MA_VA_FOR_EACH_impl_31(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_31(d,m,x,...) m(d,32,x) __VA_OPT__(MA_VA_FOR_EACH_impl_32(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_32(d,m,x,...) m(d,33,x) __VA_OPT__(MA_VA_FOR_EACH_impl_33(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_33(d,m,x,...) m(d,34,x) __VA_OPT__(MA_VA_FOR_EACH_impl_34(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_34(d,m,x,...) m(d,35,x) __VA_OPT__(MA_VA_FOR_EACH_impl_35(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_35(d,m,x,...) m(d,36,x) __VA_OPT__(MA_VA_FOR_EACH_impl_36(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_36(d,m,x,...) m(d,37,x) __VA_OPT__(MA_VA_FOR_EACH_impl_37(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_37(d,m,x,...) m(d,38,x) __VA_OPT__(MA_VA_FOR_EACH_impl_38(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_38(d,m,x,...) m(d,39,x) __VA_OPT__(MA_VA_FOR_EACH_impl_39(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_39(d,m,x,...) m(d,40,x) __VA_OPT__(MA_VA_FOR_EACH_impl_40(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_40(d,m,x,...) m(d,41,x) __VA_OPT__(MA_VA_FOR_EACH_impl_41(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_41(d,m,x,...) m(d,42,x) __VA_OPT__(MA_VA_FOR_EACH_impl_42(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_42(d,m,x,...) m(d,43,x) __VA_OPT__(MA_VA_FOR_EACH_impl_43(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_43(d,m,x,...) m(d,44,x) __VA_OPT__(MA_VA_FOR_EACH_impl_44(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_44(d,m,x,...) m(d,45,x) __VA_OPT__(MA_VA_FOR_EACH_impl_45(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_45(d,m,x,...) m(d,46,x) __VA_OPT__(MA_VA_FOR_EACH_impl_46(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_46(d,m,x,...) m(d,47,x) __VA_OPT__(MA_VA_FOR_EACH_impl_47(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_47(d,m,x,...) m(d,48,x) __VA_OPT__(MA_VA_FOR_EACH_impl_48(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_48(d,m,x,...) m(d,49,x) __VA_OPT__(MA_VA_FOR_EACH_impl_49(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_49(d,m,x,...) m(d,50,x) __VA_OPT__(MA_VA_FOR_EACH_impl_50(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_50(d,m,x,...) m(d,51,x) __VA_OPT__(MA_VA_FOR_EACH_impl_51(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_51(d,m,x,...) m(d,52,x) __VA_OPT__(MA_VA_FOR_EACH_impl_52(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_52(d,m,x,...) m(d,53,x) __VA_OPT__(MA_VA_FOR_EACH_impl_53(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_53(d,m,x,...) m(d,54,x) __VA_OPT__(MA_VA_FOR_EACH_impl_54(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_54(d,m,x,...) m(d,55,x) __VA_OPT__(MA_VA_FOR_EACH_impl_55(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_55(d,m,x,...) m(d,56,x) __VA_OPT__(MA_VA_FOR_EACH_impl_56(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_56(d,m,x,...) m(d,57,x) __VA_OPT__(MA_VA_FOR_EACH_impl_57(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_57(d,m,x,...) m(d,58,x) __VA_OPT__(MA_VA_FOR_EACH_impl_58(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_58(d,m,x,...) m(d,59,x) __VA_OPT__(MA_VA_FOR_EACH_impl_59(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_59(d,m,x,...) m(d,60,x) __VA_OPT__(MA_VA_FOR_EACH_impl_60(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_60(d,m,x,...) m(d,61,x) __VA_OPT__(MA_VA_FOR_EACH_impl_61(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_61(d,m,x,...) m(d,62,x) __VA_OPT__(MA_VA_FOR_EACH_impl_62(d,m,__VA_ARGS__))
#define MA_VA_FOR_EACH_impl_62(d,m,x,...) m(d,63,x) __VA_OPT__(MA_VA_FOR_EACH_impl_63(d,m,__VA_ARGS__))

// Similar to `MA_VA_FOR_EACH`, but operates on sequences like `(a)(b)(c)`.
#define MA_SEQ_FOR_EACH(d,m,...) __VA_OPT__(MA_SEQ_FOR_EACH_impl_minus1(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_1(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_SEQ_FOR_EACH_2(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_SEQ_FOR_EACH_3(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_SEQ_FOR_EACH_4(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_SEQ_FOR_EACH_5(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))
#define MA_SEQ_FOR_EACH_6(i,d,m,...) __VA_OPT__(MA_CAT(MA_SEQ_FOR_EACH_impl_,i)(d,m,__VA_ARGS__))

#define MA_SEQ_FOR_EACH_impl_minus1(d,m,x,...) m(d,0,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_0(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_0(d,m,x,...) m(d,1,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_1(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_1(d,m,x,...) m(d,2,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_2(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_2(d,m,x,...) m(d,3,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_3(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_3(d,m,x,...) m(d,4,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_4(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_4(d,m,x,...) m(d,5,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_5(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_5(d,m,x,...) m(d,6,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_6(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_6(d,m,x,...) m(d,7,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_7(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_7(d,m,x,...) m(d,8,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_8(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_8(d,m,x,...) m(d,9,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_9(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_9(d,m,x,...) m(d,10,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_10(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_10(d,m,x,...) m(d,11,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_11(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_11(d,m,x,...) m(d,12,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_12(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_12(d,m,x,...) m(d,13,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_13(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_13(d,m,x,...) m(d,14,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_14(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_14(d,m,x,...) m(d,15,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_15(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_15(d,m,x,...) m(d,16,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_16(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_16(d,m,x,...) m(d,17,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_17(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_17(d,m,x,...) m(d,18,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_18(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_18(d,m,x,...) m(d,19,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_19(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_19(d,m,x,...) m(d,20,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_20(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_20(d,m,x,...) m(d,21,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_21(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_21(d,m,x,...) m(d,22,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_22(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_22(d,m,x,...) m(d,23,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_23(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_23(d,m,x,...) m(d,24,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_24(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_24(d,m,x,...) m(d,25,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_25(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_25(d,m,x,...) m(d,26,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_26(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_26(d,m,x,...) m(d,27,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_27(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_27(d,m,x,...) m(d,28,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_28(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_28(d,m,x,...) m(d,29,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_29(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_29(d,m,x,...) m(d,30,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_30(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_30(d,m,x,...) m(d,31,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_31(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_31(d,m,x,...) m(d,32,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_32(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_32(d,m,x,...) m(d,33,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_33(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_33(d,m,x,...) m(d,34,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_34(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_34(d,m,x,...) m(d,35,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_35(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_35(d,m,x,...) m(d,36,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_36(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_36(d,m,x,...) m(d,37,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_37(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_37(d,m,x,...) m(d,38,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_38(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_38(d,m,x,...) m(d,39,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_39(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_39(d,m,x,...) m(d,40,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_40(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_40(d,m,x,...) m(d,41,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_41(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_41(d,m,x,...) m(d,42,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_42(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_42(d,m,x,...) m(d,43,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_43(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_43(d,m,x,...) m(d,44,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_44(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_44(d,m,x,...) m(d,45,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_45(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_45(d,m,x,...) m(d,46,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_46(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_46(d,m,x,...) m(d,47,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_47(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_47(d,m,x,...) m(d,48,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_48(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_48(d,m,x,...) m(d,49,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_49(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_49(d,m,x,...) m(d,50,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_50(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_50(d,m,x,...) m(d,51,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_51(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_51(d,m,x,...) m(d,52,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_52(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_52(d,m,x,...) m(d,53,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_53(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_53(d,m,x,...) m(d,54,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_54(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_54(d,m,x,...) m(d,55,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_55(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_55(d,m,x,...) m(d,56,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_56(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_56(d,m,x,...) m(d,57,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_57(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_57(d,m,x,...) m(d,58,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_58(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_58(d,m,x,...) m(d,59,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_59(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_59(d,m,x,...) m(d,60,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_60(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_60(d,m,x,...) m(d,61,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_61(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_61(d,m,x,...) m(d,62,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_62(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
#define MA_SEQ_FOR_EACH_impl_62(d,m,x,...) m(d,63,x) __VA_OPT__(MA_SEQ_FOR_EACH_impl_63(d,m,MA_SEQ_FIRST(__VA_ARGS__),MA_SEQ_NO_FIRST(__VA_ARGS__)))
