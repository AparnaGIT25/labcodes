#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

// comparison by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // sort in descending order
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // sort by ratio
    sort(arr, arr + n, cmp);

    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        // if item can be fully taken
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } 
        // take fraction
        else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;  // knapsack full
        }
    }
    return finalValue;
}

int main() {
    int n = 3;
    int W = 50;
    Item arr[] = {{10, 60}, {20, 100}, {30, 120}};

    cout << "Maximum value in Knapsack = " 
         << fractionalKnapsack(W, arr, n);

    return 0;
}
