#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> D;
vector<ll> d;
vector<ll> P;
vector<ll> tamanio;
ll maxid;
vector<vector<ll>> H;
void dfs(ll cur){ 
    if(cur==0){
        d[0]=0;
        D[0].push_back(cur);
    }else{
        d[cur]=d[P[cur]]+1;
        D[d[cur]].push_back(cur);
    }
    maxid=max(maxid,d[cur]);
    for(auto x:H[cur]){
        dfs(x);
        tamanio[cur]+=tamanio[x];
    }
    tamanio[cur]++;
}
int main(){
    ll n,q;
    cin>>n>>q;
    D.resize(n);
    d.resize(n);
    H.resize(n);
    P.assign(n,-1);
    vector<set<pair<ll,ll>>> V(n);
    for(int i=1;i<n;i++){
        ll a;
        cin>>a;
        a--;
        P[i]=a;
        H[a].push_back(i);
    }
    maxid=0;
    tamanio.resize(n);
    dfs(0);
    vector<ll> ans(n);
    for(int i=maxid;i>=0;i--){
        for(int j=0;j<D[i].size();j++){
            ll nodo=D[i][j];
            if(H[nodo].size()==0){
                set<pair<ll,ll>> S;
                S.insert({tamanio[nodo],nodo});
                V[nodo]=S;
            }else{
                ll big =H[nodo][0];
                for (auto x:H[nodo]) {
                    if (V[x].size()>V[big].size()) {
                        big=x;
                    }
                }
                V[nodo]=move(V[big]);
                for (auto x:H[nodo]){
                    for(auto v:V[x]){
                        V[nodo].insert(v);
                    }
                }
                V[nodo].insert({tamanio[nodo],nodo});
            }
            auto it=V[nodo].upper_bound({tamanio[nodo]/2,1e8});
            pair<ll,ll> uwu=*it;
            ans[nodo]=uwu.second;
        }
    }
    for(int i=0;i<q;i++){
        ll xd;
        cin>>xd;
        xd--;
        cout<<ans[xd]+1<<"\n";
    }
}
//dejaa