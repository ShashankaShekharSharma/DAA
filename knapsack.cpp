#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    float weight, profit, ratio;
    int index;
};

// Comparator to sort items by profit/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    float capacity;

    cout << "Enter no. of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].index = i;
    }

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    // Sort by profit/weight ratio
    sort(items.begin(), items.end(), compare);

    cout << "\nSorted order:\n";
    for (auto item : items) {
        cout << "weight: " << item.weight
             << "  profit: " << item.profit
             << "  Profit/weight: " << item.ratio << endl;
    }

    float totalProfit = 0;
    float used[n] = {0};

    cout << "\nItems chosen:\n";
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            used[items[i].index] = 1;
        } else {
            float fraction = capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            used[items[i].index] = fraction;
            break; // Knapsack is full
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "weight: " << items[i].weight
             << "  profit: " << items[i].profit
             << "  Profit/weight: " << items[i].ratio
             << "  used: " << used[items[i].index] << endl;
    }

    cout << "\nTotal profit: " << totalProfit << endl;
    return 0;
}
