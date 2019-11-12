#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
//#include <limits.h>
#include <assert.h>
#include "BTInit.h"

inline unsigned short BTIsNil (BTNode p) { return (p == NULL); } 	/* If node p is NULL , return 1 , else return 0 */

BTTree BTCreate (void) {
	BTTree bTree;  								/* Create a main tree block */
	bTree = malloc (sizeof(struct main_tree));
	bTree->tree = NULL;
	bTree->size = 0;
	bTree->last = NULL;
	printf("Tree created successfully!\n\n");

return bTree;
}

inline unsigned int BTSize (BTTree p) { return p->size; }

inline BTNode BTGetRoot(BTTree p) { return p->tree; } /* Return the node */

inline BTNode BTGetParent(BTTree head ,BTNode node) {
	if (!BTIsNil(node)) return node->parent;  							/* If node's parent exists return it */
	else return NULL;													/* Else return 0 */
}
inline BTNode BTGetChildLeft(BTTree head, BTNode node) {
	if ( (BTIsNil(BTGetRoot(head)) ) || ( BTIsNil(node) )) 	/* If the tree or the given node is NULL, return NULL */
		return NULL;
	else return node->left;								/* If the left child exists, return it */
}
inline BTNode BTGetChildRight(BTTree head, BTNode node) { 	/* If the tree or the given node is NULL, return NULL */ 
	if ((BTIsNil(BTGetRoot(head)))||(BTIsNil(node)))
		return NULL;
	else return node->right;								/* If the right child exists, return it */
}
inline BTItem BTGetItem(BTNode node)
{
	if (!BTIsNil(node)) return node->item;					/* If the item exists, return it */
	else return -1;
}
void BTInsertRoot(BTTree head, BTItem item)
{
	if (BTIsNil(BTGetRoot(head)))
	{					/* Allocate memory for new node */
		assert((head->tree = malloc(sizeof(BTNodes ))));
		 
		head->tree->item = item;  /* Pass the item to the node */
		head->tree->left = head->tree->right = head->tree->parent = head->tree->back = NULL;
		head->last = BTGetRoot(head);
		head->size++;	
	}
}
void BTInsertLeft(BTTree head,BTNode node,BTItem item)
{
	if (BTIsNil( BTGetRoot(head ))) 				/* If the tree doesn't exist, inform the user. */
		printf("Your tree is empty.\n");
	else {
		if (!BTIsNil(node)) {
			if (BTIsNil(BTGetChildLeft(head,node))) /* If the node's left child doesn't exist, create one */
			{
				assert((node->left = malloc(sizeof(BTNodes))));

				node->left->back = head->last;
				head->last = node->left;
				node->left->item = item;
				node->left->parent = node;
				node->left->left = NULL;
				node->left->right = NULL;
				head->size++;
			}	  /* If the node already has a left child, inform the user. */
			else printf("The given node has already a left child.\n"); 
		}
	}
}
void BTInsertRight(BTTree head,BTNode node,BTItem item)
{
	if (BTIsNil( BTGetRoot(head ))) 				/* If the tree doesn't exist, inform the user. */
		printf("Your tree is empty.\n");
	else {
		if (!BTIsNil(node)) {
			if (BTIsNil(BTGetChildRight(head,node)))  /* If the node's right child doesn't exist, create one */
			{
				assert((node->right=malloc(sizeof(BTNodes))));
			
				node->right->back = head->last;
				head->last = node->right;
				node->right->item = item;
				node->right->parent = node;
				node->right->left = NULL;
				node->right->right = NULL;
				head->size++;
			}	/* If the node already has a right child, inform the user. */
			else printf("The given node has already a right child.\n"); 
		}
	}
}
void BTRemoveLeaf(BTTree head,BTNode node)
{
	if (BTIsNil(BTGetRoot(head)))	return;		/* If the tree is empty, return*/
											
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
void BTreePrint(BTTree tree,BTNode node, int indent)         /* Pretty print tree */
{ 
	if ((!tree) || (BTIsNil(node))) return;
  	if (!BTIsNil(BTGetRoot(tree))) {                         /* If tree is not empty */
    BTreePrint(tree,BTGetChildRight(tree,node), indent+4);
                /* Print right subtree 4 places right of root node */
    for (unsigned int i=0 ; i < indent ; i++)
      printf(" ");                    /* Take care for indentation */
    printf("%d\n", BTGetItem(node));                    /* Print root node */
    BTreePrint(tree,BTGetChildLeft(tree,node), indent+4);
                 /* Print left subtree 4 places right of root node */
  }
}
// inline void BTChange(BTNode node, BTItem item)
// {
// 	if (node) {
// 	node->item=item; /* Change the current node's item, with the given one */
// 	return;
// 	}
// }
// static void PrintFormat (BTNode head)
// {   		/* If the item is a number, use %d */	
// 	if (BTGetItem(head,head)>=0 && BTGetItem(head,head)<ULONG_MAX)
// 		printf("<%d> ",BTGetItem(head,head));	/* If the item is a character, print it the right way */
// 	else if (isalpha(BTGetItem(head,head))&&isalpha(BTGetItem(head,head)))
// 		printf("<%c> ",BTGetItem(head,head));		
// 	else   /* If the item is a string, print it  */
// 		printf("<%s> ",BTGetItem(head,head));
// 	return;
// }
// static void BTVisit (int key,BTTree head,BTNode node,void (*visit) (BTNode root))
// {
// 	visit=PrintFormat;
// 	if (!key)     /* Based on the key, execute the right recursive traversal */
// 	{
// 		if (node==NULL)
// 			return;

// 		visit(node);  /* Pre-Order Traversal */
// 		BTVisit (0,head,BTGetChildLeft(head,node),visit);	
// 		BTVisit (0,head,BTGetChildRight(head,node),visit);
// 	}
// 	else if (key==1)
// 	{ 
// 		if (node==NULL)
// 			return;
// 						/* In-Order Traversal */
// 		BTVisit (1,head,BTGetChildLeft(head,node),visit);	
// 		visit(node);
// 		BTVisit (1,head,BTGetChildRight(head,node),visit);
// 	}
// 	else 
// 	{ 
// 		if (node==NULL)
// 			return;
// 						/* Post-Order Traversal */
// 		BTVisit (2,head,BTGetChildLeft(head,node),visit);	
// 		BTVisit (2,head,BTGetChildRight(head,node),visit);
// 		visit(node);
// 	}	
// }
// void BTPreOrder(BTTree head,void (*visit) (BTNode node))
// {
// 	BTVisit(0,head,head->tree,visit);
// 	return;
// }
// void BTInOrder(BTTree head,void (*visit) (BTNode node))
// { 
// 	BTVisit(1,head,head->tree,visit);
// 	return;
// }
// void BTPostOrder(BTTree head,void (*visit) (BTNode node))
// {
// 	BTVisit(2,head,head->tree,visit);
// 	return;
// }
// //int BTHeight(BTTree p) { return p->height; }

// void BTLevelOrder(BTTree head,void (*visit) (BTNode node))
// {
// 	visit=PrintFormat;
// 	int size=BTSize(head),i=0,j=0;
// 	BTNode arr[size],root=head->tree;
// 	arr[i++]=root;
// 	/* Create an array of Nodes and store every node in it*/
// 	while(j<size)
// 	{
// 		visit(root);
// 		if (root->left !=NULL) arr[i++]=root->left;
// 		if (root->right!=NULL) arr[i++]=root->right;
// 		root=arr[++j];  /* When the children of a node are stored in the array with the index "i", */
// 	}							/* the root becomes the node pointed by index "j" */
// 	printf("\n");
// 	return;
// }
// static void DestroyRec (BTNode head)
// {
// 	if (!head) return;
// 	DestroyRec (head->left);  /* Traverse the tree */
// 	DestroyRec (head->right);
// 	head->left=NULL; head->right=NULL;
// 	free(head);  /* Free its nodes */
// }
// void BTDestroy (BTTree head) 
// {
// 	if (!head->tree) return;
// 	DestroyRec(head->tree); return;
// }