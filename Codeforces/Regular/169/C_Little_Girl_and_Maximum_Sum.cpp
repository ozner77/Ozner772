#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> A;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        A.push_back(a);
    }
    vector<ll> B(n+1,0);
    for(int i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;
        l--;
        B[l]++;
        B[r]--;
    }
    vector<ll> C;
    ll val=0;
    for(auto x:B){
        val+=x;
        C.push_back(val);
    }
    sort(C.rbegin(),C.rend());
    sort(A.rbegin(),A.rend());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=A[i]*C[i];
    }
    cout<<ans;
}