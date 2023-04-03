#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    int numCases, leftCases;
    cin >> numCases;
    leftCases = numCases;

    string line;
    for (int i = 0; i < numCases; i++)
    {
        int numJobs;
        cin >> numJobs;
        leftCases--;

        // jump blank line
        getline(cin, line);

        // [i, fine, time]
        vector<tuple<int, int, int>> jobs(numJobs);
        for (int j = 0; j < numJobs; j++)
        {
            int time, fine;
            cin >> time >> fine;
            jobs[j] = {j + 1, time, fine};
        }

        // sort by fine/time ratio
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b)
             {
    int fta = get<2>(a) * get<1>(b);
    int ftb = get<2>(b) * get<1>(a);
    if (fta != ftb) {
        return fta > ftb;
    } else {
        return get<0>(a) < get<0>(b);
    } });

        cout << get<0>(jobs[0]);
        for (int i = 1; i < numJobs; i++)
        {
            // print the job number
            cout << " " << get<0>(jobs[i]);
        }
        cout << endl;

        // add blank line between cases
        if (leftCases > 0)
        {
            cout << endl;
        }
    }

    return 0;
}
