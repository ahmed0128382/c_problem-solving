#include "stdio.h"
#include "stdlib.h"
char containsDuplicate(int* nums, int numsSize);
int main(void)
{
	int strs[4] = {1,2,3,1};
	char flag=0;
	flag=containsDuplicate(&strs,4);
	printf("flag:%i\n",flag);
	return (0);
}
char containsDuplicate(int* nums, int numsSize){
    char flag=0;
    for(int i = 0; i<numsSize-1;i++)
    {
        int n=nums[i];
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i] == nums[j])
            {
				
                flag=1;
                return 1;
            }

        }

        
    }
    if(0 == flag)
    {
        return 0;
    }
}