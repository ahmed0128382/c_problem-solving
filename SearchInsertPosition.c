#include "stdio.h"
#include "stdlib.h"
int searchInsert(int* nums, int numsSize, int target);
int main(void)
{
	int strs[4] = {1,2,4,5};
	char flag=0;
	flag=searchInsert(&strs,4,3);
	printf("flag:%i\n",flag);
	return (0);
}
int searchInsert(int* nums, int numsSize, int target){

    int BiggerThan=0;
for(int i=0;i<numsSize;i++)
{
    
    if(target >nums[i] && target <= nums[i+1])
    {
        BiggerThan=i+1;
        break;
    }
}
return BiggerThan;
}