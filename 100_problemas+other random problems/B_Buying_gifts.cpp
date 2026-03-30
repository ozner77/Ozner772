#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> A;
        vector<ll> B;
        multiset<ll> S;
        for(int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            A.push_back({a,i});
            B.push_back(b);
            S.insert(b);
        }
        ll maxi=-1e9;
        sort(A.rbegin(),A.rend());
        ll ans=1e18;
        for(int i=0;i<n;i++){
            ll xd=A[i].first;
            ll res1=abs(xd-maxi);
            ll res2=1e18;
            ll res3=1e18;
            auto it = S.find(B[A[i].second]);
            if(it != S.end()) {
                S.erase(it); 
            }
            auto it2=S.lower_bound(xd);
            if(it2!=S.end()){
                if(*it2>maxi){
                    res2=abs(xd-*it2);
                }
            }

            if(it2!=S.begin()){
                it2=prev(it2);
                if(*it2>maxi){
                    res3=abs(xd-*it2);
                }
            }
            ll lol=min(res1,res2);
            lol=min(lol,res3);
            ans=min(ans,lol);
            maxi=max(maxi,B[A[i].second]);
        }
        cout<<ans<<"\n";
    }
}
