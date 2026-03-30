#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    if(400%n==0){
        cout<<400/n;
    }else{
        cout<<-1;
    }
}