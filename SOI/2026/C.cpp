#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pos(ll n,ll a,ll v,ll t){
    if(n==1){
        return 0;
    }
    ll pocision=(v*t);
    if(pocision+a>=n){
        pocision-=(n-a-1);
        ll vueltas=1;
        vueltas+=(pocision/(n-1));
        if(vueltas%2==0){
            return ((pocision%(n-1)));
        }
        return (n-(pocision%(n-1))-1);
    }else if(pocision+a<0){
        pocision+=a;
        ll vueltas=1;
        pocision=abs(pocision);
        vueltas+=(pocision/(n-1));
        if(vueltas%2==0){
            return (n-(pocision%(n-1))-1);
        }
        return ((pocision%(n-1)));
    }
    return pocision+a;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll l,r;
    cin>>l>>r;
    ll k;
    cin>>k;
    set<ll> S;
    for(int i=0;i<k;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        ll fila=pos(n,a,c,-(b+1));
        S.insert(fila);
    }
    ll total=r-l+1;
    ll ocu=distance(S.lower_bound(l), S.upper_bound(r));
    ll ans=total-ocu;
    cout<<ans;
}
