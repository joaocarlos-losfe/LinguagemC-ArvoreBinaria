#include "bst.h"

BST bstStart()
{
	BST abb = malloc(sizeof(struct BST));

	abb->root_node = NULL;
	abb->number_of_nodes = 0;
	abb->number_of_leafs = 0;

	return abb;
}


BSTNode bstInsert(BSTNode root_node, int key)
{
	if (root_node == NULL)
	{
		BSTNode node;
		node = bstNodeCreate(key);
		
		return node;
	}
	else
	{
		if (key < root_node->key)
		{
			root_node->left = bstInsert(root_node->left, key);
		}
		else if(key > root_node->key)
		{
			root_node->right = bstInsert(root_node->right, key);
		}
	}

	return root_node;
}

BSTNode bstSeach(BSTNode root_node, int key)
{
	if (root_node == NULL)
		return NULL;
	if (root_node->key == key)
		return root_node;

	if(root_node->key > key)
		return bstSeach(root_node->left, key); //esquerda
	
	return bstSeach(root_node->right, key); 
}


//conta ate achar a raiz null e soma. tanto na esquerda quanto na direita
int bstCountNodes(BSTNode root_node)
{
	if (root_node == NULL)
		return 0;
	else
	{
		return bstCountNodes(root_node->left) + 1 + bstCountNodes(root_node->right);
	}
}

void bstPrint(BSTNode root_node)
{
	if (root_node != NULL)
	{
		printf("(");
		bstNodePrint(root_node);
		bstPrint(root_node->left);
		bstPrint(root_node->right);
		printf(")");
	}
}

BSTNode bstSeachDad(BSTNode node, int key, BSTNode * dad)
{
	BSTNode current = node;
	*dad = NULL;

	while (current)
	{
		if(current->key == key)
			return current;

		*dad = current;

		if(key < current->key)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}

BSTNode bstDelete(BSTNode root_node, int key)
{
	BSTNode dad, node, node1, node2;
	node = bstSeachDad(root_node, key, &dad);

	if (node == NULL)
		return (root_node);

	if(!node->left || !node->right)
	{
		if(!node->left)
			node2 = node->right; //direita
		else
			node2 = node->left;  // esquerda
	}
	else
	{
		node1 = node;
		node2 = node->left;

		while (node2->right)
		{
			node1 = node2;
			node2 = node2->right;
		}

		if (node1 != node)
		{
			node1->right = node2->left;
			node2->left = node->left;
		}

		node2->right = node->right;
	}

	if(!dad)
	{
		free(node);
		return (node2);
	}

	if(key < dad->key)
		dad->left = node2;
	else
		dad->right = node2;

	free(node);
	return (root_node);
}

int bstCountSheets(BSTNode node)
{
	if(node != NULL)
	{
		if(bstNodeIsLeaf(node))
			return 1 + bstCountSheets(node->left) + bstCountSheets(node->right);
		else
		{
			return bstCountSheets(node->left) + bstCountSheets(node->right);
		}
	}
	else
	{
		return 0;
	}
}

int bstHeight(BSTNode root_node)
{
	if (root_node == NULL)
		return - 1;
	else
	{
		int HLeft = bstHeight(root_node->left);
		int HRight = bstHeight(root_node->right);

		if(HLeft < HRight)
			return HRight + 1;
		else
			return HLeft + 1;
	}
}

int bstDephNode(BSTNode root_node, int key)
{
	BSTNode current = root_node;

	bool achou = false;
	int count = 0;

	while (current && !achou )
	{
		if(current->key == key)
			achou = true;
			
		if(key < current->key)
		{
			count++;
			current = current->left;
		}
		else
		{
			count++;
			current = current->right;
		}
	}

	return count;
}

BSTNode bstDestroy(BSTNode root_node)
{
	if (root_node != NULL)
	{
		root_node->left = bstDestroy(root_node->left);
		root_node->right = bstDestroy(root_node->right);
		free(root_node);
		root_node = NULL;
	}

	return root_node;	
}

void bstMinDepth(BSTNode root_node, int count, int *less_depth_result)
{
	if (root_node != NULL)
	{
		if(bstNodeIsLeaf(root_node))
		{
			if (count < *less_depth_result)
				*less_depth_result = count;	
		}
		else
			count++;
		
		bstMinDepth(root_node->left, count,  less_depth_result);
		bstMinDepth(root_node->right, count, less_depth_result);
	}	
}

