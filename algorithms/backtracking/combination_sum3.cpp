// input may have duplicate elements
// output may have duplicate elements
// all numbers are positive

# include <cinttypes>
# include <cstdint>
# include <cstdio>

# include <list>

intmax_t do_dirty_work
(
    intmax_t * begin,
    intmax_t * end,
    intmax_t target,
    std::list<intmax_t> & list,
    int index,
    int current
)
{
    if (current == target)
    {
        for (intmax_t & item : list)
        {
            printf("%" PRIdMAX " ", item);
        }
        printf("\n");

        return 0;
    }

    for (intmax_t i = index; i < end - begin; ++ i)
    {
        list.push_back(begin[i]);

        do_dirty_work(begin, end, target, list, i, current + begin[i]);

        list.pop_back();
    }

    return 0;
}

intmax_t combination_sum(intmax_t * begin, intmax_t * end, intmax_t target)
{
    std::list<intmax_t> list;

    do_dirty_work(begin, end, target, list, 0, 0);

    return 0;
}

int main()
{
    {
        intmax_t array[4] = {2, 3, 6, 7};

        combination_sum(array + 0, array + 4, 7);
    }

    return 0;
}
