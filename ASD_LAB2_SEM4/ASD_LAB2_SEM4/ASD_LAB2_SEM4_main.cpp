#include <iostream>
#include "Coding_by_Huffman_tree_class.h"

using namespace std;

int main()
{
	cout << "Encode the messages using the Huffman tree\n\n";
	cout << "Example 1.\n";
	string firstSourceString = "Success is the ability to go from one failure to another with no loss of enthusiasm. (Winston Churchill)";
	cout << "\nSource string:\n" << firstSourceString << "\n\n";
	CodingByHuffmanTree firstString = CodingByHuffmanTree(firstSourceString);
	cout << "Encoded string:\n" << firstString.codingSourceString() << "\n\n";
	cout << "Table frequencies and codes:\n";
	firstString.getTableFrequenciesAndCodes();
	cout << "\n";
	cout << "Decode the encoded source string.\n\n";
	cout << "The result of decoding the encoded string (source string):\n";
	cout << firstString.decodingEncodedString() << "\n\n";
	cout << "The amount of memory that the source string occupies: ";
	cout << firstString.memoryCapacitySourceString() << " bit\n";
	cout << "The amount of memory that the encoded string occupies: ";
	cout << firstString.memoryCapacityEncodedString() << " bit\n\n";
	cout << "Compression ratio: " << firstString.compressionRatio();

	cout << "\n\nExample 2.\n";
	string secondSourceString = "Your time is limited, so don’t waste it living someone else’s life. (Steve Jobs)";
	cout << "\nSource string:\n" << secondSourceString << "\n\n";
	CodingByHuffmanTree secondString = CodingByHuffmanTree(secondSourceString);
	cout << "Encoded string:\n" << secondString.codingSourceString() << "\n\n";
	cout << "Table frequencies and codes:\n";
	secondString.getTableFrequenciesAndCodes();
	cout << "\n";
	cout << "Decode the encoded source string.\n\n";
	cout << "The result of decoding the encoded string (source string):\n";
	cout << secondString.decodingEncodedString() << "\n\n";
	cout << "The amount of memory that the source string occupies: ";
	cout << secondString.memoryCapacitySourceString() << " bit\n";
	cout << "The amount of memory that the encoded string occupies: ";
	cout << secondString.memoryCapacityEncodedString() << " bit\n\n";
	cout << "Compression ratio: " << secondString.compressionRatio();

	cout << "\n\nExample 3.\n";
	string thirdSourceString = "Life is like riding a bicycle. To keep your balance you must keep moving. (Albert Einstein)";
	cout << "\nSource string:\n" << thirdSourceString << "\n\n";
	CodingByHuffmanTree thirdString = CodingByHuffmanTree(thirdSourceString);
	cout << "Encoded string:\n" << thirdString.codingSourceString() << "\n\n";
	cout << "Table frequencies and codes:\n";
	thirdString.getTableFrequenciesAndCodes();
	cout << "\n";
	cout << "Decode the encoded source string.\n\n";
	cout << "The result of decoding the encoded string (source string):\n";
	cout << thirdString.decodingEncodedString() << "\n\n";
	cout << "The amount of memory that the source string occupies: ";
	cout << thirdString.memoryCapacitySourceString() << " bit\n";
	cout << "The amount of memory that the encoded string occupies: ";
	cout << thirdString.memoryCapacityEncodedString() << " bit\n\n";
	cout << "Compression ratio: " << thirdString.compressionRatio();

	return 0;
}