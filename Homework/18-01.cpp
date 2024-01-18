#include "List.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	List<int>* head = nullptr; // new List<int>(7);
	//List<int>::prepend(head, new List<int>(8));
	for (int i = 2; i > 0; i -= 1) {
		List<int>::prepend(head, new List<int>(i));
		cout << (*head);
	}
	head->remove(2);
	List<int>* me = head;
	cout << "Found! \n";
	cout << (*me);
	me = head->searchParent(100);
	return 0;

}
