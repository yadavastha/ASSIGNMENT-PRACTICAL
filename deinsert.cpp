#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);  
    dq.push_front(5);   
    dq.push_back(15);   

    cout << "Front: " << dq.front() << endl;  
    cout << "Back: " << dq.back() << endl;    

    dq.pop_front();  
    dq.pop_back();   

    cout << "After pops, front is: " << dq.front() << endl;

    return 0;
}
