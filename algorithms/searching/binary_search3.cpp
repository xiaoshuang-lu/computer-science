// $ sorted
// $ rotated
// $ no duplicates

# include <cstdint>

intmax_t binary_search(intmax_t * array, intmax_t begin, intmax_t end, intmax_t key)
{
    intmax_t low = begin;
    intmax_t high = end - 1;

    while (low <= high)
    {
        intmax_t middle = (low + high) >> 1;

        if (array[middle] == key)
        {
            return middle;
        }
        else if (array[middle] < array[low])
        {
            if (array[middle] < key && key <= array[high])
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
        else if (array[high] < array[middle])
        {
            if (key < array[middle] && array[low] <= key)
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        else
        {
            if (key < array[middle])
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
    }

    return -1;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {4, 5, 6, 7, 0, 1, 2, 3};

        intmax_t result;

        result = binary_search(array, 0, 8, 7);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
