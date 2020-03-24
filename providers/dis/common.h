#include <stdio.h>

#ifdef DEBUG
#define DEBUG_PRINT 1
#else
#define DEBUG_PRINT 0
#endif

#define printf_debug(fmt, ...) \
do { \
    if (DEBUG_PRINT) { \
        fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__,  __func__, \
                    ##__VA_ARGS__); \
    } \
} while (0)

#define DIS_STATUS_START    "Started.\n"
#define DIS_STATUS_COMPLETE "Completed.\n"
#define DIS_STATUS_FAIL     "Failed.\n"