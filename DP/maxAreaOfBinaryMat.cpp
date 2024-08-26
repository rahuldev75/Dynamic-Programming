#include<bits/stdc++.h>
#define pb push_back
 using namespace std;
 int MAH(int arr[], int n){

    vector<int> vl(n), vr(n), v(n);
    stack<pair<int, int>> s;
    

    



     // Find nearest smaller to the left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            vl[i] = -1;
        } else {
            vl[i] = s.top().second;
        }
        s.push({arr[i], i});
    }

    // Clear the stack for reuse
    while (!s.empty()) {
        s.pop();
    }

    // Find nearest smaller to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            vr[i] = n;
        } else {
            vr[i] = s.top().second;
        }
        s.push({arr[i], i});
    }
    while (!s.empty()) {
        s.pop();
    }

    // Calculate the maximum area
    int max_area = INT_MIN; // Initialize to smallest possible value
    for (int i = 0; i < n; i++) {
        int width = vr[i] - vl[i] - 1;
        int area = width * arr[i];
        max_area = max(max_area, area);
    }

    return max_area;


 }

 int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    int h[m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int j=0;j<m;j++){
        h[j]=arr[0][j];
    }
    int mx=MAH(h,m);

    h[m]={0};
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                h[j]=0;
            }else{
                h[j]=h[j]+1;
            }
        }
        mx=max(MAH(h,m),mx);
    }
    cout<<mx<<endl;
    return 0;
    
}