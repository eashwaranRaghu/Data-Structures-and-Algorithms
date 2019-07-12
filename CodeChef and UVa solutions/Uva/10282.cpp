#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main () {
    map <string, string> m;
    int flag = 0;
    string str, s1, s2;
    
    while(getline(cin, str)){
        if(str == "" && flag == 1){break;}
        if(str == ""){flag = 1; continue;}
        if(!flag){
            stringstream sstr(str);
            sstr >> s1 >> s2;
            m[s2] = s1;
        }
        else{
            cout << ((m[str] != "") ? m[str] : "eh") << endl;
        }
    }
    return EXIT_SUCCESS;
}