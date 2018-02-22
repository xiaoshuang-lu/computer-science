# include <cinttypes>
# include <cstdint>

# include <list>
# include <string>

intmax_t do_dirty_work
(
    intmax_t ** array,
    intmax_t row,
    intmax_t column,
    intmax_t target_i,
    intmax_t target_j,
    intmax_t current_i,
    intmax_t current_j,
    intmax_t ** flag,
    std::list<std::string> & list
)
{
    if (current_i < 0 || row <= current_i || current_j < 0 || column <= current_j)
    {
        return 0;
    }

    if (array[current_i][current_j] == 1)
    {
        return 0;
    }

    if (flag[current_i][current_j] == 1)
    {
        return 0;
    }

    flag[current_i][current_j] = 1;

    {
        char buffer[256];

        snprintf(buffer, 256, "(%" PRIdMAX ", %" PRIdMAX ")", current_i, current_j);

        std::string string(buffer);

        list.push_back(string);
    }

    if (current_i == target_i && current_j == target_j)
    {
        for (std::string & string : list)
        {
            printf("%s ", string.c_str());
        }
        printf("\n");

        flag[current_i][current_j] = 0;

        list.pop_back();

        return 0;
    }

    do_dirty_work(array, row, column, target_i, target_j, current_i - 1, current_j, flag, list);

    do_dirty_work(array, row, column, target_i, target_j, current_i + 1, current_j, flag, list);

    do_dirty_work(array, row, column, target_i, target_j, current_i, current_j - 1, flag, list);

    do_dirty_work(array, row, column, target_i, target_j, current_i, current_j + 1, flag, list);

    list.pop_back();

    flag[current_i][current_j] = 0;

    return 0;
}

intmax_t maze(intmax_t ** array, intmax_t row, intmax_t column)
{
    intmax_t ** flag = new intmax_t *[row];

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

    std::list<std::string> list;

    do_dirty_work(array, row, column, row - 1, column - 1, 0, 0, flag, list);

    for (intmax_t i = 0; i < row; ++ i)
    {
        delete[] flag[i];
    }

    delete[] flag;

    return 0;
}

int main()
{
    {
        intmax_t temporary[5][5] =
        {
            {0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 1},
            {0, 1, 1, 0, 0}
        };

        intmax_t ** array = new intmax_t *[5];

        for (intmax_t i = 0; i < 5; ++ i)
        {
            array[i] = & (temporary[i][0]);
        }

        for (intmax_t i = 0; i < 5; ++ i)
        {
            for (intmax_t j = 0; j < 5; ++ j)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }

        maze(array, 5, 5);

        delete[] array;
    }

    {
        intmax_t temporary[5][5] =
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };

        intmax_t ** array = new intmax_t *[5];

        for (intmax_t i = 0; i < 5; ++ i)
        {
            array[i] = & (temporary[i][0]);
        }

        for (intmax_t i = 0; i < 5; ++ i)
        {
            for (intmax_t j = 0; j < 5; ++ j)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }

        maze(array, 5, 5);

        delete[] array;
    }

    return 0;
}
