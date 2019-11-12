#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CBTInit.h"
#include "BTInit.h"

static void InsertFarLeft (CBTTree tree,CBTNode node ,CBTItem item) {
    
    if (!node->left){ 	// We've found the far left node
	    BTInsertLeft (tree,node,item); 
        return; 
    }
    InsertFarLeft(tree,node->left,item); // Continue to the left
}

static void RecInsert (CBTTree tree,CBTNode parent,CBTNode last,CBTItem item) {
    
    if (!parent) InsertFarLeft(tree,tree->tree,item);  // If the tree is full, insert the node far left
    else if (parent->right==last)		       // If the last node is a right child
        RecInsert(tree,parent->parent,parent,item);    // Go up to its parent
    else {					       // If the last node is a left child
        (!parent->right)? BTInsertRight(tree,parent,item):  // If its right brother in NULL, insert right
        InsertFarLeft(tree,parent->right,item);	       // Else, insert the node as left as possible
    } 
}

void CBTInsertLast(CBTTree tree,BTItem item) {

    if (!tree->tree) BTInsertRoot(tree,item);		// If we have 0 nodes , we insert the item instantly
    else RecInsert(tree,CBTGetLast(tree)->parent,tree->last,item);   
}  

CBTNode CBTGetLast(CBTTree head) { return head->last; }

void CBTRemove(CBTTree head,CBTNode node) {
	head->last=node->back;
    BTRemoveLeaf(head,node);
}