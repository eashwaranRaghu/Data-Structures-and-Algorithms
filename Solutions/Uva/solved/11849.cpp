#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main () {
    long long jack, jill,temp;
    
    while(cin >> jack >> jill && jack && jill){
        unordered_set <int> S1;
        int total=0;
        for (long long i = 0; i < jack; i++)
        {
            cin >> temp;
            S1.insert(temp);
        }
        for (long long i = 0; i < jill; i++)
        {
            cin >> temp;
            // cout << S1.count(temp) << '\t';
            if(S1.count(temp) > 0){total++;}
        }
        cout << total << endl;
    }
    return EXIT_SUCCESS;
}
