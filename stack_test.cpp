#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack<int> s;
    cout << "Empty? " << s.empty() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    try {
        s.pop(); s.pop(); s.pop(); s.pop();
    } catch (const underflow_error& e) {
        cout << "Caught error: " << e.what() << endl;
    }
}
