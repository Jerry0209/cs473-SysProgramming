/**
 * @file params.h
 * 
 * Defines the parameters used in the test and their default values.
 * 
 */

#ifndef PARAMS_H_INCLUDED
#define PARAMS_H_INCLUDED

#ifndef PARAM_COUNT
#define PARAM_COUNT 16
#endif

#define PARAM_MAGIC (PARAM_COUNT - 1)

#ifndef PARAM_DATALEN
#define PARAM_DATALEN 17
#endif

#ifdef PARAM_PACKED
#define PACKED __packed
#else
#define PACKED
#endif

#ifndef PARAM_DESC
#define PARAM_DESC "None"
#endif

#ifndef PARAM_ENTRY
#define PARAM_ENTRY test_none_main
#endif

#endif /* PARAMS_H_INCLUDED */
