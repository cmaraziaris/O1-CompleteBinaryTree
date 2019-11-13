#include <stdio.h>
#include <stdlib.h>
#include "CBTInit.h"
#include "BTInit.h"

static void InsertFarLeft (CBTTree tree,CBTNode node ,CBTItem item) {
    
    if (BTIsNil(BTGetChildLeft(tree,node))){ 	                                    /* We've found the far left node */
	    BTInsertLeft (tree,node,item); 
        return; 
    }
    InsertFarLeft(tree,BTGetChildLeft(tree,node),item);                              /* Continue to the left */
}

static void RecInsert (CBTTree tree,CBTNode parent,CBTNode last,CBTItem item) {
    
    if (BTIsNil(parent)) InsertFarLeft(tree,BTGetRoot(tree),item);                  /* If the tree is full, insert the node far left */
    else if (BTGetChildRight(tree,parent) == last)		                            /* If the last node is a right child */
        RecInsert(tree,BTGetParent(tree,parent),parent,item);                       /* Go up to its parent */
    else {					                                                        /* If the last node is a left child */
        (BTIsNil(BTGetChildRight(tree,parent)))? BTInsertRight(tree,parent,item) :  /* If its right brother in NULL, insert right */
        InsertFarLeft(tree,BTGetChildRight(tree,parent),item);	                    /* Else, insert the node as left as possible */
    } 
}

void CBTInsertLast(CBTTree tree,BTItem item) {

    if (BTIsNil(BTGetRoot(tree))) BTInsertRoot(tree,item);		                    /* If we have 0 nodes , we insert the item instantly */
    else RecInsert( tree , BTGetParent(tree,CBTGetLast(tree)) , CBTGetLast(tree),item );   
}  

CBTNode CBTGetLast (CBTTree head) { return head->last; }

void CBTRemove(CBTTree head,CBTNode node) {
	head->last=node->back;                                                          /* Update the last tree node */
    BTRemoveLeaf(head,node);
}
/*=======================================|| E N D  O F  F I L E ||=======================================*/