# include <cstdint>

intmax_t merge(intmax_t * begin, intmax_t * middle, intmax_t * end, intmax_t * array)
{
    intmax_t * begin1 = begin;
    intmax_t * end1 = middle;
    intmax_t * begin2 = middle;
    intmax_t * end2 = end;

    while (begin1 != end1 && begin2 != end2)
    {
        if (! (* begin2 < * begin1))
        {
            * array ++ = * begin1 ++;
        }
        else
        {
            * array ++ = * begin2 ++;
        }
    }

    while (begin1 != end1)
    {
        * array ++ = * begin1 ++;
    }

    while (begin2 != end2)
    {
        * array ++ = * begin2 ++;
    }

    while (begin != end)
    {
        * -- end = * -- array;
    }

    return 0;
}

intmax_t do_dirty_work(intmax_t * begin, intmax_t * end, intmax_t * array)
{
    intmax_t length = end - begin;

    if (length < 2)
    {
        return 0;
    }

    do_dirty_work(begin, begin + (length >> 1), array);

    do_dirty_work(begin + (length >> 1), end, array + (length >> 1));

    merge(begin, begin + (length >> 1), end, array);

    return 0;
}

intmax_t merge_sort(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (1 < length)
    {
        intmax_t * array = new intmax_t[length];

        do_dirty_work(begin, end, array);

        delete[] array;
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {7, 6, 5, 4, 3, 2, 1, 0};

        merge_sort(array + 0, array + 8);

        for (intmax_t i = 0; i < 8; ++ i)
        {
            printf("%" PRIdMAX " ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
