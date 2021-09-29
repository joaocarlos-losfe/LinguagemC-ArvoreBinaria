#ifndef _ABBNODE_H_
#define _ABBNODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode* BSTNode;

struct BSTNode
{
    int key;
    BSTNode left;
    BSTNode right;
};

BSTNode bstNodeCreate(int key);
BSTNode bstNodeDestroy(BSTNode node);
void bstNodePrint(BSTNode node);
bool bstNodeIsLeaf(BSTNode node);

#endif