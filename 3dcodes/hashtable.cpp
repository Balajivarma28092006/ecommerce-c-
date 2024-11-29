#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    double weight, profit, ratio;
    Item(double w, double p) : weight(w), profit(p), ratio(p / w) {}
};

// Function to get maximum profit
double fractionalKnapsack(int num, vector<Item> &items, double capacity, vector<double> &fractions) {
    // Sort items by profit-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.ratio > b.ratio;
    });

    double maxProfit = 0.0;
    fractions.resize(num, 0.0); // Initialize fractions vector

    for (int i = 0; i < num && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            fractions[i] = 1.0;
            maxProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            fractions[i] = capacity / items[i].weight;
            maxProfit += items[i].profit * fractions[i];
            capacity = 0; // Backpack is full
        }
    }
    return maxProfit;
}

int main() {
    int num;
    cin >> num;

    vector<Item> items;
    for (int i = 0; i < num; i++) {
        double weight, profit;
        cin >> weight >> profit;
        items.emplace_back(weight, profit);
    }

    double capacity;
    cin >> capacity;

    vector<double> fractions;
    double maxProfit = fractionalKnapsack(num, items, capacity, fractions);

    // Output results
    cout << "Fractions: ";
    for (double fraction : fractions) {
        cout << fixed << setprecision(2) << fraction << " ";
    }
    cout << endl;

    cout << "Maximum profit is: " << fixed << setprecision(2) << maxProfit << endl;
    return 0;
}
