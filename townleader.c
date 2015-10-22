#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100001
int indegree[N], outdegree[N];


int main(){
    int t;
    int n, m, a, b;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d%d", &n, &m);

        for(int i=0; i<=n; ++i)
            indegree[i] = outdegree[i] = 0;
        
        while(m--){
            scanf("%d%d", &a, &b);
            if(a != b){
                ++indegree[b];
                ++outdegree[a];
            }
        }
        
        m = n;
        while(n)
            if(indegree[n] == m-1 && outdegree[n] == 0)
                break;
            else 
                --n;
            
        if(n == 0)
            printf("0\n\n");
        else
            printf("1\n%d\n", n);
    }

    return 0;
}


