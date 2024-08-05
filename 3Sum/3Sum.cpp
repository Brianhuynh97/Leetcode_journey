#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
      // Avoid duplicates for the first element
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1, right = nums.size() - 1;

      while (left < right)
      {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0)
        {
          result.push_back({nums[i], nums[left], nums[right]});

          // Avoid duplicates for the second element
          while (left < right && nums[left] == nums[left + 1])
            left++;

          // Avoid duplicates for the third element
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        }
        else if (sum < 0)
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> results = solution.threeSum(nums);
  cout << "The unique triplets that sum up to zero are: " << endl;
  for (const auto &result : results)
  {
    for (int num : result)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
