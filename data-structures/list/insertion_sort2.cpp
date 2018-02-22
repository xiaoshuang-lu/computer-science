# include <cstdint>

class list_node
{
    public:
        list_node * prev;
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
    list->prev = & temporary;

    list_node * i = temporary.next->next;

    while (i != 0)
    {
        list_node * j = temporary.next;

        while (j != i)
        {
            if (i->data < j->data)
            {
                break;
            }

            j = j->next;
        }

        if (j != i)
        {
            if (j->next != i)
            {
                list_node * node = i->next;

                i->prev->next = i->next;

                if (i->next != 0)
                {
                    i->next->prev = i->prev;
                }

                i->prev = j->prev;
                i->next = j;

                j->prev->next = i;

                j->prev = i;

                i = node;
            }
            else
            {
                j->next = i->next;

                if (i->next != 0)
                {
                    i->next->prev = j;
                }

                i->prev = j->prev;
                i->next = j;

                j->prev->next = i;

                j->prev = i;

                i = j->next;
            }
        }
        else
        {
            i = i->next;
        }
    }

    temporary.next->prev = 0;

    return temporary.next;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        list_node list[8];

        list[0].prev = 0;
        list[0].next = list + 1;
        list[0].data = 7;

        list[1].prev = list + 0;
        list[1].next = list + 2;
        list[1].data = 6;

        list[2].prev = list + 1;
        list[2].next = list + 3;
        list[2].data = 5;

        list[3].prev = list + 2;
        list[3].next = list + 4;
        list[3].data = 4;

        list[4].prev = list + 3;
        list[4].next = list + 5;
        list[4].data = 3;

        list[5].prev = list + 4;
        list[5].next = list + 6;
        list[5].data = 2;

        list[6].prev = list + 5;
        list[6].next = list + 7;
        list[6].data = 1;

        list[7].prev = list + 6;
        list[7].next = 0;
        list[7].data = 0;

        list_node * node = list;

        {
            for (list_node * i = node; i != 0; i = i->next)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        {
            list_node * temporary = node;

            while (temporary->next != 0)
            {
                temporary = temporary->next;
            }

            for (list_node * i = temporary; i != 0; i = i->prev)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        node = insertion_sort(node);

        {
            for (list_node * i = node; i != 0; i = i->next)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        {
            list_node * temporary = node;

            while (temporary->next != 0)
            {
                temporary = temporary->next;
            }

            for (list_node * i = temporary; i != 0; i = i->prev)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }
    }

    {
        list_node list[8];

        list[0].prev = 0;
        list[0].next = list + 1;
        list[0].data = 0;

        list[1].prev = list + 0;
        list[1].next = list + 2;
        list[1].data = 0;

        list[2].prev = list + 1;
        list[2].next = list + 3;
        list[2].data = 0;

        list[3].prev = list + 2;
        list[3].next = list + 4;
        list[3].data = 0;

        list[4].prev = list + 3;
        list[4].next = list + 5;
        list[4].data = 0;

        list[5].prev = list + 4;
        list[5].next = list + 6;
        list[5].data = 0;

        list[6].prev = list + 5;
        list[6].next = list + 7;
        list[6].data = 0;

        list[7].prev = list + 6;
        list[7].next = 0;
        list[7].data = 0;

        list_node * node = list;

        {
            for (list_node * i = node; i != 0; i = i->next)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        {
            list_node * temporary = node;

            while (temporary->next != 0)
            {
                temporary = temporary->next;
            }

            for (list_node * i = temporary; i != 0; i = i->prev)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        node = insertion_sort(node);

        {
            for (list_node * i = node; i != 0; i = i->next)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }

        {
            list_node * temporary = node;

            while (temporary->next != 0)
            {
                temporary = temporary->next;
            }

            for (list_node * i = temporary; i != 0; i = i->prev)
            {
                printf("%" PRIdMAX " ", i->data);
            }
            printf("\n");
        }
    }

    return 0;
}
