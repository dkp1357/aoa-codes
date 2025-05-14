#include <stdio.h>
#include <stdlib.h>

struct item
{
	int p, w;
	double ppw; // price per weight
};

int main()
{
	int n;
	printf("Enter number of items: ");
	scanf("%d", &n);

	struct item items[n];
	
	// struct item* items = NULL;
    // items = (struct item*)malloc(sizeof(struct item) * n); 

	// price
	printf("Enter prices: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &items[i].p);
	}
	
	// weights
	printf("Enter weights: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &items[i].w);
	}

	int m;
	printf("Enter knapsack capacity: ");
	scanf("%d", &m);

	// calculate price per weight
	for (int i = 0; i < n; i++) {
		items[i].ppw = items[i].p / (double)(items[i].w);
	}

	// sort in descending order of ppw
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (items[i].ppw < items[j].ppw) {
				// swap item i and item j
				struct item temp = items[i];
				items[i] = items[j];
				items[j] = temp;
			}
		}
	}

	// store ratio
	int ratio[n];

	// apply fractional knapsack
	double totalProfit = 0.0;
	for (int i = 0; i < n; ++i) {
		if (m == 0) break;
		
		if (items[i].w <= m) {
			// take full item
			totalProfit += items[i].p;
			m -= items[i].w;
		} else {
			// take fractional part
			totalProfit += items[i].ppw * m;
			m = 0;
		}
	}

	printf("Maximum profit: %f\n", totalProfit);
	
	free(items);
	return 0;
}
