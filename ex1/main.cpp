#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    // Loop over each test case
    for (int t = 0; t < test_cases; t++)
    {
        int n, m;
        cin >> n >> m;

        // Create a queue of pairs (priority, job index) to store the jobs
        queue<pair<int, int>> q;

        // Create a priority queue to keep track of the highest priority
        priority_queue<int> pq;

        // Read the priorities of each job and push them onto both queues
        for (int i = 0; i < n; i++)
        {
            int priority;
            cin >> priority;
            q.push(make_pair(priority, i));
            pq.push(priority);
        }

        int time = 0;

        // Process the jobs in the queue until it is empty
        while (!q.empty())
        {
            // Get the job at the front of the queue
            pair<int, int> job = q.front();
            q.pop();

            // Check if the job has the highest priority
            if (job.first == pq.top())
            {
                // If so, remove the priority from the priority queue
                pq.pop();

                // Increment the time and check if this is the job we are looking for
                time++;
                if (job.second == m)
                {
                    cout << time << endl;
                    break;
                }
            }
            else
            {
                // If not, push the job back onto the queue
                q.push(job);
            }
        }
    }

    return 0;
}
