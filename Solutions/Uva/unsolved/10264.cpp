#include <iostream>
#include <string>
#include <bitset>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    int n;
    while(cin >> n){
        int mx = 0;
        pair<int,int> arr[100000];
        bitset<10000> bset(0), bset2(0);
        for (size_t i = 0; i < (1<<n); i++)
        {
            cin >> arr[i].first;
        }
        for (size_t i = 0; i < (1<<n); i++)
        {
            bset = i;
            for (size_t j = 0; j < n; j++)
            {
                bset2 = bset;
                bset2[j] = ~bset2[j];
                arr[i].second += arr[bset2.to_ulong()].first;
            }
        }
        for (size_t i = 0; i < (1<<n); i++)
        {
            bset = i;
            for (size_t j = 0; j < n; j++)
            {
                bset2 = bset;
                bset2[j] = ~bset2[j];
                mx = max(mx, (arr[i].second + arr[bset2.to_ulong()].second));
            }
        }
        cout << mx << endl;
    }
    return EXIT_SUCCESS;
}
