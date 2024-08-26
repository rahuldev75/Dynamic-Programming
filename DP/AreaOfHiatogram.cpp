#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vl(n), vr(n), v(n);
    stack<pair<int, int>> s;
    int arr[100000];
    arr[0]=0;
    arr[n+1]=0;

    for (int i = 1; i < n+1; i++) {
        cin >> arr[i];
    }
    n=n+2;

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

    // Calculate the maximum area
    int max_area = INT_MIN; // Initialize to smallest possible value
    for (int i = 0; i < n; i++) {
        int width = vr[i] - vl[i] - 1;
        int area = width * arr[i];
        max_area = max(max_area, area);
    }

    cout << max_area << endl;
    return 0;
}
