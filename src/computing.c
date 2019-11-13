/*
** PERSONAL PROJECT, 2019
** 2_pow_computer
** File description:
** 2 powers computer computing functions
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void fill_res(char *res, int n)
{
    int i = 1;

    res[0] = '1';
    for (; i < n; i++)
        res[i] = '0';
    res[i] = 0;
}

int count_len(char *res)
{
    int len = strlen(res) - 1;

    for (; res[len] == '0' || res[len] == 0; len--);
    return (len);
}

void print_res(char *res, int nth)
{
    printf("  2^%d:\t%c", nth, nth >= 100 ? 0 : '\t');
    for (int i = count_len(res); i >= 0; i--)
        printf("%c", res[i]);
    printf("\n");
}

static char calculate_resi(char *res, int jth, char carry)
{
    int nb = res[jth] - 48;

    if (nb < 0)
        return (0);
    nb *= 2;
    nb += carry;
    if (nb > 9) {
        nb %= 10;
        res[jth] = nb + 48;
        return (1);
    }
    res[jth] = nb + 48;
    return (0);
}

void calculate_res(char *res, uint nth)
{
    char carry = 0;

    for (uint i = 0; i < nth; i++) {
        for (uint j = 0; j < strlen(res) + 1; j++)
            carry = calculate_resi(res, j, carry);
        carry = 0;
    }
}
