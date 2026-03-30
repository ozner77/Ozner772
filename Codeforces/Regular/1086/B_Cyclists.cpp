#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,p,m;
        cin>>n>>k>>p>>m;
        queue<pair<ll,ll>> q;
        multiset<pair<ll,ll>> S;
        bool adentro=false;
        ll xd;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(i==p-1){
                xd=a;
            }
            if(i<k){
                if(i==p-1){
                    adentro=true;
                }
                S.insert({a,i});
            }else{
                q.push({a,i});
            }
        }
        ll ans=0;
        while(m>0){
            if(m<xd){
                break;
            }
            if(adentro){
                ans++;
                m-=xd;
                adentro=false;
                auto it=S.find({xd,p-1});
                q.push(*it);
                S.erase(it);
                pair<ll,ll> valor=q.front();
                if(valor.second==p-1){
                    adentro=true;
                }
                S.insert(q.front());
                q.pop();
            }else{
                auto it=S.begin();
                pair<ll,ll> uwu=*it;
                m-=uwu.first;
                q.push(*it);
                S.erase(it);
                pair<ll,ll> valor=q.front();
                if(valor.second==p-1){
                    adentro=true;
                }
                S.insert(q.front());
                q.pop();
            }
        }
        cout<<ans<<"\n";
    }
}