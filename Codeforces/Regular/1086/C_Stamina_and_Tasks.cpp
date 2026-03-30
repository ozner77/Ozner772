#include <bits/stdc++.h>
using namespace std;
#define ll long double
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> C(n),P(n);
        for(int i=0;i<n;i++){
            cin>>C[i]>>P[i];
            P[i]=1.0-P[i]/100.0;
        }
        vector<pair<ll,ll>> V;
        V.push_back({0.0,1.0});
        for(int i=0;i<n;i++){
            vector<pair<ll,ll>> A;
            for(auto u:V){
                A.push_back(u);
                A.push_back({u.first+u.second*C[i],u.second*P[i]});
            }
            sort(A.begin(),A.end(),greater<pair<ll,ll>>());
            vector<pair<ll,ll>> B;
            ll best=-1;
            for(auto u:A){
                if(u.second>best){
                    B.push_back(u);
                    best=u.second;
                }
            }
            V.swap(B);
        }
        ll ans=0;
        for(auto u:V){
            ans=max(ans,u.first);
        }

        cout<<fixed<<setprecision(10)<<ans<<"\n";
    }
}