#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    for(int i=a;i<n-b;i++){
        cout<<s[i];
    }
}