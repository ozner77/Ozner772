#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<ll> ans;
vector<pair<ll,ll>> bestdepth;
vector<pair<ll,ll>> bestcost;
vector<ll> depth;
vector<ll> depthdown;
vector<ll> cost;
vector<ll> normalcost;
vector<ll> A;
vector<ll> son;
void dfs(ll cur,ll p){
    if(cur!=0){
        depth[cur]=depth[p]+1;
    }
    if(adj[cur].size()==1&&cur!=0){
        depthdown[cur]=1;
    }
    if(adj[cur].size()==1&&cur!=0){
        normalcost[cur]=0;
        cost[cur]=0;
    }
    son[p]=cur;
    for(auto x:adj[cur]){
        if(x!=p){
            dfs(x,cur);
            normalcost[cur]+=A[x]+normalcost[x];
            cost[cur]+=normalcost[x]+cost[x]+A[x];
            if(cost[x]>bestcost[cur].first){
                bestcost[cur].second=bestcost[cur].first;
                bestcost[cur].first=cost[x];
            }else if(cost[x]>bestcost[cur].second){
                bestcost[cur].second=cost[x];
            }
            if(depthdown[x]>bestdepth[cur].first){
                bestdepth[cur].second=bestdepth[cur].first;
                bestdepth[cur].first=depthdown[x];
            }else if(depthdown[x]>bestdepth[cur].second){
                bestdepth[cur].second=depthdown[x];
            }
            depthdown[cur]=bestdepth[cur].first+1;        
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        normalcost.clear();
        normalcost.resize(n);
        depthdown.clear();
        depthdown.resize(n);
        A.clear();
        A.resize(n);
        adj.clear();
        adj.resize(n);
        ans.clear();
        ans.resize(n);
        bestdepth.clear();
        bestdepth.resize(n);
        bestcost.clear();
        bestcost.resize(n);
        depth.clear();
        depth.resize(n);
        cost.clear();
        cost.resize(n);
        depth[0]=0;
        cost[0]=0;
        son.clear();
        son.resize(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n-1;i++){
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,0);
        vector<pair<ll,ll>> V;
        for(int i=0;i<n;i++){
            V.push_back({depth[i],i});
        }
        sort(V.rbegin(),V.rend());
        for(int i=0;i<n-1;i++){
            ll node=V[i].second;
            if(adj[node].size()==1){
                ans[node]=normalcost[node];
            }else if(adj[node].size()==2){
                ans[node]=ans[son[node]]+A[son[node]]; 
            }else{
                
            }
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}