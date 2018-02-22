# include <cinttypes>
# include <cstdint>
# include <cstdio>

intmax_t permutation(intmax_t * begin, intmax_t * end, intmax_t * left, intmax_t * right)
{
    if (left == right || left == right - 1)
    {
        while (begin != end)
        {
            printf("%" PRIdMAX " ", * begin);
            ++ begin;
        }
        printf("\n");

        return 0;
    }

    for (intmax_t * i = left; i != right; ++ i)
    {
        {
            intmax_t temporary = * i;
            * i = * left;
            * left = temporary;
        }

        permutation(begin, end, left + 1, right);

        {
            intmax_t temporary = * i;
            * i = * left;
            * left = temporary;
        }
    }

    return 0;
}

int main()
{
    {
        intmax_t array[] = {0, 1, 2, 3};

        permutation(array + 0, array + 4, array + 0, array + 4);
    }

    return 0;
}
