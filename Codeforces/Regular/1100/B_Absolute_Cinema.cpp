#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> A,B;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            B.push_back(a);
        }
        ll ans=0;
        ll ans2=0;
        for(int i=0;i<n;i++){
            if(A[i]>B[i]){
                ans+=A[i];
                ans2=max(ans2,B[i]);
            }else{
                ans+=B[i];
                ans2=max(ans2,A[i]);
            }
        }
        cout<<ans+ans2<<endl;
    }
}