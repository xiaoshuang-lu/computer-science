# include <cstdint>

# include <algorithm>
# include <list>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

intmax_t do_dirty_work(tree_node * root, std::list<intmax_t> & list)
{
    if (root != 0)
    {
        do_dirty_work(root->left, list);

        list.push_back(root->data);

        do_dirty_work(root->right, list);
    }

    return 0;
}

intmax_t is_binary_search_tree(tree_node * root)
{
    std::list<intmax_t> list;

    do_dirty_work(root, list);

    if (std::is_sorted(list.begin(), list.end()))
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

        intmax_t result = is_binary_search_tree(tree + 0);

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

        intmax_t result = is_binary_search_tree(tree + 0);

        printf("%" PRIdMAX "\n", result);
    }

    return 0;
}
