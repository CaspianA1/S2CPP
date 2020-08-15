// if_macro.c

#include <stdio.h>

#define _COND_CHECK(cond, res1, res2) cond ? res1 : res2
#define STD_IF _COND_CHECK
#define FUNCTION_IF return _COND_CHECK

// try making cond as well

int main() {
    int y = 6;
    int x = STD_IF(y == 6, 99, 100);
    printf("Annnd the grand finale: %d", x);
    return 0;
}