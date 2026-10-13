#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> P,R;
void init(ll N){
    for(int i=0;i<N;i++){
        P.push_back(i);
        R.push_back(0);
    }
}
ll encontrar(ll x){
    if(P[x]!=x){
        P[x]=encontrar(P[x]);
    }
    return P[x];
}
void unir(ll x,ll y){
    ll rx=encontrar(x);
    ll ry=encontrar(y);
    if(R[rx]>R[ry]){
        P[ry]=rx;
    }else if(R[ry]>R[rx]){
        P[rx]=ry;
    }else{
        P[ry]=rx;
        R[rx]++;
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        P.clear();
        R.clear();
        ll n,x,y;
        cin>>n>>x>>y;
        init(n);
        for(int i=0;i<n;i++){
            if((i+x)<n){
                unir(i,i+x);
            }
            if((i+y)<n){
                unir(i,i+y);
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            a--;
            if(encontrar(i)!=encontrar(a)){
                ok=false;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}