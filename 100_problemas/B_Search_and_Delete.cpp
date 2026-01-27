#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    map<ll,ll> M;
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        M[a]++;
    }
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        if(M[a]>0){
            M[a]--;
        }
    }
    for(auto x:M){
        for(int i=0;i<x.second;i++){
            cout<<x.first<<" ";
        }
    }
}