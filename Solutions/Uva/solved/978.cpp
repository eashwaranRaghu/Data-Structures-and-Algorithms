#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int arr[1000009][2];
int main () {
    int t;
    cin >> t;
    while (t--){
        int f,g,b,temp,ind=0;
        multiset<int, greater<int>> G, B;
        cin >> f >> g >> b;
        for (size_t i = 0; i < g; i++)
        {
            cin >> temp;
            G.insert(temp);
        }
        for (size_t i = 0; i < b; i++)
        {
            cin >> temp;
            B.insert(temp);
        }
        // cout << t << "case" <<endl;
        
        while(B.size() != 0 && G.size() != 0){
            // int minPlayers = min(B.size(), G.size()) % f;
            // if(min(B.size(), G.size()) != 0 && min(B.size(), G.size()) % f ==0){
            //     minPlayers = f;
            // }
             int minPlayers;
            if(min(B.size(), G.size()) >f){
                minPlayers = f;
            }else{
                minPlayers = min(B.size(), G.size());
            }
            //if min > f, min player = f
            //else min = min()
            // cout << "minplayers: " << minPlayers << endl;
            ind = 0;
            // cout << minPlayers ;
            for (size_t i = 0; i < minPlayers; i++)
            {
                //cout << "for";
                auto tmp1 = B.begin();
                auto tmp2 = G.begin();
                if(*tmp1 != *tmp2){
                    arr[ind][0] = abs(*tmp1 - *tmp2);
                    arr[ind][1] = (*tmp1 - *tmp2 < 0);
                    ind++;
                }
                B.erase(tmp1);
                G.erase(tmp2);
                // cout << B.size() << ' ' << G.size() <<endl;
            }
            for (size_t i = 0; i < ind; i++)
            {
                // cout << arr[i][1] << '\t';
                if(arr[i][1] == 0){
                    B.insert(arr[i][0]);
                } else {
                    G.insert(arr[i][0]);
                }
            }
            // cout << "minplayers: " << minPlayers << endl;
        }
        // cout << B.size() << ' ' << G.size() <<endl;
        // cout<<endl;
        if(B.size() == 0 && G.size() ==0){
            cout << "green and blue died" << endl;
        } else {
            if(G.size() ==0){
                cout << "blue wins" << endl;
                for(auto x: B)cout << x << endl;
            } else{
                cout << "green wins" << endl;
                for(auto x: G)cout << x << endl;
            }
        }
        if(t) cout<<endl;
    }
    return EXIT_SUCCESS;
}