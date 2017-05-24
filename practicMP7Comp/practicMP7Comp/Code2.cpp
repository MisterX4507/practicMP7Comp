#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

// Component
class Component
{
public:
	virtual int getAddition() = 0;
	virtual void addItem(Component* p) {
		throw runtime_error("Can't add to a leaf\n");
	}
	virtual void removeItem() {
		throw runtime_error("Can't remove from a leaf\n");
	}
};

// Leafes
class Leaf : public Component
{
private:
	int value;
public:
	virtual int getAddition() {
		value = 1;
		return value;
	}
};

// Composite
class CompositeItem : public Component
{
public:
	int getAddition() {
		int total = 0;
		for (int i = 0; i<c.size(); i++)
			total += c[i]->getAddition();
		return total;
	}
	void addItem(Component* p) {
		c.push_back(p);
	}
	void removeItem() {
		for (int i = 0; i<c.size(); ++i)
			delete c[i];
	}
private:
	vector<Component*> c;
};
// ��������������� ������� ��� �������� ����������
CompositeItem* createConnection()
{
	// ��������� ��������:
	CompositeItem* Compose = new CompositeItem;
	// 1000 ������
	for (int i = 0; i<1000; ++i)
		Compose->addItem(new Leaf);
	return Compose;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	// ������ �������� 4 ���������� � 4 ����������
	CompositeItem* tree = new CompositeItem;
	for (int i = 0; i<4; ++i) {
		tree->addItem(createConnection());
		tree->addItem(new Leaf);
	}
	cout << "����� ���� ��������� � ������ ����� " << tree->getAddition() << endl;
	delete tree;
	return 0;
}