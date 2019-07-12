
#include <iostream>
#include <queue>
using namespace std;

int main () {
    int n, temp;
    while (cin >> n && n!=0){
        priority_queue <int> Q;
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            Q.push(temp * (-1));
        }
        int cost = 0;
        while(Q.size() > 1){
            int a, b, c;
            a = Q.top(); Q.pop();
            b = Q.top(); Q.pop();
            c = abs(a+b);
            Q.push(c*(-1));
            cost += c;
        }
        cout << cost << endl;        
    }
    return EXIT_SUCCESS;
}
