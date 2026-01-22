#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        map<ll,ll> D;
        map<ll,vector<ll>> M;
        vector<ll> R,S;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            R.push_back(a);
        }
        for(int i=0;i<m;i++){
            ll b;
            cin>>b;
            S.push_back(b);
        }
        sort(S.begin(),S.end());
        for(int i=0;i<n;i++){
            ll xr=1e12;
            ll xl=1e12;
            auto itr=lower_bound(S.begin(),S.end(),R[i]);
            if(itr!=S.end()){
                xr=*itr;
            }
            if(itr!=S.begin()){
                auto itl=prev(itr);
                xl=*itl;
            }
            D[xr-R[i]]++;
            D[xl-R[i]]++;
            M[xr-R[i]].push_back(xl-R[i]);
            M[xl-R[i]].push_back(xr-R[i]);
        }
        string instructions;
        cin>>instructions;
        ll cur=0;
        ll ans=n;
        if(D[cur]>0){
                ans-=D[cur];
                D[cur]=0;
                for(auto x:M[cur]){
                    D[x]--;
                }
            }
        for(auto x:instructions){
            if(x=='L'){
                cur--;
            }else{
                cur++;
            }
            if(D[cur]>0){
                ans-=D[cur];
                D[cur]=0;
                for(auto x:M[cur]){
                    D[x]--;
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}