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

int display_DB(main_node_t **head)
{
	int i;
	printf("[index]	 word	file_count	file(s):	file_name	word_count\n");
	for(i=0;i<27;i++)
	{
		if(head[i]!=NULL)
	          print_words(head[i]);
	}
	return SUCCESS;
}

void print_words(main_node_t *head)
{
	int ind=0;
	while(head!=NULL)
	{
		ind=(toupper(head->word[0])%65);
		if(ind>25)
			ind=26;
		printf("[%d]	%s 	%d		file(s): ",ind,head->word,head->f_count);

		sub_node_t *subhead=head->sub_link;
		while(subhead!=NULL)
		{
			printf("	%s		%d",subhead->f_name,subhead->w_count);
			subhead=subhead->link;
		}
		printf("\n");
		head=head->link;
	}
}
            // PROGRAM ENDS HERE
