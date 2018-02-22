# include <cstdint>

intmax_t catalan(intmax_t n)
{
    if (n == 0)
    {
        return 1;
    }

    intmax_t * array = new intmax_t[n + 1];

    array[0] = 1;

    for (intmax_t i = 1; i < n + 1; ++ i)
    {
        intmax_t temporary = 0;

        for (intmax_t j = 0; j < i; ++ j)
        {
            temporary = temporary + array[j] * array[i - 1 - j];
        }

        array[i] = temporary;
    }

    intmax_t result = array[n];

    delete[] array;

    return result;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        for (intmax_t i = 0; i < 8; ++ i)
        {
            intmax_t data = catalan(i);

            printf("%" PRIdMAX " ", data);
        }
        printf("\n");
    }

    return 0;
}
