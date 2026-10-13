#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    vector<ll> A,B;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<m;i++){
        ll b;
        cin>>b;
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll l=0;
    ll r=0;
    ll ans=0;
    while(l<n && r<m){
        if(abs(A[l]-B[r])<=k){
            ans++;
            l++;
            r++;
        }else{
            if(A[l]<B[r]){
                l++;
            }else{
                r++;
            }
        }
    }
    cout<<ans;
}