#include "header.h"

void deleteAccount(doublyLinkedListType &accountList)
{
	
	nodeType *current = nullptr;
	current = findNode(); //findNode returns a nullptr if no object is found
	
	if(current != nullptr)
	{
	
		if(current->prev != nullptr)
		{
			current->prev->next = current->next;
		}
		else 
		{
			head = current->next; //update the head before delete 
		}


		if(current->next != nullptr)	
		{
			current->next->prev = current->prev;
		}
		else
		{
			tail = current->prev; //update the tail before deleting it
		}

		delete current;

	}


}

