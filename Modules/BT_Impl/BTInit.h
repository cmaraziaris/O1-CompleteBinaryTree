#pragma once
#include "Init_ptr.h"

typedef struct tnode *BTNode;
typedef struct tnode 
{
	int priority;
	BTItem item;
	BTNode left;
	BTNode right;
	BTNode back;
	BTNode parent;
} BTNodes;

typedef struct main_tree
{
	int size;
	//int height;
	BTNode last;
	BTNode tree;
}maintree;
typedef struct main_tree* BTTree;

BTTree BTCreate (void);
int BTHeight(BTTree);
int BTSize(BTTree);
int BTIsEmpty(BTNode);
BTNode BTGetRoot(BTTree);
BTNode BTGetParent(BTTree,BTNode);
BTNode BTGetChildLeft(BTTree, BTNode);
BTNode BTGetChildRight(BTTree, BTNode);
int BTGetItem(BTNode,BTNode);
void BTInsertRoot(BTTree, BTItem);
void BTInsertLeft(BTTree,BTNode,BTItem);
void BTInsertRight(BTTree,BTNode,BTItem);
void BTRemoveLeaf(BTTree,BTNode);
void BTChange(BTNode, BTItem);
void BTPreOrder(BTTree,void (*visit) (BTNode));
void BTInOrder(BTTree,void (*visit) (BTNode));
void BTPostOrder(BTTree,void (*visit) (BTNode));
void BTLevelOrder(BTTree,void (*visit) (BTNode));
void BTDestroy (BTTree);
