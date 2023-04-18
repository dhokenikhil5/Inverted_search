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
void print_list(file_node_t *head)
{
	if (head == NULL)
	    printf("INFO : List is empty\n");
        else
        {
	    while (head)		
	    {
		    printf("%s -> ", head -> f_name);
		    head = head -> link;
	    }
	    printf("NULL\n");
        }
}

int main(int argc, char *argv[])
{
	if(argc==1)
	{
		printf("No files passed as argument\n");
		return 0;
	}
	file_node_t *head=NULL;
	main_node_t *head2[27]={NULL};
	validate_n_store_filenames(&head,argv);
    print_list(head);
	printf("\n");
	char string[30];
	int choice,ind;
	char ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{
		printf("Select your choice among following options:\n");
		printf("1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\n6. Exit\nEnter your choice\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				if(create_DB(head,head2)==SUCCESS)
					printf("Data base created successfully\n\n");
				else
					printf("DB creation failed\n\n");
				break;
			case 2:
				if(display_DB(head2)==SUCCESS)
					printf("\nDisplayed successfully\n\n");
				else
					printf("Failure in displaying\n\n");
				break;
			case 3:
				printf("Enter the filename that needed to be updated:");
				scanf("%s",string);
				if(update_DB(&head,head2,string)==SUCCESS)
				{
					printf("\n");
				}
				else
					printf("Failure in updating Database\n\n");
				break;
			case 4:
				printf("Enter the word to be searched:");
				scanf("%s",string);
				ind=(toupper(string[0])%65);
				if(ind>25)
					ind=26;
				if(search_DB(head2[ind],string)==SUCCESS)
				{
					printf("\n");
				}
				else
					printf("Word not found in Database!\n\n");
				break;
			case 5:
				printf("Enter the filename to save Database:");
				scanf("%s",string);
				if(save_DB(head2,string)==SUCCESS)
				{
					printf("Database saved successfully in %s\n\n",string);
				}
				else
					printf("Database not saved\n\n");
				break;
			case 6:
				return 0;
			default:
				printf("Invalid option entered\n\n");
		}
	printf("Do you want to continue : ");
	scanf(" %c",&ch);
	}
}
 
                           // PROGRAM ENDS HERE

