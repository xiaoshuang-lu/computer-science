// $ sorted
// $ rotated
// $ no duplicates

# include <cstdint>

intmax_t binary_search(intmax_t * array, intmax_t begin, intmax_t end)
{
    intmax_t low = begin;
    intmax_t high = end - 1;

    while (low <= high)
    {
        intmax_t middle = (low + high) >> 1;

        // left: low + 0, low + 1, low + 2, ..., low + middle + 0
        // right: low + middle + 1, low + middle + 2, low + middle + 3, ..., high

        if (array[high] < array[middle])
        {
            low = middle + 1;
        }
        else
        {
            high = middle;
        }
    }

    return low;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {4, 5, 6, 7, 0, 1, 2, 3};

        intmax_t result;

        result = binary_search(array, 0, 8);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
