#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<char>> A,B;
ll n;
vector<vector<char>> rotate90(vector<vector<char>> V){
    vector<vector<char>> ans(n);
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            ans[i].push_back(V[j][i]);
        }
    }
    return ans;
}
ll dif(vector<vector<char>> V){
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(V[i][j]!=B[i][j]){
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<char> XD;
        for(auto x:s){
            XD.push_back(x);
        }
        A.push_back(XD);
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<char> XD;
        for(auto x:s){
            XD.push_back(x);
        }
        B.push_back(XD);
    }
    ll ans=dif(A);
    A=rotate90(A);
    ans=min(ans,dif(A)+1);
    A=rotate90(A);
    ans=min(ans,dif(A)+2);
    A=rotate90(A);
    ans=min(ans,dif(A)+3);
    cout<<ans;
}