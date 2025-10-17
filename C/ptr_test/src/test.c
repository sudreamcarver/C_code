#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    size_t n = 5;
    size_t *arry = malloc (n * sizeof (size_t));

    if (arry == NULL)
        {
            perror ("malloc failed");
            return 1;
        }

    for (size_t i = 0; i < n; ++i)
        {
            arry[i] = i * i;
        }
    for (size_t i = 0; i < n; ++i)
        printf ("%ld", arry[i]);
    printf ("\n");

    free (arry);
    arry = NULL;

    return 0;
}
