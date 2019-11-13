#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTInit.h"

unsigned short BTIsNil (BTNode p) { return (p == NULL); }

BTTree BTCreate (void) {
	BTTree bTree;  											/* Create a main tree block */
	bTree = malloc (sizeof(struct main_tree));
	bTree->tree = NULL;
	bTree->last = NULL;
	bTree->size = 0;
	printf("Tree created successfully!\n\n");

return bTree;
}

unsigned int BTSize (BTTree p) { return p->size; }

BTNode BTGetRoot(BTTree p) { return p->tree; } 				/* Return the root */

BTNode BTGetParent(BTTree head ,BTNode node) {
	if ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) 
		return NULL;
	else return node->parent;  								/* If node's parent exists return it */										
}

BTNode BTGetChildLeft(BTTree head, BTNode node) {
	if ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) 	/* If the tree or the given node is NULL, return NULL */
		return NULL;
	else return node->left;									/* If the left child exists, return it */
}

BTNode BTGetChildRight(BTTree head, BTNode node) { 			
	if ((BTIsNil(BTGetRoot(head)))||(BTIsNil(node)))		/* If the tree or the given node is NULL, return NULL */ 
		return NULL;
	else return node->right;								/* If the right child exists, return it */
}

BTItem BTGetItem(BTNode node) { return node->item; }		

void BTInsertRoot(BTTree head, BTItem item)
{
	if (BTIsNil(BTGetRoot(head))) {							
		assert((head->tree = malloc(sizeof(BTNodes ))));	/* Allocate memory for new node */
		 
		head->tree->item = item;  							/* Pass the item to the node */
		head->tree->left = head->tree->right = head->tree->parent = head->tree->back = NULL;
		head->last = BTGetRoot(head);
		head->size++;	
		return;
	}
	printf("Tree has already a root.\nRoot insertion failed.\n");
}

void BTInsertLeft(BTTree head,BTNode node,BTItem item)
{
	if (BTIsNil( BTGetRoot(head ))) 						/* If the tree doesn't exist, inform the user. */
		printf("Your tree is empty.\n");
	else {
		if (!BTIsNil(node)) {
			if (BTIsNil(BTGetChildLeft(head,node))) 		/* If the node's left child doesn't exist, create one */
			{
				assert((node->left = malloc(sizeof(BTNodes))));

				node->left->back = head->last;
				head->last = node->left;
				node->left->item = item;
				node->left->parent = node;
				node->left->left = NULL;
				node->left->right = NULL;
				head->size++;
			}	  											/* If the node has already a left child, inform the user. */
			else printf("Node with item <%d> has already a left child.\n", BTGetItem(node)); 
		}
	}
}

void BTInsertRight(BTTree head,BTNode node,BTItem item)
{
	if (BTIsNil( BTGetRoot(head ))) 						/* If the tree doesn't exist, inform the user. */
		printf("Your tree is empty.\n");
	else {
		if (!BTIsNil(node)) {
			if (BTIsNil(BTGetChildRight(head,node)))  		/* If the node's right child doesn't exist, create one */
			{
				assert((node->right=malloc(sizeof(BTNodes))));
			
				node->right->back = head->last;
				head->last = node->right;
				node->right->item = item;
				node->right->parent = node;
				node->right->left = NULL;
				node->right->right = NULL;
				head->size++;
			}												/* If the node has already a right child, inform the user. */
			else printf("Node with item <%d> has already a right child.\n", BTGetItem(node)); 
		}
	}
}

void BTRemoveLeaf(BTTree head,BTNode node)
{
	if (BTIsNil(BTGetRoot(head)))	return;					/* If the tree is empty, return */

	if (BTGetChildLeft(head,node) || BTGetChildRight(head,node)) {		
		printf("Node with item <%d> is not a leaf.\nRemoval failed.\n" , BTGetItem(node));
		return;												/* Check whether the given node is a leaf */
	}										
	BTNode temp=node;
	if (!BTIsNil(BTGetParent(head,node))) {					
		node=BTGetParent(head,node);
		if (node->left == temp) {
			free(temp);
			node->left = NULL;
		} else {
			free(temp);
			node->right = NULL;
		}
	} else {
		free(BTGetRoot(head));
		head->tree = NULL;
	}
	head->size--;
}

void BTreePrint(BTTree tree,BTNode node, int indent)        /* Pretty print tree */
{ 
	if ((!tree) || (BTIsNil(node))) return;
  	if (!BTIsNil(BTGetRoot(tree))) {                        /* If tree is not empty */
    BTreePrint(tree,BTGetChildRight(tree,node), indent+4);
                											/* Print right subtree 4 places right of root node */
    for (unsigned int i = 0 ; i < indent ; i++)
      printf(" ");                    						/* Take care for indentation */
    printf("(%d)\n", BTGetItem(node));                    	/* Print root node */
    BTreePrint(tree,BTGetChildLeft(tree,node), indent+4);	/* Print left subtree 4 places right of root node */
	}
}
/*=======================================|| E N D  O F  F I L E ||=======================================*/