#include <stdio.h>
#include <stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	int ch, entry;
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	while(1)
	{
		printf("\n1. Append at start\n2. append at end\n3.display\n4. Delete Head\n5. Delete Tail\n6. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					head->prev=(struct node*)malloc(sizeof(struct node));
					head->prev->next=head;
					head->prev->data=entry;
					head->prev->prev=NULL;
					head=head->prev;
				}break;
			}
			case 2:
			{
				printf("Enter Data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}break;
			}
			case 3: 
			{
				pos=head;
				printf("\nElements in forward order are:");
				while (pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				} break;
			}
			case 4:
			{
				struct node *temp=head;
				head=head->next;
				temp->next=NULL;
				head->prev=NULL;
				free(temp);
				break;
			}
			case 5:
			{
				struct node *temp=tail;
				tail=tail->prev;
				temp->prev=NULL;
				tail->next=NULL;
				free(temp);
				break;
			}
			case 6:
			{
				printf("\nGood Bye\n");
				exit(0);
			}
		}
	}
}

