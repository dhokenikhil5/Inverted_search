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

void validate_n_store_filenames(file_node_t **head,char *filename[])
{
	int i,count=0,flag;
	while(filename[count]!=NULL)
		count++;
	for(i=1;i<count;i++)
	{
		if(IsFileValid(filename[i])==SUCCESS)
		{
			if(store_filenames_to_list(filename[i],head)==SUCCESS)
			{
				printf("The no.%d argument is valid and hence stored successfully\n",i);
			}
			else
				printf("The no.%d argument is not valid and storing failed\n",i);
		}
		else
			printf("The no.%d argument is not valid\n",i);
		printf("\n");
	}
}	
int IsFileValid(char *filename)
{
	FILE *fptr=fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("File doesn't exist\t");
		//fclose(fptr);
		return FAILURE;
	}
	fseek(fptr,0,SEEK_END);
	if(ftell(fptr)==0)
	{
		printf("File empty\t");
		fclose(fptr);
		return FAILURE;
	}
	else
		return SUCCESS;
}
int store_filenames_to_list(char *filename,file_node_t **head)
{
	int value;
	file_node_t *new,*temp;
	if(*head==NULL)
	{
		new=malloc(sizeof(file_node_t));
		if(new==NULL)
		{
			printf("Memory allocation failed\n");
			return FAILURE;
		}
		else
		{
			strcpy(new->f_name,filename);
			new->link=NULL;
			*head=new;
			return SUCCESS;
		}
	}
	else
	{
		temp=*head;
		while(temp!=NULL)
		{
			value=strcmp(temp->f_name,filename);
			if(value==0)
			{
				return FAILURE;
			}
			temp=temp->link;
		}
		new=malloc(sizeof(file_node_t));
		if(new==NULL)
		{
			printf("Memory allocation failed\n");
			return FAILURE;
		}
		else
		{
			strcpy(new->f_name,filename);
			new->link=*head;
			*head=new;
			return SUCCESS;
		}
	}
}
            // PROGRAM ENDS HERE
