// implement rand7 with rand2

# include <cstdint>
# include <cstdlib>

intmax_t rand2()
{
    return rand() % 2;
}

intmax_t rand7()
{
    while (true)
    {
        intmax_t value = 4 * rand2() + 2 * rand2() + rand2();

        if (value < 7)
        {
            return value;
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
