#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    bool ok=true;
    l--;
    r--;
    for(int i=l+1;i<=r;i++){
        if(s[i]!=s[i-1]){
            ok=false;
        }
    }
    if(ok && s[l]=='o'){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}