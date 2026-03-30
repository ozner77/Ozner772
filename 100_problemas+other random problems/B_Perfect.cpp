#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    map<ll,ll> M;
    for(int i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        M[a]++;
        if(M[a]==m){
            cout<<a<<" ";
        }
    }
}