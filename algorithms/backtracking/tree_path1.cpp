# include <cstdint>

# include <list>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

intmax_t do_dirty_work(tree_node * root, std::list<std::list<intmax_t>> & result, std::list<intmax_t> & list)
{
    if (root == 0)
    {
        return 0;
    }

    list.push_back(root->data);

    if (root->left == 0 && root->right == 0)
    {
        result.push_back(list);
    }

    do_dirty_work(root->left, result, list);

    do_dirty_work(root->right, result, list);

    list.pop_back();

    return 0;
}

intmax_t path(tree_node * root, std::list<std::list<intmax_t>> & result)
{
    std::list<intmax_t> list;

    do_dirty_work(root, result, list);

    return 0;
}

# include <cinttypes>
# include <cstdio>

int main()
{
    tree_node tree[7];

    tree[0].left = tree + 1;
    tree[0].right = tree + 2;
    tree[0].data = 0;

    tree[1].left = tree + 3;
    tree[1].right = tree + 4;
    tree[1].data = 1;

    tree[2].left = tree + 5;
    tree[2].right = tree + 6;
    tree[2].data = 2;

    tree[3].left = 0;
    tree[3].right = 0;
    tree[3].data = 3;

    tree[4].left = 0;
    tree[4].right = 0;
    tree[4].data = 4;

    tree[5].left = 0;
    tree[5].right = 0;
    tree[5].data = 5;

    tree[6].left = 0;
    tree[6].right = 0;
    tree[6].data = 6;

    std::list<std::list<intmax_t>> result;

    path(tree, result);

    for (std::list<intmax_t> & list : result)
    {
        for (intmax_t & data : list)
        {
            printf("%" PRIdMAX " ", data);
        }

        if (! list.empty())
        {
            printf("\n");
        }
    }

    return 0;
}
