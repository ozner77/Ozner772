#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> A,B,C;
        multiset<pair<ll,ll>> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
            C.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            B.push_back(a);
            M.insert({a,i});
        }
        sort(C.begin(),C.end());
        bool ok=true;
        for(int i=0;i<n;i++){
            if(C[i]>B[i]){
                ok=false;
            }
        }
        if(ok){
            vector<ll> V(n);
            for(int i=0;i<n;i++){
                auto ind=M.lower_bound({A[i],-1});
                pair<ll,ll> xd=*ind;
                V[i]=xd.second;
                M.erase(ind);
            }
            ll ans=0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(V[i] > V[j]){
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}