#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> V(m);
    for(int i=0;i<m;i++){
        ll k;
        cin>>k;
        vector<ll> L;
        for(int j=0;j<k;j++){
            ll a;
            cin>>a;
            L.push_back(a);
        }
        V[i]=L;
    }
    vector<ll> B;
    unordered_map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        M[a]=i;
        B.push_back(a);
    }
    vector<ll> ans(n);
    for(int i=0;i<m;i++){
        ll res=-1;
        for(auto x:V[i]){
            res=max(res,M[x]);
        }
        ans[res]++;
    }
    vector<ll> pans;
    pans.push_back(ans[0]);
    for(int i=1;i<n;i++){
        pans.push_back(pans[i-1]+ans[i]);
    }
    for(auto x:pans){
        cout<<x<<"\n";
    }
}