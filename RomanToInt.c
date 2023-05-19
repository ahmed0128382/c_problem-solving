#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int romanToInt(char * s);
int main(void)
{
	char *s="MCMXCIV";
	int num=romanToInt(s);
	printf("number is : %d",num);
	return (0);
}
int romanToInt(char * s){
   // char *a=s;
    int sum=0;
	int count=strlen(s);
    while( 0 != count )
    {

        switch(*s)
        {
            case 'I':
                if((('V') == *(s+1)) || (('X') == *(s+1)))
                {
                    sum-=1;
					
                }
                else
                {
                    sum+=1;
					
                }
                break;
            case 'V':
                sum+=5;
				printf("sum after V is : %d\n",sum);
                break;
            case 'X':
                if(('C') == *(s+1) || ('L') == *(s+1))
                {
                    sum=sum-10;
					printf("sum after X is : %d\n",sum);
					
                }
                else
                {
                    sum+=10;
					printf("Error\n");
					printf("sum after X is : %d\n",sum);
					
                }
                break;
            case 'L':
                sum+=50;
				
                break;
            case 'C':
                if(('M') == *(s+1) || ('D') == *(s+1) )
                {
                    sum-=100;
					printf("sum after C is : %d\n",sum);
					
                }
                else
                {
                    sum+=100;
					printf("sum after C is : %d\n",sum);
					
                }
                break;
            case 'D':
                sum+=500;
				
                break;
            case 'M':
                sum+=1000;
				printf("sum after M is : %d\n",sum);
				
                break;    

        }
		s++;
        count--;
    }
    return sum;
}