#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	int strs[4] = {7,7,7,7};
	char count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(strs[i] == strs[j])
			{
				count++;
				break;
			}
		}
	}
	printf("required shoes no is:%i\n",count);
	return (0);
}
