# include <cstdint>
# include <cstdlib>

intmax_t reservoir_sample(intmax_t item, intmax_t * reservoir_begin, intmax_t * reservoir_end, intmax_t & count)
{
    intmax_t reservoir_size = reservoir_end - reservoir_begin;

    if (count < reservoir_size)
    {
        reservoir_begin[count] = item;

        return 0;
    }

    intmax_t index = rand() % (count + 1);

    if (index < reservoir_size)
    {
        reservoir_begin[index] = item;
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
        intmax_t count = 0;

        for (intmax_t i = 0; i < 64; ++ i)
        {
            reservoir_sample(array[i], reservoir + 0, reservoir + 4, count);

            ++ count;
        }

        for (intmax_t i = 0; i < 4; ++ i)
        {
            printf("%" PRIdMAX " ", reservoir[i]);
        }
        printf("\n");
    }

    return 0;
}
