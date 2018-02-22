# include <cstdint>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

intmax_t is_binary_search_tree(tree_node * root, intmax_t minimum, intmax_t maximum)
{
    if (root == 0)
    {
        return 1;
    }

    if (root->data < minimum || maximum < root->data)
    {
        return 0;
    }

    intmax_t left = is_binary_search_tree(root->left, minimum, root->data);

    intmax_t right = is_binary_search_tree(root->right, root->data, maximum);

    if (left == 1 && right == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

# include <cinttypes>
# include <cstdio>

int main()
{
    {
        tree_node tree[7];

        tree[0].left = tree + 1;
        tree[0].right = tree + 2;
        tree[0].data = 3;

        tree[1].left = tree + 3;
        tree[1].right = tree + 4;
        tree[1].data = 1;

        tree[2].left = tree + 5;
        tree[2].right = tree + 6;
        tree[2].data = 5;

        tree[3].left = 0;
        tree[3].right = 0;
        tree[3].data = 0;

        tree[4].left = 0;
        tree[4].right = 0;
        tree[4].data = 2;

        tree[5].left = 0;
        tree[5].right = 0;
        tree[5].data = 4;

        tree[6].left = 0;
        tree[6].right = 0;
        tree[6].data = 6;

        intmax_t result = is_binary_search_tree(tree + 0, INTMAX_MIN, INTMAX_MAX);

        printf("%" PRIdMAX "\n", result);
    }

    {
        tree_node tree[7];

        tree[0].left = tree + 1;
        tree[0].right = tree + 2;
        tree[0].data = 3;

        tree[1].left = tree + 3;
        tree[1].right = tree + 4;
        tree[1].data = 1;

        tree[2].left = tree + 5;
        tree[2].right = tree + 6;
        tree[2].data = 5;

        tree[3].left = 0;
        tree[3].right = 0;
        tree[3].data = 0;

        tree[4].left = 0;
        tree[4].right = 0;
        tree[4].data = 2;

        tree[5].left = 0;
        tree[5].right = 0;
        tree[5].data = 6;

        tree[6].left = 0;
        tree[6].right = 0;
        tree[6].data = 4;

        intmax_t result = is_binary_search_tree(tree + 0, INTMAX_MIN, INTMAX_MAX);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
