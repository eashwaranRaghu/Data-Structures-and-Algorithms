#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n, mx=0, len;
    string str[1000];
    while (cin >> n && n){
        for (size_t i = 0; i < n; i++)
        {
            cin >> str[i];
            len = str[i].length();
            mx = max(len , mx);
            
        }
        cout<<endl;
    }
    return EXIT_SUCCESS;
}
