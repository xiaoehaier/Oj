// write your code here cpp
#include <stdio.h>
char pageStack[100][104];

int main()
{
    char action[8];
    int n, curPage, latestPage;
    
    while(~scanf("%d", &n)){
        curPage = latestPage = -1;
        while(n--){
            scanf("%s", action);
        	switch(action[0]){
            	case 'V':
            		scanf("%s", pageStack[latestPage = ++curPage]);
            		printf("%s\n", pageStack[curPage]);
            	break;
            	case 'B':
                	printf("%s\n", curPage>0?pageStack[--curPage]:"ignore");
                break;
                case 'F':
                	printf("%s\n", curPage<latestPage?pageStack[++curPage]:"ignore");
                break;
        	}
        }
        printf("\n");
    }
    
    return 0;
}