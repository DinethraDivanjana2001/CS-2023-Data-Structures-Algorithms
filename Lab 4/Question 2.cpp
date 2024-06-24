#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr_orig) {
    int result = INT_MAX;
    vector<int> sorted(arr_orig);
    sort(sorted.begin(), sorted.end());
    for (size_t rev = 0; rev < 2; rev++) {
        int curSwap = 0;
        if (rev) {
            reverse(sorted.begin(), sorted.end());
        }
        vector<int> arr(arr_orig);
        // Map to store value to position mapping
        unordered_map<int, size_t> valueToPosition;
        // Store the position of each element in the original array
        for (size_t i = 0; i < arr.size(); i++) {
            valueToPosition[arr[i]] = i;
        }
        // Iterate through the array to perform swaps
        for (size_t i = 0; i < arr.size(); i++) {
            // If the current element is already in its sorted position, continue
            if (arr[i] == sorted[i]) {
                continue;
            }
            // Swap the current element with its sorted counterpart
            int currentElement = arr[i];
            int sortedElement = sorted[i];
            swap(arr[i], arr[valueToPosition[sortedElement]]);
            curSwap++;
            // Update the position of the current element and sorted element in the map
            valueToPosition[currentElement] = valueToPosition[sortedElement];
            valueToPosition[sortedElement] = i;
        }
        // Update the result with the minimum number of swaps
        result = min(result, curSwap);
    }
    return result;
}
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
