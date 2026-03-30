#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll n;
    while(cin>>n){
        if(n==0){
            break;
        }
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
}