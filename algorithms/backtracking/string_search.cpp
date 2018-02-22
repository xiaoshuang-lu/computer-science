// search strings in matrix

# include <cinttypes>
# include <cstdint>
# include <cstdio>

# include <list>
# include <string>

intmax_t do_dirty_work
(
    intmax_t ** array,
    intmax_t row,
    intmax_t column,
    intmax_t * begin,
    intmax_t * end,
    intmax_t ** flag,
    std::list<std::list<std::string>> & result,
    std::list<std::string> & list,
    intmax_t * count,
    intmax_t i,
    intmax_t j,
    intmax_t index
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

    if (index > end - begin - 1)
    {
        return 0;
    }

    if (array[i][j] != begin[index])
    {
        return 0;
    }

    flag[i][j] = 1;

    char buffer[256];

    snprintf(buffer, 256, "(%" PRIdMAX ", %" PRIdMAX ") ", i, j);

    list.push_back(std::string(buffer));

    if (index == end - begin - 1)
    {
        result.push_back(list);

        ++ (* count);
    }

    intmax_t temporary = * count;

    do_dirty_work(array, row, column, begin, end, flag, result, list, count, i - 1, j, index + 1);

//    if (temporary < * count)
//    {
//        // check existence only
//       return 0;
//    }

    do_dirty_work(array, row, column, begin, end, flag, result, list, count, i + 1, j, index + 1);

//    if (temporary < * count)
//    {
//        // check existence only
//        return 0;
//    }

    do_dirty_work(array, row, column, begin, end, flag, result, list, count, i, j - 1, index + 1);

//    if (temporary < * count)
//    {
//        // check existence only
//        return 0;
//    }

    do_dirty_work(array, row, column, begin, end, flag, result, list, count, i, j + 1, index + 1);

    list.pop_back();

    flag[i][j] = 0;

    return 0;
}

intmax_t string_search
(
    intmax_t ** array,
    intmax_t row,
    intmax_t column,
    intmax_t * begin,
    intmax_t * end,
    intmax_t i,
    intmax_t j
)
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

    std::list<std::list<std::string>> result;

    std::list<std::string> list;

    intmax_t count = 0;

    do_dirty_work(array, row, column, begin, end, flag, result, list, & count, i, j, 0);

    for (intmax_t i = 0; i < row; ++ i)
    {
        delete[] flag[i];
    }
    delete[] flag;

    return count;
}

int main()
{
    {
        intmax_t data[2][2] =
        {
            {'a', 'a'},
            {'a', 'b'}
        };

        intmax_t ** array = new intmax_t *[2];

        for (intmax_t i = 0; i < 2; ++ i)
        {
            array[i] = & data[i][0];
        }

        intmax_t string[] = {'b', 'a', 'a', 'a'};

        intmax_t result = string_search(array, 2, 2, string + 0, string + 4, 1, 1);

        printf("%" PRIdMAX "\n", result);

        delete[] array;
    }

    {
        intmax_t data[3][4] =
        {
            {'a', 'b', 'c', 'e'},
            {'s', 'f', 'c', 's'},
            {'a', 'd', 'e', 'f'}
        };

        intmax_t ** array = new intmax_t *[3];

        for (intmax_t i = 0; i < 3; ++ i)
        {
            array[i] = & data[i][0];
        }

        intmax_t string[] = {'a', 'b', 'c', 'c', 'e'};

        intmax_t result = string_search(array, 3, 4, string + 0, string + 5, 0, 0);

        printf("%" PRIdMAX "\n", result);

        delete[] array;
    }

    return 0;
}
