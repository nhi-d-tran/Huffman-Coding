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