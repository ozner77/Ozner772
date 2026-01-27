#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> A;
        vector<ll> B;
        ll maxi=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
            maxi=max(maxi,a);
        }
        for(int i=0;i<n;i++){
            ll b;
            cin>>b;
            B.push_back(b);
        }
        vector<ll> pB;
        pB.push_back(0);
        for(int i=0;i<n;i++){
            pB.push_back(pB[i]+B[i]);
        }
        ll ans=0;
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++){
            auto it=lower_bound(A.begin(),A.end(),A[i]);
            ll ind=A.end()-it;
            auto it2=lower_bound(pB.begin(),pB.end(),ind);
            ll jaja=it2-pB.begin();
            ll xd=*it2;
            if(ind<xd){
                jaja--;
            }
            ans=max(ans,jaja*A[i]);
        }
        cout<<ans;
        cout<<"\n";
    }
}