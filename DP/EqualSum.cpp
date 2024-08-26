#include<iostream>
using namespace std;
//without a table of order (n+1 x sum +1) 
bool subset(int arr[], int n, int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]>sum){
        return subset(arr,n-1,sum);
    }else{
        return subset(arr,n-1,sum-arr[n-1]) || subset(arr,n-1,sum);
    }
}

bool equalsum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2 !=0 || n==1){
        return false;
    }else if(sum%2==0){
        return subset(arr, n, sum/2);
    }
}

int main(){
    int arr[5]={2,5,7};
    int n=3;
    if(equalsum(arr,n)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}