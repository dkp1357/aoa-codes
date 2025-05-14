#include <stdio.h>

struct item {
    int p, w;
};

int max(int a, int b) {
	return (a > b) ? a: b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

	struct item items[n];

    printf("Enter prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].p);
    }

    printf("Enter weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].w);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

	// dp[i][w] represents the maximum value we can get using the first i items and capacity w
	int dp[n+1][W+1];

    // Fill the dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].w <= w)
				dp[i][w] = max(dp[i-1][w], items[i-1].p + dp[i-1][w-items[i-1].w]);
            else
				// items[i-1].w > w
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum profit: %d\n", dp[n][W]);

    // Backtracking to find which items were taken
    int res = dp[n][W];
    int w = W;
    printf("Items taken (profit weight):\n");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            // This item was included
            printf("p = %d w = %d\n", items[i - 1].p, items[i - 1].w);
            res -= items[i - 1].p;
            w -= items[i - 1].w;
        }
    }

    return 0;
}
