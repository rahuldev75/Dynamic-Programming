#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    vector<int> v;
    stack<int> s;
    int arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.pb(-1);
        }else if(s.size()>0 && s.top()>arr[i]){
            v.pb(s.top());
        }else if(s.size()>0 && s.top()<=arr[i]){
            while(s.size()>0 && s.top()<=arr[i]){
                s.pop();
            }if(s.size()==0){
                v.pb(-1);
            }else{
                v.pb(s.top());
            }
        }s.push(arr[i]);

    }
    for(int i=n-1;i>=0;i--){
        cout<<v[i]<<endl;
    }
    
    return 0;
}