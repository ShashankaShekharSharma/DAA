#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find and print LCS
void printLCS(string a, string b) {
    int m = a.length();
    int n = b.length();

    // Create a DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS from the DP table
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs = a[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Output the result
    cout << "Length of LCS: " << dp[m][n] << endl;
    cout << "LCS: " << lcs << endl;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    printLCS(s1, s2);

    return 0;
}
