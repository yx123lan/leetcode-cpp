/*
* Given an integer, convert it to a roman numeral.
* Input is guaranteed to be within the range from 1 to 3999. 
*/
class Solution {
public:
	string intToRoman(int num) {
		vector<pair<string, int>> signArray = {
			pair<string, int>("M", 1000),
			pair<string, int>("CM", 900),
			pair<string, int>("D", 500),
			pair<string, int>("CD", 400),
			pair<string, int>("C", 100),
			pair<string, int>("XC", 90),
			pair<string, int>("L", 50),
			pair<string, int>("XL", 40),
			pair<string, int>("X", 10),
			pair<string, int>("IX", 9),
			pair<string, int>("V", 5),
			pair<string, int>("IV", 4),
			pair<string, int>("I", 1)
		};
		string roman;
		for (auto it = signArray.begin(); it != signArray.end(); it++) {
			while ((num - it->second) >= 0) {
				num -= it->second;
				roman.append(it->first);
			}
		}
		return roman;
	}
};