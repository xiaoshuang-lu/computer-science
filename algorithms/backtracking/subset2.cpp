// input may have duplicates

# include <cinttypes>
# include <cstdint>
# include <cstdio>

# include <algorithm>

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

    intmax_t count = 1;

    for (intmax_t i = index + 1; i < length; ++ i)
    {
        if (begin[index] == begin[i])
        {
            ++ count;
        }
        else
        {
            break;
        }
    }

    std::fill(array + index + 0, array + index + count, 0);

    do_dirty_work(begin, end, array, index + count);

    for (intmax_t i = 0; i < count; ++ i)
    {
        array[index + i] = 1;

        do_dirty_work(begin, end, array, index + count);
    }

    return 0;
}

intmax_t subset(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (0 < length)
    {
        std::sort(begin, end);

        intmax_t * array = new intmax_t[length];

        do_dirty_work(begin, end, array, 0);

        delete[] array;
    }

    return 0;
}

int main()
{
    {
        intmax_t array[4] = {0, 1, 1, 2};

        subset(array + 0, array + 4);
    }

    return 0;
}
