#include <stdio.h>

//General concept

#define PRINT(...) (IF_ELSE(IS_EMPTY(__VA_ARGS__)) (PRINTF("\n")) \
                                        (EVAL(PRINT_(__VA_ARGS__))))
#define PRINT_(X, ...) PRINTF(X) IF_ELSE(IS_EMPTY(__VA_ARGS__)) () \
                                  (+ DELAY2(PRINT__)()(__VA_ARGS__))
#define PRINT__() PRINT_

#define PRINTF(X) F_PRINT(X)(FORMAT_PR(X), X)

#define EVAL(...) EXPAND256(__VA_ARGS__)

#define IF_0FALSE__(...) ELSE_0FALSE__
#define IF_1TRUE__(...) __VA_ARGS__ ELSE_1TRUE__
#define ELSE_0FALSE__(...) __VA_ARGS__
#define ELSE_1TRUE__(...)
#define NOT(X) TEST(CAT(NOT_, X))
#define NOT_0FALSE__ IS_TRUE()
#define TRUTHINESS(X) NOT(NOT(X))
#define IF_ELSE(X) IF_ELSE_(TRUTHINESS(X))
#define IF_ELSE_(X) CAT(IF_, X)

#define TEST(X) SECOND(X, 0FALSE__)
#define SECOND(X, Y, ...) Y
#define IS_TRUE() -, 1TRUE__
#define FIRST(X, ...) X

#define SECOND_EXP(...) SECOND(__VA_ARGS__)
#define DET_PAR_(...) -, 1TRUE__
#define DET_PAR(...) SECOND_EXP(DET_PAR_ __VA_ARGS__, 0FALSE__)
#define PAR_0FALSE__(...) __VA_ARGS__
#define PAR_1TRUE__(...) -

#define IS_EMPTY(...) TEST(FIRST(IS_TRUE \
        CAT(PAR_, DET_PAR(FIRST(__VA_ARGS__)))(FIRST(__VA_ARGS__))()))

#define CAT(X, Y) CAT_(X, Y)
#define CAT_(X, Y) X ## Y

#define TO_STR(X) TO_STR_(X)
#define TO_STR_(X) # X

#define DELAY(X) X EMPTY()
#define DELAY2(...) __VA_ARGS__ DELAY(EMPTY)()

#define EMPTY()

#define EXPAND(...) __VA_ARGS__
#define EXPAND4(...) EXPAND(EXPAND(EXPAND(EXPAND(__VA_ARGS__))))
#define EXPAND16(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND64(...) EXPAND16(EXPAND16(EXPAND16(EXPAND16(__VA_ARGS__))))
#define EXPAND256(...) EXPAND64(EXPAND64(EXPAND64(EXPAND64(__VA_ARGS__))))

//Below is specific code for PRINT

struct {unsigned long long val;} typedef int_hex_;
struct {unsigned long long val;} typedef int_oct_;

int print_hex(const char *f_str, int_hex_ val)
{
    return printf(f_str, val.val);
}
int print_oct(const char *f_str, int_oct_ val)
{
    return printf(f_str, val.val);
}

#define HEX(X) (int_hex_){X}
#define OCT(X) (int_oct_){X}

#define F_PRINT(X) _Generic((X),\
        int_hex_: print_hex,\
        int_oct_: print_oct,\
        default: printf)
#define FORMAT_PR(X) (*TO_STR(X) == '\'' ? "%c" :\
        _Generic((X),\
        int: "%i",\
        unsigned: "%u",\
        double: "%f",\
        char: "%c",\
        char *: "%s",\
        int_hex_: "%llX",\
        int_oct_: "%llo",\
        default: "%p"))

int main(void)
{
    PRINT(1, 2, 3, "\n", HEX(0xff), "\n", OCT(0xff));
    return 0;
}