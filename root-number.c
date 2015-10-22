// write your code here cpp
#include<string.h>
#include<stdio.h>

char n[102];

int rootNumber(char *n)
{
    int result = 0, tmp = 0;
    
    for(int i=0; n[i]; ++i)
        result += n[i]-'0';
        
    while(result/10){
    	while(result){
        	tmp += result%10;
        	result /= 10;
    	}
    	result ^= tmp;
    	tmp ^= result;
    	result ^= tmp;
    }        
            
    return result;  
}


int main()
{
    while(~scanf("%s", n))
        printf("%d\n", rootNumber(n));
    
    return 0;
}