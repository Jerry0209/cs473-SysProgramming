#ifndef IMPLEMENT_ME_H_INCLUDED
#define IMPLEMENT_ME_H_INCLUDED

#include <assert.h>


#ifndef SOLUTION

#define IMPLEMENT_ME                                                   \
    do {                                                               \
        assert_printf(                                                 \
            "[ ASSERT ] '%s' is not implemented."                      \
            " (from " __FILE__ ":" STRINGIZE(__LINE__) ")\n", __func__ \
        );                                                             \
        assert_die();                                                  \
    } while (0)

#else

#define IMPLEMENT_ME

#endif

#undef SOLUTION

#endif /* IMPLEMENT_ME_H_INCLUDED */
