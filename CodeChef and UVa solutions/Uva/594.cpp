#include <iostream>
#include <bitset>
using namespace std;

int main () {
    int n, sign=0;
    while(cin >> n){
        bitset<32> bset1(abs(n)), bset2(0);
        if(n<0){bset1.flip(); bset1 = bset1.to_ulong() + 1;}
        for (int j = 0; j < 8; j++)
        {
            bset2.set(j, bset1[j+24]);
            bset2.set(j+8, bset1[j+16]);
            bset2.set(j+16, bset1[j+8]);
            bset2.set(j+24, bset1[j]);
        }
        // cout << bset1 << ' ' << bset2 << '\t';
        int ans = bset2.to_ulong();
        if(bset2[31]){bset2.flip(); ans = bset2.to_ulong() + 1; ans *= -1;}
        cout << n << " converts to " << ans <<endl;
    }
    return EXIT_SUCCESS;
}