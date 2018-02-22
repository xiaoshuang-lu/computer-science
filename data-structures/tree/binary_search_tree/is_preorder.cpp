# include <cstdint>

intmax_t is_preorder(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    if (length < 2)
    {
        return 1;
    }

    intmax_t root = * begin;
    intmax_t i, j;
    intmax_t left = 1, right = 1;

    for (i = 1; i < length; ++ i)
    {
        if (! (begin[i] < root))
        {
            break;
        }
    }

    for (j = i; j < length; ++ j)
    {
        if (begin[j] < root)
        {
            return 0;
        }
    }

    if (i > 1)
    {
        left = is_preorder(begin + 1, begin + i);
    }

    if (i < length)
    {
        right = is_preorder(begin + i, end);
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
        intmax_t array[] = {0, 1, 3, 4, 2, 5, 6};

        intmax_t result = is_preorder(array + 0, array + 7);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
