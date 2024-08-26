#include<bits/stdc++.h>
using namespace std;
int knap(int wt[], int val[], int w, int n,int t[102][1002]){
    if (n == 0 || w == 0) {
        return 0;
    }
    if (t[n][w] != -1) {
        return t[n][w];
    }
    if(wt[n-1]<=w){
        return t[n][w]= max(val[n-1]+knap(wt,val,w-wt[n-1],n-1,t), knap(wt,val,w,n-1,t));
    }
    else if(wt[n-1]>w){
        t[n][w]=knap(wt,val,w,n-1,t);   
    }
}

int main() {
    int t[102][1002];
    memset(t,-1,sizeof(t)); 
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    int n = sizeof(wt) / sizeof(wt[0]);

    int a = knap(wt, val, w, n,t);
    cout << a << endl;

    return 0;
}