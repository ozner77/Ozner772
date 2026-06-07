#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        string s;
        map<char,ll> m;
        cin>>s;
        for(auto x:s){
            m[x]++;
        }
        x=abs(x);
        y=abs(y);
        x++;
        y++;
        if(x>n+1){
            cout<<"NO\n";
        }else{
            ll uwu=x-m['8'];
            uwu--;
            ll maxy;
            if(uwu<=0){
                maxy=n+1;
            }else{
                maxy=n-uwu+1;
            }
            if(y<=maxy){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}