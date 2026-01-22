#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        vector<ll> A,B;
        ll n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll b;
            cin>>b;
            B.push_back(b);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            ll pos=A.end() - lower_bound(A.begin(), A.end(), A[i]);
            auto ind=lower_bound(B.begin(),B.end(),A[i]);
            ll com=n-(ind-B.begin());
            ll neg=com-pos;
            if(neg<=k){
                ans=max(ans,com*A[i]);
            }
        }
        for(int i=0;i<n;i++){
            ll com=B.end() - lower_bound(B.begin(), B.end(), B[i]);
            auto ind=lower_bound(A.begin(),A.end(),B[i]);
            ll pos=n-(ind-A.begin());
            ll neg=com-pos;
            if(neg<=k){
                ans=max(ans,com*(B[i]));

            }
        }
        cout<<ans<<"\n";
    }
}
