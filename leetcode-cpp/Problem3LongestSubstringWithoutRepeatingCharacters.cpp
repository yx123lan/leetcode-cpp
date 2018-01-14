/**
* Given a string, find the length of the longest substring without repeating characters.
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 0) {
			return 0;
		}
		unordered_map<char, int> map;
		int max = 0;
		int index = -1;
		for (int i = 0; i<s.size(); i++) {
			auto iterator = map.find(s[i]);
			if (iterator != map.end()) {
				index = iterator->second > index ? iterator->second : index;
			}
			map[s[i]] = i;
			max = (i - index) > max ? (i - index) : max;
		}
		return max;
	}
};