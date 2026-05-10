#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> V;
        vector<vector<ll>> A(m);
        map<ll,ll> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            A[a].push_back(i);
            M[a]++;
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            bool tem=false;
            if(i>0){
                if(V[i-1]<V[i]){
                    tem=true;
                }
            }
            if(i<n-1){
                if(V[i+1]<V[i]){
                    tem=true;
                }
            }
            if(V[i]==0){
                tem=true;
            }
            if(!tem){
                ok=false;
                break;
            }
        }
        ll MOD=676767677;
        for(int i=1;i<m;i++){
            M[i]+=M[i-1];
        }
        M[-1]=1;
        if(n==1){
            cout<<1<<"\n";
        }else if(ok){
            ll ans=1;
            for(int i=1;i<m;i++){
                for(auto x:A[i]){
                    ll lado=1e18;
                    if(x>0){
                        lado=min(lado,V[x-1]); 
                    }
                    if(x<n-1){
                        lado=min(lado,V[x+1]);
                    }
                    ll restar=0;
                    if(lado<V[x]-1){
                        restar=M[i-2];
                    }
                    ans=(ans*(M[i-1]-restar))%MOD;
                }
            }
            cout<<ans<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
}