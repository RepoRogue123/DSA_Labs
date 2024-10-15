#include <bits/stdc++.h>
using namespace std;

#define pi 3.14

void display_matrix(int n, double arr[]) {
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
}

void sum(int n, double arr[]) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << fixed << setprecision(2) << sum << endl;
}

void max_min(int n, double arr[]) {
    double max_val = arr[0];
    double min_val = arr[0]; 

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }

        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    cout << fixed << setprecision(2) << max_val << endl;
    cout << fixed << setprecision(2) << min_val << endl;
}

int main() {
    int size1;
    cin >> size1;
    int lowerValue;
    cin >> lowerValue;
    int upperValue;
    cin >> upperValue;


    double difference = (double)(upperValue - lowerValue) / (size1 - 1);

    double arr[size1];
    for (int i = 0; i < size1; i++) {
        arr[i] = lowerValue + (difference * i);
    }

    vector<pair<double, double>> final_arr(size1 / 2);

    // Using your preferred loop logic
    for (int i = 0, j = 0; i < (size1) / 2 && j < size1; i++, j += 2) {
        final_arr[i].first = arr[j];
        final_arr[i].second = arr[j + 1];
    }

    double result[size1 / 2];
    for (int i = 0; i < size1 / 2; i++) {
        double volume = pi * (final_arr[i].first * final_arr[i].first) * final_arr[i].second;
        result[i] = volume;
    }

    display_matrix(size1 / 2, result);
    sum(size1 / 2, result);
    max_min(size1 / 2, result);

    return 0;
}
