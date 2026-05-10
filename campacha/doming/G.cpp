#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>0){
        ans++;
        string s=to_string(n);
        ll maxi=0;
        for(auto x:s){
            maxi=max(maxi,(ll)(x-'0'));
        }
        n-=maxi;
    }
    cout<<ans;
}