#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ---------------- COUNTING SORT ----------------
void countingSort() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = 8;
    int k = 5; // maximum element
    int count[6] = {0};
    int output[8];
    // Step 1: Count frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    // Step 2: Cumulative count
    for (int i = 1; i <= k; i++)
        count[i] = count[i] + count[i - 1];
    // Step 3: Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // Step 4: Copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    cout << "Sorted array using Counting Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// ---------------- RADIX SORT ----------------
void countSort(int arr[], int n, int pos) {
    int output[100];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / pos) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort() {
    int arr[] = {236, 15, 333, 27, 9, 108, 76, 498};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int pos = 1; max / pos > 0; pos *= 10)
        countSort(arr, n, pos);
    cout << "Sorted array using Radix Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// ---------------- BUCKET SORT ----------------
void bucketSort() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<float> bucket[n];
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[k++] = bucket[i][j];
    cout << "Sorted array using Bucket Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// ---------------- MAIN FUNCTION ----------------
int main() {
    int choice;
    do {
    cout << "\nSorting Algorithms Menu\n";
    cout << "1. Counting Sort\n";
    cout << "2. Radix Sort\n";
    cout << "3. Bucket Sort\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            countingSort();
            break;
        case 2:
            radixSort();
            break;
        case 3:
            bucketSort();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
   }
    } while (choice != 4);
    return 0;
}
