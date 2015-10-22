#include <stdio.h>
#include <string.h>

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

#define M 1000007

char s1[104], s2[104];
unsigned d[104];

int main()
{
    int l1, l2, ls1, ls2;
    unsigned r;
    
    while(~scanf("%s%s%d%d", s1, s2, &l1, &l2)){
        //initial
        r = 0;
        ls1 = strlen(s1);
        ls2 = strlen(s2);
        
        for(int i=1; i<=max(l1, l2); ++i){
            d[i] = (ls2<i?'a':s2[i-1]) - (ls1<i?'a':s1[i-1]);
            d[i] += d[i-1]*26;
            d[i] %= M;
            
            if(i<min(l1, l2))
                continue;
            
            r += d[i]+1 -(i<ls2?0:1) -(ls1<i?0:1);
            r %= M;
        }
        printf("%u\n", r);
    }
    return 0;
}
