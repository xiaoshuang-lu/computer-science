// implement rand7 with rand5

# include <cstdint>
# include <cstdlib>

intmax_t rand5()
{
    return rand() % 5;
}

intmax_t rand7()
{
    while (true)
    {
        intmax_t value = 5 * rand5() + rand5();

        if (value < 21)
        {
            return value % 7;
        }
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>
# include <ctime>

int main()
{
    srand(time(0));

    {
        for (intmax_t i = 0; i < 8; ++ i)
        {
            printf("%" PRIdMAX " ", rand7());
        }
        printf("\n");
    }

    return 0;
}
