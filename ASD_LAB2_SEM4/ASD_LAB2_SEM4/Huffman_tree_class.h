#pragma once

// Class HuffmanTree
class HuffmanTree {

private:

	// Huffman tree element class
	class ElementHuffmanTree
	{
	public:

		char symbol; // Input alphabet symbol
		size_t frequencyOccurrence; // Frequency of occurrence of the input symbol
		ElementHuffmanTree* left_node; // Pointer to the left child of the node of the Huffman tree
		ElementHuffmanTree* right_node; // Pointer to the right child of the node of the Huffman tree
		ElementHuffmanTree* parent_node; // Pointer to the parent node of the Huffman tree

		// Constructor of the Huffman tree element class
		ElementHuffmanTree(char symbol = '\0', size_t frequencyOccurrence = 0, ElementHuffmanTree* parent_node = nullptr, ElementHuffmanTree* left_node = nullptr, ElementHuffmanTree* right_node = nullptr)
		{
			this->symbol = symbol;
			this->frequencyOccurrence = frequencyOccurrence;
			this->parent_node = parent_node;
			this->left_node = left_node;
			this->right_node = right_node;
		}
		// The destructor of the Huffman tree element class
		~ElementHuffmanTree()
		{
			symbol = '\0';
			frequencyOccurrence = 0;
			parent_node = nullptr;
			left_node = nullptr;
			right_node = nullptr;
		}
	};

	size_t sizeTree; // Huffman tree size
	ElementHuffmanTree* rootNode; // Pointer to the root element of the Huffman tree

	// Reverse removal of Huffman tree elements
	void reverseRemoval(ElementHuffmanTree* node)
	{
		if (node == nullptr) return;
		reverseRemoval(node->left_node); // Deleting nodes in the left subtree
		reverseRemoval(node->right_node); // Deleting nodes in the right subtree
		delete node; // Deleting a leaf node
		sizeTree--;
	}

public:

	// Constructor of the Huffman tree class
	HuffmanTree()
	{
		sizeTree = 0;
		rootNode = nullptr;
	}
	// The destructor of the Huffman tree class
	~HuffmanTree()
	{
		clear();
		sizeTree = 0;
		rootNode = nullptr;
	}

	// Setting the value of the root element in the Huffman tree
	void setRootNode(ElementHuffmanTree* root)
	{
		rootNode = root;
	};

	// Getting the size of the Huffman tree
	size_t getSizeTree()
	{
		return sizeTree;
	}

	// Clearing the Huffman tree
	void clear()
	{
		if (getSizeTree() != 0)
		{
			reverseRemoval(rootNode);
			sizeTree = 0;
			rootNode = nullptr;
		}
	}

	// Getting the root element in the Huffman tree
	ElementHuffmanTree* getRootNode()
	{
		return rootNode;
	};

	// Creating a new Huffman Tree element
	ElementHuffmanTree* createNewElement(char symbol, size_t frequency)
	{
		sizeTree++;
		return new ElementHuffmanTree(symbol, frequency);
	}

	// Decoding an encoded string using a Huffman tree
	string decoding(string& encodedString)
	{
		string decodedString = "";
		ElementHuffmanTree* currentElement = rootNode;
		for (int index = 0; encodedString[index] != '\0'; index++)
		{
			if (getSizeTree() != 1)
			{
				if (encodedString[index] == '0')
				{
					currentElement = currentElement->right_node;
				}
				else
				{
					currentElement = currentElement->left_node;
				}
			}
			if (currentElement->symbol != '\0')
			{
				decodedString += currentElement->symbol;
				currentElement = rootNode;
			}
		}
		return decodedString;
	}

	// Getting the symbol code from the Huffman tree
	string getCode(ElementHuffmanTree* currentSymbol)
	{
		string codeSymbol = "";
		ElementHuffmanTree* previousNode = currentSymbol;
		while (currentSymbol->parent_node != nullptr)
		{
			previousNode = currentSymbol;
			currentSymbol = currentSymbol->parent_node;
			if (currentSymbol->left_node == previousNode) {
				codeSymbol = "1" + codeSymbol;
			}
			else codeSymbol = "0" + codeSymbol;
		}
		if (currentSymbol->parent_node == nullptr && currentSymbol->left_node == nullptr && currentSymbol->right_node == nullptr)
		{
			codeSymbol = "0";
		}
		return codeSymbol;
	}

