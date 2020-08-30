
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main () {
    int n, typ, oper, temp;
    
    while (cin >> n ){
        queue <int> Q;
        stack <int> S;
        priority_queue <int> PQ;
        int f1=1, f2=1, f3=1;
        for (size_t i = 0; i < n; i++)
        {
            cin >> typ >> oper;
            if(typ == 1){
                Q.push(oper);
                S.push(oper);
                PQ.push(oper);
            } else {
                if(Q.size()){if(oper != Q.front()){f1 = 0;} Q.pop();}else{f1 = 0;}
                if(S.size()){if(oper != S.top()){f2 = 0;} S.pop();}else{f2 = 0;}
                if(PQ.size()){if(oper != PQ.top()){f3 = 0;} PQ.pop();}else{f3 = 0;}
            }
        }
        if((f1 && f2 && f3) || (f1 && f2) || (f1 && f3) || (f2 && f3)){cout << "not sure" << endl;}
        else if (f1){cout << "queue" << endl;}
        else if (f2){cout << "stack" << endl;}
        else if (f3){cout << "priority queue" << endl;}
        else{cout << "impossible" << endl;}
    }
    return EXIT_SUCCESS;
}
