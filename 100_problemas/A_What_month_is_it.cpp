#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    if((a+b)%12==0){
        cout<<12;
    }else{
        cout<<(a+b)%12;
    }
}