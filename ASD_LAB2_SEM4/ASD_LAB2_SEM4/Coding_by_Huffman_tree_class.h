#pragma once
#include <iostream>
#include "Map_class.h"
#include "Huffman_tree_class.h"

using namespace std;

// Class CodingByHuffmanTree
class CodingByHuffmanTree
{
private:

	Red_Black_Tree<char, int, string> Map; // Associative array storing the symbol, its frequency of occurrence and code
	HuffmanTree Tree; // Huffman tree for encoding the source string
	string encodedString; // A string storing the encoded original message
	string sourceString; // The string storing the original message

	// Counting the frequency of occurrence in the transmitted string
	void ñountingFrequencyOccurrence(string str, Red_Black_Tree<char, int, string>& Map)
	{
		if (getStringLength(str) == 0)
		{
			throw domain_error("An empty string cannot be encoded");
		}
		else
		{
			for (int index = 0; str[index] != '\0'; index++)
			{
				if (Map.get_size_tree() == 0)
				{
					Map.insert(str[index], 1); // Adding a new character to an associative array
				}
				else
				{
					if (Map.find(str[index]))
					{
						// Increasing the frequency of occurrence if the symbol is already in the associative array
						Map.Get_map_element(str[index])->value++;
					}
					else
					{
						Map.insert(str[index], 1); // Adding a new character to an associative array
					}
				}
			}
		}
	}

	// Creating a Huffman Tree
	void createTreeHuffman(Red_Black_Tree<char, int, string>& Map, HuffmanTree& Tree)
	{
		// Filling in the list of Huffman tree leaves
		HuffmanTree::List listVertices;
		Red_Black_Tree<char, int, string>::List<char> List_keys = Map.get_keys();
		Red_Black_Tree<char, int, string>::List<int> List_values = Map.get_values();
		while (List_keys.get_head() != nullptr && List_values.get_head() != nullptr)
		{
			listVertices.pushBack(Tree.createNewElement(List_keys.get_head()->data, List_values.get_head()->data));
			List_keys.pop_front();
			List_values.pop_front();
		}
		// Duplicating the list of Huffman tree leaves to get codes
		HuffmanTree::List processedVertices;
		processedVertices.copyList(listVertices);
		// Forming a Huffman tree from a list of sheets
		formingTreeHuffman(listVertices);
		// Filling in the code table
		getCodeSymbols(processedVertices);
	};

	// Forming a Huffman tree from a list of sheets
	void formingTreeHuffman(HuffmanTree::List& listVertices)
	{
		listVertices.sortListElements(); // Sorting the list elements in ascending order
		while (listVertices.getSizeList() != 1)
		{
			listVertices.pushBack(listVertices.CombiningElements(Tree));
			listVertices.popFront();
			listVertices.popFront();
			if (listVertices.getSizeList() > 2)
			{
				listVertices.sortListElements(); // Sorting the list elements in ascending order
			}
		}
		Tree.setRootNode(listVertices.getHead()->data); // Setting the pointer to the root element of the tree
	}

	// Filling in the code table
	void getCodeSymbols(HuffmanTree::List& processedVertices)
	{
		// Adding character codes to an associative array
		while (processedVertices.getHead() != nullptr) {
			Map.Get_map_element(processedVertices.getHead()->data->symbol)->code = Tree.getCode(processedVertices.getHead()->data);
			processedVertices.popFront();
		}
	};

	// Getting the length of the transmitted string
	double getStringLength(string string)
	{
		double index = 0;
		for (index; string[index] != '\0'; index++);
		return index;
	}

public:

	// Constructor of the coding by Huffman tree class
	CodingByHuffmanTree(string str)
	{
		sourceString = str;
		encodedString = "";
		ñountingFrequencyOccurrence(str, Map);
		createTreeHuffman(Map, Tree);
	}
	// The destructor of the coding by Huffman tree class
	~CodingByHuffmanTree()
	{
		sourceString = "";
		encodedString = "";
		Map.clear();
		Tree.clear();
	}

	// Getting a Huffman tree built to encode the source string
	HuffmanTree* getHuffmanTree()
	{
		return &Tree;
	};

	// Getting an associative array built to store characters and their parameters of the source string
	Red_Black_Tree<char, int, string>* getMap()
	{
		return &Map;
	};

	// Displaying a table of frequencies and codes on the screen
	void getTableFrequenciesAndCodes()
	{
		if (encodedString != "")
		{
			Map.print();
		}
	}

	// The result of encoding the encoding of the original string
	string codingSourceString()
	{
		for (int index = 0; sourceString[index] != '\0'; index++) {
			encodedString += Map.Get_map_element(sourceString[index])->code;
		}
		return encodedString;
	}

	// The result of decoding the encoded string
	string decodingEncodedString()
	{
		string decodedString = "";
		if (encodedString == "")
		{
			return decodedString;
		}
		else
		{
			decodedString = Tree.decoding(encodedString);
			return decodedString;
		}
	}

	// Calculating the amount of memory that the source string occupies.
	double memoryCapacitySourceString()
	{
		return getStringLength(sourceString) * 8;
	};

	// Calculation of the amount of memory that the encoded string occupies.
	double memoryCapacityEncodedString()
	{
		return getStringLength(encodedString);
	};

	// Calculating the compression ratio
	double compressionRatio()
	{
		return (getStringLength(sourceString) * 8 / getStringLength(encodedString));
	}
};