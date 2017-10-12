//SmartArrays - Practice TODO template
#include <iostream>
#include <algorithm>
using namespace std;

struct SmartArray
{
	int *head;
	int used;
	int capacity;
	void print();

	SmartArray(int size = 0);	//Default value to serve as default constructor
	~SmartArray();

	void resize(int new_cap);
	int  get(int index);
	void set(int index, int val);
	void push(int val);
	void pop();
	void insert(int index, int val);
	void remove(int index);
};
void SmartArray::print()
{
	if(used == 0)
		cout << "[empty] ";
	else
	{
		cout << "[ ";
		for(int i = 0; i < used; i++)
			cout << head[i] << ' ';
	}
	cout << "] used = " << used << " cap = " << capacity << endl;
}
SmartArray::SmartArray(int size)
{
	//Treat negative sizes as though size = 0, min capacity of 8
	if (size < 0 || size < 8)
	{
		used = 0;
		capacity = 8;
		head = new int[capacity];
	}
	else
	{
		used = 0;
		capacity = size;
		head = new int[size];
	}

}

//Deconstructor
SmartArray::~SmartArray()
{
	delete[] head; 
}
//Resizes the array
void SmartArray::resize(int new_cap)
{
	//If the new capacity is already the capacity or below zero
	if(new_cap < 0 || new_cap == capacity)
	{
		return;
	}
	//Finds the new capacity
	capacity = max(8, new_cap);
	//Creates an integer pointer array with the new capacity
	int *p = new int[capacity];
	//Finds how bog used is
	used = min(used, new_cap);
	//Puts old values in new array
	for(int i = 0; i < used; i++)
	{
		p[i] = head[i];
	}
	//Deletes old array
	delete[] head;
	//Makes head array equal to the new array
	head = p;
}
//Gets specified index
int SmartArray::get(int index)
{
	if(index < 0 || index >= used)
	{
		return INT_MIN;			//Must return something
	}
	else
	{
		return head[index];
	}
}
//Sets value at specified index
void SmartArray::set(int index, int val)
{
	if(0 <= index && index < used)
	{
		head[index] = val;
	}
}
//Adds one to the end of the array
void SmartArray::push(int val)
{
	if(used == capacity)
	{
		resize(2 * capacity);	//Double the capacity while resizing
	}
	head[used] = val;
	used++;
}
//Takes one off the used list
void SmartArray::pop()
{
	if(used > 0)
	{
		used--;
	}
}
//Inserts value at a specific index
void SmartArray::insert(int index, int val)
{
	if(index < 0 || index >= used)
	{
		return;
	}
	if(used == capacity)
	{
		resize(2 * capacity);
	}
	else 
	{
		for(int i = used; i > index; i--)
		{
			head[i] = head[i-1];
		}
	}
	head[index] = val;
	used++;
}
//Removes specific index from the array
void SmartArray::remove(int index)
{
	if(index < 0 || index >= used)
	{
		return;
	}
	for(int i = index; i < used; i++)
	{
		head[i] = head[i+1];
	}
	used--;
}

int main()
{
	SmartArray a(4);
	for(int i = 0; i < a.used; i++)
		a.set(i, i);				//[0 1 2 3] used = 4 capacity = 8
	int menu_choice = 0;
	while(menu_choice != 8)
	{
		system("cls");		//Clear the screen
		cout << "Before: ";
		a.print();
		cout << "1. resize\n";
		cout << "2. get\n";
		cout << "3. set\n";
		cout << "4. push\n";
		cout << "5. pop\n";
		cout << "6. insert\n";
		cout << "7. remove\n";
		cout << "8. exit\n";
		int menu_choice;
		cin >> menu_choice;

		int index, val, new_cap;
		if(menu_choice == 1)
		{
			cout << "New capacity: ";
			cin >> new_cap;
			a.resize(new_cap);
		}
		if(menu_choice == 2)
		{
			cout << "Index: ";
			cin >> index;
			cout << "Value = " << a.get(index) << endl;
		}
		if(menu_choice == 3)
		{
			cout << "Index & New_Value: ";
			cin >> index >> val;
			a.set(index, val);
		}
		if(menu_choice == 4)
		{
			cout << "New_Value: ";
			cin >> val;
			a.push(val);
		}
		if(menu_choice == 5)
		{
			a.pop();
		}
		if(menu_choice == 6)
		{
			cout << "Index & New_Value: ";
			cin >> index >> val;
			a.insert(index, val);
		}
		if(menu_choice == 7)
		{
			cout << "Index: ";
			cin >> index;
			a.remove(index);
		}
		if(menu_choice == 8)
			break;

		cout << "After: ";
		a.print();
		system("pause");
	}
	return 0;
}