#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main () {
    string temp, ig[20], title[50], key[10000], all[10009];
    int flag=0, igi=0, titlei=0, keyi=0;
    while(getline(cin, temp)){
        if(temp == "::"){flag = 1;}
        else{
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if(flag) {title[titlei] = temp; titlei++;}
            else{ig[igi] = temp; igi++;}
        }
    }
    // while(igi--){cout<<ig[igi];}
    // while(titlei--){cout<<title[titlei]<<endl;}
    for (int j = 0; j < titlei; j++)
    {
        stringstream str_strm(title[j]);
        while (str_strm >> temp) {
            flag = 0;
            for (int i = 0; i < igi; i++)
            {
                if(temp.compare(ig[i]) == 0){flag = 1; break;}   
            }
            if(flag == 0){key[keyi] = temp; keyi++;}
        }
    }
    sort(key, key+keyi);
    // while(keyi--){cout<<key[keyi]<<endl;}
    int arr[20][20];
    for (int i = 0; i < keyi; i++)
    {
        for (int j = 0; j < titlei; j++)
        {
            int pos = 0;
            stringstream str_strm(title[j]);
            while (str_strm >> temp) {
               if(arr[j][pos] != 1){
                   if(temp == key[i]){
                       arr[j][pos] = 1;
                        cout << title[j] << endl;
                   }
               }
               pos++;
            }
        }
    }
    
    return EXIT_SUCCESS;
}
