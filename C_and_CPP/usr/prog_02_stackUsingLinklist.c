#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct node {
	int val;
	struct node *next;
};

struct node *top;
int val,item,i;

void push(){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)	{
		printf("\n Cannot push the elemnet\n");
	} else {
		printf("\n Enter the value : ");
		scanf("%d", &val);
		if(top == NULL){
			ptr->val = val;
			ptr->next = NULL;
			top = ptr;
		} else {
			ptr->val = val;
			ptr->next = top;
			top = ptr;
		}
		printf("\n Item Pushed\n");
	}

}

void pop(){
	struct node *ptr;
	if(top == NULL){
		printf("\n Underflow\n");
	} else {
		item=top->val;
		ptr  = top;
		top = top->next;
		free(ptr);
		printf("\n Item Popped= %d \n", item);
	}

}

void display(){
	struct node *ptr;
	ptr=top;
	if(ptr==NULL){
		printf("\n Stack is empty\n");
	} else {
		printf("\n Printing statck elemnet\n");
		while(ptr != NULL){
			printf("\n %d ", ptr->val);
			ptr=ptr->next;
		}
	}
}

int main(){
	int choice;
	while(choice!=4){
		printf("\nChoose any on option");
		printf("\n1. Push\n2. Pop=2\n3. Display\n4. Exit\n");
		printf("\nEnter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n Exiting");
				exit(0);
			default:
				printf("\n Error...\n Enter a valid choice");
		};

	}


	return 0;
}
