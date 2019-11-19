#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main () {
    int t; t++;
    string str, s;
    cin >> t >> ws;
    while (t--){
        map <string, double> m;
        double sz =0;
        while (getline(cin, str)){
            if(str == ""){break;}
            m[str]++;
            sz++;
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            cout << i->first << " " << std::fixed << setprecision(4) << ((i->second/sz)* 100) << endl;
        }
        if(t){cout << endl;}
    }
    return EXIT_SUCCESS;
}
