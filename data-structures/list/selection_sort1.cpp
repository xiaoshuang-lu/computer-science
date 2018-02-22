# include <cstdint>

struct list_node
{
    public:
        list_node * next;
        intmax_t data;
};

list_node * selection_sort(list_node * list)
{
    if (list == 0 || list->next == 0)
    {
        return list;
    }

    list_node temporary;
    temporary.next = list;

    list_node * i = & temporary;

    while (i != 0)
    {
        list_node * j_prev = i;
        list_node * j = i->next;
        list_node * mininum_prev = i;
        list_node * minimum = i->next;

        while (j != 0)
        {
            if (j->data < minimum->data)
            {
                mininum_prev = j_prev;
                minimum = j;
            }

            j_prev = j_prev->next;
            j = j->next;
        }

        if (minimum != 0)
        {
            if (i != mininum_prev)
            {
                mininum_prev->next = minimum->next;
                minimum->next = i->next;
                i->next = minimum;
            }
        }

        i = i->next;
    }

    return temporary.next;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        list_node list[8];

        list[0].next = list + 1;
        list[0].data = 7;

        list[1].next = list + 2;
        list[1].data = 6;

        list[2].next = list + 3;
        list[2].data = 5;

        list[3].next = list + 4;
        list[3].data = 4;

        list[4].next = list + 5;
        list[4].data = 3;

        list[5].next = list + 6;
        list[5].data = 2;

        list[6].next = list + 7;
        list[6].data = 1;

        list[7].next = 0;
        list[7].data = 0;

        list_node * node = list;

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");

        node = selection_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    {
        list_node list[8];

        list[0].next = list + 1;
        list[0].data = 0;

        list[1].next = list + 2;
        list[1].data = 0;

        list[2].next = list + 3;
        list[2].data = 0;

        list[3].next = list + 4;
        list[3].data = 0;

        list[4].next = list + 5;
        list[4].data = 0;

        list[5].next = list + 6;
        list[5].data = 0;

        list[6].next = list + 7;
        list[6].data = 0;

        list[7].next = 0;
        list[7].data = 0;

        list_node * node = list;

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");

        node = selection_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    return 0;
}
