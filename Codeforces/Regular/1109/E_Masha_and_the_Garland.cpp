#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<ll> prefix;
        prefix.push_back(0);
        prefix.push_back(0);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                prefix.push_back(1);
            }else{
                prefix.push_back(0);
            }
            prefix[i+1]+=prefix[i];
        }
        for(int i=0;i<q;i++){
            ll l,r,k;
            cin>>l>>r>>k;
            ll ans=prefix[r]-prefix[l];
            ans++;
            ans/=2;
            if(ans<=k){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}