/**
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Example
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return sum(l1, l2, 0);
	}

private:
	ListNode* sum(ListNode* l1, ListNode* l2, int carry) {
		int newVal = getNodeVal(l1) + getNodeVal(l2) + carry;
		ListNode* l1Next = getNextNode(l1);
		ListNode* l2Next = getNextNode(l2);
		ListNode* newNode = new ListNode(newVal % 10);
		if (l1Next == NULL && l2Next == NULL) {
			if (newVal / 10 > 0) {
				newNode->next = new ListNode(newVal / 10);
			}
		}
		else {
			newNode->next = sum(l1Next, l2Next, newVal / 10);
		}
		return newNode;
	}

	int getNodeVal(ListNode* node) {
		return node == NULL ? 0 : node->val;
	}

	ListNode* getNextNode(ListNode* node) {
		return node == NULL ? NULL : node->next;
	}
};