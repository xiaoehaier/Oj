// write your code here cpp

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define min(a,b) ( ((a)>(b)) ? (b):(a) )

int weight[31], data[31][31];
bool undone[31];

int main()
{
    int m, n, f, t, c;
    while(~scanf("%d%d", &m, &n)){
        //initial
        memset(weight+1, 0x7f, sizeof(int)*30);
        memset(undone, true, sizeof(undone));
        memset(data, 0, sizeof(data));

        while(m--){
            scanf("%d%d%d", &f, &t, &c);
            data[f][t] = c;
        }
        
        //dijkstra
        int new_done = 0, least = -1;
        while(undone[n]){
            //update node linked with new_done
            //found least of all undone
            for(int i=1; i<=n; ++i){
                if(undone[i]){
                	if(least == -1) 
                        least = i;

                	if(data[new_done][i])
                        weight[i] = min(weight[i], weight[new_done]+data[new_done][i]);
                    
                	if(weight[least] > weight[i])
                        least = i;
            	}
            }
     
            undone[least] = false;
            new_done = least;
            least = -1;
        }
        printf("%d\n", weight[n]);
        
    }
    
    return 0;
}
