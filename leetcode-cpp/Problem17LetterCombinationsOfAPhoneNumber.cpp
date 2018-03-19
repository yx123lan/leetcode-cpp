class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> outputList;
		if (digits == "") {
			return outputList;
		}
		unordered_map<char, vector<string>> charMap;
		charMap.insert(pair<char, vector<string>>('2', vector<string>{"a", "b", "c"}));
		charMap.insert(pair<char, vector<string>>('3', vector<string>{"d", "e", "f"}));
		charMap.insert(pair<char, vector<string>>('4', vector<string>{"g", "h", "i"}));
		charMap.insert(pair<char, vector<string>>('5', vector<string>{"j", "k", "l"}));
		charMap.insert(pair<char, vector<string>>('6', vector<string>{"m", "n", "o"}));
		charMap.insert(pair<char, vector<string>>('7', vector<string>{"p", "q", "r", "s"}));
		charMap.insert(pair<char, vector<string>>('8', vector<string>{"t", "u", "v"}));
		charMap.insert(pair<char, vector<string>>('9', vector<string>{"w", "x", "y", "z"}));
		vector<vector<string>> latterList;
		for (int i = 0; i<digits.size(); i++) {
			auto it = charMap.find(digits[i]);
			if (it != charMap.end()) {
				latterList.push_back(it->second);
			}
		}
		insertNumber(outputList, "", latterList, 0);
		return outputList;
	}

	void insertNumber(vector<string>& outputList, string latter, vector<vector<string>>& latterList, int index) {
		if (index >= latterList.size()) {
			outputList.push_back(latter);
			return;
		}
		vector<string> charList = latterList[index];
		for (auto c : charList) {
			insertNumber(outputList, latter + c, latterList, index + 1);
		}
	}
};