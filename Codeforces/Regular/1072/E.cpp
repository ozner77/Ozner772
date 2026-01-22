#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> P,R;
void init(ll n){
    P.clear();
    R.clear();
    for(int i=0;i<n;i++){
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
    if(rx==ry){
        return;
    }
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
        ll n;
        cin>>n;
        init(n);
        vector<ll> V(n);
        vector<ll> Res(n,0);
        vector<vector<pair<ll,ll>>> L;
        vector<ll> groupval(n,1);
        for(int i=0;i<n;i++){
            cin>>V[i];
        }
        L.resize(n);
        for(int i=1;i<n;i++){
            L[abs(V[i]-V[i-1])].push_back({i,i-1});
        }
        ll cur=0;
        for(int i=n-1;i>0;i--){
            for(auto x:L[i]){
                ll a=x.first;
                ll b=x.second;
                if(encontrar(a)==encontrar(b)){
                    continue;
                }
                ll n1=groupval[encontrar(a)];
                ll n2=groupval[encontrar(b)];
                cur-=((n1*(n1-1))/2);
                cur-=((n2*(n2-1))/2);
                unir(a,b);
                ll xd=encontrar(a);
                groupval[xd]=n1+n2;
                ll jaja=groupval[xd];
                jaja*=(jaja-1);
                jaja/=2;
                cur+=jaja;
            }
            Res[i]=cur;
        }
        for(int i=1;i<Res.size();i++){
            cout<<Res[i]<<" ";
        }
        cout<<"\n";
    }
}