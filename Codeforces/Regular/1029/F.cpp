#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> V;
vector<ll> depth;
ll MOD=1e9+7;
void dfs(ll cur,ll prev){
    if(cur!=0){
        depth[cur]=depth[prev]+1;
    }else{
        depth[cur]=0;
    }
    for(auto x:V[cur]){
        if(x!=prev){
            dfs(x,cur);
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        V.clear();
        depth.clear();
        V.resize(n);
        depth.resize(n);
        for(int i=0;i<n-1;i++){
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        ll con=0;
        ll con2=0;
        for(int i=1;i<n;i++){
            if(V[i].size()>2){
                con++;
            }
            if(V[i].size()>3){
                con2++;
            }
        }
        if(V[0].size()>2){
            con2++;
        }
        if(V[0].size()==2){
            con++;
        }
        if(con2>0){
            cout<<0<<"\n";
        }else if(con>1){
            cout<<0<<"\n";
        }else if(con==0){
            ll ans=1;
            for(int i=0;i<n;i++){
                ans*=2;
                ans%=MOD;
            }
            cout<<ans%MOD<<"\n";
        }else{
            dfs(0,-1);
            ll x,y;
            x=-1;
            y=-1;
            for(int i=1;i<n;i++){
                if(V[i].size()==1){
                    if(x==-1){
                        x=i;
                    }else{
                        y=i;
                    }
                }
            }
            ll ancestor;
            if(V[0].size()==2){
                ancestor=0;
            }
            for(int i=1;i<n;i++){
                if(V[i].size()==3){
                    ancestor=i;
                }
            }
            ll uwu=abs(depth[x]-depth[y]);
            ll lol=uwu-1;
            ll ans=1;
            for(int i=0;i<depth[ancestor]+1;i++){
                ans*=2;
                ans=ans%MOD;
            }
            ll ans2=1;
            for(int i=0;i<uwu;i++){
                ans2*=2;
                ans2=ans2%MOD;
            }
            ll ans3=1;
            for(int i=0;i<lol;i++){
                ans3*=2;
                ans3=ans3%MOD;
            }
            cout<<((ans%MOD)*((ans2+ans3)%MOD))%MOD<<"\n";
        }
    }
}