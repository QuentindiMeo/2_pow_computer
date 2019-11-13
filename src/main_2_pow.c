/*
** PERSONAL PROJECT, 2019
** 2_pow_computer
** File description:
** main 2 powers computer
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/2pow.h"
#include "../include/my.h"

static char *get_nb(char *res)
{
    char *nb = my_evil_str(res);
    char *buff = NULL;

    if (*nb == '0') {
        buff = my_cut_str(nb, 1, my_strlen(nb));
        free(nb);
        return (buff);
    }
    return (nb);
}

static void twopow_find(set_t *settings)
{
    char *res = NULL;
    char *nb = NULL;
    int len;

    if (settings->find > 2222)
        printf("This may take a while...\n");
    for (uint nth = 1; nth <= settings->find; nth++) {
        len = (res == NULL) ? 0 : count_len(res);
        free2(res, nb);
        res = malloc(sizeof(char) * len + 3);
        fill_res(res, len + 2);
        calculate_res(res, nth);
        nb = get_nb(res);
    }
    write_result(settings->find, nb, settings);
    free2(res, nb);
}

static void twopow_loop(set_t *settings)
{
    char *res = NULL;
    char *nb = NULL;
    int len;

    if (!settings->silent && my_strcmpi("1\0", settings->start) >= 0)
        write_result(0, "1", settings);
    for (uint nth = 1; nth <= settings->until; nth++) {
        len = (res == NULL) ? 0 : count_len(res);
        free2(res, nb);
        res = malloc(sizeof(char) * len + 3);
        fill_res(res, len + 2);
        calculate_res(res, nth);
        nb = get_nb(res);
        if (!digits_ok(settings, nb) || end_exceeded(nb, settings->end))
            break;
        if (my_strcmpi(nb, settings->start) >= 0)
            write_result(nth, nb, settings);
    }
    free2(res, nb);
}

int main(int ac, char **av)
{
    set_t *settings = NULL;

    if (my_str_isinarray(av, "-h") || my_str_isinarray(av, "--help"))
        return (help());
    settings = setup();
    if (get_settings(ac, av, settings) == FAILURE)
        return (FAILURE);
    if (settings->find != 0)
        twopow_find(settings);
    else {
        remove("calculations_2pow.txt");
        twopow_loop(settings);
    }
    printf("Calculations done.\n");
    freer(settings);
    return (SUCCESS);
}
