#include<bits/stdc++.h>
#define pb push_back
#define emp s.empty()
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> v;
    stack <int> s;
    
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
         while(s.size()!=0 && s.top()>=arr[i]){
                s.pop();}
        if(emp){
            v.pb(0);
        }else v.pb(s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());

    for(int i=0; i<n ;i++){
        cout<<v[i]<<endl;
    }
    return 0;
}