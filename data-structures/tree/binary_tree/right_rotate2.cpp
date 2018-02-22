# include <cstdint>

class tree_node
{
    public:
        tree_node * parent;
        tree_node * left;
        tree_node * right;
        intmax_t data;
};

intmax_t right_rotate(tree_node * tree, tree_node * node)
{
    tree_node * parent = node->parent;
    tree_node * left = node->left;

    node->left = left->right;
    if (node->left != 0)
    {
        node->left->parent = node;
    }
    node->parent = left;
    left->right = node;
    left->parent = parent;

    if (parent == tree)
    {
        tree->parent = left;
    }
    else if (node == parent->left)
    {
        parent->left = left;
    }
    else if (node == parent->right)
    {
        parent->right = left;
    }

    return 0;
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

int main()
{
    tree_node root;
    tree_node array[7];

    {
        array[0].parent = & root;
        array[0].left = array + 1;
        array[0].right = array + 2;
        array[0].data = 0;

        array[1].parent = array + 0;
        array[1].left = array + 3;
        array[1].right = array + 4;
        array[1].data = 1;

        array[2].parent = array + 0;
        array[2].left = array + 5;
        array[2].right = array + 6;
        array[2].data = 2;

        array[3].parent = array + 1;
        array[3].left = 0;
        array[3].right = 0;
        array[3].data = 3;

        array[4].parent = array + 1;
        array[4].left = 0;
        array[4].right = 0;
        array[4].data = 4;

        array[5].parent = array + 2;
        array[5].left = 0;
        array[5].right = 0;
        array[5].data = 5;

        array[6].parent = array + 2;
        array[6].left = 0;
        array[6].right = 0;
        array[6].data = 6;

        root.parent = array + 0;
        root.left = 0;
        root.right = 0;
    }

    show(root.parent);

    {
        tree_node * current = root.parent;

        while (current->right != 0)
        {
            while (current->left != 0)
            {
                right_rotate(& root, current);
                current = current->parent;
            }

            current = current->right;
        }
    }

    show(root.parent);

    return 0;
}
