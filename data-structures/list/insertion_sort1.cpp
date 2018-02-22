# include <cstdint>

class list_node
{
    public:
        list_node * next;
        intmax_t data;
};

list_node * insertion_sort(list_node * list)
{
    if (list == 0 || list->next == 0)
    {
        return list;
    }

    list_node temporary;
    temporary.next = list;

    list_node * i_prev = temporary.next;
    list_node * i = temporary.next->next;

    while (i != 0)
    {
        list_node * j_prev = & temporary;
        list_node * j = temporary.next;

        while (j != i)
        {
            if (i->data < j->data)
            {
                break;
            }

            j_prev = j_prev->next;
            j = j->next;
        }

        if (j != i)
        {
            if (j->next != i)
            {
                j_prev->next = i;
                i_prev->next = i->next;
                i->next = j;
                i = i_prev->next;
            }
            else
            {
                j_prev->next = i;
                j->next = i->next;
                i->next = j;
                i_prev = j;
                i = j->next;
            }
        }
        else
        {
            i_prev = i_prev->next;
            i = i->next;
        }
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

        node = insertion_sort(node);

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

        node = insertion_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    return 0;
}
