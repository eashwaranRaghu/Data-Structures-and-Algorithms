#include <iostream>
#include <queue>
using namespace std;


class Compare
{
public:
    bool operator() (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        if(a.first < b.first) return false;
        else if (a.first > b.first) return true;
        else{
            return (a.second.first > b.second.first);
        }
    }
};



int main () {
    string str;
    int id, interval;
    pair<int, pair<int, int>> temp, temp2;
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> Q;
    while (cin >> str && str == "Register"){
        cin >> id >> interval;
        temp.first = interval;
        temp.second.first = id;
        temp.second.second = interval;
        Q.push(temp);
    }
    // temp2 = Q.top(); cout << temp2.second.first << endl;
    int k;
    cin >> k;
    // cout << k;
    for (size_t i = 0; i < k; i++)
    {
        temp = Q.top(); Q.pop();
        cout << temp.second.first << endl;
        temp.first += temp.second.second;
        Q.push(temp);
    }
    
    return EXIT_SUCCESS;
}
