# include <cinttypes>
# include <cstdint>
# include <cstdio>

intmax_t do_dirty_work(intmax_t ** array, intmax_t row, intmax_t column, intmax_t i, intmax_t j, intmax_t ** flag)
{
    if (i < 0 || row <= i || j < 0 || column <= j)
    {
        return 0;
    }

    printf("%" PRIdMAX " ", array[i])
}

intmax_t depth_first_search(intmax_t ** array, intmax_t row, intmax_t column)
{
    intmax_t ** flag = new intmax_t[row];

    for (intmax_t i = 0; i < row; ++ i)
    {
        flag[i] = new intmax_t[column];
    }

    for (intmax_t i = 0; i < row; ++ i)
    {
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
                if (flag[i][j] == 0)
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

        do_dirty_work(array, i_, j_, flag);
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
    return 0;
}
