#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    string str;
    while(cin >> str && str != "#"){
        bool val = next_permutation(str.begin(), str.end()); 
        if (val == false) 
            cout << "No Successor" << endl; 
        else
            cout << str << endl; 
    }
    return EXIT_SUCCESS;
}
