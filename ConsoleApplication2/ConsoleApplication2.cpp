// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LinkedListNode {
public:
	int val;
	LinkedListNode *next;

	LinkedListNode(int node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
	if (head == NULL) {
		head = new LinkedListNode(val);
		tail = head;
	}
	else {
		LinkedListNode *node = new LinkedListNode(val);
		tail->next = node;
		tail = tail->next;
	}
	return tail;
}
/*
* Complete the function below.
*/
/*
For your reference:
LinkedListNode {
int val;
LinkedListNode *next;
};
*/
LinkedListNode* removeNodes(LinkedListNode* list, int x) {

	if (list == NULL)
		return NULL;
	else {
		LinkedListNode* pNode = list;
		LinkedListNode* pNodeToDel = NULL;

		if (pNode->val > x) {
			pNodeToDel = pNode;
			pNode = pNode->next;
			delete pNodeToDel;
			return removeNodes(pNode, x);
		}
		else {
			pNode->next = removeNodes(pNode->next, x);
			return pNode;
		}
	}
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	LinkedListNode* res;

	int _list_size = 0;
	int _list_item;
	LinkedListNode* _list = NULL;
	LinkedListNode* _list_tail = NULL;
	cin >> _list_size;
	int _list_i;
	for (_list_i = 0; _list_i < _list_size; _list_i++) {
		cin >> _list_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (_list_i == 0) {
			_list = _insert_node_into_singlylinkedlist(_list, _list_tail, _list_item);
			_list_tail = _list;
		}
		else {
			_list_tail = _insert_node_into_singlylinkedlist(_list, _list_tail, _list_item);
		}
	}

	int _x;
	cin >> _x;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	res = removeNodes(_list, _x);
	while (res != NULL) {
		fout << res->val << endl;

		res = res->next;
	}

	fout.close();
	return 0;
}

