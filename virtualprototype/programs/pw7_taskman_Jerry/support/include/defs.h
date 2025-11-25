#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Places a global variable in the .text.global section.
 *
 * @note Trailing `#` prevents assembler messages with mutable variables.
 *
 */
#define __global __attribute__((section(".text.global # ")))

/**
 * @brief Marks a function to be always inline.
 *
 */
#define __always_inline __attribute__((always_inline))

/**
 * @brief Defines a weak symbol.
 *
 */
#define __weak __attribute__((weak))

/**
 * @brief Marks a function to be static and inline.
 *
 */
#define __static_inline static inline __always_inline

/**
 * @brief Disables the optimizations.
 *
 */
#define __no_optimize __attribute__((optimize("O0")))

/**
 * @brief Defines a packed struct.
 *
 */
#define __packed __attribute__((packed))

/**
 * @brief Alignment.
 *
 */
#define __aligned(x) __attribute__((aligned(x)))

#ifndef offsetof

/**
 * @brief Finds the offset of a member in its container type.
 * @param TYPE the container type.
 * @param MEMBER the member identifier.
 */
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE*)0)->MEMBER)

#endif

#ifndef container_of

/**
 * @brief Cast a member of a structure out to the containing structure.
 * @param ptr the pointer to the member.
 * @param type the type of the container struct this is embedded in.
 * @param member the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) \
    (type*)((char*)(ptr) - offsetof(type, member))

#endif

#ifndef memfn
/**
 * @brief Calls a member function.
 * @param ptr the pointer to the object.
 * @param ptr the identifier of the member function.
 */
#define memfn(ptr, func, ...) (((ptr)->func)((ptr)__VA_OPT__(, ) __VA_ARGS__))

#endif

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif

#ifndef STRINGIZE
#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)
#endif

#endif /* DEFS_H_INCLUDED */
