/*
***
***					Notes:
***---------------------------------------------------------------------------------
***	char.c_str():	   returns the current value of the string object
***	atoi(ASCII Value): returns the integer representation of an ascii character
***	to_string(number): returns a string containing the representation of a number
***---------------------------------------------------------------------------------
***
***
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class listNode
{
	public:
		string chStr;
		int prob;
		listNode* next;
		listNode();
		listNode(string, int, listNode*);
};

listNode::listNode()
{
	chStr = "dummy";
	prob = -1;
	next = NULL;
}

listNode::listNode(string chStr, int prob, listNode* next)
{
	this->chStr = chStr;
	this->prob = prob;
	this->next = next;
}

class linkedList
{
	public:
		listNode listHead;
		listNode* findSpot(listNode const*, listNode*);
		void insertNewNode(listNode*,listNode*);
		string printList(listNode);
};

listNode* linkedList::findSpot(listNode const* listHead, listNode* newNode)
{
	listNode* spot = (listNode*)listHead;
	while(spot->next != NULL)
	{	
		if(spot->next != NULL && spot->next->prob < newNode->prob)
			spot = spot->next;
		else
			return spot;
	}
	return spot;
}

string linkedList::printList(listNode listHead)
{
	string line = "listHead --> ";
	listNode* ptr = &(listHead);// pointer to the head of the list
	while(ptr->next != NULL)
	{
		line += "(\"" + ptr->chStr +"\", " + to_string(ptr->prob);
		line += ", \"" + ptr->next->chStr + "\") --> ";
		ptr = ptr->next;
	}

	line += "(\"" + ptr->chStr + "\", ";
	line += to_string(ptr->prob) + ", NULL) --> NULL\n";
	return line;
}

void linkedList::insertNewNode(listNode* listHead, listNode* newNode)
{
	listNode* temp = findSpot(listHead, newNode);
	newNode->next = temp->next;
	temp->next = newNode;
}

int main(int argc, char** argv)
{
	linkedList L;
	string word;
	string charIn;
	int prob;

	/* true reads string from file
	** false: reads integer from file
	*/ 
	bool isChar_Num = true;
	
	ifstream inFile;
	inFile.open(argv[1]);
	ofstream outFile(argv[2]);

	while(inFile >> word)
	{
		if(isChar_Num == true)
		{
			charIn = word;
			isChar_Num = false;
		}
		else
		{
			prob = atoi(word.c_str());
			if(prob > 0)
			{

				/* Adding newNode to the linked list */

				listNode* tempNode = new listNode(charIn,prob,NULL);
				L.insertNewNode(&L.listHead, tempNode);
			}
			
			isChar_Num = true;
		}
	}
	outFile << L.printList(L.listHead) << endl;

	inFile.close();
	outFile.close();

	return 0;
}
