#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        ll cur=V[0];
        ll curi=1;
        vector<ll> F(n+1, 0);
        vector<pair<ll,ll>> A;
        ll elementos=n;
        ll distintos=1;
        for(int i=1;i<n;i++){
            if(V[i]==cur){
                curi++;
            }else{
                distintos++;
                F[curi]++;
                curi=1;
                cur=V[i];
            }
        }
        F[curi]++;
        for(int i=1;i<=n;i++){
            if(F[i]>0){
                A.push_back({i-1,F[i]});
            }
        }
        ll ans=0;
        for(int i=0;i<A.size();i++){
            ll min_elementos=elementos-(A[i].first*distintos);
            ll target=k-min_elementos;
            if(target>=0){
                if(target%distintos==0){
                    ans++;
                }
            }
            elementos-=(A[i].first+1)*A[i].second;
            distintos-=A[i].second;
        }
        cout<<ans<<"\n";
    }
}