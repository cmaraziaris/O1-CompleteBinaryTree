#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTInit.h"

bool BTIsNil (BTNode p) { return p == NULL; }

BTree BTCreate (DestroyFunc destroyVal , PrintFunc printVal) {
	BTree newTree;  											/* Create a main tree block */
	assert ((newTree = malloc (sizeof(struct main_tree))));
	newTree->tree = NULL;
	newTree->last = NULL;
	newTree->size = 0;
	newTree->destroyValue = destroyVal;
	newTree->printValue = printVal;
	printf("Tree created successfully!\n\n");

return newTree;
}

static void BTsetNode (BTNode node ,BTItem item, BTNode left, BTNode right, BTNode parent, BTNode back) {
	/* Set given node's interior */
	assert(node);
	node->item = item;
	node->left = left;
	node->right = right;
	node->parent = parent;
	node->back = back;
}

uint32_t BTSize (BTree p) { return p->size; }

BTNode BTGetRoot(BTree p) { return p->tree; } 				/* Return the root */

BTNode BTGetParent(BTree head ,BTNode node) {
	/* If node's parent exists return it */
	return ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) ? NULL : node->parent;	
}

BTNode BTGetChildLeft(BTree head, BTNode node) {
	/* If the tree or the given node is NULL, return NULL */
	/* If the left child exists, return it */
	return ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) ? NULL : node->left;
}

BTNode BTGetChildRight(BTree head, BTNode node) { 			
	/* If the tree or the given node is NULL, return NULL */
	/* If the right child exists, return it */ 
	return ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) ? NULL : node->right;
}

BTItem BTGetItem(BTNode node) { return node->item; }		

void BTInsertRoot(BTree head, BTItem item) {
	assert(head);
	if (BTIsNil(BTGetRoot(head))) {							
		assert((head->tree = malloc(sizeof(BTNodes ))));	/* Allocate memory for new node */

		BTsetNode(head->tree , item , NULL , NULL , NULL , NULL);

		head->last = BTGetRoot(head);
		head->size++;	
		return;
	}
	printf("Tree has already a root.\nRoot insertion failed.\n");
}

void BTInsertLeft(BTree head, BTNode node, BTItem item) {
	assert(head);
	/* If the tree doesn't exist, inform the user. */
	if (BTIsNil( BTGetRoot(head ))) 						
		printf("Tree is empty.\n");
	/* If the node's left child doesn't exist, create one */
	else if (!BTIsNil(node) && BTIsNil(BTGetChildLeft(head,node))) {
			
		assert((node->left = malloc(sizeof(BTNodes))));
			
		BTsetNode(node->left , item , NULL , NULL , node , head->last);

		head->last = node->left;
		head->size++;
	}
	/* If the node has already a left child, inform the user. */
	else printf("Attempt to insert a left child to a non-empty position.\n"); 
}

void BTInsertRight(BTree head, BTNode node, BTItem item) {
	assert(head);
	/* If the tree doesn't exist, inform the user. */
	if (BTIsNil( BTGetRoot(head ))) 						
		printf("Tree is empty.\n");
	/* If the node's right child doesn't exist, create one */
	else if (!BTIsNil(node) && BTIsNil(BTGetChildRight(head,node))) {
		
		assert((node->right=malloc(sizeof(BTNodes))));
	
		BTsetNode(node->right , item , NULL , NULL , node , head->last);

		head->last = node->right;
		head->size++;
	}
	/* If the node has already a right child, inform the user. */
	else printf("Attempt to insert a right child to a non-empty position.\n"); 
}

void BTRemoveLeaf(BTree head , BTNode node ) {
	/* If the tree is empty, return */
	if (head == NULL || BTIsNil(BTGetRoot(head))) return;		

	/* Check whether the given node is a leaf */
	if (BTGetChildLeft(head,node) || BTGetChildRight(head,node)) {		
		printf("Used function <BTRemoveLeaf> to remove a non-leaf node.\nRemoval failed.\n");
		return;												
	}		

	BTNode parent = BTGetParent(head,node);
	if (!BTIsNil(parent)) {	

		if (parent->left == node) 
			parent->left = NULL; 
		
		else parent->right = NULL;

		head->destroyValue(BTGetItem(node));
		free(node);
	} else {

		head->destroyValue(BTGetItem(BTGetRoot(head)));
		free(BTGetRoot(head));
		head->tree = NULL;
	}
	head->size--;
}

/* Pretty print tree */
void BTreePrint(BTree tree ,BTNode node ,int indent)        
{ 
	if (tree == NULL || BTIsNil(node)) return ;
	/* If tree is not empty */
  	if (!BTIsNil(BTGetRoot(tree))) {                        
	/* Print right subtree 4 places right of root node */
    BTreePrint(tree ,BTGetChildRight(tree,node) ,indent + 4);
                												
    for (unsigned int i = 0 ; i < indent ; i++)
      printf(" ");                    							/* Take care for indentation */
	tree->printValue(BTGetItem(node));  								/* Print root node */
	/* Print left subtree 4 places right of root node */
	BTreePrint(tree ,BTGetChildLeft(tree,node) ,indent + 4);	
	}
}
/*=======================================|| E N D  O F  F I L E ||=======================================*/