#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    map<ll,map<ll,ll>> M;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        M[a][b]=c;
        M[b][a]=c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    vector<ll> dist(n,1e18);
    vector<ll> build(n,-1);
    dist[0]=0;
    
    while(!pq.empty()){
        ll node=pq.top().second;
        ll w=pq.top().first;
        pq.pop();
        if(dist[node]<w){
            continue;
        }
        for(auto x:adj[node]){
            if(M[node][x]+dist[node]<dist[x]){
                pq.push({M[node][x]+dist[node],x});
                dist[x]=dist[node]+M[node][x];
                build[x]=node;
            }
        }
    }
    ll cur=n-1;
    vector<ll> ans;
    while(cur!=0){
        if(cur==-1){
            cout<<-1;
            return 0;
        }
        ans.push_back(cur+1);
        cur=build[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
}