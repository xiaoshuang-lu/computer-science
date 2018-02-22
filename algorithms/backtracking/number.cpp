# include <cstdint>
# include <cstdio>

intmax_t do_dirty_work(int8_t * array, intmax_t length, intmax_t index)
{
    if (index == length)
    {
        printf("%s\n", array);

        return 0;
    }

    for (intmax_t i = 0; i < 10; ++ i)
    {
        array[index] = i + '0';

        do_dirty_work(array, length, index + 1);
    }

    return 0;
}

int main()
{
    int8_t array[8];

    do_dirty_work(array, 2, 0);

    return 0;
}
