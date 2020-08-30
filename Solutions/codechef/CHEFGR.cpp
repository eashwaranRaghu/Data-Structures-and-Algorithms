// Created on 22-06-2019 20:57:04 by necronomicon
#include <stdio.h>

int max(int a, int b){
    return (a > b)? a:b;
}

int main () {
	int t;
    scanf("%d", t);
    while (t--){
        int n, m, arr[100000], mx=0;
        scanf("%d %d", n, m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", arr[i]);
            mx = max(arr[i], mx);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] != mx){
                sum += (mx-arr[i]);
            }
        }
        m -= sum;
        if( m == 0 || m%n == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
