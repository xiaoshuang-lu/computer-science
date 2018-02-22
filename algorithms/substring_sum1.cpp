// find all substrings whose sum equals to n

# include <cinttypes>
# include <cstdint>
# include <cstdio>

intmax_t substring_sum(intmax_t * begin, intmax_t * end, intmax_t n)
{
    intmax_t length = end - begin;

    intmax_t ** array = new intmax_t *[length];

    for (intmax_t i = 0; i < length; ++ i)
    {
        array[i] = new intmax_t[length + 1];
    }

    for (intmax_t i = 0; i < length; ++ i)
    {
        array[i][i] = 0;

        for (intmax_t j = i + 1; j < length + 1; ++ j)
        {
            array[i][j] = array[i][j - 1] + begin[j - 1];

            if (array[i][j] == n)
            {
                printf("(%" PRIdMAX ", %" PRIdMAX "): ", i, j);
                for (intmax_t temporary = i; temporary < j; ++ temporary)
                {
                    printf("%" PRIdMAX " ", begin[temporary]);
                }
                printf("\n");
            }
        }
    }

    for (intmax_t i = 0; i < length; ++ i)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

int main()
{
    {
        intmax_t array[3] = {1, 1, 1};

        substring_sum(array + 0, array + 3, 2);
    }

    {
        intmax_t array[5] = {-3, 1, 2, -3, 4};

        substring_sum(array + 0, array + 5, 0);
    }

    return 0;
}
