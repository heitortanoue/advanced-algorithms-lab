#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Two priority queues (heaps) to store the smaller and larger halves of the input numbers
    priority_queue<long long> max_heap;                                        // to store the smaller half of the input numbers
    priority_queue<long long, vector<long long>, greater<long long>> min_heap; // to store the larger half of the input numbers

    long long n; // current input number
    while (cin >> n)
    { // read input until end of file
        // Insert current number into the appropriate heap based on its value compared to the top of the max heap
        if (max_heap.empty() || n < max_heap.top())
        {
            max_heap.push(n);
        }
        else
        {
            min_heap.push(n);
        }

        // Balance the sizes of the heaps if necessary by moving the top element from one heap to the other
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        int size = max_heap.size() + min_heap.size(); // total size of the two heaps

        // Calculate and output the median based on the sizes and top elements of the two heaps
        if (size % 2 == 0)
        {
            // If the total size is even, take the average of the two middle values
            long long median = (max_heap.top() + min_heap.top()) / 2;
            cout << median << endl;
        }
        else
        {
            // If the total size is odd, the median is simply the top element of the max heap
            cout << max_heap.top() << endl;
        }
    }

    return 0;
}
