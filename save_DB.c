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

int save_DB(main_node_t **head,char *filename)
{
	FILE *fptr=fopen(filename,"w");
	for(int i=0;i<27;i++)
	{
		if(head[i]!=NULL)
		 write_tofile(head[i],fptr);
	}
	fclose(fptr);
	return SUCCESS;
}

void write_tofile(main_node_t *head,FILE *fptr)
{
	int ind;
	while(head!=NULL)
	{
		ind=(toupper(head->word[0])%65);
		if(ind>25)
			ind=26;
		fprintf(fptr,"#[%d];\n%s;%d;",ind,head->word,head->f_count);

		sub_node_t *temp=head->sub_link;
		
		while(temp!=NULL)
		{
			fprintf(fptr,"%s;%d;",temp->f_name,temp->w_count);
			temp=temp->link;
		}
		fprintf(fptr,"#\n");
		head=head->link;
	}
}
        // PROGRAM ENDS HERE
