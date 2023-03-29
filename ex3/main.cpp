#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (true)
    {
        // Initialize a studentsionary with keys as project names and values as set of userids
        unordered_map<string, string> students; // student -> project
        unordered_set<string> not_allowed;
        unordered_map<string, int> count;

        // Read the input until a line starts with "1"
        string line;
        string last_project;
        while (getline(cin, line) && line[0] != '1')
        {
            if (line[0] == '0')
            {
                return 0;
            }

            // If the line starts with a capital letter, it is a project name
            if (line[0] >= 'A' && line[0] <= 'Z')
            {
                last_project = line;
                count[last_project] = 0;
                continue;
            }

            if (not_allowed.count(line))
            {
                continue;
            }

            // If the name is an userid and its already signed up, remove it from the project
            string project = students[line];
            if (project != "" && project != last_project)
            {
                not_allowed.insert(line);
                continue;
            }

            // Else, add the userid to the project
            students[line] = last_project;
        }

        // Count the number of students in each project
        for (auto &p : students)
        {
            if (!not_allowed.count(p.first))
            {
                count[p.second]++;
            }
        }

        vector<pair<int, string>> res;
        for (auto &p : count)
        {
            res.push_back({p.second, p.first});
        }

        // Sort the projects by number of students in descending order
        sort(res.begin(), res.end(), [](pair<int, string> &a, pair<int, string> &b)
             {
             if(a.first != b.first) return a.first>b.first;
             return a.second<b.second; });

        for (auto it = res.begin(); it != res.end(); it++)
        {
            cout << it->second.substr(0, it->second.length() - 1) << " " << it->first << endl;
        }
    }

    return 0;
}
