#include <iostream>

// Chapter 19, Programming Challenge 12: Inventory Bin Queue
#include <iostream>
#include "InvItem.h"
#include "InvStack.h"
#include "InvQue.h"
using namespace std;

int main()
{
	InvStack<InventoryItem> stack;	// create stack
	InvQue queue;
	InventoryItem item;				// create inventory item object
	int listChoice;
	int queueSize;
	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date

	cout << "\n Would you like to store your items in a queue or a stack? \n";
	cout << "1. Queue\n";
	cout << "2. Stack\n";
	cin >> listChoice;
	
	if(listChoice == 1)
	{
		cout << "How long would you like your queue to be?\n";
		cin >> queueSize;
		queue.resize(queueSize);
	}

	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Display.\n";
		cout << "4.  Quit.\n\n";
		cout << "Please make a choice (1, 2, 3, or 4):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter 1, 2, 3, or 4: ";
			cin >> choice;
		}
		if (listChoice == 1) //user picked queue
		{
			switch(choice)
			{
				case 1:

					cout << "\nYou have chosen to add an item to the inventory queue.\n\n";
					if (queue.isFull())
					{
						cout << "The queue is full." << endl;
					}
					else
					{
						cout << "Enter the item's serial number: ";
						cin >> serial;
						item.setSerialNum(serial);
						cout << "Enter the item's manufacture date: ";
						cin >> mDate;
						item.setManufactDate(mDate);

						queue.enqueue(item);
					}
					break;
				case 2:
					cout << "\n You have chosen to remove an item from the inventory queue.\n\n";
					if (queue.isEmpty())
						cout << "Nothing to remove.\n";
					else
					{
						queue.dequeue(item);
						cout << "\nThe part you removed was:\n";
						item.Display();
						//cout << "\tSerial number: " << item.getSerialNum() << endl;
						//cout << "\tManufacture date: " << item.getManufactDate() << endl;
						cout << endl;
					}
					break;
				case 3:
					cout << "Displaying...\n";
					if (queue.isEmpty())
						cout << "The queue is empty.\n";
					else
						{
							for (int i = 0; i < queue.GetNumItems(); i++)
							{
								if (queue.GetItem(i).getSerialNum() != 0) //Item is defined
								{
									cout << "Item " << i + 1 << ": \n";
									queue.GetItem(i).Display();
								}
							}
						}
					break;

				case 4:
					cout << "Goodbye!";
					break;
			}
		}
		else //user picked stack
		{
			// Act on the user's choice.
			switch(choice)
			{
				case 1:
					
					// Enter a part into inventory.
					cout << "\nYou have chosen to add an item to the inventory bin.\n\n";
					cout << "Enter the item's serial number: ";
					cin >> serial;
					item.setSerialNum(serial);
					cout << "Enter the item's manufacture date: ";
					cin >> mDate;
					item.setManufactDate(mDate);
					stack.push(item);
					break;
		
				case 2:
					// Take a part out of inventory.
					cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";
					if (stack.isEmpty())
						cout << "No parts to remove.\n";
					else
					{
						stack.pop(item);
						cout << "\nThe part you removed was:\n";
						item.Display();
						//cout << "\tSerial number: " << item.getSerialNum() << endl;
						//cout << "\tManufacture date: " << item.getManufactDate() << endl;
						cout << endl;
					}
					break;
				case 3:
					cout << "Displaying...\n";
					if (stack.isEmpty())
					{
						cout << "The stack is empty.\n";
					}
					else
					{
						for (int i = 0; i < stack.GetCurrSize(); i++)
						{
							cout << "Item " << i + 1 << ": \n";
							stack.GetItem(i).Display();
						}
					}
					break;
				case 4:
					cout << "\nGoodbye!\n\n";
					break;
	
			}
		}


	} while (choice  != 4);

	return 0;
}