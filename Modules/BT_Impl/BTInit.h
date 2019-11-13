#pragma once

#include "Init_ptr.h"

/*===================================||	S T R U C T S ||===================================*/

typedef struct tnode *BTNode;	/* Our nodes are called BTNodes */

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
	int size;					/* Number of treenodes */
	BTNode last;
	BTNode tree;
}maintree;

typedef struct main_tree* BTTree;

/*===================================||	F U N C T I O N S ||===================================*/

BTTree BTCreate ( void );

BTItem BTGetItem ( BTNode );

BTNode BTGetRoot ( BTTree );

unsigned int BTSize ( BTTree );

unsigned short BTIsNil ( BTNode );

void BTRemoveLeaf ( BTTree , BTNode );

void BTInsertRoot ( BTTree , BTItem );

BTNode BTGetParent ( BTTree , BTNode );

BTNode BTGetChildLeft ( BTTree , BTNode );

void BTreePrint ( BTTree , BTNode , int );

BTNode BTGetChildRight ( BTTree , BTNode );

void BTInsertLeft ( BTTree , BTNode , BTItem );

void BTInsertRight ( BTTree , BTNode , BTItem );

/*=======================================|| E N D  O F  F I L E ||=======================================*/