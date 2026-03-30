#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a;
    cin>>a;
    ll xd=0;
    vector<string> B;
    for(int i=0;i<a;i++){
        string s;
        ll b;
        cin>>s>>b;
        B.push_back(s);
        xd+=(b%a);
        xd%=a;
    }
    sort(B.begin(),B.end());
    cout<<B[xd];
}