#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    string s="wbwbwwbwbwbw";
    string p;
    for(int i=0;i<100;i++){
        p+=s;
    }
    for(int i=0;i<20;i++){
        ll white=0;
        ll black=0;
        for(int j=i;j<a+b+i;j++){
            if(p[j]=='w'){
                white++;
            }else{
                black++;
            }
        }
        if(white==a && black==b){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}