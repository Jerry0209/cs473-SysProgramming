#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED

#include <defs.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int (*assert_printf)(const char*, ...);
extern void assert_die();

#define die_if_not_f(expr, format, ...)                                                            \
    do {                                                                                           \
        if (!(expr)) {                                                                             \
            assert_printf(                                                                         \
                "[ ASSERT ] \"%s\" Message: " format                                               \
                " (from " __FILE__ ":" STRINGIZE(__LINE__) ")\n", #expr __VA_OPT__(, ) __VA_ARGS__ \
            );                                                                                     \
            assert_die();                                                                          \
        }                                                                                          \
    } while (0)

#define die_if_not(expr)                                                \
    do {                                                                \
        if (!(expr)) {                                                  \
            assert_printf(                                              \
                "[ ASSERT ] \"%s\""                                     \
                " (from " __FILE__ ":" STRINGIZE(__LINE__) ")\n", #expr \
            );                                                          \
            assert_die();                                               \
        }                                                               \
    } while (0)

#ifndef NDEBUG
#define assert(...) die_if_not(__VA_ARGS__)
#define assert_f(...) die_if_not_f(__VA_ARGS__)
#else
#define assert(...)
#define assert_f(...)
#endif

#ifdef __cplusplus
}
#endif

#endif /* ASSERT_H_INCLUDED */
