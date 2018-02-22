# include <cinttypes>
# include <cstdint>
# include <cstdio>

intmax_t do_dirty_work(intmax_t * input_begin, intmax_t * input_end, intmax_t * output_begin, intmax_t * output_end, intmax_t count)
{
    intmax_t length = input_end - input_begin;

    if (count == length)
    {
        for (intmax_t i = 0; i < length; ++ i)
        {
            printf("%" PRIdMAX " ", output_begin[i]);
        }
        printf("\n");

        return 0;
    }

    for (intmax_t i = 0; i < input_begin[count]; ++ i)
    {
        output_begin[count] = i;

        do_dirty_work(input_begin, input_end, output_begin, output_end, count + 1);
    }

    return 0;
}

int main()
{
    {
        intmax_t input_array[4] = {1, 4, 1, 4};
        intmax_t output_array[4];

        do_dirty_work(input_array + 0, input_array + 4, output_array + 0, output_array + 4, 0);
    }

    return 0;
}
