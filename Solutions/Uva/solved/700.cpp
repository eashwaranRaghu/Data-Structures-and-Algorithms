#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    int n,y,a,b, flag=0;
    vector <pair <int,int> > c(20);
    int count=1;
    while(cin >> n && n!=0){
        for (int i = 0; i < n; i++)
        {
            cin>>y>>a>>b;
            c[i].first = y; c[i].second = b-a;
        }
        flag=0;
        while(true){
            int temp = c[0].first;
            flag =0;
            for(int j = 1; j < n; j++)
            {
                if(temp != c[j].first){
                    flag = 1; break;
                }
            }
            if(flag == 1){
                sort(c.begin(), c.begin()+n);
                c[0].first += c[0].second;
            }
            else{
                flag = 0;
                break;
            }
            if(c[0].first >= 10000){flag = 1; break;}
        }
        cout << "Case #" << count << ":" << endl; count++;
        (flag == 0) ? cout << "The actual year is " << c[0].first << '.' <<endl : cout << "Unknown bugs detected." <<endl;
        cout << endl;
    }
    return EXIT_SUCCESS;
}
