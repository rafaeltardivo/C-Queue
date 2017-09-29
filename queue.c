#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{

	int data;
	struct node* previous;

}*node_ptr;


node_ptr front = NULL;
node_ptr rear = NULL;

bool is_empty(){

	return (front == NULL);
}

void display_front(){

	if(is_empty())
		printf("\nThe queue is empty!\n");
	else
		printf("\n[%d]\n", front->data);
}

void display_rear(){

	if(is_empty())
		printf("\nThe queue is empty!\n");
	else
		printf("\n[%d]\n", rear->data);
}

bool enqueue(int value){

	node_ptr item = (node_ptr) malloc(sizeof(struct node));

	if(item != NULL){

		item->data = value;
		item->previous = NULL;

		if(rear == NULL)
			front = rear = item;
		else{
			rear->previous = item;
			rear = item;
		}

		return true;
	}

	return false;

}

bool dequeue(){

	if(is_empty())
		printf("\nThe queue is empty!\n");
	else{

		node_ptr temp = front;
		front = front->previous;
		free(temp);

		return true;
	}

	return false;

}

void display(){

	if(is_empty())
		printf("\nThe queue is empty!\n");
	else{

		node_ptr temp = front;

		printf("\n[front -> ");

		while(temp != NULL){
			printf("[%d]", temp->data);
			temp = temp->previous;
		}

		printf(" <- rear]\n");

	}	

}

bool clear(){

	if(is_empty())
		printf("\nThe queue is empty!\n");
	else{

		node_ptr current = front;
		node_ptr previous = NULL;

		while(current != NULL){

			previous = current->previous;
			free(current);
			current = previous;
		}

		front = NULL;

		return is_empty();
	}

	return false;
}


void main(){

	int option = 0, value = 0;

	do{
		
		printf("\nQUEUE Menu\n"
			   "\n1 - Is Empty?"
			   "\n2 - Enqueue"
			   "\n3 - Dequeue"
			   "\n4 - Show FRONT"
			   "\n5 - Show REAR"
			   "\n6 - Display elements"
			   "\n7 - Clear queue"
			   "\n\n0 - EXIT\n\n");

		printf("option: ");
		scanf("%d", &option);

		switch(option){

			case 0:
				break;

			case 1:
				printf(is_empty() ? "\nTrue\n" : "\nFalse\n");
				break;

			case 2:
				printf("\nInsert a integer value to enqueue: ");
				scanf("%d", &value);
				printf(enqueue(value) ? "\nEnqueued :)\n" : "\nSomething went wrong :(\n");
				break;

			case 3:
				printf(dequeue() ? "\nDequeued :)\n" : "\nSomething went wrong :(\n");
				break;

			case 4:
				display_front();
				break;

			case 5:
				display_rear();
				break;

			case 6:
				display();
				break;

			case 7:
				printf(clear() ? "\nCleared :)\n": "\nSomething went wrong :(\n");
				break;

			default:
				printf("\nINVALID OPTION!!!\n");
				break;

		}

	}while(option != 0);

	printf("\n\n** See more at: https://github.com/rafaeltardivo \n\n");
}
