// generate all combinations of well-formed brackets

# include <cstdint>
# include <cstdio>

intmax_t do_dirty_work(intmax_t * begin, intmax_t * end, intmax_t index, intmax_t left_count, intmax_t right_count)
{
    intmax_t length = end - begin;

    if (index == length)
    {
        for (intmax_t * temporary = begin; temporary != end; ++ temporary)
        {
            printf("%c", * temporary);
        }
        printf("\n");

        return 0;
    }

    if (left_count < (length >> 1))
    {
        begin[index] = '(';

        do_dirty_work(begin, end, index + 1, left_count + 1, right_count);
    }

    if (right_count < left_count)
    {
        begin[index] = ')';

        do_dirty_work(begin, end, index + 1, left_count, right_count + 1);
    }

    return 0;
}

intmax_t bracket(intmax_t n)
{
    intmax_t * array = new intmax_t[n << 1];

    do_dirty_work(array + 0, array + (n << 1), 0, 0, 0);

    delete[] array;

    return 0;
}

int main()
{
    bracket(4);

    return 0;
}
