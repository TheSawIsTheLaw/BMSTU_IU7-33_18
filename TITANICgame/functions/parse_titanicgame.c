#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/struct.h"

#define TESTSET 418
#define TRAINSET 891

#define OK 0

char *get_field(char *const line, int field)
{
    char *tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--field)
            return tok;
    }

    return NULL;
}

int compare_none(char *const str)
{
    if (!strcmp(str, "None"))
    {
        return 1;
    }

    return 0;
}

void parse_set(passenger *const set, const int set_len, FILE *f)
{
    for (int data = 0; data < set_len; ++data)
    {
        char line[MAX_STRING_LEN], tmp[MAX_STRING_LEN], field[MAX_STRING_LEN];
        fgets(line, MAX_STRING_LEN, f);
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 1));
        if (compare_none(field))
        {
            set[data].passenger_id = -1;
        }
        else
        {
            set[data].passenger_id = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 2));
        if (compare_none(field))
        {
            set[data].survived = -1;
        }
        else
        {
            set[data].survived = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 3));
        if (compare_none(field))
        {
            set[data].pclass = -1;
        }
        else
        {
            set[data].pclass = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 4));
        if (compare_none(field))
        {
            strcpy(set[data].name, "\0");
        }
        else
        {
            strcpy(set[data].name, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 5));
        if (compare_none(field))
        {
            strcpy(set[data].sex, "\0");
        }
        else
        {
            strcpy(set[data].sex, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 6));
        if (compare_none(field))
        {
            set[data].age = -1.0;
        }
        else
        {
            set[data].age = atof(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 7));
        if (compare_none(field))
        {
            set[data].siblings_sp = -1;
        }
        else
        {
            set[data].siblings_sp = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 8));
        if (compare_none(field))
        {
            set[data].parch = -1;
        }
        else
        {
            set[data].parch = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 9));
        if (compare_none(field))
        {
            strcpy(set[data].ticket, "\0");
        }
        else
        {
            strcpy(set[data].ticket, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 10));
        if (compare_none(field))
        {
            set[data].fare = -1;
        }
        else
        {
            set[data].fare = atof(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 11));
        if (compare_none(field))
        {
            strcpy(set[data].cabin, "\0");
        }
        else
        {
            strcpy(set[data].cabin, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 12));
        if (compare_none(field))
        {
            set[data].embarked = '\0';
        }
        else
        {
            set[data].embarked = field[0];
        }
    }
}

void parse(passenger *const test_p, passenger *const train_p)
{
    FILE *test = fopen("TITANICgame/data/test.csv", "r");
    FILE *train = fopen("TITANICgame/data/train.csv", "r");

    parse_set(test_p, TESTSET, test);
    parse_set(train_p, TRAINSET, train);

    fclose(test);
    fclose(train);
}