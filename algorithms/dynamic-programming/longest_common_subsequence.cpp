// longest common subsequence problem
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

// let dp(i, j) donate the length of longest common subsequence of x1, ..., xi and y1, ..., yj
// dp(i, j) =
// $. 0 if i == 0 || j == 0
// $. dp(i - 1, j - 1) + 1 if 0 < i && 0 < j && xi == yj
// $. max{dp(i, j - 1), dp(i - 1, j)} if 0 < i && 0 < j && xi != yj

# include <cstdint>

intmax_t longest_common_subsequence(intmax_t * begin1, intmax_t * end1, intmax_t * begin2, intmax_t * end2)
{
    intmax_t length1 = end1 - begin1;

    intmax_t length2 = end2 - begin2;

    intmax_t maximum = 0;

    intmax_t ** array = new intmax_t *[length1 + 1];

    for (intmax_t i = 0; i <= length1; ++ i)
    {
        array[i] = new intmax_t[length2 + 1];
    }

    for (intmax_t i = 0; i <= length1; ++ i)
    {
        array[i][0] = 0;
    }

    for (intmax_t i = 0; i <= length2; ++ i)
    {
        array[0][i] = 0;
    }

    for (intmax_t i = 0; i < length1; ++ i)
    {
        for (intmax_t j = 0; j < length2; ++ j)
        {
            if (begin1[i] == begin2[j])
            {
                array[i + 1][j + 1] = array[i][j] + 1;
            }
            else
            {
                array[i + 1][j + 1] = array[i + 1][j] < array[i][j + 1] ? array[i][j + 1] : array[i + 1][j];
            }

            if (maximum < array[i + 1][j + 1])
            {
                maximum = array[i + 1][j + 1];
            }
        }
    }

    return maximum;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array1[7] = {0, 1, 2, 1, 3, 0, 1};
        intmax_t array2[6] = {1, 3, 2, 0, 1, 0};

        intmax_t result = longest_common_subsequence(array1 + 0, array1 + 7, array2 + 0, array2 + 6);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
