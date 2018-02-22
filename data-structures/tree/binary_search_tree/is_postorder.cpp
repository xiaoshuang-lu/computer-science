# include <cstdint>

intmax_t is_postorder(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (length < 2)
    {
        return 1;
    }

    intmax_t root = begin[length - 1];
    intmax_t i, j;
    intmax_t left = 1, right = 1;

    for (i = 0; i < length - 1; ++ i)
    {
        if (! (begin[i] < root))
        {
            break;
        }
    }

    for (j = i; j < length - 1; ++ j)
    {
        if (begin[j] < root)
        {
            return 0;
        }
    }

    if (i > 0)
    {
        left = is_postorder(begin, begin + i);
    }

    if (i < length - 1)
    {
        right = is_postorder(begin + i, end - 1);
    }

    if (left == 1 && right == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {3, 4, 1, 5, 6, 2, 0};

        intmax_t result = is_postorder(array + 0, array + 7);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
