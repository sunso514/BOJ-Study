#include<bits/stdc++.h>
using namespace std;
const int m=1234567891;
int l;
int H(string a){
    long long hash=0,r=1;
    for(int i=0;i<l;i++){
        hash=(hash+(a[i]+1-'a')*r)%m;
        r=(r*31)%m;
    }
    return hash;
}
int main(){
    string s;
    cin>>l;
    cin>>s;
    cout<<H(s);
}