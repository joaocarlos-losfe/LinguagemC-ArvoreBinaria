#ifndef _ABB_H_
#define _ABB_H_

#include "bst_node.h"

typedef struct BST* BST;

struct BST
{
	BSTNode root_node; //raiz da arvore ou primeiro elemento

	unsigned int number_of_nodes; // n�mero de dados (n�s) inseridos
	unsigned int number_of_leafs; // numero de folhas
	
};


BST bstStart();
BSTNode bstInsert(BSTNode root_node, int key); //insere um nó a arvore
BSTNode bstSeach(BSTNode root_node, int key); // procura um elemento da arvore e retorna o seu nó
void bstPrint(BSTNode root_node); // exibe a arvore inteira
int bstCountNodes(BSTNode root_node); // conta o numero de nos da arvore
BSTNode bstSeachDad(BSTNode node, int key, BSTNode * dad); // procura um elemento da arvore para delecao
BSTNode bstDelete(BSTNode root_node, int key); // deleta um elemento da arvore
int bstCountSheets(BSTNode node); //conta o numero de folhas da aarvore
int bstHeight(BSTNode root_node); //altura da arvore
int bstDephNode(BSTNode node, int key); //busca a profudidadade dado um elemento
BSTNode bstDestroy(BSTNode root_node); // destruir a arvore inteira
void bstMinDepth(BSTNode root_node, int count, int *less_depth_result); // menor profundidade das folhas


#endif
