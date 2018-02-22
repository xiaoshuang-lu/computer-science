// longest common substring problem
// https://en.wikipedia.org/wiki/Longest_common_substring_problem

// let dp(i, j) donate the length of longest common suffix of x1, ..., xi and y1, ..., yj
// dp(i, j) =
// $. dp(i - 1, j - 1) + 1 if xi == yj
// $. 0

# include <cstdint>

intmax_t longest_common_substring(intmax_t * begin1, intmax_t * end1, intmax_t * begin2, intmax_t * end2)
{
    intmax_t length1 = end1 - begin1;
    intmax_t length2 = end2 - begin2;

    intmax_t ** array = new intmax_t *[length1 + 1];

    for (intmax_t i = 0; i < length1 + 1; ++ i)
    {
        array[i] = new intmax_t[length2 + 1];
    }

    for (intmax_t i = 0; i < length1 + 1; ++ i)
    {
        array[i][0] = 0;
    }

    for (intmax_t i = 0; i < length2 + 1; ++ i)
    {
        array[0][i] = 0;
    }

    for (intmax_t i = 1; i < length1 + 1; ++ i)
    {
        for (intmax_t j = 1; j < length2 + 1; ++ j)
        {
            if (begin1[i - 1] == begin2[j - 1])
            {
                array[i][j] = array[i - 1][j - 1] + 1;
            }
            else
            {
                array[i][j] = 0;
            }
        }
    }

    intmax_t maximum = array[0][0];

    for (intmax_t i = 0; i < length1 + 1; ++ i)
    {
        for (intmax_t j = 0; j < length2 + 1; ++ j)
        {
            if (maximum < array[i][j])
            {
                maximum = array[i][j];
            }
        }
    }

    for (intmax_t i = 0; i < length1 + 1; ++ i)
    {
        delete[] array[i];
    }
    delete[] array;

    return maximum;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array1[4] = {0, 1, 0, 1};
        intmax_t array2[4] = {1, 0, 1, 0};

        intmax_t result = longest_common_substring(array1 + 0, array1 + 4, array2 + 0, array2 + 4);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
