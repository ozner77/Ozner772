#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> A(n),B(n);
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A[i]=a;
            if(a<3){
                B[i]=1;
            }else{
                B[i]=-1;
            }
        }
        vector<ll> prefix;
        vector<ll> suffix;
        ll curi1=0;
        ll curi2=-1e18;
        for(int i=0;i<n;i++){
            prefix.push_back(curi1+B[i]);
            curi1=prefix.back();
        }
        for(int i=0;i<n;i++){
            if(i==0){
                suffix.push_back(-1e18);
            }else{
                suffix.push_back(max(curi2,prefix[n-1-i]));
                curi2=suffix.back();
            }
        }
        reverse(suffix.begin(),suffix.end());
        suffix[n-1]=-1e18;
        ll con=0;
        bool ok=false;
        for(int i=0;i<n-2;i++){
            if(A[i]==1){
                con++;
            }
            if(con*2>=(i+1)){
                if(suffix[i+1]>=prefix[i]){

                    ok=true;
                }
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}