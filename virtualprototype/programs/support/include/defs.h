#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

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

// #define 是预处理指令，用于定义宏。
// __packed 是宏的名字。
// __attribute__((packed)) 是 GCC 编译器的一个扩展，用于告诉编译器：

// “不要对结构体成员进行对齐优化，按最紧凑的方式排列。”
// It's built into the GCC compiler itself — not stored in a header file or external library.
// When you compile code with GCC, 
// the compiler recognizes __attribute__ as a keyword 
// and applies the specified behavior (like packed) during compilation.

/**
 * @brief Alignment.
 * 
 */
#define __aligned(x) __attribute__((aligned(x)))

#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)

#endif /* DEFS_H_INCLUDED */

// The __aligned(x) macro is used to specify memory alignment requirements for variables or data structures. 
// When applied, it ensures that the annotated variable or structure is aligned to x bytes in memory, 
// where x is typically a power of 2 (like 4, 8, 16, etc.).
