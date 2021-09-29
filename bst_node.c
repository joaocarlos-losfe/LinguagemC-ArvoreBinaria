#include "bst_node.h"
#include "string.h"


BSTNode bstNodeCreate(int key) 
{
    BSTNode node = malloc(sizeof(struct BSTNode));

    node->key = key;

    node->left = NULL;
    node->right = NULL;

    return node;
}

BSTNode bstNodeDestroy(BSTNode node) 
{
    free(node);
    node = NULL;
    return node;
}

void bstNodePrint(BSTNode node) 
{
    printf("%d", node->key);
}

bool bstNodeIsLeaf(BSTNode node)
{   
    bool is_leaf = false;

    if (node->left == NULL && node->right == NULL)
    {
        is_leaf = true;
    }
    return is_leaf;
}