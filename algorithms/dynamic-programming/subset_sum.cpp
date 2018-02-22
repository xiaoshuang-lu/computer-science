// subset sum problem
// https://en.wikipedia.org/wiki/Subset_sum_problem

// let dp(i, s) donate whether there is a nonempty subset of x1, ..., xi which sums to s.
// dp(i, s) = dp(i - 1, s) || xi == s || dp(i - 1, s - xi)
// dp(1, s) = x1 == s

# include <cstdint>

intmax_t subset_sum(intmax_t * begin, intmax_t * end, intmax_t sum)
{
    intmax_t length = end - begin;
    intmax_t negative_sum = 0;
    intmax_t positive_sum = 0;

    for (intmax_t * p = begin; p != end; ++ p)
    {
        if (* p < 0)
        {
            negative_sum = negative_sum + * p;
        }
        else if (0 < * p)
        {
            positive_sum = positive_sum + * p;
        }
    }

    if (sum < negative_sum || positive_sum < sum)
    {
        return 0;
    }

    intmax_t ** array = new intmax_t *[length];

    for (intmax_t i = 0; i < length; ++ i)
    {
        array[i] = new intmax_t[positive_sum - negative_sum + 1];
    }

    intmax_t result = 0;

    for (intmax_t i = negative_sum; i < positive_sum + 1; ++ i)
    {
        if (begin[0] == i)
        {
            array[0][i - negative_sum] = 1;
        }
        else
        {
            array[0][i - negative_sum] = 0;
        }
    }

    for (intmax_t i = 1; i < length; ++ i)
    {
        for (intmax_t j = negative_sum; j < positive_sum + 1; ++ j)
        {
            if (array[i - 1][j - negative_sum] == 1 ||
                array[i - 1][j - begin[i] - negative_sum] == 1 ||
                begin[i] == j)
            {
                array[i][j - negative_sum] = 1;
            }
            else
            {
                array[i][j - negative_sum] = 0;
            }
        }
    }

    result = array[length - 1][sum - negative_sum];

    for (intmax_t i = 0; i < length; ++ i)
    {
        delete[] array[i];
    }

    delete[] array;

    return result;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[5] = {1, 2, 3, 4, 5};

        intmax_t result = subset_sum(array + 0, array + 5, 16);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
