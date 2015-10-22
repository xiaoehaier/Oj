// write your code here cpp
#include <stdio.h>

int numberWithOne(int n)
{
    int countedN = 0;
    int result = 0;

    for(int i=1, onesPerI=0, cur; n; 
        onesPerI = onesPerI*9 + i, i*=10, n/=10){

        cur = n % 10;

        if(cur == 0)
            continue;

        if(cur == 1)
            result = onesPerI + countedN + 1;
        else
            result += (cur-1)*onesPerI + i;

        countedN += cur*i;
        
    }

    return result;
}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        printf("%d\n", numberWithOne(n));
    }
    return 0;
}