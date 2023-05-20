#include "stdio.h"
#include "stdlib.h"

#define HASHSIZE 100
char containsDuplicate(int* nums, int numsSize);

typedef struct nlist{
        struct nlist *next;
        int num;
}nlist_t;
static nlist_t *hashtab[HASHSIZE] = {NULL};
int main(void)
{
	int strs[4] = {1,2,3,1};
	char flag=0;
	flag=containsDuplicate(&strs,4);
	printf("flag:%i\n",flag);
	return (0);
}
char containsDuplicate(int* nums, int numsSize){
    int i;
    int flag=0;
    nlist_t *np;
    nlist_t *temp;
    for(i = 0; i < numsSize; i++ )
    {
        
        unsigned hashval;
        np = (nlist_t *)malloc(sizeof(*np));
        np->num = nums[i];
        hashval = abs(nums[i])%HASHSIZE;
        np->next = hashtab[hashval];
        while(np->next != NULL)
        {
            if(np->next->num == nums[i])
            {
                flag=1;
                break;
            }
            temp=np;
            np=np->next;
            np->next=temp;
        }
        if(flag == 1)
        {
            break;
        }
        hashtab[hashval] = np;
        
    }
    return flag;
}