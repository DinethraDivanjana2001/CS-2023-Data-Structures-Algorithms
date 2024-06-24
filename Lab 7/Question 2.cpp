#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

int cookies(int k, vector<int> A) {
    // Initialize a min-heap with sweetness values of the cookies
    priority_queue<int, vector<int>, greater<int>> min_heap(A.begin(), A.end());

    // Variable to count the number of operations
    int operations = 0;

    // Continue the loop until either the sweetness threshold 'k' is reached or there's only one cookie left in the heap
    while (min_heap.size() > 1 && min_heap.top() < k) {
        // Extract the sweetness levels of the two least sweet cookies
        int least_sweet1 = min_heap.top();
        min_heap.pop();
        int least_sweet2 = min_heap.top();
        min_heap.pop();
        
        // Combine the two least sweet cookies to create a new cookie
        int new_cookie = least_sweet1 + 2 * least_sweet2;
        min_heap.push(new_cookie); // Add the new cookie to the heap
        
        operations++; // Increment the number of operations
    }
    
    // Check if the desired sweetness threshold is reached
    if (min_heap.top() >= k) {
        return operations; // Return the number of operations
    } else {
        return -1; // Return -1 if it's not possible to reach the sweetness threshold
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

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
