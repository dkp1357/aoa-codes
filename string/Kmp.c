#include <stdio.h>
#include <string.h>

// Function to compute LPS array
void computeLPS(char *pattern, int M, int *lps) {
    int length = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0)
                length = lps[length - 1]; // fall back
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern searching
void KMPSearch(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M];
    computeLPS(pattern, M, lps); // Preprocess the pattern

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Look for next match
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1]; // Fall back in pattern
            else
                i++; // Move to next char in text
        }
    }
}

// Main function
int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMPSearch(pattern, text);
    return 0;
}
