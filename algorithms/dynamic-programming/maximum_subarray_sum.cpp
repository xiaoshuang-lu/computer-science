// let dp(i) donate the maximum sum of x1, ..., xi
// dp(i) =
// $. 0 if i == 0
// $. dp(i - 1) + array[i] if 0 < 1 && 0 < dp(i - 1)
// $. array[i]

# include <cstdint>

intmax_t maximum_subarray_sum(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    intmax_t * array = new intmax_t[length + 1];

    array[0] = 0;

    intmax_t maximum = 0;

    for (intmax_t i = 1; i < length + 1; ++ i)
    {
        if (0 < array[i - 1])
        {
            array[i] = array[i - 1] + begin[i - 1];
        }
        else
        {
            array[i] = begin[i - 1];
        }

        if (maximum < array[i])
        {
            maximum = array[i];
        }
    }

    delete[] array;

    return maximum;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {

    }

    return 0;
}
