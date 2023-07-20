//579A - DIV2	
#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	int Bacteria_Wanted;
	int Bacteria_Put;
	int chosen_first_put;
	int sum;
	printf("Enter Bacteria_Wanted\n");
	scanf("%d",&Bacteria_Wanted);
	//first put always either 1 or 3 optimum
	if(Bacteria_Wanted == 1)
	{
		Bacteria_Put=1;
	}
	else
	{
		if(Bacteria_Wanted%2 < Bacteria_Wanted%3)
	    {
	    	chosen_first_put=1;
			Bacteria_Put=1;
	    }
	    else 
	    {
	    	chosen_first_put=3;
			Bacteria_Put=3;
	    }
	    
	    while(Bacteria_Wanted>chosen_first_put)
	    {
	    	chosen_first_put*=2;
	    }
		if(chosen_first_put == Bacteria_Wanted)
		{
			//do nothing
		}
		else
		{
			chosen_first_put/=2;
			Bacteria_Put+=(Bacteria_Wanted-chosen_first_put);
		}
	}
	
	printf("Bacteria_Put is:%d\n",Bacteria_Put);
	return (0);
}
