#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
vector<vector<ll>> adj;
map<pair<ll,ll>,ll> M;
map<pair<ll,ll>,ll> M2;
vector<bool> S;
bool escaped;
ll n,s,q,e;
ll ansi;
void dfs(ll cur,ll p,ll peso,ll roto){
    if(S[cur]){
        ansi=min(ansi,peso);
    }
    if(cur==e){
        escaped=true;
    }
    for(auto x:adj[cur]){
        if(x!=p && M2[{cur,x}]!=roto){
            dfs(x,cur,peso+M[{cur,x}],roto);
        }
    }
}
int main(){
    cin>>n>>s>>q>>e;
    e--;
    S.resize(n,false);
    adj.resize(n);
    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        M[{a,b}]=c;
        M[{b,a}]=c;
        M2[{a,b}]=i;
        M2[{b,a}]=i;
    }
    for(ll i=0;i<s;i++){
        ll a;
        cin>>a;
        a--;
        S[a]=true;
    }
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ansi=1e18;
        escaped=false;
        dfs(b,-1,0,a);
        if(escaped){
            cout<<"escaped\n";
        }else{
            if(ansi==1e18){
                cout<<"oo\n";
            }else{
                cout<<ansi<<"\n";
            }
        }
    }
}