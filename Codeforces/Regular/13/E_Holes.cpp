#include <bits/stdc++.h>
using namespace std;
#define ll int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll S=sqrt(n);
    if(S==0){
        S=1;
    }
    vector<ll> nxt(n+1),cnt(n+1),last(n+1);
    for(int i=n;i>=1;i--){
        ll nx=i+a[i];
        if(nx>n||((nx-1)/S)>((i-1)/S)){
            nxt[i]=nx;
            cnt[i]=1;
            last[i]=i;
        }else{
            nxt[i]=nxt[nx];
            cnt[i]=cnt[nx]+1;
            last[i]=last[nx];
        }
    }
    while(m--){
        ll t;
        cin>>t;
        if(t==0){
            ll p,x;
            cin>>p>>x;
            a[p]=x;
            for(int i=p;i>=((p-1)/S)*S+1;i--){
                ll nx=i+a[i];
                if(nx>n||((nx-1)/S)>((i-1)/S)){
                    nxt[i]=nx;
                    cnt[i]=1;
                    last[i]=i;
                }else{
                    nxt[i]=nxt[nx];
                    cnt[i]=cnt[nx]+1;
                    last[i]=last[nx];
                }
            }
        }else{
            ll v;
            cin>>v;
            ll jumps=0,ult=-1;
            while(v<=n){
                jumps+=cnt[v];
                ult=last[v];
                v=nxt[v];
            }
            cout<<ult<<" "<<jumps<<"\n";
        }
    }
}