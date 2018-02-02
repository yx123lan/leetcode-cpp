/*
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> signMap = {
			{ "M", 1000 },
			{ "CM", 900 },
			{ "D", 500 },
			{ "CD", 400 },
			{ "C", 100 },
			{ "XC", 90 },
			{ "L", 50 },
			{ "XL", 40 },
			{ "X", 10 },
			{ "IX", 9 },
			{ "V", 5 },
			{ "IV", 4 },
			{ "I", 1 }
		};
		int number = 0;
		int stringIndex = 0;
		for (;;) {
			if (stringIndex + 2 <= s.size()) {
				auto find = signMap.find(s.substr(stringIndex, 2));
				if (find != signMap.end()) {
					stringIndex += 2;
					number += find->second;
					continue;
				}
			}
			if (stringIndex + 1 <= s.size()) {
				auto find = signMap.find(s.substr(stringIndex, 1));
				if (find != signMap.end()) {
					stringIndex += 1;
					number += find->second;
				}
			}
			else {
				break;
			}
		}
		return number;
	}

};