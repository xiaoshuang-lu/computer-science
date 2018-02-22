# include <cstdint>

class list_node
{
    public:
        list_node * next;
        intmax_t data;
};

list_node * reverse(list_node * first, list_node * & last)
{
    last = first;

    list_node * prev = 0;
    list_node * curr = first;
    list_node * next;

    while (curr != 0)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        list_node list[8];

        list[0].next = list + 1;
        list[0].data = 0;

        list[1].next = list + 2;
        list[1].data = 1;

        list[2].next = list + 3;
        list[2].data = 2;

        list[3].next = list + 4;
        list[3].data = 3;

        list[4].next = list + 5;
        list[4].data = 4;

        list[5].next = list + 6;
        list[5].data = 5;

        list[6].next = list + 7;
        list[6].data = 6;

        list[7].next = 0;
        list[7].data = 7;

        list_node * first;
        list_node * last;

        first = reverse(list + 0, last);

        for (list_node * temporary = first; temporary != 0; temporary = temporary->next)
        {
            printf("%" PRIdMAX " ", temporary->data);
        }
        printf("\n");
    }

    return 0;
}
