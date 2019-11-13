/*
** PERSONAL PROJECT, 2019
** 2_pow_computer
** File description:
** 2 powers detectors
*/

#include <stdlib.h>
#include "../include/2pow.h"
#include "../include/my.h"

uint adjust(char *optarg, uint val)
{
    for (int i = 0; optarg[i]; i++)
        if (optarg[i] != '0' && val == 0)
            return (MAX);
    return (val);
}

int end_exceeded(char *number, char *limit)
{
    if (!limit || !number)
        return (FALSE);
    if (my_strcmpi(number, limit) >= 0)
        return (TRUE);
    return (FALSE);
}

int digits_ok(set_t *settings, char *nb)
{
    if (!nb)
        return (TRUE);
    if (my_strlen(nb) >= settings->digits)
        return (FALSE);
    return (TRUE);
}
