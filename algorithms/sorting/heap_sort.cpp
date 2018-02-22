# include <cstdint>

intmax_t up(intmax_t * begin, intmax_t * end, intmax_t index)
{
    intmax_t temporary = begin[index];
    intmax_t parent = (index - 1) >> 1;

    while (index > 0)
    {
        if (begin[parent] < temporary)
        {
            begin[index] = begin[parent];
            index = parent;
            parent = (index - 1) >> 1;
        }
        else
        {
            break;
        }
    }

    begin[index] = temporary;

    return 0;
}

intmax_t down(intmax_t * begin, intmax_t * end, intmax_t index)
{
    intmax_t length = end - begin;
    intmax_t temporary = begin[index];
    intmax_t child = (index << 1) + 1;

    while (child < length)
    {
        if (child < length - 1 && begin[child] < begin[child + 1])
        {
            ++ child;
        }

        if (temporary < begin[child])
        {
            begin[index] = begin[child];
            index = child;
            child = (index << 1) + 1;
        }
        else
        {
            break;
        }
    }

    begin[index] = temporary;

    return 0;
}

intmax_t heap_sort(intmax_t * begin, intmax_t * end)
{
    if (end - begin > 1)
    {
        intmax_t length = end - begin;
        intmax_t index = (length >> 1) - 1;

        while (index >= 0)
        {
            down(begin, end, index);
            -- index;
        }
    }

    while (end - begin > 1)
    {
        -- end;
        intmax_t temporary = * begin;
        * begin = * end;
        * end = temporary;
        down(begin, end, 0);
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        intmax_t array[] = {7, 6, 5, 4, 3, 2, 1, 0};

        heap_sort(array + 0, array + 8);

        for (intmax_t i = 0; i < 8; ++ i)
        {
            printf("%" PRIdMAX " ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
