#include <stdio.h>
#include "BTInit.h"

int main(void)
{ 
	BTTree BT;
	void (*visit) (BTNode head);
	BT=BTCreate();
	BTInsertRoot(BT,100);
	BTInsertLeft(BT,BT->tree,26);
	BTInsertRight(BT,BT->tree,20);

	printf("Visiting tree Pre Order:\n");
	BTPreOrder(BT,visit); printf("\n");

	BTRemoveLeaf(BT,BTGetChildLeft(BT,BT->tree));
	BTChange(BTGetChildRight(BT,BT->tree),58);
	
	/* Time to print our tree */
	
	printf("Visiting tree Pre Order:\n");
	BTPreOrder(BT,visit); printf("\n");
	printf("Visiting tree in Order:\n");
	BTInOrder(BT,visit); printf("\n");
	printf("Visiting tree Post Order:\n");
	BTPostOrder(BT,visit); printf("\n");
	printf("Visiting tree Level Order:\n");
	BTLevelOrder(BT,visit);

	BTDestroy (BT);
	BT=NULL;
	printf("Tree destroyed succesfully.\n");

return 0;
}
