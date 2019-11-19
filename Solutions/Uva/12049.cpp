#include <iostream>
#include <unordered_set>
using namespace std;

int main () {
    int t,n,m,temp;
    cin >> t;
    while (t--){
        int total =0;
        cin >> n >> m;
        unordered_multiset <int> S;
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            S.insert(temp);
        }
        for (size_t i = 0; i < m; i++)
        {
            cin >> temp;
            auto match = S.find(temp);
            if(match == S.end()){
                total++;
            } else {
                S.erase(match);
            }
        }
        for(auto const val:S) {total++;}
        cout << total << endl;
        
    }
    return EXIT_SUCCESS;
}
