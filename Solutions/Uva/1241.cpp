#include <iostream>
#include <bitset>
using namespace std;

int main () {
    int t,n,m,arr[10000],temp;
    cin >> t;
    while (t--){
        cin >> n >> m;
        bitset<1024> bset1(0);
        for (size_t i = 0; i < m; i++)
        {
            cin >> temp;
            temp--;
            bset1[temp] = 1;
        }
        bset1.flip();
        int wo =0;
        while(n){
            for (size_t i = 0, j = 0; i < (1<<n); i+=2, j++)
            {
                wo += (bset1[i] ^ bset1[i+1]);
                bset1[j] = (bset1[i] | bset1[i+1]);
            }
            // cout << bset1 << endl;
            n--;
        }
        cout << wo << endl;
    }
    return EXIT_SUCCESS;
}
