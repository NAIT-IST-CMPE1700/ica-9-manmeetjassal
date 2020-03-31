#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
	char firstName[10];
	int IDnumber;
	int studentMarks;
	struct node* next;
};
typedef struct node* ptr;

ptr CreateNode()
{
	ptr pNode;
	pNode = (ptr)malloc(sizeof(struct node));
	pNode->next = NULL;
	return pNode;
}

ptr AddNodeInc(ptr head, char* str, int id, int mark)
{
	ptr temp, current;
	temp = CreateNode();
	temp->IDnumber = id;
	temp->studentMarks = mark;
	strcpy(temp->firstName, str);
	if (head == NULL)
	{
		head = temp;
	}
	else {
		if (id < head->IDnumber)
		{
			temp->next = head;
			head = temp;
			temp = NULL;
		}
		else {
			current = head;
			while ((current->next != NULL) && (current->next->IDnumber < id))
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
			temp = NULL;
		}
	}
	return head;
}
ptr AddNodeDec(ptr head, char* string, int id, int mark)
{
	ptr current, temp;
	temp = CreateNode();
	temp->IDnumber = id;
	temp->studentMarks = mark;
	strcpy(temp->firstName, string);
	if (head == NULL)
	{
		head = temp;
	}
	else {
		if (mark > head->studentMarks)
		{
			temp->next = head;
			head = temp;
			temp = NULL;
		}
		else {
			current = head;
			while ((current->next != NULL) && (current->next->studentMarks > mark))
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
			temp = NULL;
		}
	}
	return head;
}

void displaySearchedID(ptr searched, int id)
{
	ptr current = searched;
	int rank = 0;
	while (current != NULL)
	{
		if (current->IDnumber == id)
		{
			printf("Name : %s ID: %d Mark: %d Rank: %d\n", current->firstName, current->IDnumber, current->studentMarks, rank);

		}
		current = current->next;
		rank++;
	}

}
void displayThreshold(ptr head, int value)
{
	ptr current;
	current = head;
	while (current->studentMarks > value)
	{
		printf("Name : %s ID: %d Mark: %d\n", current->firstName, current->IDnumber, current->studentMarks);
		current = current->next;
	}
	printf("\n");
}
void displayList(ptr head)
{
	ptr current;
	current = head;
	while (current != NULL)
	{
		printf("Name : %s ID: %d Mark: %d\n", current->firstName, current->IDnumber, current->studentMarks);
		current = current->next;
	}
	printf("\n");
}
int main(void)
{
	char name[10][20] = { "Aragorn","Mclovin","Kumar","Jose","Jeff","Beyonce","Riri","JayZ","Asa","Ramona" };
	char givenID[10] = { 6,4,2,7,5,8,10,9,1,3 };
	char marks[10] = { 76,81,96,99,51,60,90,87,67,74 };
	ptr L = NULL;
	ptr secondL = NULL;
	int idNum = 0;
	int markNum = 0;
	int userChoice = 0;
	do {
		printf("Enter a program you want to run: ");
		scanf_s("%d", &userChoice, sizeof(int));
		switch (userChoice)
		{
		case 1:
		{
			for (int i = 0; i < 10; i++)
			{
				L = AddNodeInc(L, name[i], givenID[i], marks[i]); // 1 with displaylist
				//L = AddNodeDec(L, name[i], givenID[i], marks[i]); // 2 with displaylist
			}
			displayList(L);
			break;
		}
		case 2:
		{
			for (int i = 0; i < 10; i++)
			{
				//L = AddNodeInc(L, name[i], givenID[i], marks[i]); // 1 with displaylist
				secondL = AddNodeDec(secondL, name[i], givenID[i], marks[i]); // 2 with displaylist
			}
			displayList(secondL);
			break;
		}
		case 3:
		{
			printf("Enter ID: ");
			scanf_s("%d", &idNum, sizeof(int));
			displaySearchedID(secondL, idNum);
			break;
		}
		case 4:
		{
			printf("Enter Mark Threshold: ");
			scanf_s("%d", &markNum, sizeof(int));
			displayThreshold(secondL, markNum);
		}
		}
	} while (userChoice != 5);
	exit(EXIT_SUCCESS);


}