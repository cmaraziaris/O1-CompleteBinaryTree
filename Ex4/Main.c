#include <stdio.h>
#include "CBTInit.h"
#include <time.h>

int main(void)
{
	clock_t t; 
     
	CBTTree CBT=BTCreate();
	void (*visit) (BTNode head);

 for (int j=1000000 ; j<=10000000 ; j*=10) {
	 
    t = clock();

	for (int i = 0 ; i < j ; i++) {
		CBTInsertLast(CBT , rand()%10000);
		CBTGetLast(CBT);
 	}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC;

	printf ("Took : %lf seconds for %d elements.\n",time_taken,j);
	
	t = clock();
 	
	 for (int i = 0 ; i < j ; i++)
		CBTRemove(CBT , CBTGetLast(CBT));
	
	t = clock() - t;
	time_taken = ((double) t) / CLOCKS_PER_SEC;
	printf ("Took : %lf seconds to delete %d elements.\n",time_taken,j);

}
return 0;
}