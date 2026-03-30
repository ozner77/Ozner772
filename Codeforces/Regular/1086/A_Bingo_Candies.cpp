#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>> t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> M;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ll xd;
                cin>>xd;
                M[xd]++;
            }
        }
        ll maxi=0;
        for(auto x:M){
            maxi=max(maxi,x.second);
        }
        ll jaja=n*n;
        if(jaja-maxi>=n){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}