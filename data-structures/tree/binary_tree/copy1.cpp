# include <cstdint>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

tree_node * copy(tree_node * root)
{
    if (root == 0)
    {
        return 0;
    }

    tree_node * node = new tree_node();
    node->left = copy(root->left);
    node->right = copy(root->right);
    node->data = root->data;

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
        tree_node tree[7];

        tree[0].left = tree + 1;
        tree[0].right = tree + 2;
        tree[0].data = 0;

        tree[1].left = tree + 3;
        tree[1].right = tree + 4;
        tree[1].data = 1;

        tree[2].left = tree + 5;
        tree[2].right = tree + 6;
        tree[2].data = 1;

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

        show(tree);

        tree_node * root = copy(tree);

        show(root);

        cleanup(root);
    }

    return 0;
}
