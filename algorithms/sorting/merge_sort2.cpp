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

intmax_t merge_sort(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (1 < length)
    {
        intmax_t * array = new intmax_t[length];

        intmax_t step = 1;

        while (step < length)
        {
            intmax_t * pointer = begin;

            while (pointer + step + step <= end)
            {
                merge(pointer, pointer + step, pointer + step + step, array + (pointer - begin));

                pointer = pointer + step + step;
            }

            if (pointer + step <= end)
            {
                merge(pointer, pointer + step, end, array + (pointer - begin));
            }

            step = step << 1;
        }

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
