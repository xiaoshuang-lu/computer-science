# include <cstdint>

# include <vector>

intmax_t nth_permutation(intmax_t * begin, intmax_t * end, intmax_t n)
{
    intmax_t length = end - begin;

    intmax_t * factorial = new intmax_t[length + 1];

    factorial[0] = 1;

    for (intmax_t i = 1; i <= length; ++ i)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    std::vector<intmax_t> temporary(begin, end);

    for (intmax_t i = 1; i <= length; ++ i)
    {
        intmax_t index = n / factorial[length - i];

        * begin ++ = temporary[index];

        temporary.erase(temporary.begin() + index);

        n = n % factorial[length - i];
    }

    delete[] factorial;

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {0, 1, 2, 3};

        nth_permutation(array + 0, array + 4, 1);

        for (intmax_t i = 0; i < 4; ++ i)
        {
            printf("%02" PRIdMAX " ", array[i]);
        }
        printf("\n");
    }

    {
        intmax_t array[] = {0, 1, 2, 3};

        nth_permutation(array + 0, array + 4, 4);

        for (intmax_t i = 0; i < 4; ++ i)
        {
            printf("%02" PRIdMAX " ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
