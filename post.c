// write your code here cpp

#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main()
{
    int n, operand[52], iop;
    char expr[52];

    memset(operand, 0, sizeof(int)*52);

    while(~scanf("%d", &n)){
        iop=-1;
        operand[0] = 0;
        while(n--){
            scanf("%s", expr);

            if(isdigit(expr[0])){
                ++iop;
                for(int i=0; expr[i]; ++i){
                    operand[iop] *= 10;
                    operand[iop] += expr[i] - '0';
                }
            }else{
                switch(expr[0]){
                    case '+': 
                	   operand[iop-1] += operand[iop];
                	break;
               	    case '-':
                	   operand[iop-1] -= operand[iop];
                	break;
                    case '*':
                	   operand[iop-1] *= operand[iop];
                	break;
                    case '/':
                	   operand[iop-1] /= operand[iop];
                	break;
                }
                operand[iop] = 0;
                --iop;
            }
            
        }
        printf("%d\n", operand[0]);
    }
    
    return 0;
}