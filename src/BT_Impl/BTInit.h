#pragma once

#include "Init_ptr.h"

/*===================================||	S T R U C T S ||===================================*/

typedef struct tnode *BTNode;	/* Our nodes are called BTNodes */
typedef void (*DestroyFunc) (void *);
typedef void (*PrintFunc) (void *);

typedef struct tnode 
{
	BTItem item;
	BTNode left;				/* Left child */
	BTNode right;				/* Right child */
	BTNode back;				/* Brother */
	BTNode parent;				/* Parent of node */
} BTNodes;

typedef struct main_tree
{
	uint32_t size;				/* Number of treenodes */
	BTNode last;
	BTNode tree;
	DestroyFunc destroyValue;
	PrintFunc printValue;

} mainTree;

typedef struct main_tree* BTree;

/*===================================||	F U N C T I O N S ||===================================*/

BTree BTCreate ( DestroyFunc , PrintFunc );

BTItem BTGetItem ( BTNode );

BTNode BTGetRoot ( BTree );

uint32_t BTSize ( BTree );

bool BTIsNil ( BTNode );

void BTRemoveLeaf ( BTree , BTNode );

void BTInsertRoot ( BTree , BTItem );

BTNode BTGetParent ( BTree , BTNode );

BTNode BTGetChildLeft ( BTree , BTNode );

void BTreePrint ( BTree , BTNode , int );

BTNode BTGetChildRight ( BTree , BTNode );

void BTInsertLeft ( BTree , BTNode , BTItem );

void BTInsertRight ( BTree , BTNode , BTItem );

/*=======================================|| E N D  O F  F I L E ||=======================================*/