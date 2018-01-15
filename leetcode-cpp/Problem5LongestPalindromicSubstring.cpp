class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 1) {
			return s;
		}
		string charSequence("#");
		for (int i = 0; i<s.size(); i++) {
			charSequence.insert(charSequence.size(), 1, s[i]);
			charSequence.insert(charSequence.size(), 1, '#');
		}
		string subString;
		vector<int> strLength(charSequence.size(), 0);
		int position = 0;
		int maxRight = 0;
		for (int i = 0; i<charSequence.size(); i++) {
			int length = 1;
			if (i < maxRight) {
				length = min(strLength[position - (i - position)], maxRight - i); // 已经确定的回文长度
			}
			while (i - length >= 0 && i + length < charSequence.size() && charSequence[i - length] == charSequence[i + length]) {
				length += 1;
			}
			strLength[i] = length;

			int newRight = i + length - 1;
			if (newRight > maxRight) {
				maxRight = newRight;
				position = i;
			}
			if (length - 1 > subString.size()) {
				subString = s.substr((i - length + 1) / 2, length - 1);
			}
		}
		return subString;
	}
};