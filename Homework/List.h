#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List {
	T elem;
	List* next;
public:
	List(T useful) : elem(useful) { next = nullptr; }

	// List<int> *head = new List<int>(8);
	// (*head).prepend(new List(8));
	// head->prepend(new List(8))
	// 7->X   ������ �����: 8->7->X;

	static void prepend(List*& h, List* el) {
		// ���������, ��� el ��� ������!
		el->next = h;
		h = el;
	}
	/* ������ �������� ���� ����������������
	goto
	break
	continue
	*/


	List* search(T key) {
		List* p = this;
		while ((p != nullptr) && (p->elem != key)) {
			// � C++ ����������� "������� ����������": ���� � ������ ������ false,
			// ������ �� �����������!
			cout << (*p);
			cout << "My elem is " << p->elem << ", key is " << key << "\n";
			p = p->next;  // ����������� "�������" ��������� �� ��������� �������,
		}                 // ������� �������� � ���� next ���� �������, �� �������
		return p;         // p ��������� ������ - ������!
	}

	List* searchParent(T key) {
		List* p = this,
			* parent = nullptr;
		while ((p != nullptr) && (p->elem != key)) {
			cout << (*p);
			cout << "My elem is " << p->elem << ", key is " << key << "\n";
			parent = p;
			p = p->next;
		}
		return parent;
	}

	void remove(T key) {
		List* prev = searchParent(key);
		List* current = search(key);
		if (prev == nullptr) {
		}
		else {
			prev->next = current->next;
		}
		delete current;
		return;
	}

	template <typename T>
	friend ostream& operator<<(ostream& out, const List<T>& el) {
		out << el.elem << "->";
		if (el.next == nullptr) {
			out << "X\n";
		}
		else {
			out << (*el.next);
		}
		return out;
	}
};

