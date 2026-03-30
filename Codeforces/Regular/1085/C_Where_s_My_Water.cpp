#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,h;
vector<ll> V;
vector<ll> Vh;
vector<bool> vis;
ll wateriz(ll i){
    ll curh=V[i];
    ll ans=0;
    while(i>=0){
        curh=max(curh,V[i]);
        if(curh<Vh[i]){
            ans+=Vh[i]-curh;
            Vh[i]=curh;
        }
        i--;
    }
    return ans;
}   
ll waterde(ll i){
    ll curh=V[i];
    i++;
    ll ans=0;
    while(i<n){
        curh=max(curh,V[i]);
        if(curh<Vh[i]){
            ans+=Vh[i]-curh;
            Vh[i]=curh;
        }
        i++;
    }
    return ans;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>h;
        V.clear();
        Vh.clear();
        V.push_back(h);
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            Vh.push_back(h);
        }
        V.push_back(h);
        n+=2;
        ll res=0;
        map<ll,ll> M;
        for(int i=1;i<n-1;i++){
            if(V[i+1]>=V[i] && V[i-1]>=V[i]){
                M[i]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i]!=1 || M[j]!=1){
                    continue;
                }
                Vh.assign(n,h);
                ll a=wateriz(i);
                ll b=waterde(i);
                ll c=wateriz(j);
                ll d=waterde(j);
                res=max(res,a+b+c+d);
            }
        }
        cout<<res<<endl;
    }

}