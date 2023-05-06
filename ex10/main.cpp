#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int left, right;
        cin >> left >> right;
        int min_num = *min_element(nums.begin() + left, nums.begin() + right + 1);
        cout << min_num << endl;
    }
    return 0;
}
