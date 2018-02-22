# include <cstdint>

# include <list>
# include <queue>
# include <vector>

class tuple
{
    public:
        intmax_t data;
        std::list<intmax_t> * list;
};

class comparator
{
    public:
        bool operator() (tuple const & tuple1, tuple const & tuple2)
        {
            return tuple2.data < tuple1.data;
        }
};

intmax_t multiway_merge_sort(std::list<std::list<intmax_t>> * list, std::list<intmax_t> * result)
{
    std::priority_queue<tuple, std::vector<tuple>, comparator> priority_queue;

    for (std::list<intmax_t> & item : * list)
    {
        tuple temporary;

        temporary.list = & item;
        temporary.data = item.front();
        item.pop_front();

        priority_queue.push(temporary);
    }

    while (! priority_queue.empty())
    {
        tuple temporary = priority_queue.top();

        priority_queue.pop();

        result->push_back(temporary.data);

        if (! temporary.list->empty())
        {
            tuple tuple;

            tuple.list = temporary.list;
            tuple.data = temporary.list->front();
            temporary.list->pop_front();

            priority_queue.push(tuple);
        }
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        std::list<std::list<intmax_t>> list =
        {
            {0, 4, 8, 12},

            {1, 5, 9, 13},

            {2, 6, 10, 14},

            {3, 7, 11, 15}
        };

        std::list<intmax_t> result;

        multiway_merge_sort(& list, & result);

        for (intmax_t & item : result)
        {
            printf("%" PRIdMAX " ", item);
        }
        printf("\n");
    }

    return 0;
}
