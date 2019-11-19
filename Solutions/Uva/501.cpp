#include <iostream>
#include <sstream>
#include <set>
#include <iterator>
using namespace std;

int main () {
    string str, s1, s2, s3;
    int t;
    cin >> t;
    while (t--){
        int n, m;
        int v1[30005], v2[30005];
        multiset <int> S;
        cin >> m >> n;
        for (size_t i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            v1[i] = (temp);
            // cout << temp << '\t';
        }
        // cout << endl;
        
        for (size_t i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v2[i] = (temp);
            //cout<< temp << '\t';
        }
        // cout << endl;
        int vi = 0, pos =0;
        set<int>::iterator res = S.begin();
        for(int i = 0; i != n; i++){
            // cout << (*i) << '\t'; 
            while(vi+1 <= (v2[i])){
                S.insert(v1[vi]);
                if(vi == 0){res = S.begin();}
                if((v1[vi] <  (*res)) || res == S.end()){res--;}
                vi++;
                // cout << (*i) << '\t';
            }
            if(pos > 0){res++;}
            pos++;
            cout << *(res) << endl;
            // cout << endl;
            // for(auto j = S.begin(); j != S.end(); j++){cout << (*j) << '\t';} cout << endl;
        }
        if(t) cout << endl;
    }
    return EXIT_SUCCESS;
}
