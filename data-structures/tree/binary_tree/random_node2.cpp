# include <cstdint>
# include <cstdlib>

class tree_node
{
    public:
        tree_node * left;
        tree_node * right;
        intmax_t data;
        // left size + 1 + right + size
        intmax_t size;
};

intmax_t handle(tree_node * tree)
{
    if (tree != 0)
    {
        tree->size = 1;

        if (tree->left != 0)
        {
            handle(tree->left);

            tree->size = tree->size + tree->left->size;
        }

        if (tree->right != 0)
        {
            handle(tree->right);

            tree->size = tree->size + tree->right->size;
        }
    }

    return 0;
}

tree_node * random_node(tree_node * tree)
{
    if (tree != 0)
    {
        intmax_t left = tree->left != 0 ? tree->left->size : 0;

        intmax_t temporary = rand() % tree->size;

        if (temporary < left)
        {
            return random_node(tree->left);
        }
        else if (left < temporary)
        {
            return random_node(tree->right);
        }
        else
        {
            return tree;
        }
    }

    return 0;
}

# include <cinttypes>
# include <cstdio>

intmax_t preorder(tree_node * tree)
{
    if (tree != 0)
    {
        printf("(%" PRIdMAX ", %" PRIdMAX ") ", tree->data, tree->size);
        preorder(tree->left);
        preorder(tree->right);
    }

    return 0;
}

intmax_t inorder(tree_node * tree)
{
    if (tree != 0)
    {
        inorder(tree->left);
        printf("(%" PRIdMAX ", %" PRIdMAX ") ", tree->data, tree->size);
        inorder(tree->right);
    }

    return 0;
}

intmax_t postorder(tree_node * tree)
{
    if (tree != 0)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("(%" PRIdMAX ", %" PRIdMAX ") ", tree->data, tree->size);
    }

    return 0;
}

intmax_t show(tree_node * tree)
{
    if (tree != 0)
    {
        preorder(tree);
        printf("\n");
        inorder(tree);
        printf("\n");
        postorder(tree);
        printf("\n");
    }

    return 0;
}

# include <ctime>

int main()
{
    srand(time(0));

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

        {
            handle(tree);

            show(tree);
        }

        for (intmax_t i = 0; i < 8; ++ i)
        {
            tree_node * node = random_node(tree);

            printf("%" PRIdMAX "\n", node->data);
        }
    }

    return 0;
}
