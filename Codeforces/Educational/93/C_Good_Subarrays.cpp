#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<ll,ll> M;
        ll cur=0;
        M[cur]++;
        ll ans=0;
        ll ind=1;
        for(auto x:s){
            cur+=(x-'0');
            ans+=M[cur-ind];
            M[cur-ind]++;
            ind++;
        }
        cout<<ans<<"\n";
    }
}