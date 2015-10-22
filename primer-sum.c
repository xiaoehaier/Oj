#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
 
#define N 100001

bool primerTable[N];
uint16_t infoTable[N];
unsigned primerPos[N];
 
void initialTable()
{
    for(unsigned i=2, k=0; i<N; ++i)
        if(!primerTable[i]){
            primerPos[k++] = i;
            for(unsigned j=i*2; j<=N; j+=i)
                primerTable[j] = true;
        }
    
    for(unsigned i=0; primerPos[i]; ++i)
        for(unsigned j=i+1; primerPos[j]; ++j)
            if(primerPos[i]+primerPos[j]<N)
                ++infoTable[primerPos[i]+primerPos[j]];
}
 
int main()
{
    unsigned n;
    initialTable();
    while(~scanf("%u", &n))
        printf("%u\n", infoTable[n]);
	return 0;
}  