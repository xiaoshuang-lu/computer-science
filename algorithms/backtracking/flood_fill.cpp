# include <cstdint>

intmax_t do_dirty_work
(
    intmax_t ** array,
    intmax_t row,
    intmax_t column,
    intmax_t i,
    intmax_t j,
    intmax_t old_data,
    intmax_t new_data,
    intmax_t ** flag
)
{
    if (i < 0 || row <= i || j < 0 || column <= j)
    {
        return 0;
    }

    if (flag[i][j] == 1)
    {
        return 0;
    }

    flag[i][j] = 1;

    if (array[i][j] != old_data)
    {
        return 0;
    }

    array[i][j] = new_data;

    do_dirty_work(array, row, column, i + 1, j, old_data, new_data, flag);

    do_dirty_work(array, row, column, i, j + 1, old_data, new_data, flag);

    do_dirty_work(array, row, column, i - 1, j, old_data, new_data, flag);

    do_dirty_work(array, row, column, i, j - 1, old_data, new_data, flag);

    return 0;
}

intmax_t flood_fill(intmax_t ** array, intmax_t row, intmax_t column, intmax_t old_data, intmax_t new_data)
{
    intmax_t ** flag = new intmax_t *[row];

    for (intmax_t i = 0; i < row; ++ i)
    {
        flag[i] = new intmax_t[column];

        for (intmax_t j = 0; j < column; ++ j)
        {
            flag[i][j] = 0;
        }
    }

    while (true)
    {
        intmax_t i_ = -1;
        intmax_t j_ = -1;

        for (intmax_t i = 0; i < row; ++ i)
        {
            for (intmax_t j = 0; j < column; ++ j)
            {
                if (array[i][j] == old_data && flag[i][j] == 0)
                {
                    i_ = i;
                    j_ = j;
                }
            }
        }

        if (i_ == -1 || j_ == -1)
        {
            break;
        }

        do_dirty_work(array, row, column, i_, j_, old_data, new_data, flag);
    }

    for (intmax_t i = 0; i < row; ++ i)
    {
        delete[] flag[i];
    }
    delete[] flag;

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t temporary[8][8] = {{0}};

        intmax_t * array[8];

        for (intmax_t i = 0; i < 8; ++ i)
        {
            array[i] = & (temporary[i][0]);
        }

        array[2][2] = 1;
        array[2][3] = 1;
        array[2][4] = 1;
        array[2][5] = 1;
        array[2][2] = 1;
        array[3][2] = 1;
        array[3][5] = 1;
        array[4][2] = 1;
        array[4][5] = 1;
        array[5][2] = 1;
        array[5][3] = 1;
        array[5][4] = 1;
        array[5][5] = 1;

        for (intmax_t i = 0; i < 8; ++ i)
        {
            for (intmax_t j = 0; j < 8; ++ j)
            {
                printf("%" PRIdMAX " ", array[i][j]);
            }
            printf("\n");
        }

        flood_fill(array, 8, 8, 0, 8);

        for (intmax_t i = 0; i < 8; ++ i)
        {
            for (intmax_t j = 0; j < 8; ++ j)
            {
                printf("%" PRIdMAX " ", array[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
