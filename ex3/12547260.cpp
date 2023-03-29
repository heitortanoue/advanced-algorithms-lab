#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    while (true)
    {
        // Initialize a dictionary with keys as project names and values as set of userids
        map<string, set<string>> projects; // project -> students
        map<string, string> students;      // student -> project
        priority_queue<pair<int, string>> pq;

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
                projects[last_project] = set<string>();
                continue;
            }

            // If the name is an userid and its already signed up, remove it from the project
            string project = students[line];
            if (project != "" && project != last_project)
            {
                projects[project].erase(line);
                continue;
            }

            // Else, add the userid to the project
            students[line] = last_project;
            projects[last_project].insert(line);
        }

        // Add the projects to the priority queue
        for (auto project : projects)
        {
            pq.push(make_pair(project.second.size(), project.first));
        }

        // Print the output (NAME_OF_PROJECT NUMBER_OF_STUDENTS)
        while(!pq.empty())
        {
            pair<int, string> project = pq.top();
            pq.pop();
            cout << project.second.substr(0, project.second.length() - 1) << " " << project.first << endl;
        }
    }
}
