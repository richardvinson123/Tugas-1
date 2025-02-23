#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int x;
	tnode *next;
	tnode *prev;
}*head, *tail, *curr;

void push_front(int value)
{

	struct tnode node = (tnode)malloc(sizeof(tnode));
	node->x = value;

	if(head==NULL)
	{
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
		head->prev = NULL;
	}
}

void push_back(int value)
{

	struct tnode node = (tnode)malloc(sizeof(tnode));
	node->x = value;

	if(head==NULL)
	{
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
		tail->next = NULL;
	}
}

void push_mid(int value, int searchKey)
{

	struct tnode node = (tnode)malloc(sizeof(tnode));
	node->x = value;

	if(head==NULL)
	{
		head = tail = node;
		tail->next = NULL;
	}
	else
	{

		while(curr!=NULL)
		{
			if(curr->x == searchKey)
			{
				if(curr==tail)
				{
					push_back(value);
				}
				else
				{
					node->next = curr->next;
					curr->next = node;
				}
				break;
			}
			curr = curr->next;
		}
		if(curr==NULL)
		{
			printf("Data %d not found\n", searchKey);
		}
	}
}

void delete_front(){
	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}

	else{
		if(head == tail)
		{
			free(head);
			head = tail = NULL;
		}

		else
		{
			tnode *curr = head;
			head = head->next;
			free(curr);
			head->prev = NULL;
		}
	}
}

void delete_back(){
	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}

	else{
		if(head == tail)
		{
			free(tail);
			tail = head = NULL;
		}

		else
		{
			tnode *ToDel = tail;
			tail = tail->prev;
			free(ToDel);
			tail->next = NULL;
		}
	}
}

void delete_mid(int value){

	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}

	if(value == head->x)
	{
		delete_front();
	}
	else if(value == tail->x)
	{
		delete_back();
	}
	else
	{
		tnode *curr = head;

		while(curr)
		{

			if(curr->x == value)
			{
				break;
			}
			curr = curr->next;
		}

		tnode *prevNode = curr->prev;
		tnode *nextNode = curr->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		free(curr);
		curr = NULL;
	}
}

void clearData()
{
	while(head!=NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

void printList()
{
	if(head==NULL)
	{
		printf("There is No Data\n");
		return;
	}

	curr = head;

	while(curr!=NULL)
	{
		printf("%d ", curr->x);
		curr=curr->next;
	}
}


int main()
{
	printf("PUSH DATA\n");

	push_front(11);
	push_back(90);
	push_front(78);
	push_back(50);

	delete_front();
	delete_back();


	printList();getchar();
	return 0;
}
