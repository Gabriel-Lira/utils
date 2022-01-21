#ifndef REPEAT_TYPE
#define REPEAT_TYPE

#ifdef __cplusplus
extern "C"
{
#endif

#define REPEAT_0(X)
#define REPEAT_1(X) X
#define REPEAT_2(X) REPEAT_1(X) X
#define REPEAT_3(X) REPEAT_2(X) X
#define REPEAT_4(X) REPEAT_3(X) X
#define REPEAT_5(X) REPEAT_4(X) X
#define REPEAT_6(X) REPEAT_5(X) X
#define REPEAT_7(X) REPEAT_6(X) X
#define REPEAT_8(X) REPEAT_7(X) X
#define REPEAT_9(X) REPEAT_8(X) X
#define REPEAT_10(X) REPEAT_9(X) X
#define REPEAT_100(X) REPEAT_10(REPEAT_10(X))

#define REPEAT_ONES(X, ONES) REPEAT_##ONES(X)
#define REPEAT_TENS(X, TENS) REPEAT_##TENS(REPEAT_10(X))
#define REPEAT_HUNDREDS(X, HUNDREDS) REPEAT_##HUNDREDS(REPEAT_100(X))

#define REPEAT(X, HUNDREDS, TENS, ONES)                                        \
    REPEAT_HUNDREDS(X, HUNDREDS) REPEAT_TENS(X, TENS) REPEAT_ONES(X, ONES)

#ifdef __cplusplus
}
#endif

#endif // REPEAT_TYPE