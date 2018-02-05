# Huffman-Coding

	Step 1: Construct Huffman ordered linked list using insertion sort
  
	Step 2: Construct Huffman binary tree
  
	Step 3: Create Huffman coding scheme
  
  Finally, traverse the Huffman binary tree in the order of:
	
  a) pre-order 
	
  b) in-order
	
  c) post-order


I. Input: A file contains a list of <char prob> pairs with the  following format. The input prob are integer, has been multiplied by 100, i.e., a prob equal to .40 will be given as 40, char should be treated as string. 

	char1  prob1  
	char2  prob2
	char3  prob3



II. Outputs: 

    - outFile1 (argv[1]/argv[2]): A text file contain the Huffman <char code> pairs 
    - outFile2 (argv[2]/argv[3]): A text file contain the pre-order traversal of the Huffman binary tree
    - outFile3 (argv[3]/argv[4]): A text file contain the in-order traversal of the Huffman binary tree
    - outFile4 (argv[4]/argv[5]): A text file contain the post-order traversal of the Huffman binary tree
    - outFile5 (argv[5]/argv[6]): Debugging outputs
