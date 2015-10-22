#include<stdio.h>

char base64[50004];

int main()
{
    while(~scanf("%s", base64)){
        char *h = base64, tmp;
        for(int i=0; ; ++i){
            if(i == 76){
                tmp = h[76];
                h[76] = '\0';
                printf("%s\n", h);
                h += 76;
                h[0] = tmp;
                i = 0;
                continue;
            }
            if(h[i] == '\0'){
                printf("%s\n\n", h);
                break;
            }
        }
    }
    return 0;
}