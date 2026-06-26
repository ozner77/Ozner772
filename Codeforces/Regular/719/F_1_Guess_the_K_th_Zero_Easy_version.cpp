#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,k;
vector<ll> T;
vector<ll> memo;
void upd(ll ind, ll val){
    while(ind<n){
        T[ind]+=val;
        ind+=ind&-ind;
    }
}
ll get(ll ind){
    ll ans=0;
    while(ind>0){
        ans+=T[ind];
        ind-=ind&-ind;
    }
    return ans;
}
int main(){
    cin>>n>>t;
    T.resize(n+1);
    memo.assign(n+1,-1);
    while(t--){
        ll k;
        cin>>k;
        ll l=1;
        ll r=n;
        while(l<r){
            ll mid=(l+r)/2;
            ll comp;
            if(memo[mid]!=-1){
                comp=memo[mid];
                comp+=get(mid);
            }else{
                cout<<"? "<<1<<" "<<mid<<endl;
                cin>>comp;
                comp-=get(mid);
                memo[mid]=comp;
                comp+=get(mid);
            }
            comp=mid-comp;
            if(comp>=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<"! "<<l<<endl;
        upd(l,1);
    }
}