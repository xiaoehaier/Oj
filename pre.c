// write your code here cpp

#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main()
{
    int n, expr[52],ie;
    char item[52];

    while(~scanf("%d", &n)){
        ie = -1;
        memset(expr, 0, sizeof(expr));

        while(n--){
            scanf("%s", item);
            if(isdigit(item[0])){
                ++ie;
                for(int i=0; item[i]; ++i){
                    expr[ie] *= 10;
                    expr[ie] += item[i]-'0';
                }
            }else switch(item[0]){
                    case '+':
                        expr[++ie] = -1; break;
                    case '-':
                        expr[++ie] = -2; break;
                    case '*':
                        expr[++ie] = -3; break;
                    case '/':
                        expr[++ie] = -4; break;
            }

            while(ie>0 && expr[ie]>=0 && expr[ie-1]>=0){
                    switch(expr[ie-=2]){
                        case -1:
                            expr[ie] = expr[ie+1] + expr[ie+2]; break;
                        case -2:
                            expr[ie] = expr[ie+1] - expr[ie+2]; break;
                        case -3:
                            expr[ie] = expr[ie+1] * expr[ie+2]; break;
                        case -4:
                            expr[ie] = expr[ie+1] / expr[ie+2]; break;
                    }
                    expr[ie+1] = expr[ie+2] = 0;
            }
               
        }
        printf("%d\n", expr[0]);
    }
    
    return 0;
}