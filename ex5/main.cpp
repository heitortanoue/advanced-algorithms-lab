#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

        int num, caseNum = 1;
        while (cin >> num, num != 0)
        {
            int bachelors = num;
            int spinsters;
            cin >> spinsters;

            vector<int> bachelors_list;
            for (int i = 0; i < bachelors; i++)
            {
                int bachelor;
                cin >> bachelor;
                bachelors_list.push_back(bachelor);
            }
            sort(bachelors_list.begin(), bachelors_list.end());


            for (int i = 0; i < spinsters; i++)
            {
                int spinster_age;
                cin >> spinster_age;
            }

            int left = bachelors - spinsters > 0 ? bachelors - spinsters : 0;
            int more_young = left > 0 ? bachelors_list[0] : 0;
        
            cout << "Case " << caseNum++ << ": ";
            if (left == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout << left << " " << more_young << "\n";
            }
        }
    

    return 0;
}
