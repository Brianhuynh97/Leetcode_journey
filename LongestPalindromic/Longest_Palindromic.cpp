#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (s.empty())
      return "";
    int start = 0, maxLen = 1;

    for (int i = 0; i < s.length(); ++i)
    {
      // Odd-length palindromes (center at s[i])
      int len1 = expandAroundCenter(s, i, i);
      // Even-length palindromes (center between s[i] and s[i+1])
      int len2 = expandAroundCenter(s, i, i + 1);

      int len = max(len1, len2);
      if (len > maxLen)
      {
        maxLen = len;
        start = i - (len - 1) / 2; // Adjust start index based on palindrome length
      }
    }
    return s.substr(start, maxLen);
  }

private:
  // Helper function to expand around the center and return palindrome length
  int expandAroundCenter(const string &s, int left, int right)
  {
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
      --left;
      ++right;
    }
    return right - left - 1; // Length of the palindrome
  }
};
