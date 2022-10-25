#include <stdio.h>
#include <stdlib.h>

#define NUll 0

struct Node {
	int coeff;
	int pow;
	struct Node *next;

};

void create_node(int x, int y, struct Node **temp){
	struct Node *r,*z;
	z = *temp;
	if(z==NUll){
		r=(struct Node*)malloc(sizeof(struct Node));
		r->coeff =x;
		r->pow = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r= r->next;
		r->next = NULL;
	}
	else {
		r->coeff = x;
		r->pow = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r= r->next;
		r->next = NUll;
	}
}

void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly){
	while(poly1->next && poly2->next){
		if(poly1->pow > poly2->pow){
			poly->pow = poly1->pow;
			poly->coeff = poly->pow;
			poly1 = poly->next;
		}
		else if (poly1->pow < poly2->pow){
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2=poly2->next;
		}
		else {
			poly->pow = poly->pow;
			poly->coeff = poly1->coeff+poly2->coeff;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		poly->next = (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}

	while(poly1->next || poly2->next){
		if(poly1->next){
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;

		}
		if (poly2->next)
		{
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}

		poly->next = (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
}

void show(struct Node* node){
	while(node->next != NULL){
		printf("%dx^%d", node->coeff,node->pow);
		node = node->next;
		if(node->next != NULL){
			printf(" + ");
		}
	}
}

int main(){

	struct Node *poly1=NULL;
	struct Node *poly2=NULL;
	struct Node *poly=	(struct Node*) malloc(sizeof(struct Node));

// first
	create_node(5,2,&poly1);
	create_node(4,1,&poly1);
	create_node(2,0,&poly1);
// second
	create_node(5,1,&poly2);
	create_node(5,0,&poly2);

	printf("1st Number: \n");
	show(poly1);

	printf("\n2nd Number: \n");
	show(poly2);

	// fun add two
	polyadd(poly1,poly2,poly);

	//Display list
	printf("\n Addd polynomial\n");
	show(poly);


	
	return 0;
}