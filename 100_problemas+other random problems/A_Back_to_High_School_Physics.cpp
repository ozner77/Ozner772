#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    long double a,b;
    while(cin>>a){
        cin>>b;
        if(a==0){
            cout<<0<<"\n";
            continue;
        }
        long double xd=b;
        xd/=a;
        long double vf=xd*b*2;
        vf=vf*vf;
        vf/=(ll)2;
        vf/=xd;
        cout<<vf;
    }
    //Vf=Vo+at
    //Vf2=2ad
    //
}