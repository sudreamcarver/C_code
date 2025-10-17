#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SWAP(a, b)                                                            \
    _Generic ((a),                                                            \
        int: swap_int,                                                        \
        double: swap_double,                                                  \
        char: swap_char,                                                      \
        default: swap_default) (&(a), &(b))

static inline void
swap_int (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static inline void
swap_double (double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

static inline void
swap_char (char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

static inline void
swap_default (int *a, int *b)
{
    char tmp[sizeof (a)];
    memcpy (tmp, a, sizeof (tmp));
    memcpy (a, b, sizeof (tmp));
    memcpy (b, tmp, sizeof (tmp));
}

int
main (void)
{
    int bigger, smaller, temp;
    scanf ("input a num:%d", &bigger);
    scanf ("input otherone:%d", &smaller);

    if (bigger < smaller)
        {
            temp = smaller;
            smaller = bigger;
            bigger = temp;
        }
    while (bigger % smaller != 0)
        {
            int lay;
            lay = bigger % smaller;

            bigger = lay;
            if (bigger < smaller)
                {
                    SWAP (bigger, smaller);
                }
        }
}
