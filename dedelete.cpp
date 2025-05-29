#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};
    vector<string> commands = {"pop_front", "pop_back", "pop_front"};

    for (string cmd : commands) {
        if (cmd == "pop_front" && !dq.empty()) {
            dq.pop_front();
        } else if (cmd == "pop_back" && !dq.empty()) {
            dq.pop_back();
        }
    }

    cout << "Final deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
