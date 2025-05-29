#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

    void build(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            update(i + 1, arr[i]);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    FenwickTree tree(arr.size());
    tree.build(arr);

    cout << tree.query(3) << endl;
    tree.update(2, 2);
    cout << tree.query(3) << endl;

    return 0;
}
