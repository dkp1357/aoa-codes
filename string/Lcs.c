#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return (a > b) ? a: b;
}

// Function to find and print the LCS
void printLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];

    // Step 1: Fill dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                // max of upar wala, peeche wala
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Step 2: Reconstruct LCS string by backtracking
    int index = dp[m][n]; // Length of LCS
    char lcs[index + 1];
    lcs[index] = '\0'; // Null terminate the LCS string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index - 1] = X[i - 1]; // Add current char to LCS
            i--;
            j--;
            index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    // Step 3: Output
    printf("LCS string: %s\n", lcs);
    printf("Length of LCS: %d\n", dp[m][n]);
}

// Main function
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    printLCS(X, Y);
    return 0;
}
