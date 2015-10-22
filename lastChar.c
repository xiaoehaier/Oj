#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
 
int main()
{
    int n;
    long long fre[0x7f-0x21];
    char *buffer = (char*)malloc(N + 1);
     
     
    scanf("%d", &n);
    while(n--){
        memset(fre, 0, sizeof(fre));
             
        scanf(" %s", buffer);       
        long long i=-1;
        while(buffer[++i]){
            if(fre[buffer[i]-0x21] == 0)
            	fre[buffer[i]-0x21] = i+1;
        	else
                fre[buffer[i]-0x21] = -1;
        }

        long long max = N+1;
        for(int j=0; j<0x7f-0x21; ++j)
            if(fre[j] > 0 && fre[j] < max){
                max = fre[j];
                i = j;
            }
         
        printf("%c\n", i+0x21);
    }
    return 0;
}