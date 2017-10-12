//SmartArrays - Practice TODO template
#include <iostream>
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
	//Treat negative sizes as though size = 0.
	//Insure that the capacity is never less than 8.
	//Allocated sufficient memory and initialize the used portion to 0's.

	//TODO: Replace this code which only handles size = 0.
	used = 0;
	capacity = 8;
	head = new int[8];
}
SmartArray::~SmartArray()
{
	//TODO: Call delete[] to prevent memory leaks
}
void SmartArray::resize(int new_cap)
{
	//TODO: Uncomment the code and finish the statements
	//if(new_cap < 0 || new_cap == capacity)	//Nothing to do
	//	???;
	//capacity = max(...			//Never fewer than 8
	//int *p = new...
	//used = min(...		//Keep as much as we can
	//for(int i = 0; i < used; i++)
	//	p[i] = ???
	//delete[] ???;
	//head = ???;
}
int SmartArray::get(int index)
{
	//TODO: replace the following code. Don't forget to check for valid index.
	return 0;
}
void SmartArray::set(int index, int val)
{
	if(0 <= index && index < used)
	{
		//TOTO: what goes here?
	}
}
void SmartArray::push(int val)
{
	//TODO: don't do any resizing here. Call resize() to resize to double the current capacity.
	//Then place the new element at the end. Is the variable "used" right when you are done?
}
void SmartArray::pop()
{
	//TODO: This one is simply a change to "use". You don't need to "erase" any values.
	//What happens if an empty SmartArray is popped?
}
void SmartArray::insert(int index, int val)
{
	if(index < 0 || index >= used)
		return;
	if(used == capacity)
		resize(2 * capacity);	//Double the capacity while resizing
	else
	{
		//TODO: The for loop to transfer the data is tricky.
		//I suggest that you strt from the right and slide data to the left.

	}
	head[index] = val;
	used++;
}
void SmartArray::remove(int index)
{
	if(index < 0 || index >= used)
		return;
	//TODO: write the for loop to transfer the data.
	//You don't actually erase anything; you just shift it.



	used--;
}

int main()
{
	//Things may not work properly until you do the TODO's above.
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