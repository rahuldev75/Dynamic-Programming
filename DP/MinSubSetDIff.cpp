#include<bits/stdc++.h>
using namespace std;

int mindif(int arr[], int n, int range) {
    bool t[n + 1][range + 1];
    memset(t, false, sizeof(t));
    
    for (int i = 0; i <= n; i++) {
        t[i][0] = true;
    }
    
    for (int j = 1; j <= range; j++) {
        t[0][j] = false;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= range; j++) {
            if (arr[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    int mn = INT_MAX;
    vector<bool> v;
    for (int j = 0; j <= range; j++) {
        v.push_back(t[n][j]);
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            mn = min(mn, abs(range - 2 * i));
        }
    }
    
    return abs(mn);
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int range = sum / 2;
    int a = mindif(arr, n, range);
    cout << a;
    return 0;
}