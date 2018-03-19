class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size == 0) {
			return "";
		}
		string first = strs[0];
		int longest = first.length();
		for (int i = 1; i<size; i++) {
			string str = strs[i];
			int j = 0;
			for (; j<first.length() && j<str.length() && first[j] == str[j]; j++) {

			}
			if (j < longest) {
				longest = j;
			}
		}
		return first.substr(0, longest);
	}
};