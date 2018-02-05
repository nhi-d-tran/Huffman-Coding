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
