#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<ll> S;
    unordered_map<ll,ll> M,M1;
    vector<ll> V;

    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert(a);
        V.push_back(a);
        M1[a]++;
    }
    reverse(V.begin(),V.end());
    ll cur=1;
    bool ok=false;
    for(auto x:S){
        if(cur>m){
            break;
        }
        if(cur==x){
            M[x]=1;
        }else{
            ok=true;
            break;
        }
        cur++;
    }
    if(ok){
        cout<<0;
        return 0;
    }
    ll ans=0;
    for(auto x:V){
        M1[x]--;
        ans++;
        if(M1[x]==0){
            if(M[x]==1){
                break;
            }
        }
    }
    cout<<ans;
}