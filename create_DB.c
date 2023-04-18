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

int create_DB(file_node_t *file_head,main_node_t **head)
{
	while(file_head!=NULL)
	{
		read_datafile(file_head,head);
		file_head=file_head->link;
	}
	return SUCCESS;
}
void read_datafile(file_node_t *filehead,main_node_t **head)
{
	FILE *fptr=fopen(filehead->f_name,"r");
	rewind(fptr);
	char word[20];
	int flag,ind=0;
	while(fscanf(fptr,"%s",word)!=EOF)
	{
		flag=1;
		ind=(toupper(word[0])%65);
		if(ind>25)
			ind=26;
		
		if(head[ind]!=NULL)
		{
			main_node_t *temp=head[ind];
			while(temp!=NULL)
			{
				if(strcmp(temp->word,word)==0)
				{
					update_word_count(&head[ind],filehead->f_name);
					flag=0;
				}
				temp=temp->link;
			}
		}
		if(flag==1)
		    insert_at_last_main(&head[ind],word,filehead->f_name);
		    
	}
	printf("Database created for %s\n",filehead->f_name);
}

int insert_at_last_main(main_node_t **head,char *word,char *filename)
{
	main_node_t *new=malloc(sizeof(main_node_t));

	new->f_count=1;
	strcpy(new->word,word);
	new->link=NULL;

	update_link_table(&new,filename);

	if(*head==NULL)
	{
		*head=new;
		return SUCCESS;
	}
	main_node_t *temp=*head;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=new;
	return SUCCESS;
}

int update_link_table(main_node_t **head,char *filename)
{
	sub_node_t *new2=malloc(sizeof(sub_node_t));
	if(new2==NULL)
		return FAILURE;
	new2->w_count=1;
	strcpy(new2->f_name,filename);
	new2->link=NULL;

	(*head)->sub_link=new2;
	return SUCCESS;
}

int update_word_count(main_node_t **head,char *filename)
{
	main_node_t *temp2=*head;
	sub_node_t *temp=(*head)->sub_link;
	sub_node_t *prev=(*head)->sub_link;

	while(temp!=NULL)
	{
		if(strcmp(temp->f_name,filename)==0)
		{
			temp->w_count++;
			return SUCCESS;
		}
		prev=temp;
		temp=temp->link;
	}

	sub_node_t *new=malloc(sizeof(sub_node_t));
	if(new==NULL)
		return FAILURE;
	new->w_count=1;
	strcpy(new->f_name,filename);
	new->link=NULL;

	prev->link=new;

	temp2->f_count=temp2->f_count+1;
	return SUCCESS;
}

            // PROGRAM ENDS HERE
            
                     
            
            
  
