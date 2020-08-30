#include <iostream>
#include <set>
using namespace std;

int main () {
    int n,k,temp,res;
    while(scanf("%d", &n) && n!=0){
        multiset <int> S;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &temp);
                S.insert(temp);
            }
            res = abs(*(S.begin()) - *(--S.end()));
            sum += res;
            S.erase(S.begin());
            S.erase(--S.end());
        }
        cout << sum << endl;
    }
    return EXIT_SUCCESS;
}
