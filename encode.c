// write your code here cpp


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int seq[132];

int main()
{
    char *a = (char*)malloc(sizeof(char)*132), *b = (char*)malloc(sizeof(char)*132),*c;
    int n, k;
    
    while(~scanf("%d%d", &n, &k)){
        for(int i=1; i<=n; ++i)
            scanf("%d", seq+i);
        
        scanf("%s", a+1);
        
        //fill it to n
        int sl = strlen(a+1);
        for(int i=sl+1; i<=n; ++i)
            a[i] = ' ';
        a[n+1] = b[n+1] = '\0';
        
        //encode
        while(k--){
            for(int i=1; i<=n; ++i)
                b[seq[i]] = a[i];
            
            c = a;
            a = b;
            b = c;
        }
        printf("%s\n", a+1);
    }
    free(a); a = NULL;
    free(b); b = NULL; c = NULL;
    return 0;
}