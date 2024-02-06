#include <stdio.h>
#include <stdbool.h>

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
    int weights[NUM_ITEMS]; // weights of items A, B, C, D, E
    int values[NUM_ITEMS]; // values of items A, B, C, D, E
    bool selected_bool[NUM_ITEMS] = {false};
    char result[NUM_ITEMS];

    for(int i = 0; i < NUM_ITEMS; i++){
        scanf(" %d", &values[i]);
    }
    for(int i = 0; i < NUM_ITEMS; i++){
        scanf(" %d", &weights[i]);
    }

    // Find the maximum value
    int max_value = knapSack(weights, values, selected_bool);

    int result_count = 0;

    // Store selected items in the result array
    for(int i = NUM_ITEMS - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            result[result_count++] = 'A' + i;
        }
    }
    // Print selected items and maximum value
    printf("Maximum profit: %d\n", max_value);
    printf("Items that give the maximum profit: [");
    for(int i = 0; i < result_count; i++){
        if (i > 0) {
            printf(", ");
        }
    //for(int i = result_count - 1; i >= 0; i--) {
        printf("%c", result[i]);
        
    }
    printf("]\n");

    return 0;
}

