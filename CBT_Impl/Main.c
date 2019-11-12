#include <stdio.h>
#include <stdlib.h>
#include "CBTInit.h"
#include <time.h>

#define MINNUM 1e5
#define MAXNUM 1e7

int main(int argc , char* argv[])
{
	if(argv[1] == NULL) {
		printf("Usage : ./O1_cbt <size_of_tree>\n");
		exit(EXIT_FAILURE);
	}
	unsigned int size = atoi(argv[1]);
	clock_t t; 
    
	CBTTree CBT = BTCreate();	/*	Create a tree  */

	for (unsigned int i = 0; i < size ; i++)
		CBTInsertLast(CBT , rand()%50);

	printf("Inserted %u elements in the tree.\n",size);
	printf("Printing tree . .\n\n");
	BTreePrint(CBT,CBT->tree,1);

	for (int i = 0 ; i < size ; i++)	
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
	return EXIT_SUCCESS;
}