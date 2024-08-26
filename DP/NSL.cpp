#include<bits/stdc++.h>
#define pb push_back
#define emp s.empty()
using namespace std;
int main(){
    int n;
    cout << "enter the length of array :\n";
    cin>>n;
    cout << "enter the array items :";
    int arr[n];
    vector<int> v;
    stack <int> s;
    
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
       
            while(s.size()!=0 && s.top()>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.pb(0);
            }else{
                v.pb(s.top());
            }
        
        s.push(arr[i]);
    }

    for(int i=0; i<n ;i++){
        cout<<v[i]<< " ";
    }
    cout << "\n";
    return 0;
}