	// List class for forming a Huffman tree
	class List {

		// List node class
		class Node
		{
		public:

			ElementHuffmanTree* data; // Pointer to an element of the Huffman tree
			Node* next; // Pointer to the next item in the list

			// Constructor of the List node class
			Node(HuffmanTree::ElementHuffmanTree* data = nullptr, Node* next = nullptr) {
				this->data = data;
				this->next = next;
			};
			// List node class destructor
			~Node()
			{
				data = nullptr;
				next = nullptr;
			};
		};

		size_t sizeList; // List size
		Node* head; // Pointer to the first item in the list
		Node* last; // Pointer to the last item in the list

	public:

		// Constructor of the List node class
		List(size_t size = 0, Node* head = nullptr, Node* last = nullptr)
		{
			this->sizeList = size;
			this->head = head;
			this->last = last;
		}
		// List node class destructor
		~List()
		{
			clearList();
			sizeList = 0;
			head = nullptr;
			last = nullptr;
		};

		// Getting a pointer to the head element of the list
		Node* getHead()
		{
			return head;
		}

		// Getting the list size
		size_t getSizeList()
		{
			return sizeList;
		}

		// Clearing the list
		void clearList()
		{
			if (getSizeList() != 0)
			{
				Node* current_item = head;
				while (current_item != nullptr)
				{
					current_item = current_item->next;
					delete head;
					head = current_item;
				}
				head = nullptr;
				last = nullptr;
				sizeList = 0;
			}
		};

		// Adding a new element to the end of the list
		void pushBack(ElementHuffmanTree* element_value)
		{
			if (head == nullptr)
			{
				Node* new_list_item = new Node(element_value, nullptr);
				head = new_list_item;
				last = new_list_item;
				sizeList++;
			}
			else
			{
				Node* new_list_item = new Node(element_value, nullptr);
				last->next = new_list_item;
				last = new_list_item;
				sizeList++;
			}
		};

		// Removing an item from the top of the list
		ElementHuffmanTree* popFront()
		{
			if (getSizeList() > 0)
			{
				if (getSizeList() == 1)
				{
					clearList();
				}
				else
				{
					Node* list_item = head;
					head = head->next;
					sizeList--;
					return list_item->data;
				}
			}
			else throw invalid_argument("The list is empty, there are no available elements to delete");
		};

		// Combining two elements in a list
		ElementHuffmanTree* CombiningElements(HuffmanTree& Tree)
		{
			Node* firstElement = head;
			Node* secondElement = head->next;
			int totalFrequency = firstElement->data->frequencyOccurrence + secondElement->data->frequencyOccurrence;
			ElementHuffmanTree* newNode = Tree.createNewElement('\0', totalFrequency);
			firstElement->data->parent_node = newNode;
			newNode->left_node = firstElement->data;
			secondElement->data->parent_node = newNode;
			newNode->right_node = secondElement->data;
			return newNode;
		}

		// Sorting the list elements in ascending order
		void sortListElements()
		{
			if (head != nullptr)
			{
				for (int i = 0; i < getSizeList(); i++)
				{
					for (Node* ñurrentElement = head; ñurrentElement->next != nullptr; ñurrentElement = ñurrentElement->next) {
						if (ñurrentElement->data->frequencyOccurrence > ñurrentElement->next->data->frequencyOccurrence)
						{
							// Swapping elements
							HuffmanTree::ElementHuffmanTree* temporaryElement = ñurrentElement->data;
							ñurrentElement->data = ñurrentElement->next->data;
							ñurrentElement->next->data = temporaryElement;
						}
					}
				}
			}
			else throw invalid_argument("Sorting the list is not possible because it is empty");
		}

		// Copying a list to a new list
		void copyList(const List& copiedList)
		{
			Node* currentElement = copiedList.head;
			while (currentElement != nullptr)
			{
				pushBack(currentElement->data);
				currentElement = currentElement->next;
			}
		}

		// Overloading the output operator
		friend ostream& operator<<(ostream& stream, const List& List)
		{
			if (List.head != nullptr)
			{
				List::Node* current = List.head;
				while (current != nullptr)
				{
					stream << current->data->symbol << " ";
					current = current->next;
				}
				stream << '\n';
				return stream;
			}
			else return stream << "\n\n";
		};
	};
};