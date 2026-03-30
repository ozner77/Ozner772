#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        if(a[i]==b[i] && a[i]=='o'){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}