// DynStack template

template <class T>
class InvStack
{
	private:
		struct StackNode
		{
			T value;
			StackNode *next;
		};

		StackNode *top;
		int currSize = 0;

	public:
		InvStack()
			{ top = nullptr; }
		void push(T);
		void pop(T &);
		bool isEmpty();
		int GetCurrSize();
		T GetItem(int);
};

//*********************************************************
// Member function push pushes the argument onto          *
// the stack.                                             *
//*********************************************************

template <class T>
void InvStack<T>::push(T num)
{
	StackNode *newNode = nullptr;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = num;
	
	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else		// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}

	currSize++;
}

//*********************************************************
// Member function pop pops the value at the top          *
// of the stack off, and copies it into the variable      *
// passed as an argument.                                 *
//*********************************************************

template <class T>
void InvStack<T>::pop(T &num)
{
	StackNode *temp = nullptr;
	
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else   // pop value off top of stack
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
		currSize--;
	}
}
 
//*********************************************************
// Member funciton isEmpty returns true if the stack      *
// is empty, or false otherwise.                          *
//*********************************************************

template <class T>
bool InvStack<T>::isEmpty()
{
	bool status = false;

	if (!top)
	{
		status = true;
	}
		
	return status;
}

template <class T>
T InvStack<T>::GetItem(int index)
{
	StackNode *currNode = top;

	for (int i = 0; i < index; i++)
	{
		currNode = currNode->next;
	}

	return currNode->value;
}

template <class T>
int InvStack<T>::GetCurrSize()
{
	return currSize;
}