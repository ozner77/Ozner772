#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll ans=0;
    for(auto x:s){
        if(x=='j' || x=='i'){
            ans++;
        }
    }
    cout<<ans;
}