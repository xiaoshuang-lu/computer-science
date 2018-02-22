# include <cstdint>

intmax_t binary_search(intmax_t * array, intmax_t begin, intmax_t end, intmax_t key)
{
    intmax_t low = begin;
    intmax_t high = end - 1;

    while (low <= high)
    {
        intmax_t middle = (low + high) >> 1;

        if (array[middle] < key)
        {
            low = middle + 1;
        }
        else if (key < array[middle])
        {
            high = middle - 1;
        }
        else
        {
            return middle;
        }
    }

    return 0 - low - 1;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {0, 0, 0, 0, 0, 0, 0, 0};

        intmax_t result;

        result = binary_search(array, 0, 8, 0);

        printf("%" PRIdMAX "\n", result);

        result = binary_search(array, 0, 8, 1);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
