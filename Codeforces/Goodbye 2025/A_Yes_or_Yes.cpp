#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool a=false;
        ll con=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='Y'){
                con++;
            }
        }
        if(con>1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}