#include <stdio.h>
#include <stdlib.h>
#include "CBTInit.h"
#include <time.h>

#define MINNUM 1e6
#define MAXNUM 1e7

int main(void)
{
	clock_t t; 
     
	CBTTree CBT = BTCreate();	/*	Create a tree  */

 for (int j=MINNUM ; j<=MAXNUM ; j*=10) {
	 
    t = clock();

	for (int i = 0 ; i < j ; i++) 	/*	Insert elements	 */
		CBTInsertLast(CBT , rand()%10000);

	t = clock() - t;

	printf ("Took : %.3lf seconds to add %d elements.\n\n",((double) t) / CLOCKS_PER_SEC,j);
	
	t = clock();
 	
	 for (int i = 0 ; i < j ; i++)	/*	Delete them  */
		CBTRemove(CBT , CBTGetLast(CBT));
	
	t = clock() - t;
	
	printf ("Took : %.3lf seconds to delete %d elements.\n\n",((double) t) / CLOCKS_PER_SEC,j);

	}
	return 0;
}