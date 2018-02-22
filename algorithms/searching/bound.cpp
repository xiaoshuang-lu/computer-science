# include <cstdint>

intmax_t * lower_bound(intmax_t * begin, intmax_t * end, intmax_t key)
{
    while (end - begin > 0)
    {
        intmax_t * middle = begin + ((end - begin) >> 1);

        if (* middle < key)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle;
        }
    }

    return end;
}

intmax_t * upper_bound(intmax_t * begin, intmax_t * end, intmax_t key)
{
    while (end - begin > 0)
    {
        intmax_t * middle = begin + ((end - begin) >> 1);

        if (! (key < * middle))
        {
            begin = middle + 1;
        }
        else
        {
            end = middle;
        }
    }

    return end;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {0, 0, 0, 0, 0, 0, 0, 0};

        intmax_t * result;

        result = lower_bound(array + 0, array + 8, 0);

        printf("%" PRIdMAX "\n", result - array);

        result = upper_bound(array + 0, array + 8, 0);

        printf("%" PRIdMAX "\n", result - array);

        result = lower_bound(array + 0, array + 8, 1);

        printf("%" PRIdMAX "\n", result - array);

        result = upper_bound(array + 0, array + 8, 1);

        printf("%" PRIdMAX "\n", result - array);
    }

    {
        intmax_t array[] = {0, 0, 1, 1, 1, 1, 2, 2};

        intmax_t * result;

        result = lower_bound(array + 0, array + 8, 1);

        printf("%" PRIdMAX "\n", result - array);

        result = upper_bound(array + 0, array + 8, 1);

        printf("%" PRIdMAX "\n", result - array);
    }

    return 0;
}
