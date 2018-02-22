// sorted list to binary search tree

# include <cstdint>

class list_node
{
    public:
        list_node * next;
        intmax_t data;
};

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

tree_node * list_to_tree(list_node * begin, list_node * end)
{
    if (begin == end)
    {
        return 0;
    }

    if (begin->next == end) {
        tree_node * root = new tree_node();
        root->left = 0;
        root->right = 0;
        root->data = begin->data;

        return root;
    }

    list_node * slow = begin->next;
    list_node * fast = begin->next->next;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    tree_node * root = new tree_node();
    root->left = list_to_tree(begin, slow);
    root->right = list_to_tree(slow->next, end);
    root->data = slow->data;

    return root;
}

# include <cinttypes>
# include <cstdio>

intmax_t preorder(tree_node * root)
{
    if (root != 0)
    {
        printf("%" PRIdMAX " ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

    return 0;
}

intmax_t inorder(tree_node * root)
{
    if (root != 0)
    {
        inorder(root->left);
        printf("%" PRIdMAX " ", root->data);
        inorder(root->right);
    }

    return 0;
}

intmax_t postorder(tree_node * root)
{
    if (root != 0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%" PRIdMAX " ", root->data);
    }

    return 0;
}

intmax_t show(tree_node * root)
{
    if (root != 0)
    {
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }

    return 0;
}

intmax_t cleanup(tree_node * root)
{
    if (root != 0)
    {
        cleanup(root->left);
        cleanup(root->right);
        delete root;
    }

    return 0;
}

# include <cstdio>

int main()
{
    {
        list_node node[7];

        node[0].next = node + 1;
        node[0].data = 0;

        node[1].next = node + 2;
        node[1].data = 1;

        node[2].next = node + 3;
        node[2].data = 2;

        node[3].next = node + 4;
        node[3].data = 3;

        node[4].next = node + 5;
        node[4].data = 4;

        node[5].next = node + 6;
        node[5].data = 5;

        node[6].next = 0;
        node[6].data = 6;

        tree_node * root = list_to_tree(node + 0, 0);

        show(root);

        cleanup(root);
    }

    return 0;
}
