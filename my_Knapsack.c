#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WEIGHT 20
#define NUM_ITEMS 5

int knapSack(int weights[], int values[], bool selected_bool[]) {
    int dp[NUM_ITEMS + 1][MAX_WEIGHT + 1];

    for (int i = 0; i <= NUM_ITEMS; i++) {
        for (int w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]]) > dp[i - 1][w] ? values[i - 1] + dp[i - 1][w - weights[i - 1]] : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int res = dp[NUM_ITEMS][MAX_WEIGHT];
    int w = MAX_WEIGHT;
    for (int i = NUM_ITEMS; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            selected_bool[i - 1] = true;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return dp[NUM_ITEMS][MAX_WEIGHT];
}

int main() {
    char items[NUM_ITEMS];
    int weights[NUM_ITEMS];
    int values[NUM_ITEMS];
    bool selected_bool[NUM_ITEMS] = {false};
    char result[NUM_ITEMS];


    for(int i = 0; i < NUM_ITEMS; i++){
        scanf(" %c %d %d", &items[i], &values[i], &weights[i]);
    }

    // Find the maximum value
    int max_value = knapSack(weights, values, selected_bool);

    int result_count = 0;

    // Store selected items in the result array
    for(int i = 0; i < NUM_ITEMS; i++) {
        if (selected_bool[i]) {
            result[result_count++] = isupper(items[i])? toupper(items[i]) : tolower(items[i]);
        }
    }
    // Print selected items and maximum value
    printf("Maximum profit: %d\n", max_value);
    printf("Selected items:");
    for(int i = 0; i < result_count; i++){
        printf(" %c", result[i]);
    }
    return 0;
}
