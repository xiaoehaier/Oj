// write your code here cpp
#include <stdio.h>
#include <stdbool.h>

unsigned sons[11];

unsigned gcd(unsigned m, unsigned n)
{
    unsigned temp;
    while(n!=0){
      temp = m%n;
      m = n;
      n = temp;
    }
    return m;
}

bool solve(unsigned sons[], unsigned n, unsigned m)
{   
    unsigned lcm = 1;
    
    for(unsigned i=0; i<n; ++i)
        lcm = lcm/gcd(lcm, sons[i])*sons[i];
    
    
    unsigned sum = 0;
    for(unsigned i=0; i<n; ++i){
        sons[i] = lcm/sons[i];
        sum += sons[i];
    }
    
    if(m%sum)
        return false;
    
    for(unsigned i=0,tmp=m/sum ; i<n; ++i)
        sons[i] *= tmp;
    
    return true;
}

int main()
{
    unsigned m, n;
    
    while(1){
        scanf("%u%u", &m, &n);
        if(m == 0 && n == 0)
            break;
        
        for(unsigned i=0; i<n; ++i)
            scanf("%u", sons+i);
                
        if(solve(sons, n, m))
            for(unsigned i=0; i<n; ++i)
                printf("%u%c", sons[i], i==n-1?'\n':' ');
        else
            printf("Can't Solve\n");
    }
    
    return 0;
}