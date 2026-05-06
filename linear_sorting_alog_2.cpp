#include <iostream>
using namespace std;
// ---------- QUICK SORT ----------
#define MAX 7
int qArr[MAX] = {4,6,3,2,1,9,7};
void displayQuick() {
    cout << "[ ";
    for(int i = 0; i < MAX; i++) {
        cout << qArr[i] << " ";
    }
    cout << "]\n";
}
void swapQ (int i, int j) {
    int temp = qArr[i];
    qArr[i] = qArr[j];
    qArr[j] = temp;
}
int partition (int left, int right) {
    int pivot = qArr[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(qArr[j] <= pivot) {
            i++;
            swapQ(i, j);
        }
    }
    swapQ(i + 1, right);
    return i + 1;
}
void quickSort(int left, int right) {
    if(left < right) {
        int p = partition(left, right);
        quickSort(left, p - 1);
        quickSort(p + 1, right);
    }
}
// ---------- MERGE SORT ----------
#define M 10
int mArr[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int temp[11];
void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high) {
        if(mArr[i] <= mArr[j])
            temp[k++] = mArr[i++];
        else
            temp[k++] = mArr[j++];
    }
    while(i <= mid)
        temp[k++] = mArr[i++];
    while(j <= high)
        temp[k++] = mArr[j++];
    for(i = low; i <= high; i++)
        mArr[i] = temp[i];
}
void mergeSort(int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}
void displayMerge() {
    for(int i = 0; i <= M; i++)
        cout << mArr[i] << " ";
    cout << endl;
}
// ---------- MAIN FUNCTION ----------
int main() {
    int choice;
    cout << "Choose Sorting Algorithm:\n";
    cout << "1. Quick Sort\n";
    cout << "2. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "\nQuick Sort Selected\n";
            cout << "Before Sorting: ";
            displayQuick();
            quickSort(0, MAX - 1);
            cout << "After Sorting: ";
            displayQuick();
            break;
        case 2:
            cout << "\nMerge Sort Selected\n";
            cout << "Before Sorting: ";
            displayMerge();
            mergeSort(0, M);
            cout << "After Sorting: ";
            displayMerge();
            break;
        default:
            cout << "Invalid choice!";
    }
    return 0;
}
