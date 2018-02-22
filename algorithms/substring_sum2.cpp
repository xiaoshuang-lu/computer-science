// find all substrings whose sum equals to n

# include <cinttypes>
# include <cstdint>
# include <cstdio>

# include <unordered_map>

intmax_t substring_sum(intmax_t * begin, intmax_t * end, intmax_t n)
{
    std::unordered_multimap<int, int> unordered_multimap;

    typedef std::unordered_multimap<int, int>::iterator iterator_type;

    intmax_t length = end - begin;

    intmax_t sum = 0;

    intmax_t count = 0;

    for (intmax_t i = 0; i < length; ++ i)
    {
        sum = sum + begin[i];

        if (sum == n)
        {
            printf("(%" PRIdMAX ", %" PRIdMAX "): ", 0, i + 1);
            for (intmax_t j = 0; j < i + 1; ++ j)
            {
                printf("%" PRIdMAX " ", begin[j]);
            }
            printf("\n");
        }

        std::pair<iterator_type, iterator_type> pair = unordered_multimap.equal_range(sum - n);

        for (iterator_type temporary = pair.first; temporary != pair.second; ++ temporary)
        {
            printf("(%" PRIdMAX ", %" PRIdMAX "): ", temporary->second + 1, i + 1);
            for (intmax_t j = temporary->second + 1; j < i + 1; ++ j)
            {
                printf("%" PRIdMAX " ", begin[j]);
            }
            printf("\n");
        }

        unordered_multimap.insert(std::pair<int, int>(sum, i));
    }

    return 0;
}

int main()
{
    {
        intmax_t array[3] = {1, 1, 1};

        substring_sum(array + 0, array + 3, 2);
    }

    {
        intmax_t array[5] = {-3, 1, 2, -3, 4};

        substring_sum(array + 0, array + 5, 0);
    }

    return 0;
}
