/**
* Given a 32-bit signed integer, reverse digits of an integer.
*/
class Solution {
public:
	const int signBit = 0x80000000;

	int reverse(int x) {
		return reverseNumber(x, 0);
	}
	int reverseNumber(int x, int total) {
		if (x == 0) {
			return total;
		}
		int up = total * 10;
		int lower = x % 10;
		int newTotal = up + lower;
		if (up != 0 && (up / 10 != total || up & signBit != newTotal & signBit)) {
			return 0;
		}
		return reverseNumber(x / 10, newTotal);
	}
};