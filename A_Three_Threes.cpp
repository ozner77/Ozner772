#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    string ans="";
    cin>>n;
    for(int i=0;i<n;i++){
        ans+=to_string(n);
    }
    cout<<ans<<"\n";
}