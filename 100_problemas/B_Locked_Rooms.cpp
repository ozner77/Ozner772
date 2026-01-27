#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    ll xd=0,lol=0;
    for(auto x:V){
        if(x==0){
            xd++;
        }else{
            break;
        }
    }
    reverse(V.begin(),V.end());
    for(auto x:V){
        if(x==0){
            lol++;
        }else{
            break;
        }
    }
    n-=(xd+lol);
    if(n<0){
        n=1;
    }
    cout<<n-1;
}