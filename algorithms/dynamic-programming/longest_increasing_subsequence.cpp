// longest increasing subsequence problem
// https://en.wikipedia.org/wiki/Longest_increasing_subsequence

// let dp(i) donate the length of longest increasing subsequence of x1, ..., xi
// dp(i) =
// $. 1 if i == 1
// $. max{dp(j) + 1} if 0 <= j < i && array[j] < array[i]

# include <cstdint>

intmax_t longest_increasing_subsequence(intmax_t * begin, intmax_t * end)
{
    intmax_t length = end - begin;

    intmax_t * array = new intmax_t[length];

    array[0] = 1;

    for (intmax_t i = 1; i < length; ++ i)
    {
        // minimum value
        array[i] = 1;

        for (intmax_t j = 0; j < i; ++ j)
        {
            if (begin[j] < begin[i])
            {
                if (array[i] < array[j] + 1)
                {
                    array[i] = array[j] + 1;
                }
            }
        }
    }

    intmax_t result = array[length - 1];

    delete[] array;

    return result;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

        intmax_t result = longest_increasing_subsequence(array + 0, array + 16);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
