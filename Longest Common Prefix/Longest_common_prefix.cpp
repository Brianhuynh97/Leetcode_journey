#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Check for empty input vector
        if (strs.empty()) return "";

        int n = strs.size();
        // Outer loop to iterate over characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            // Inner loop to compare the current character with other strings
            for (int j = 1; j < n; ++j) {
                // Check if the current string is shorter or characters don't match
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    // Return the common prefix up to this point
                    return strs[0].substr(0, i);
                }
            }
        }
        // If no mismatches found, return the first string
        return strs[0];
    }
};
