// write your code here cpp

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


unsigned short digits[9];
bool isUsable[10];
unsigned long pwd;
unsigned prime[3432];

void createPrime() {
  int i, j, a[32000] = {true, true, false};
 
  for (i = 2; i * i < 32000; i++) {
    if (a[i]) continue;
    for (j = i * i; j < 32000; j += i)
      a[j] = true;
  }
 
  j = 0;
  for (i = 2; i < 32000; i++)
    if (!a[i])
      prime[j++] = i;
}
 
bool isPrime(int n) {
  int i;
  if (n < 2) return false;
  for (i = 0; prime[i] * prime[i] <= n; i++) {
    if (n % prime[i] == 0)
      return false;
  }
  return true;
}

void generatePwd(int n, int m)
{
    for(int i=0; i<n; ++i){
        if(isUsable[i]){
            isUsable[i] = false;
            pwd = pwd*10 + digits[i];
            
            if(m+1 < n)
                generatePwd(n, m+1);
            else if(isPrime(pwd)){
                printf("%lu\n", pwd);
                isUsable[9] = false;
            }     
                
            isUsable[i] = true;
            pwd /= 10;
        }      
    }
}


int compar (const void *a, const void *b)
{
    unsigned short *aa=(unsigned short*)a,*bb =(unsigned short*)b;
    if( *aa >*bb)return 1;
    if( *aa == *bb) return 0;
    if( *aa < *bb) return -1;
}

int main()
{
    int n, sum;
    createPrime();
    while(~scanf("%d", &n)){
        if(n == 0) break;
        
        //initial
        qsort(digits, n, sizeof(unsigned short), compar);
        memset(isUsable, true, sizeof(isUsable));
        pwd = 0;
        sum = 0;
        for(int i=0; i<n; ++i){
            scanf("%hu", digits+i);
            sum += digits[i];
        }
        
        //3
        if(sum%3 == 0 && n>1)
            printf("NONE\n");
        else{ 
            generatePwd(n, 0);
            if(isUsable[9])
                printf("NONE\n");
        }
        printf("\n");
    }
    
    return 0;
}


