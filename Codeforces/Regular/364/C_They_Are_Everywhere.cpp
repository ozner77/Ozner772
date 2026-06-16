#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    set<ll> S;
    map<ll,ll> M;
    for(auto x:s){
        S.insert(x);
    }
    ll xd=0;
    ll l=0;
    ll ans=1e18;
    for(int i=0;i<n;i++){
        M[s[i]]++;
        if(M[s[i]]==1){
            xd++;
        }
        while(true){
            if(M[s[l]]>1){
                M[s[l]]--;
                l++;
            }else{
                break;
            }
        }
        if(xd==S.size()){
            ans=min(ans,i-l+1);
        }
    }
    cout<<ans;
}