# include <cstdint>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

tree_node * create_tree
(
    intmax_t * inorder_begin,
    intmax_t * inorder_end,
    intmax_t * preorder_begin,
    intmax_t * preorder_end
)
{
    if (inorder_begin == inorder_end || preorder_begin == preorder_end)
    {
        return 0;
    }

    intmax_t root = * preorder_begin;

    intmax_t size = 0;

    while (inorder_begin + size != inorder_end)
    {
        if (inorder_begin[size] == root)
        {
            break;
        }

        ++ size;
    }

    tree_node * node = new tree_node();
    node->left = create_tree(inorder_begin, inorder_begin + size, preorder_begin + 1, preorder_begin + size + 1);
    node->right = create_tree(inorder_begin + size + 1, inorder_end, preorder_begin + size + 1, preorder_end);
    node->data = root;

    return node;
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

int main()
{
    {
        intmax_t inorder_array[7] = {3, 1, 4, 0, 5, 2, 6};
        intmax_t preorder_array[7] = {0, 1, 3, 4, 2, 5, 6};

        tree_node * root = create_tree(inorder_array + 0, inorder_array + 7, preorder_array + 0, preorder_array + 7);

        show(root);

        cleanup(root);
    }

    return 0;
}
