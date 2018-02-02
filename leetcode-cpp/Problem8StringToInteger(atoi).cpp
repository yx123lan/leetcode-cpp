/*
* Implement atoi to convert a string to an integer.
*/
class Solution {
public:
	int myAtoi(string str) {
		const char* cstring = str.c_str();
		bool start = false;
		bool minus = false;
		int length = str.length();
		int signBit = 0x80000000;
		int number = 0;
		for (int i = 0; i<length; i++) {
			char word = *cstring++;
			if ('0' <= word && '9' >= word) {
				if (!start) {
					start = true;
				}
				int up = number * 10;
				int lower = word - 48;
				int newNumber = minus ? up - lower : up + lower;
				if (up != 0 && (up / 10 != number || (newNumber & signBit) != (up & signBit))) {
					return minus ? INT_MIN : INT_MAX;
				}
				else {
					number = newNumber;
				}
			}
			else if (!start) {
				if (word == '-') {
					minus = true;
					start = true;
				}
				else if (word == '+') {
					minus = false;
					start = true;
				}
				else if (isspace(word)) {
					continue;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		return number;
	}
};