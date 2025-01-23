template <typename T>
class MyList
{
private:
    template <typename T>
    class Node
    {
    public:
        T value;
        Node* pNext;

        Node(T value = {}, Node* pNext = nullptr)
        {
            this->value = value;
            this->pNext = pNext;
        }
    };

private:
    size_t numElements;
    Node<T>* firstNode;

public:
    MyList() : numElements(0), firstNode(nullptr) {}

    ~MyList()
    {
        clear();
    }

    void clear();

    void pop_front();
    void pop_back();
    
    void push_front(T value);
    void push_back(T value);

	void insert_at(T value, size_t index);
	void remove_at(size_t index);

	void PrintList();

    size_t get_size();

    T& operator[](const size_t index);
};

template<typename T>
inline void MyList<T>::clear()
{
	while (firstNode)
	{
		pop_front();
	}
}

template<typename T>
void MyList<T>::pop_front()
{
	Node<T>* newFirstNode = firstNode->pNext;
	delete firstNode;
	firstNode = newFirstNode;

	numElements--;
}

template<typename T>
void MyList<T>::pop_back()
{
	Node<T>* currentNode = firstNode;

	while (currentNode->pNext->pNext != nullptr)
	{
		currentNode = currentNode->pNext;
	}

	delete currentNode->pNext;
	currentNode->pNext = nullptr;

	numElements--;
}

template<typename T>
void MyList<T>::push_front(T value)
{
	firstNode = new Node<T>(value, firstNode);

	numElements++;
}

template<typename T>
void MyList<T>::push_back(T value)
{
	if (firstNode == nullptr)
	{
		firstNode = new Node(value);
	}
	else
	{
		Node<T>* currentNode = firstNode;

		while (currentNode->pNext != nullptr)
		{
			currentNode = currentNode->pNext;
		}

		currentNode->pNext = new Node(value);
	}

	numElements++;
}

template<typename T>
inline void MyList<T>::insert_at(T value, size_t index)
{
	if (index > numElements)
		throw std::out_of_range("Вы вышли за границы массива");

	if (index == numElements)
	{
		push_back(value);
		return;
	}

	Node<T>* currentNode = firstNode;

	for (size_t i = 0; i < index - 1; i++)
	{
		currentNode = currentNode->pNext;
	}

	Node<T>* newValue = new Node<T>(value);
	newValue->pNext = currentNode->pNext;
	currentNode->pNext = newValue;

	numElements++;
}

template<typename T>
inline void MyList<T>::remove_at(size_t index)
{
	if (index >= numElements)
		throw std::out_of_range("Вы вышли за границы массива");

	Node<T>* currentNode = firstNode;

	for (size_t i = 0; i < index - 1; i++)
	{
		currentNode = currentNode->pNext;
	}

	Node<T>* saved_pNext = currentNode->pNext->pNext;
	delete currentNode->pNext;
	currentNode->pNext = saved_pNext;

	numElements--;
}

template<typename T>
inline void MyList<T>::PrintList()
{
	for (size_t i = 0; i < get_size(); i++)
	{
		std::cout << this->operator[](i) << ' ';
	}
	std::cout << std::endl;
}

template<typename T>
inline size_t MyList<T>::get_size()
{
	return numElements;
}

template<typename T>
T& MyList<T>::operator[](const size_t index)
{
	if (index >= numElements)
		throw std::out_of_range("Вы вышли за границы массива");

	Node<T>* currentNode = firstNode;

	for (size_t i = 0; i < index; i++)
	{
		currentNode = currentNode->pNext;
	}

	return currentNode->value;
}