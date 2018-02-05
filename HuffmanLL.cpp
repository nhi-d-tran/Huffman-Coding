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
