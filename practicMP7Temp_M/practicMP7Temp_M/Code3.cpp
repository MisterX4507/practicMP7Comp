#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int i, j;
class SORTING {
protected:
const int size = 10;
int *array = new int[size];
private:
int nomer; 
	void creation() {
		srand((unsigned int)time(0));
		for (int k = 0; k < size; k++)
		{			
			array[k] = rand() % 100;
		}
	}
	virtual void operation() = 0;
	void output() {
		for (int k = 0; k < size; k++)
		{
			cout << array[k] << "\n";
		}
		cout << "\n";
	}
public:	
	void execute() {
		creation();
		operation();
		output();		
	}
};
class SELECTION : public SORTING {
public:
	void operation()
	{
		int len = size;
		for (i = 0; i < len - 1; i++)
		{
			int i_min = i;
			for (j = i + 1; j < len; j++)
			{
				if (array[j] < array[i_min]) i_min = j;
			}
			if (i != i_min) {
				int temp;
				temp = array[i]; array[i] = array[i_min]; array[i_min] = temp;
			}
		}
	}
};
class COMB : public SORTING {
public:
	void operation()
	{
		const double A = 1.3;
		int len = size;
		int step, temp; step = len / A;
		while (step > 1)
		{
			for (i = 0; (i + step) < len; i++)
			{
				if (array[i] > array[i + step]) {
					temp = array[i]; array[i] = array[i + step];
					array[i + step] = temp;
				}
			}
			step /= A;
		}
		for (i = 0; i < len - 1; i++) {
			for (j = 0; j < len - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					temp = array[j]; array[j] = array[j + 1];
					array[j + 1] = array[j];
				}
			}
		}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");	
	SELECTION x; x.execute();
	COMB y; y.execute();
	return 0;
}