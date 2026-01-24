#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)p[i]=i;
        for(int i=2;i<n;i+=2)swap(p[i],p[i+1]);
        if(n%2&&n>3)swap(p[1],p[n-2]);
        for(int i=1;i<=n;i++)cout<<p[i]<<" ";
        cout<<"\n";
    }
    return 0;
}