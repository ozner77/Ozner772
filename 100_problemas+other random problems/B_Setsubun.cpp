#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll original=n;
    n=0;
    ll ans=-1;
    ll con=0;
    while(n<k){
        ans++;
        n+=original+con;
        con++;
    }
    cout<<ans;
}