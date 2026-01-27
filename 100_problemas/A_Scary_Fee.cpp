#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,c;
    cin>>n>>c;
    n*=1000;
    n/=(1000+c);
    n-=(n%1000);
    cout<<n;
}