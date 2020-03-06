#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CBTInit.h"

#ifdef INT

void printItem(void * item) {
	printf("(%d)\n" , *(int *)item);
}

void destroyItem(void * item) {
	if (item != NULL) free((int *)item);
}

int* createItem(int value) {
	int* pointer = malloc(sizeof(int));		
	*pointer = value;						
	return pointer;
}

#endif

#ifdef STR

#include <string.h>

static char * randomStrGen (void) {
	uint8_t size = rand()%10 + 1;
	char * str = malloc (size * sizeof(char));
	for (uint8_t i = 0; i < size - 1; i++) {
		str[i] = (rand()%(122 - 65)) + 65;
	}
	str[size - 1] = '\0';
	return str;
}

void printItem(void * item) {
	printf("(%s)\n" , (char *)item);
}

void destroyItem(void * item) {
	if (item != NULL) free((char *)item);
}

char* createItem(char * value) {
	char* pointer = strdup(value);					
	return pointer;
}

#endif


int main(int argc , char* argv[])
{
	if (argc != 4) {			
		printf("Usage : ./O1_cbt  <size_of_tree>  <minimum_num_of_elements>  <maximum_num_of_elements> \n");
		exit(EXIT_FAILURE);
	}

	const uint32_t size = atoi(argv[1]);
	#define MINNUM atoi(argv[2])
	#define MAXNUM atoi(argv[3])

	clock_t t; 
    
	const CBTree CBT = BTCreate(destroyItem , printItem);	/*	Create a tree  */

	for (uint32_t i = 0; i < size ; i++)
	#ifdef INT
		CBTInsertLast(CBT , createItem(rand()%50));
	#else
		CBTInsertLast(CBT , createItem(randomStrGen()));
	#endif

	printf("Inserted %u elements in the tree.\n" , size);
	printf("Printing tree . .\n\n");

	BTreePrint(CBT , BTGetRoot(CBT) , 2);

	for (uint32_t i = 0 ; i < size ; i++)	
		CBTRemove(CBT , CBTGetLast(CBT));
	printf("CBTree Destroyed.\n\n");

	printf("Let's add some more elemets . . .\n\n\n");

 for (uint32_t j=MINNUM ; j<=MAXNUM ; j*=10) {
	 
    t = clock();

	for (uint32_t i = 0 ; i < j ; i++) 					/*	Insert elements	 */
	#ifdef INT
		CBTInsertLast(CBT , createItem(rand()%1000000));
	#else
		CBTInsertLast(CBT , createItem(randomStrGen()));
	#endif

	t = clock() - t;

	printf ("Took : %.3lf seconds to add %d elements.\n\n",((double) t) / CLOCKS_PER_SEC , BTSize(CBT));

	t = clock();
 	
	 for (uint32_t i = 0 ; i < j ; i++)					/*	Delete them  */
		CBTRemove(CBT , CBTGetLast(CBT));
	
	t = clock() - t;
	
	printf ("Took : %.3lf seconds to delete them.\n\n",((double) t) / CLOCKS_PER_SEC);

	}

	free(CBT);		

	return EXIT_SUCCESS;
}