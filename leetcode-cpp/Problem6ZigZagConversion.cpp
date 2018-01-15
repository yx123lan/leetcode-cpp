/**
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) {
			return s;
		}
		vector<vector<char>> charArray;
		int i = 1;
		int used = 0;
		for (;; i++) {
			vector<char> bucket(numRows, '0');
			int index = (i - 1) % (numRows - 1);
			if (i == 1 || index == 0) {
				int count = 0;
				while (count < numRows && used < s.size()) {
					bucket[count++] = s[used++];
				}
			}
			else {
				bucket[numRows - index - 1] = s[used++];
			}
			charArray.insert(charArray.end(), bucket);
			if (used >= s.size()) {
				break;
			}
		}
		string newStr;
		for (int i = 0; i<numRows; i++) {
			for (int j = 0; j<charArray.size(); j++) {
				char word = charArray[j][i];
				if (word != '0') {
					newStr.insert(newStr.size(), 1, word);
				}
			}
		}
		return newStr;
	}
};