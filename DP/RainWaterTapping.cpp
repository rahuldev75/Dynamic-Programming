#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],mxl[n],mxr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mxl[0]=arr[0];
    mxr[n-1]=arr[n-1];
    //max of Left
    for(int i=1;i<n;i++){
        if(arr[i]>mxl[i-1]){
            mxl[i]=arr[i];
        }else{
            mxl[i]=mxl[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(mxr[n-1]<arr[i]){
            mxr[i]=arr[i];
        }else{
            mxr[i]=mxl[i+1];
        }
    }
    int s=0;
    for(int i=0;i<n;i++){
        s+=(min(mxr[i],mxl[i])-arr[i]);
    }
    cout<<s<<endl;
    return 0;
}