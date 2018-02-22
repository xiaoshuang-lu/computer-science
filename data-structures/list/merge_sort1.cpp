# include <cstdint>

struct list_node
{
    public:
        list_node * next;
        intmax_t data;
};

list_node * merge(list_node * list1, list_node * list2, list_node * list)
{
    while (list1 != 0 && list2 != 0)
    {
        if (! (list2->data < list1->data))
        {
            list_node * next = list1->next;

            list1->next = 0;

            list->next = list1;

            list = list1;

            list1 = next;
        }
        else
        {
            list_node * next = list2->next;

            list2->next = 0;

            list->next = list2;

            list = list2;

            list2 = next;
        }
    }

    while (list1 != 0)
    {
        list_node * next = list1->next;

        list1->next = 0;

        list->next = list1;

        list = list1;

        list1 = next;
    }

    while (list2 != 0)
    {
        list_node * next = list2->next;

        list2->next = 0;

        list->next = list2;

        list = list2;

        list2 = next;
    }

    return list;
}

list_node * merge_sort(list_node * list)
{
    if (list == 0 || list->next == 0)
    {
        return list;
    }

    list_node temporary;
    temporary.next = list;

    intmax_t length = 0;

    {
        for (list_node * i = list; i != 0; i = i->next)
        {
            ++ length;
        }
    }

    intmax_t step = 1;

    while (step < length)
    {
        list_node node;
        node.next = 0;

        list_node * prev = & node;

        while (true)
        {
            list_node * begin_prev = & temporary;

            list_node * begin = temporary.next;

            list_node * middle_prev = begin_prev;

            list_node * middle = begin;

            intmax_t left_count = 0;

            while (middle != 0)
            {
                if (left_count == step)
                {
                    break;
                }

                ++ left_count;

                middle_prev = middle;
                middle = middle->next;
            }

            if (left_count == step && middle != 0)
            {
                list_node * end_prev = middle_prev;

                list_node * end = middle;

                intmax_t right_count = 0;

                while (end != 0)
                {
                    if (right_count == step)
                    {
                        break;
                    }

                    ++ right_count;

                    end_prev = end;
                    end = end->next;
                }

                begin_prev->next = end;

                middle_prev->next = 0;

                end_prev->next = 0;

                prev = merge(begin, middle, prev);
            }
            else
            {
                prev->next = temporary.next;

                temporary.next = node.next;

                break;
            }
        }

        step = step << 1;
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

        node = merge_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    {
        list_node list[9];

        list[0].next = list + 1;
        list[0].data = 8;

        list[1].next = list + 2;
        list[1].data = 7;

        list[2].next = list + 3;
        list[2].data = 6;

        list[3].next = list + 4;
        list[3].data = 5;

        list[4].next = list + 5;
        list[4].data = 4;

        list[5].next = list + 6;
        list[5].data = 3;

        list[6].next = list + 7;
        list[6].data = 2;

        list[7].next = list + 8;
        list[7].data = 1;

        list[8].next = 0;
        list[8].data = 0;

        list_node * node = list;

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");

        node = merge_sort(node);

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

        node = merge_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    {
        list_node list[9];

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

        list[7].next = list + 8;
        list[7].data = 0;

        list[8].next = 0;
        list[8].data = 0;

        list_node * node = list;

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");

        node = merge_sort(node);

        for (list_node * i = node; i != 0; i = i->next)
        {
            printf("%" PRIdMAX " ", i->data);
        }
        printf("\n");
    }

    return 0;
}
