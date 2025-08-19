#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//13. Roman to Integer: https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {

        int result = 0;

        unordered_map<char, int> romanMap = { {'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C',100},{'D', 500}, {'M', 1000} };

        for (int i = 0; i < s.length(); ++i) {
            if (((i + 1) < s.length()) && (romanMap[s[i + 1]] > romanMap[s[i]])) {
                result = result - romanMap[s[i]];
            }
            else
                result = result + romanMap[s[i]];
        }

        return result;
    }
};

int main()
{
    Solution solution;

    string test1 = "III";
    string test2 = "LVIII";
    string test3 = "MCMXCIV";

    cout << "Case 1: " << test1 << " = " << solution.romanToInt(test1) << endl;
    cout << "Case 2: " << test2 << " = " << solution.romanToInt(test2) << endl;
    cout << "Case 3: " << test3 << " = " << solution.romanToInt(test3) << endl;

    return 0;
}