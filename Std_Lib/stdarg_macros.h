#include <stdarg.h>
#define INIT va_list args; va_start(args, nargs);
#define LOOP for (int i = 0; i < nargs; i++)
#define DEINIT va_end(args); return r;