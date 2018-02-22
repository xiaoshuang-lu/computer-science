# include <cstdint>
# include <cstdlib>

intmax_t random_shuffle(intmax_t * begin, intmax_t * end)
{
    intmax_t size = end - begin;

    for (intmax_t i = 0; i < size; ++ i)
    {
        intmax_t swap = rand() % (i + 1);

        intmax_t temporary = begin[i];
        begin[i] = begin[swap];
        begin[swap] = temporary;
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
        intmax_t array[] = {0, 1, 2, 3, 4, 5, 6, 7};

        random_shuffle(array + 0, array + 8);

        for (intmax_t i = 0; i < 8; ++ i)
        {
            printf("%" PRIdMAX " ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
