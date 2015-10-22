// write your code here cpp
#include <stdio.h>

#define min(x, y) ((x)<(y) ? (x) : (y))

//最小的最大值
int dp[1001];

int search(int *a, int l)
{
    int h=1, mid;
    while(h<=l){
        mid = (h+l)/2;
        if(a[mid] == a[0])
            return mid-1;
        else if(a[mid] > a[0])
            l = mid-1;
        else
            h = mid+1;
    }
    return l;
}

int main()
{
    int n, maxl;
    while(~scanf("%d", &n)){
        maxl = 0;
        while(n--){
            scanf("%d", dp);
            if(maxl == 0){
                maxl = 1;
                dp[maxl] = dp[0];
            }else{
                int pos = search(dp, maxl);
                pos==maxl ? dp[++maxl] = dp[0] : (dp[pos+1] = min(dp[pos+1], dp[0]));
            }
        }
        printf("%d\n", maxl);
    }
    return 0;
}