#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */
//int num =1;
int powerSum(int X, int N, int num=1) {
    // Calculate the value after subtracting the Nth power of the current number from X
    int val = X - pow(num, N);//100-1=99
    
    // If the value becomes negative, return 0 (no valid combination)
    if (val < 0) {
        return 0;
    } 
    // If the value becomes 0, return 1 (a valid combination is found)
    else if (val == 0) {
        return 1;
    } 
    // Otherwise, recursively call powerSum with updated X and the next natural number
    else {
        return powerSum(val, N, num + 1) + powerSum(X, N, num + 1);//(1,2,2)+(100,2,2)
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);
    cout << result << "\n";
    fout << result << "\n";

    fout.close();

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
