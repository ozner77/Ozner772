#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n){
    return n*(n-1)*(n-2)/6;
}

int main(){
    unordered_map<ll,ll> M;
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        M[a]++;
        M[b]++;
    }
    for(int i=1;i<=n;i++){
        ll xd=M[i];
        xd++;
        xd=n-xd;
        if(xd<3){
            cout<<0<<" ";
        }else{
            cout<<solve(xd)<<" ";
        }
    }
}