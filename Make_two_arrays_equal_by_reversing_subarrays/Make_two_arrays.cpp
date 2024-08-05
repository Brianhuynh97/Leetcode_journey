#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        map<int, int> counter;

        // Count elements in the target array
        for (int e : target)
        {
            counter[e] += 1;
        }

        // Check elements in the arr array
        for (int e : arr)
        {
            // If element not found in the counter map, return false
            if (counter.find(e) == counter.end())
            {
                return false;
            }
            counter[e] -= 1;
            // If count reaches zero, remove the element from the map
            if (counter[e] == 0)
            {
                counter.erase(e);
            }
        }

        // If all elements are matched, the map should be empty
        return counter.empty();
    }
};

int main()
{
    Solution solution;
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};

    if (solution.canBeEqual(target, arr))
    {
        cout << "The arrays can be made equal by reversing subarrays." << endl;
    }
    else
    {
        cout << "The arrays cannot be made equal by reversing subarrays." << endl;
    }

    return 0;
}
