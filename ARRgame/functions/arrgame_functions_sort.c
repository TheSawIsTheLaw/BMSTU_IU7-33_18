/*
Функция быстрой сортировки сортирующая интервал:
1) По возрастанию передается ключ UP_SORT_KEY
2) По убыванию DOWN_SORT_KEY
3) Передается отрезок, концы которого являются валидными указателями
*/

#include "../headers/arrgame.h"

#define UP_SORT_KEY 1
#define DOWN_SORT_KEY -1

static void change(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

static void up_sort(int *head, int *tail)
{
    int len = tail - head;

    if (head >= tail)
    {
        return;
    }

    int mid = *(head + len / 2);
    int *start = head, *end = tail;

    while (start <= end)
    {
        while (*start < mid)
        {
            start++;
        }

        while (*end > mid)
        {
            end--;
        }

        if (start <= end)
        {
            change(start, end);
            start++;
            end--;
        }
    }

    up_sort(head, end);
    up_sort(start, tail);
}

static void down_sort(int *head, int *tail)
{
    int len = tail - head;

    if (head >= tail)
    {
        return;
    }

    int mid = *(head + len / 2);
    int *start = head, *end = tail;

    while (start <= end)
    {
        while (*start > mid)
        {
            start++;
        }

        while (*end < mid)
        {
            end--;
        }

        if (start <= end)
        {
            change(start, end);
            start++;
            end--;
        }
    }

    down_sort(head, end);
    down_sort(start, tail);
}

void arrgame_sort(int *head, int *tail, int key) // Принимает указатели на сортируемый интервал
{
    if (key == UP_SORT_KEY)
    {
        up_sort(head, tail);
    }
    else
    {
        down_sort(head, tail);
    }
}
