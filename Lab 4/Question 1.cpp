#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int p;
    cin >> n;
    vector<int> arr(n);
    vector<int> final_arr(n);
    vector<int> left_arr;
    vector<int> equal_arr;
    vector<int> right_arr;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    p = arr[0];
    equal_arr.push_back(p);

    for (int k = 1; k < n; k++) {
        if (arr[k] == p) {
            equal_arr.push_back(arr[k]);
        }
        else if (arr[k] < p) {
            left_arr.push_back(arr[k]);
        }
        else {
            right_arr.push_back(arr[k]);
        }
    }

    int l = 0;
    for (size_t j = 0; j < left_arr.size(); j++) {
        final_arr[l] = left_arr[j];
        l++;
    }
    for (size_t a = 0; a < equal_arr.size(); a++) {
        final_arr[l] = equal_arr[a];
        l++;
    }
    for (size_t b = 0; b < right_arr.size(); b++) {
        final_arr[l] = right_arr[b];
        l++;
    }

    // Output final_arr
    for (int i = 0; i < n; i++) {
        cout << final_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
