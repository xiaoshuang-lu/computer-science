# include <cstdint>
# include <cstdlib>

intmax_t reservoir_sample(intmax_t * begin, intmax_t * end, intmax_t * reservoir_begin, intmax_t * reservoir_end)
{
    intmax_t size = end - begin;
    intmax_t reservoir_size = reservoir_end - reservoir_begin;

    intmax_t i = 0;

    while (i < reservoir_size)
    {
        reservoir_begin[i] = begin[i];
        ++ i;
    }

    while (i < size)
    {
        intmax_t index = rand() % (i + 1);

        if (index < reservoir_size)
        {
            reservoir_begin[index] = begin[i];
        }

        ++ i;
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>
# include <ctime>

int main()
{
    {
        srand(time(0));
    }

    {
        intmax_t array[64];

        for (intmax_t i = 0; i < 64; ++ i)
        {
            array[i] = i;
        }

        intmax_t reservoir[4];

        reservoir_sample(array + 0, array + 64, reservoir + 0, reservoir + 4);

        for (intmax_t i = 0; i < 4; ++ i)
        {
            printf("%" PRIdMAX " ", reservoir[i]);
        }
        printf("\n");
    }

    return 0;
}
