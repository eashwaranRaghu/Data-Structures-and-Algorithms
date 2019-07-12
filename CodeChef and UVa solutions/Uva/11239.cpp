#include <iostream>
#include <set>
#include <map>
using namespace std;

int main () {
    string s, temp;
    int flag =0;
    while (getline(cin, s)){
        map <string, string> m;
        set <string> st, ban;
        if(s == "0"){break;}
        if(s == "1"){continue;}
        if(isupper(s[0])){
            temp = s;
            st.insert(temp);
        } else{
            if(!ban.count(s)){
                if(m[s] != "" && temp != m[s]) {ban.insert(s);}
                else{m[s] = temp;}
                cout << temp << '\t';
            } else{cout << s <<endl ;}
        }
        for (auto i = st.begin(); i!= st.end(); i++)
        {
            cout << *i << endl;
        }
        
    }
    return EXIT_SUCCESS;
}
