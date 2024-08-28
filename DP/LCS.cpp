

//Longest common subsequence
#include <iostream>
#include <string>
using namespace std;

int LCS(string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (x[n - 1] == y[m - 1]) {
        return 1 + LCS(x, y, n - 1, m - 1);
    } else {
        return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
    }
}

int main() {
    string x = "abcdgf";
    string y = "abedhfr";
    cout << LCS(x, y, x.length(), y.length()) << endl;
    return 0;
}