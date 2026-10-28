#ifndef INVQUE_H
#define INVQUE_H
#include <iostream>
#include "InvItem.h"

using namespace std;

class InvQue
{
    private:
        InventoryItem *itemArray; //Points to the item array
        int queueSize;
        int front; //position of first item to remove
        int rear; //position of last item added
        int numItems;
    public:
        InvQue()
        {
            itemArray = nullptr;
            queueSize = 0;
            front = -1;
            rear = -1;
            numItems = 0;
        }

        InvQue(int QueueSize)
        {
            itemArray = new InventoryItem[QueueSize];
            queueSize = QueueSize;
            front = -1;
            rear = -1;
            numItems = 0;
        }
        InvQue(const InvQue& copy)
        {
            itemArray = new InventoryItem[copy.queueSize];
            queueSize = copy.queueSize;
            front = copy.front;
            rear = copy.rear;
            numItems = copy.numItems;

            //copy other queue's array
            for (int i = 0; i < copy.queueSize; i++)
                itemArray[i] = copy.itemArray[i];
        }
        ~InvQue()
        {
            delete[] itemArray;
        }

        void enqueue(InventoryItem item)
        {
            if (isFull())
            {
                cout << "The queue is full." << endl;
            }
            else
            {
                rear = (rear + 1) % queueSize; //will loop to the beginning if at end of queue
                itemArray[rear] = item;
                numItems++;
            }
        }
        void dequeue(InventoryItem& item)
        {
            if (isEmpty())
            {
                cout << "The queue is empty" << endl;
            }
            else
            {
                front = (front + 1) % queueSize;
                item = itemArray[front];
                numItems--;
            }
        }
        bool isEmpty() const
        {
            if (numItems)
                return false;
            else
                return true;
        }
        bool isFull() const
        {
            if (numItems < queueSize)
                return false;
            else
                return true;
        }
        void clear()
        {
            front = queueSize - 1;
            rear = queueSize - 1;
            numItems = 0;
        }
        void resize(int QueueSize) 
        {
            delete[] itemArray;

            itemArray = new InventoryItem[QueueSize];
            queueSize = QueueSize;
            front = -1;
            rear = -1;
            numItems = 0;
        }
        int GetNumItems()
        { return numItems; }
        InventoryItem GetItem(int index)
        {
            return itemArray[(index + front + 1) % queueSize];
        }


};

#endif