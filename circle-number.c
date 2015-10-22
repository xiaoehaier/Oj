// write your code here cpp

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char n[64], m[64];

void calBig(char *n, char *m, int fac)
{
    m[strlen(n)] = '\0';
    for(int i=strlen(n)-1, tmp=0, car=0; i>=0; --i){
        tmp = (n[i]-'0')*fac + car;
        m[i] = tmp%10+'0';
        car = tmp/10;
    }
}

bool isCircle(char *n, char *m)
{
    for(int i=0, k=0; m[i]; ++i, k=0){
    	for(int j=i; 
            m[i]==n[0]&&n[k]&&n[k]==m[j]; ++j, ++k)
            if(!m[j+1]) 
            	j = -1;
        if(!n[k])
            return true;
    }
    return false;
}

int main()
{
    while(~scanf("%60s", n)){
        bool isC = true;
        for(int i=2; i<=6; ++i){
            calBig(n, m, i);
            if(!(isC=isCircle(n, m)))
                break;
        }
        printf("%s\n", isC?"Yes":"No");
    }
    return 0;
}
