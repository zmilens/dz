// lab16zadanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "pch.h"
#include <iostream>

template<typename T>
class myTree {
	struct Node {
		T item;
		Node *son;
		Node *bro;

		Node(T i, Node *s = NULL, Node *b = NULL) {
			item = i;
			son = s;
			bro = b;
		}
	};
	Node *root;
public:
	myTree() {
		root = NULL;
	}
	~myTree() {
		Delete(root);
	}
	int GetHeight() {
		return GetHeight(root);
	}
	int GetNodesOnLevel(int level) {
		return GetNodesOnLevel(root, level);
	}
	void add(const T &elem) {
		add(root, elem);
	}
private:
	void add(Node *&node, const T &elem);
	void Delete(Node *node);
	int GetHeight(Node *node);
	int GetNodesOnLevel(Node *node, int level);
};
int main() {
	myTree<int> tree;
	int n, a;
	std::cout << "Count" << std::endl;
	std::cin >> n;
	int *m = new int[n];
	std::cout << std::endl << "Elements" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		tree.add(a);
		m[i] = a;
	}
	std::cout << std::endl << "Tree" << std::endl;
	int t = 0, temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (m[j] < m[j + 1]) {
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
	t = 0;
	int **b = new int*[tree.GetHeight()];
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		b[i] = new int[tree.GetNodesOnLevel(i) + 1];
	}
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		for (int j = 1; j < tree.GetNodesOnLevel(i) + 1; j++) {
			b[j][i] = m[t];
			t++;
		}
	}
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		for (int j = 1; j < tree.GetNodesOnLevel(i); j++) {
			if (b[j][i] > b[j + 1][i]) {
				t = b[j][i];
				b[j][i] = b[j + 1][i];
				b[j + 1][i] = t;
			}
		}
	}
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		for (int j = 1; j < tree.GetNodesOnLevel(i) + 1; j++) {
			std::cout << b[j][i] << '\t';
		}
		std::cout << std::endl;
	}


	/*t = 1; int temp2 = 0,temp3=0;
	while (t != tree.GetHeight()) {
		for (int i = 0; i < tree.GetNodesOnLevel(t); i++) {
			for (int j = temp2; j < temp2+tree.GetNodesOnLevel(t)-i-1; j++) {
				if ((m[j] > m[j + 1])&&(j<n)) {
					temp = m[j];
					m[j] = m[j + 1];
					m[j + 1] = temp;
				}
				temp3++;
			}
		}
		temp3++;
		temp2 += temp3;
		t++;
	}
	for (int i = 0; i < n; i++)
		std::cout << m[i];
	std::cout << '\n';
	t = 0;
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		for (int j = 0; j < tree.GetNodesOnLevel(i); j++) {
			std::cout << m[t] << '\t';
			t++;
		}
		std::cout << std::endl;
	}*/
	system("pause");
	return 0;
}
template<typename R>
R maximum(R *a, int len) {
	R max = a[0];
	for (int i = 1; i < len; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

template<typename T>
void myTree<T>::add(Node *& node, const T & item)
{
	if (node == NULL) {
		node = new Node(item);
	}
	else if (item < node->item) {
		add(node->son, item);
	}
	else {
		add(node->bro, item);
	}
}

template<typename T>
void myTree<T>::Delete(Node * node)
{
	if (node) {
		Delete(node->son);
		Delete(node->bro);
		delete node;
	}
}

template<typename T>
int myTree<T>::GetHeight(Node * node)
{
	if (node == NULL)
		return 0;
	int max = 0;
	for (Node *current = node->son; current; current = current->bro) {
		int curHeight = GetHeight(current);
		if (curHeight > max)
			max = curHeight;
	}
	return max + 1;
}

template<typename T>
int myTree<T>::GetNodesOnLevel(Node * node, int level)
{
	if (node == NULL)
		return 0;
	if (level <= 0)
		return 0;

	return GetNodesOnLevel(node->son, level - 1) +
		(level == 1) +
		GetNodesOnLevel(node->bro, level);
}