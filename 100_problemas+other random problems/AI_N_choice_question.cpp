#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x==a+b){
            ans=i+1;
        }
    }
    cout<<ans;
}