// add two lists

# include <cstdint>

class list_node
{
    public:
        list_node * next;
        intmax_t data;
};

list_node * do_add(list_node * list1, list_node * list2, intmax_t & carry)
{
    if (list1 == 0 || list2 == 0)
    {
        carry = 0;

        return 0;
    }

    intmax_t temporary;

    list_node * node = new list_node();
    node->next = do_add(list1->next, list2->next, temporary);
    node->data = list1->data + list2->data + temporary;

    if (9 < node->data)
    {
        node->data = node->data - 10;
        carry = 1;
    }
    else
    {
        carry = 0;
    }

    return node;
}

list_node * add(list_node * list1, list_node * list2)
{
    intmax_t length1 = 0;

    {
        list_node * node = list1;

        while (node != 0)
        {
            ++ length1;
            node = node->next;
        }
    }

    intmax_t length2 = 0;

    {
        list_node * node = list2;

        while (node != 0)
        {
            ++ length2;

            node = node->next;
        }
    }

    if (length1 < length2)
    {
        // pad list 1

        for (intmax_t i = 0; i < length2 - length1; ++ i)
        {
            list_node * node = new list_node();
            node->next = list1;
            node->data = 0;

            list1 = node;
        }
    }
    else if (length2 < length1)
    {
        // pad list2

        for (intmax_t i = 0; i < length1 - length2; ++ i)
        {
            list_node * node = new list_node();
            node->next = list2;
            node->data = 0;

            list2 = node;
        }
    }

    intmax_t carry;

    list_node * node = do_add(list1, list2, carry);

    if (carry == 1)
    {
        list_node * temporary = new list_node();
        temporary->next = node;
        temporary->data = 1;
        node = temporary;
    }

    return node;
}

intmax_t cleanup(list_node * list)
{
    if (list != 0)
    {
        cleanup(list->next);
        delete list;
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    list_node list1[4];

    {
        list1[0].next = list1 + 1;
        list1[0].data = 1;

        list1[1].next = list1 + 2;
        list1[1].data = 2;

        list1[2].next = list1 + 3;
        list1[2].data = 3;

        list1[3].next = 0;
        list1[3].data = 4;
    }

    list_node list2[3];

    {
        list2[0].next = list2 + 1;
        list2[0].data = 5;

        list2[1].next = list2 + 2;
        list2[1].data = 6;

        list2[2].next = 0;
        list2[2].data = 7;
    }

    {
        list_node * node = add(list1 + 0, list2 + 0);

        while (node != 0)
        {
            printf("%" PRIdMAX "", node->data);

            node = node->next;
        }
        printf("\n");
    }

    return 0;
}
