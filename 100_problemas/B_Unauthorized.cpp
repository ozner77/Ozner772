#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans=0;
    bool logged=false;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="login"){
            logged=true;
        }else if(s=="logout"){
            logged=false;
        }else if(s=="private" && !logged){
            ans++;
        }
    }
    cout<<ans;
}