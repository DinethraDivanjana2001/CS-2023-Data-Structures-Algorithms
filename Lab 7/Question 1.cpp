#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) { // Insert an element
            int val;
            cin >> val;
            min_heap.push(val);
        } else if (type == 2) { // Delete an element
            int val;
            cin >> val;
            
            // Find the position of the element to be deleted
            priority_queue<int, vector<int>, greater<int>> temp; // Temporary min-heap
            while (!min_heap.empty()) {
                int top = min_heap.top();
                min_heap.pop();
                if (top != val) {
                    temp.push(top);
                }
            }
            
            // Rebuild the original min-heap without the deleted element
            while (!temp.empty()) {
                min_heap.push(temp.top());
                temp.pop();
            }
        } else if (type == 3) { // Print the minimum value
            cout << min_heap.top() << endl;
        }
    }
    
    return 0;
}
