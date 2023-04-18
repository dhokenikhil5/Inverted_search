/*

Name           : NIKHIL RAMESH DHOKE
Date           : 13-3-23
Description    : Inverted Search
Sample input   : 
Sample output  :

*/
       // PROGRAM STARTS

#include "inverted_index.h"
#include <stdio.h>

int update_DB(file_node_t **file_head,main_node_t **head,char *filename)
{
	if(IsFileValid(filename)==FAILURE)
	{
		printf("File not added to file list!\n");
		return FAILURE;
	}
	else
	{
		if(store_filenames_to_list(filename,file_head)==FAILURE)
		{
			printf("File already exist in the file list!\n");
			return FAILURE;
		}
		else
		{
			printf("%s added the file list successfully\n",filename);
			read_datafile(*file_head,head);
			return SUCCESS;
		}
	}
	return FAILURE;
}
      // PROGRAM ENDS HERE

