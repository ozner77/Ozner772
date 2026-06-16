#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> T;
vector<ll> A;
void upd(ll ind,ll val){
    while(ind<T.size()){
        T[ind]+=val;
        ind+=ind&-ind;
    }
}
ll query(ll ind){
    ll ans=0;
    while(ind>0){
        ans+=T[ind];
        ind-=ind&-ind;
    }
    return ans;
}
int main(){
    ll n,q;
    cin>>n>>q;
    T.resize(n+1);
    A.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1;i<=n;i++){
        upd(i,A[i]);
    }
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==2){
            b--;
            if(b>0){
                cout<<query(c)-query(b)<<"\n";
            }else{
                cout<<query(c)<<"\n";
            }
        }else{
            upd(b,c-A[b]);
            A[b]=c;
        }
    }
}