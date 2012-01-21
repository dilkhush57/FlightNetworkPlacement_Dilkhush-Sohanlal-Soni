/*Fare Matrix Program 2: Game */

/* This program is implemented using circular linklist */

#include<stdio.h>
#include<conio.h>

struct node
{
	int player;
	struct node * next;
};


struct node *current,*head,*save;

int total_players=0;

void freelist()
{
	int i;
	current = head;
	for (i=1;i<=total_players;i++);
	{
		current = current->next;
		free(head);
		head = current;
	}
}

struct node * getnode()
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("\n Memory allocation Failure");
		exit(1);
	}
	else
		return(temp);
}

void list_creation(int n)
{
	struct node *temp;
	int i;
	if (n<=1)
	{
		printf("\n There Should be atleast 2 Players for this game");
		getch();
		return;
	}
	current = getnode();
	current->player = 1;
	current->next = current;
	head = current;

	for (i=2;i<=n;i++)
	{
		temp = getnode();
		current->next = temp;
		current = temp;
		current->player = i;

	}
	current->next = head;
	total_players = n;
 }

void display()
{
	clrscr();
	if (head == NULL)
	{
		printf("\nNo players in the Queue");
		return;
	}

	printf("%d ",head->player);
	current = head->next;
	while( current != head)
	{
		printf("%d ",current->player);
		current = current->next;
	}
	return;
}

struct node * tail()
{
	struct node *temp;
	current = head->next;
	while (current != head)
	{
		temp = current;
		current = current->next;
	}
	return(temp);
}

int remaining_after_died(int by_n)
{
	int i=1,j,removed_player;
	current = head;
	save = tail();

	while (i<total_players)
	{
		for (j=1;j<by_n;j++)
		{
			save = current;
			current = current->next;
		}
		save->next = current->next;
		if (current == head)
		head = current->next;
		removed_player = current->player;
		free(current);

		display();
		printf("\n\n%d is Died \n ",removed_player);
		getch();
		current = save->next;
		i++;
	}
	head = current;
	display();
	total_players = 1;
	return(head->player);
}

void main()
{
	int choice,n;
	head = NULL;

	do
	{
		clrscr();
		printf("\n1. For player list creation");
		printf("\n2. For Display the players list");
		printf("\n3. For Reomove player");
		printf("\n4. For Exit from Game\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the total no. of Player\n");
				scanf("%d",&n);
				list_creation(n);
				break;

			case 2:
				display();
				getch();
				break;

			case 3:

				if (total_players <= 1)
					printf("\There Should Be Atleast 2 Players in this Game");
				else
				{
					printf("\nEnter the number by which Players remove from this Game\n");
					scanf("%d",&n);
					if (n<1)
						printf("\nInvalid Number!");
					else
						printf("\n\n\n\n\n\t\t\tCONGRATULATION...........!!!! \n\n\t\t The  Winner  of  this  Game  is  Player No: %d",remaining_after_died(n));

				}

				getch();
				break;

			case 4:
				return;

			default :
				printf("\nINVALID CHOICE");
				getch();
		}
	}while (choice!=4);
	freelist();
}
