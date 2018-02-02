/*
* Implement regular expression matching with support for '.' and '*'.
*/
class Solution {
public:
	bool isMatch(string s, string p) {

		return matchWord(s, p, 0, 0);
	}

	bool matchWord(string s, string p, int sPosition, int pPosition) {
		if (p.length() == pPosition) {
			return s.length() == sPosition;
		}
		if (p[pPosition + 1] != '*' || pPosition == p.length() - 1) {
			if (s.length() == sPosition || (s[sPosition] != p[pPosition] && p[pPosition] != '.')) {
				return false;
			}
			else {
				return matchWord(s, p, sPosition + 1, pPosition + 1);
			}
		}
		for (; sPosition < s.length() && (s[sPosition] == p[pPosition] || p[pPosition] == '.'); sPosition++) {
			if (matchWord(s, p, sPosition, pPosition + 2)) {
				return true;
			}
		}
		return  matchWord(s, p, sPosition, pPosition + 2);
	}
};