#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<ll,ll>>> children;
bool ok;
pair<ll,ll> dfs(ll cur,ll val){
    vector<pair<ll,ll>> childs;
    ll minl=1e18;
    ll maxr=-1;
    ll idx=-1;
    for(int i=0;i<children[cur].size();i++){
        pair<ll,ll> xd=dfs(children[cur][i].first,children[cur][i].second);
        if(xd.first<minl){
            idx=i;
            minl=xd.first;
        }
        maxr=max(maxr,xd.second);
        childs.push_back(xd);
    }
    if(childs.size()==0){
        return {val,val};
    }
    for(int i=0;i<childs.size()-1;i++){
        ll idx2=(idx+1)%childs.size();
        if(childs[idx2].first<=childs[idx].second){
            ok=false;
        }
        idx=idx2;
    }
    return {minl,maxr};
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ok=true;
        children.clear();
        children.resize(n);
        vector<ll> V,L(n);
        for(int i=0;i<n-1;i++){
            ll a;
            cin>>a;
            V.push_back(a-1);
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            L[i]=a;
        }
        for(int i=0;i<n-1;i++){
            children[V[i]].push_back({i+1,L[i+1]});
        }
        if(n==1){
            cout<<"YES\n";
        }else{
            dfs(0,0);
            if(ok){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}