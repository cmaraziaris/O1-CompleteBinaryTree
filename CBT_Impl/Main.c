#include <stdio.h>
#include <stdlib.h>
#include "CBTInit.h"
#include <time.h>

#define MINNUM 1e5
#define MAXNUM 1e7

int main(void)
{
	clock_t t; 
    
	CBTTree CBT = BTCreate();	/*	Create a tree  */

	for (unsigned int i = 0; i < 20 ; i++)
		CBTInsertLast(CBT , rand()%50);

	printf("Inserted 20 elements in the tree.\n");
	printf("Printing tree . .\n\n");
	BTreePrint(CBT,CBT->tree,1);

	for (int i = 0 ; i < 20 ; i++)	
		CBTRemove(CBT , CBTGetLast(CBT));
	printf("CBTree Destroyed.\n\n");

	printf("Let's add some more elemets . . .\n\n\n");

 for (int j=MINNUM ; j<=MAXNUM ; j*=10) {
	 
    t = clock();

	for (int i = 0 ; i < j ; i++) 	/*	Insert elements	 */
		CBTInsertLast(CBT , rand()%10000);

	t = clock() - t;

	printf ("Took : %.3lf seconds to add %d elements.\n\n",((double) t) / CLOCKS_PER_SEC , BTSize(CBT));

	t = clock();
 	
	 for (int i = 0 ; i < j ; i++)	/*	Delete them  */
		CBTRemove(CBT , CBTGetLast(CBT));
	
	t = clock() - t;
	
	printf ("Took : %.3lf seconds to delete them.\n\n",((double) t) / CLOCKS_PER_SEC);

	}
	return 0;
}