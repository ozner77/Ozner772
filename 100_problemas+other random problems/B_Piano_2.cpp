#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    set<pair<ll,ll>> S;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert({a,1});
    }
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        S.insert({a,2});
    }
    ll prev=-1;
    for(auto x:S){
        if(x.second==prev && x.second==1){
            cout<<"Yes";
            return 0;
        }
        prev=x.second;
    }
    cout<<"No";
}