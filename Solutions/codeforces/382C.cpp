#include<bits/stdc++.h>
using namespace std;
int t,i,n,y,a[102400];
map<int,int>C,X,R;
int main(){ 
 for(cin>>n;i<n;cin>>a[i++]);
 if(n==1){cout<<-1;return 0;}
 for(sort(a,a+n);--i;)y=a[i]-a[i-1],C[y]++,X[y]=i;
 y=C.begin()->first;t=C.rbegin()->first;
 if(y==t)R[a[0]-y]=R[a[n-1]+y]=n>2||y%2?1:R[a[1]-y/2]=1;
 if(C.size()==2&&t==y*2&&C[t]==1)R[a[X[t]]-y]=1;
 cout<<R.size()<<endl;for(auto r:R)cout<<r.first<<" ";
}
