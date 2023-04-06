#include <stdio.h>
// n종류의 동전으로 k원을 만드는 동전의 최소 개수를 구하는 프로그램.
int main(){
    int n, k, i, j, a[101], dp[10001]={0};
    scanf("%d %d", &n, &k);
    for(i=1; i<=k; i++) dp[i] = 10000;
    for(i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    };
    for(i=1; i<=n; i++)
        for(j=a[i]; j<=k; j++)
            dp[j] = dp[j] < dp[j-a[i]]+1 ? dp[j] : dp[j-a[i]]+1;
    for(i=0; i<=k; i++) printf("%d ", dp[i]);
    printf("\n");
    printf("%d\n", dp[k]);
    return 0;
}
