# fiao2222

Project 2:  You are to implement  the Huffman coding algorithm step 2 -- Construct Huffman ordered linked list using insertion sort.
  	
********************************
I.  Language: C++ 
********************************
Points : 10 pts
Due Date:  Soft copy: 9/9/2019 Monday before midnight
      Hard copy: 9/10/2018 Tuesday in class

 1 day late: -1 pt 9/10/2019 Tuesday before midnight
Hard copy: 9/12/2018 Thursday in class

2 days late: -3pts 9/11/2019 Wednesday before midnight
Hard copy: 9/12/2018 Thursday in class

-10 pts after 9/11/2019  
	    
********************************
II. Input :  A text file contains a list of <char  prob> pairs with the  following format. 
 // note: The input prob are integer, has been multiplied by 100, i.e., a prob equal to .40 will be given as 40.
********************************
	char1  prob1  
	char2  prob2
	char3  prob3
:
:
charn  probn  

********************************
II. Outputs (use argv):  a text file. The output  format is given below.

********************************
III. Data structure:  Must have all the object classes as given below.
********************************
  -  listNode  class  
- chStr (string)
- prob (int)
- next (listNode *)
-  constructor(chStr, prob, next)

-  linkedList class
- listHead (listNode *) // Initially it points to a dummy node
- constructor (..)
- insertNewNode (listHead ,  newNode)  
// Use the algorithm steptaught in class.
- findSpot (…)  // Use the findSpot algorithm steps taught in class.
- printList (…)
// print the list to outFile, from listHead to the end of the list in the following format:

listHead -->(“dummy”, 0, next’s chStr1)-->( chStr1, prob1, next’s chStr2)...... --> (chStrj, probj, NULL)--> NULL
	For example: 
listHead -->(“dummy”, 0, “b”)-->( “b”, 5, “a”) -->( “a”, 7, “d”)............ --> (“x”, 45, NULL)--> NULL
******************************************
IV.  Main(argv)
******************************************
Step 1:  listHead ← get a newNode as the dummy listNode with (“dummy” ,0, null),  listHead to point to.  

Step 2: inFile ←open input file using argv
	outFIle ← open ouput file using argv

Step 3: chr  ← get  from inFile
            Prob  ← get  from inFile
	newNode ← get a new listNode (chr, Prob, null)

Step 4: insertNewNode (listHead, newNode) // use algorithm steps given in class
           
Step 5: printList (listHead) // Out put the list to outFile, use the format given in the above.

Step 6: repeat step 3 – step 5 until the end of inFile .
	
Step 7: close all files.

