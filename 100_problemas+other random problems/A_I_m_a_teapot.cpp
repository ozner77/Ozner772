#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n<3){
        cout<<"No";
    }else{
        if(s[n-3]=='t' && s[n-2]=='e' && s[n-1]=='a'){
            cout<<"Yes";
            return 0;
        }
        cout<<"No";
    }
}