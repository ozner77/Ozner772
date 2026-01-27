#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pair<int,int> normalize(int x, int y) {
    ll a=gcd(x,y);
    x/=a;
    y/=a;
    return {x,y};
}
int main(){
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        
    }
}