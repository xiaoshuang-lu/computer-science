# include <cstdint>

intmax_t fibonacci(intmax_t n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    intmax_t a = 0;
    intmax_t b = 1;

    for (intmax_t i = 2; i < n; ++ i)
    {
        intmax_t temporary = a + b;
        a = b;
        b = temporary;
    }

    return a + b;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        for (intmax_t i = 0; i < 8; ++ i)
        {
            intmax_t data = fibonacci(i);

            printf("%" PRIdMAX " ", data);
        }
        printf("\n");
    }

    return 0;
}
