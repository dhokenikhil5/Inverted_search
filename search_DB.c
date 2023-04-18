/*

Name           : NIKHIL RAMESH DHOKE
Date           : 13-3-23
Description    : Inverted Search
Sample input   : 
Sample output  :

*/
       // PROGRAM STARTS

#include <stdio.h>
#include "inverted_index.h"

int search_DB(main_node_t *head,char *word)
{
	if(head==NULL)
		return FAILURE;
	while(head!=NULL)
	{
		if(strcmp(head->word,word)==0)
		{
			printf("The word [%s] is present in %d files\n",head->word,head->f_count);
			sub_node_t *temp=head->sub_link;
			while(temp!=NULL)
			{
				printf("In file: %s %d times\n",temp->f_name,temp->w_count);
				temp=temp->link;
			}
			return SUCCESS;
		}
		head=head->link;
	}
	return FAILURE;
}

      // PROGRAM ENDS HERE
