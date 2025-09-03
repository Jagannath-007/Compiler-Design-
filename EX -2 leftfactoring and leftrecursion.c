#include <stdio.h>
#include <string.h>

// Function to remove immediate left recursion
void removeLeftRecursion(char nonTerminal, char *productions[], int n) {
    int i;
    char alpha[10][10], beta[10][10];
    int alphaCount = 0, betaCount = 0;

    for (i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) { // Left recursive
            strcpy(alpha[alphaCount++], productions[i] + 1);
        } else {
            strcpy(beta[betaCount++], productions[i]);
        }
    }

    if (alphaCount == 0) {
        printf("%c -> ", nonTerminal);
        for (i = 0; i < n; i++) {
            printf("%s", productions[i]);
            if (i != n - 1) printf(" | ");
        }
        printf("\n");
    } else {
        printf("%c -> ", nonTerminal);
        for (i = 0; i < betaCount; i++) {
            printf("%s%c'", beta[i], nonTerminal);
            if (i != betaCount - 1) printf(" | ");
        }
        printf("\n");

        printf("%c' -> ", nonTerminal);
        for (i = 0; i < alphaCount; i++) {
            printf("%s%c' | ", alpha[i], nonTerminal);
        }
        printf("ε\n");
    }
}

int main() {
    char *productions[] = {"Aa", "b"};  // Example: A → Aa | b
    int n = 2;
    char nonTerminal = 'A';

    removeLeftRecursion(nonTerminal, productions, n);
    return 0;
}
