# include <cstdint>

intmax_t matrix_rotate(intmax_t ** matrix, intmax_t dimension)
{
    intmax_t half = dimension >> 1;

    for (intmax_t lap = 0; lap < half; ++ lap)
    {
        for (intmax_t i = lap; i < dimension - 1 - lap; ++ i)
        {
            intmax_t temporary = matrix[lap][i];
            matrix[lap][i] = matrix[dimension - 1 - i][lap];
            matrix[dimension - 1 - i][lap] = matrix[dimension - 1 - lap][dimension - 1 - i];
            matrix[dimension - 1 - lap][dimension - 1 - i] = matrix[i][dimension - 1 - lap];
            matrix[i][dimension - 1 - lap] = temporary;
        }
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    intmax_t matrix[4][4] =
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };

    for (intmax_t i = 0; i < 4; ++ i)
    {
        for (intmax_t j = 0; j < 4; ++ j)
        {
            printf("%02" PRIdMAX " ", matrix[i][j]);
        }
        printf("\n");
    }

    {
        intmax_t ** temporary = new intmax_t *[4];

        for (intmax_t i = 0; i < 4; ++ i)
        {
            temporary[i] = matrix[i];
        }

        matrix_rotate(temporary, 4);

        delete[] temporary;
    }

    printf("\n");

    for (intmax_t i = 0; i < 4; ++ i)
    {
        for (intmax_t j = 0; j < 4; ++ j)
        {
            printf("%02" PRIdMAX " ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
