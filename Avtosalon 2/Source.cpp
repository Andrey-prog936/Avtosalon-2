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

};


int main()
{

    return 0;
}