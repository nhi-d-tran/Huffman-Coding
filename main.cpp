
#include <iostream>
#include <fstream>
using namespace std;

/*main file*/
int main(int argc, char **argv)
{
	try
	{
		/*create and open the file*/
		ifstream inFile;
		ofstream outFile1;
		ofstream outFile2;
		ofstream outFile3;
		ofstream outFile4;
		ofstream outFile5;

		inFile.open(argv[1]);
		outFile1.open(argv[2]);
		outFile2.open(argv[3]);
		outFile3.open(argv[4]);
		outFile4.open(argv[5]);
		outFile5.open(argv[6]);

		/*check if the file is opened or not*/
		if(!inFile.is_open())
		{
			cout << "The file is not open!" << endl;
		}
		else
		{
			HuffmanLinkedList* list = new HuffmanLinkedList();			// create list
			list->constructHuffmanLList(inFile, list, outFile5);			//	construct list and output in outFile5
			HuffmanBinaryTree* tree = new HuffmanBinaryTree();			// create tree
			tree->constructHuffmanBinTree(list, outFile5);				// construct tree and output in outFile5
			tree->constructCharCode(tree->root, "", outFile1);			// construct charCode and output in outFile1
			tree->preOrderTraversal(tree->root, outFile2);				// pre-order in outFile2
			tree->inOrderTraversal(tree->root, outFile3);					// in-order in outFile3
			tree->postOrderTraversal(tree->root, outFile4);				// post-order in outFile4

			/*close the files*/
			inFile.close();
			outFile1.close();
			outFile2.close();
			outFile3.close();
			outFile4.close();
			outFile5.close();
		}
	}
	catch(exception &e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}

	return 0;
}

