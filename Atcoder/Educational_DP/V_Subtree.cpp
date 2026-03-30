#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<vector<ll>> children;
vector<ll> dp;
vector<bool> visited;
ll n,m;
vector<vector<ll>> prefix,sufix;
vector<ll> ans;
void dfs(ll cur){
    visited[cur]=true;
    vector<ll> MATENME;
    dp[cur]=1;
    for(auto x:adj[cur]){
        if(!visited[x]){
            children[cur].push_back(x);
            dfs(x);
            dp[cur]=((dp[cur])%m*(dp[x]+1)%m)%m;
            MATENME.push_back(dp[x]+1);
        }
    }
    if(MATENME.size()>0){
        prefix[cur].push_back(MATENME[0]);
        for(int i=1;i<MATENME.size();i++){
            prefix[cur].push_back((prefix[cur][i-1]*MATENME[i])%m);
        }
        reverse(MATENME.begin(),MATENME.end());
        sufix[cur].push_back(MATENME[0]);
        for(int i=1;i<MATENME.size();i++){
            sufix[cur].push_back((sufix[cur][i-1]*MATENME[i])%m);
        }
    }
}
void dfs2(ll cur, ll parent_value){
    ans[cur]=(dp[cur]*parent_value)%m;
    visited[cur]=true;
    int child_count = children[cur].size();
    for(int i=0;i<child_count;i++){
        ll node = children[cur][i];
        ll l;
        if(i>0){
            l=prefix[cur][i-1];
        }
        else{
            l=1;
        }
        ll r;
        if(i+1<child_count){
            r=sufix[cur][child_count-i-2];
        }
        else{
            r=1;
        }
        ll uwu=(l*r)%m;
        ll newe=((uwu*parent_value) % m + 1) % m;
        dfs2(node,newe);
    }
}
int main(){
    cin>>n>>m;
    adj.resize(n);
    children.resize(n);
    ans.resize(n);
    visited.assign(n,false);
    dp.resize(n);
    prefix.resize(n);
    sufix.resize(n);
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    visited.assign(n,false);
    dfs2(0,1);
    for(auto x:ans){
        cout<<x<<"\n";
    }
}