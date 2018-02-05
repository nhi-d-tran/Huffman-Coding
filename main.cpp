//============================================================================
// Name        : 323-Project3.cpp
// Author      : Nhi Tran
// Description :
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;

/*
 * listBinTreeNode class
 * */
class listBinTreeNode
{
public:
	/*
	 * declare the variables
	 * */
	string chStr;
	int prob;
	listBinTreeNode* next;
	listBinTreeNode* left;
	listBinTreeNode* right;

	/*Constructors
	 * */
	listBinTreeNode()
	{
		chStr = "";
		prob = 0;
		next = NULL;
		left = NULL;
		right = NULL;
	}

	listBinTreeNode(string theStr, int pro)
	{
		chStr = theStr;
		prob = pro;
		next = NULL;
		left = NULL;
		right = NULL;
	}

	/*Print the node with chStr, and prob
	 * Also print the next, left and right child with the conditions if else
	 * */
	static void printNode(listBinTreeNode* T, ofstream& outFile)
	{
		outFile << " (" <<T->chStr << ", " << T->prob << "): ";

		if(T->next != NULL)
		{
			outFile << "(Next: " << T->next->chStr << ", " << T->next->prob << ") ";
		}
		else
		{
			outFile << "(Next: NULL) ";
		}
		if(T->left != NULL)
		{
			outFile << "(Left: " << T->left->chStr << ", " << T->left->prob << ") ";
		}
		else
		{
			outFile << "(Left: NULL) ";
		}
		if(T->right != NULL)
		{
			outFile << "(Right: " << T->right->chStr << ", " << T->right->prob << ") --> ";
		}
		else
		{
			outFile << "(Right: NULL) --> ";
		}
	}
};

/*
 * HuffmanLinkedList class
 * */
class HuffmanLinkedList
{
public:
	/*
	 * declare the variables
	 * */
	listBinTreeNode* listHead;
	listBinTreeNode* dummy;
	listBinTreeNode* oldListHead;

	/*constructors
	 * */
	HuffmanLinkedList()
	{
		dummy = new listBinTreeNode;
		oldListHead = new listBinTreeNode;
		dummy->chStr = "dummy";
		listHead = dummy;
	}

	/*ConstructHuffmanLList function - will be called in main has inFile, list and outFile arguments
	 * */
	void constructHuffmanLList(ifstream& inFile, HuffmanLinkedList* list, ofstream& outFile)
	{
		string theString;
		int pro;

		listBinTreeNode* spot = new listBinTreeNode;			// create the spot for find the spot to insert

		/* Read theString and pro in the file
		 * Create the newNode that has theString and pro
		 * then find the spot for the newNode and insert
		 * then print the list
		 * */
		while(inFile >> theString >> pro)
		{
			listBinTreeNode* newNode = new listBinTreeNode(theString, pro);
			spot = list->findSpot(pro);
			list->listInsert(spot, newNode);
			list->printList(outFile);
		}
		inFile.close(); 	//close the file
	}

	/*Find the spot before insert by comparing the probability*/
	listBinTreeNode* findSpot(int prob)
	{
		listBinTreeNode* current = listHead;

		/*if the list is empty return the spot*/
		if(isEmpty())
		{
			return current;
		}

		/*if not, keep checking the qualify spot by comparing the probability and return the spot*/
		while(true)
		{
			if(current->next == NULL)
			{
				return current;
			}
			if(current->next->prob < prob)
			{
				current = current->next;
			}
			else
			{
				return current;
			}
		}
	}

	/*
	 * Insert the newNode with the spot found it
	 * */
	void listInsert(listBinTreeNode* spot, listBinTreeNode* theNewNode)
	{
		listBinTreeNode* temp = spot->next;
		spot->next = theNewNode;
		theNewNode->next = temp;
	}

	/*check if list is empty or not*/
	bool isEmpty()
	{
		return listHead == NULL;
	}

	/*
	 * Print the list on outFile
	 * */
	void printList(ofstream &outFile)
	{
		listBinTreeNode* current;
		outFile << "listHead --> ";
		current = listHead;

		/*if current.next is not null, keep writing on the list and move to next node*/
		while(current->next != NULL)
		{
			outFile << "(" << current->chStr << ", " << current->prob << ", " << current->next->chStr << ") --> ";
			current = current->next;
		}
		outFile << "(" << current->chStr << ", " << current->prob << ", " << "null) " << endl;
	}
};

/*HuffmanBinaryTree class*/
class HuffmanBinaryTree
{
public:
	listBinTreeNode* root;

	/* constructHuffmanBinTree function will be called in main
	 * create oldListHead with dummy and 0
	 * */
	void constructHuffmanBinTree(HuffmanLinkedList* list, ofstream& outFile)
	{
		listBinTreeNode* oldListHead = new listBinTreeNode("dummy", 0);
		oldListHead->next = list->listHead->next;

		/*if the listHead.next.next is not null and oldListHead is not empty
		 * adding the prob and concatenate the string
		 * findSpot for newNode and insert
		 * */
		while(oldListHead->next != NULL && list->listHead->next->next!= NULL)
		{
			listBinTreeNode* newNode = new listBinTreeNode();
			newNode->prob = list->listHead->next->prob + list->listHead->next->next->prob;
			newNode->chStr = list->listHead->next->chStr + list->listHead->next->next->chStr;
			newNode->left = list->listHead->next;
			newNode->right = list->listHead->next->next;
			list->listHead = list->listHead->next->next;
			outFile << endl;										//go to the next line
			newNode->printNode(newNode, outFile);				//print the newNode
			listBinTreeNode* spot = list->findSpot(newNode->prob);
			list->listInsert(spot, newNode);
		}
		root = list->listHead->next;
	}

	/*Pre-order traversal*/
	void preOrderTraversal(listBinTreeNode* T, ofstream& outFile)
	{
		if(T == NULL)
		{
			return;
		}
		else
		{
			listBinTreeNode::printNode(T, outFile);
			preOrderTraversal(T->left, outFile);
			preOrderTraversal(T->right, outFile);
		}
	}

	/*In-order traversal*/
	void inOrderTraversal(listBinTreeNode* T, ofstream& outFile)
	{
		if(T == NULL)
		{
			return;
		}
		else
		{
			preOrderTraversal(T->left, outFile);
			listBinTreeNode::printNode(T, outFile);
			preOrderTraversal(T->right, outFile);
		}
	}

	/*Post-order traversal*/
	void postOrderTraversal(listBinTreeNode* T, ofstream& outFile)
	{
		if(T == NULL)
		{
			return;
		}
		else
		{
			postOrderTraversal(T->left, outFile);
			postOrderTraversal(T->right, outFile);
			listBinTreeNode::printNode(T, outFile);
		}
	}

	/*if the tree has leaf*/
	bool isLeaf(listBinTreeNode* T)
	{
		return (T->left == NULL && T->right == NULL);
	}

	/*Construct char code*/
	void constructCharCode(listBinTreeNode* T, string code, ofstream& outFile)
	{
		if (T == NULL)
		{
			outFile << "This is an empty tree";
			outFile.close();
		}
		else if(isLeaf(T))
		{
			outFile << T->chStr << " ";	//output to outFile1
			outFile << code << " \n";	//output to outFile1
		}
		else
		{
			constructCharCode(T->left, code + "0", outFile); //string concatenation
			constructCharCode(T->right, code + "1", outFile); //string concatenation
		}
	}
};

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

