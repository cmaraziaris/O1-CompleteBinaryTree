#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CBTInit.h"

int main(int argc , char* argv[])
{
	if(argc != 4) {			
		printf("Usage : ./O1_cbt  <size_of_tree>  <minimum_num_of_elements>  <maximum_num_of_elements> \n");
		exit(EXIT_FAILURE);
	}
	const unsigned int size = atoi(argv[1]);
	#define MINNUM atoi(argv[2])
	#define MAXNUM atoi(argv[3])

	clock_t t; 
    
	const CBTTree CBT = BTCreate();							/*	Create a tree  */

	for (unsigned int i = 0; i < size ; i++)
		CBTInsertLast(CBT , rand()%50);

	printf("Inserted %u elements in the tree.\n",size);
	printf("Printing tree . .\n\n");
	BTreePrint(CBT,BTGetRoot(CBT),2);

	for (unsigned int i = 0 ; i < size ; i++)	
		CBTRemove(CBT , CBTGetLast(CBT));
	printf("CBTree Destroyed.\n\n");

	printf("Let's add some more elemets . . .\n\n\n");

 for (unsigned int j=MINNUM ; j<=MAXNUM ; j*=10) {
	 
    t = clock();

	for (unsigned int i = 0 ; i < j ; i++) 					/*	Insert elements	 */
		CBTInsertLast(CBT , rand()%1000000);

	t = clock() - t;

	printf ("Took : %.3lf seconds to add %d elements.\n\n",((double) t) / CLOCKS_PER_SEC , BTSize(CBT));

	t = clock();
 	
	 for (unsigned int i = 0 ; i < j ; i++)					/*	Delete them  */
		CBTRemove(CBT , CBTGetLast(CBT));
	
	t = clock() - t;
	
	printf ("Took : %.3lf seconds to delete them.\n\n",((double) t) / CLOCKS_PER_SEC);

	}

	free(CBT);		

	return EXIT_SUCCESS;
}