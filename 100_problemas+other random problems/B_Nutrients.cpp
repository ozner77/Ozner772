#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> V(m),L(m,0);
    for(int i=0;i<m;i++){
        cin>>V[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll a;
            cin>>a;
            L[j]+=a;
        }
    }
    for(int i=0;i<m;i++){
        if(L[i]<V[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}