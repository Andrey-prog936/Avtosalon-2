#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Auto
{
    string name;
    int year;
    float capacity;
    int price;
	Auto* next = nullptr;
};

class AutoSalon
{
public:
	Auto* AddAuto(Auto* Head, int Number) {
		Number--;
		Auto* NewItem = new(Auto);
		cout << "Year of car production: ";
		cin >> NewItem->year;
		cout << "Name: ";
		cin >> NewItem->name;
		cout << "Price: ";
		cin >> NewItem->price;
		cout << "Engine capacity: ";
		cin >> NewItem->capacity;
		NewItem->next = nullptr;
		if (Head == nullptr)
		{
			Head = NewItem;
		}
		else {
			Auto* Current = Head;
			for (int i = 1; i < Number && Current->next != nullptr; i++)
			{
				Current = Current->next;
			}
			if (Number == 0) {

				NewItem->next = Head;
				Head = NewItem;
			}
			else {
				if (Current->next != nullptr)
				{
					NewItem->next = Current->next;
				}

				Current->next = NewItem;
			}
		}
		return Head;
	}
	void DeleteAutoYearLess2000(Auto* Head)
	{
		while (Head->year < 2000)
		{
			DeleteAutoYearLess2000(Head->next);
			delete Head;
			Head = Head->next;
		}
	}
	void Print(Auto* Head)
	{
		if (Head == nullptr)
		{
			cout << "List is empty!";
		}
		else
		{
			while (Head != nullptr)
			{
				cout << "Name: " << Head->name << "\nYear: " << Head->year << "\nEngine capacity: "
					<< Head->capacity << "\nPrice: " << Head->price << endl << endl;
				Head = Head->next;
			}
		}
	}
	bool FindYear(Auto* Head, int NumberItem)
	{
		Auto* linkk;
		linkk = Head;
		while (linkk != nullptr) {
			if (NumberItem == linkk->year)
			{
				return true;
			}
			else linkk = linkk->next;
		}
		return false;
	}
};


int main()
{

    return 0;
}