// input has no duplicates

# include <cinttypes>
# include <cstdint>
# include <cstdio>

intmax_t do_dirty_work(intmax_t * begin, intmax_t * end, intmax_t * array, intmax_t index)
{
    intmax_t length = end - begin;

    if (index == length)
    {
        for (intmax_t i = 0; i < length; ++ i)
        {
            if (array[i] == 1)
            {
                printf("%" PRIdMAX " ", begin[i]);
            }
        }
        printf("\n");

        return 0;
    }

    array[index] = 0;

    do_dirty_work(begin, end, array, index + 1);

    array[index] = 1;

    do_dirty_work(begin, end, array, index + 1);

    return 0;
}

intmax_t subset(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (0 < length)
    {
        intmax_t * array = new intmax_t[length];

        do_dirty_work(begin, end, array, 0);

        delete[] array;
    }
}

int main()
{
    {
        intmax_t array[4] = {0, 1, 2, 3};

        subset(array + 0, array + 4);
    }

    return 0;
}
