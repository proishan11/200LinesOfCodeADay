#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* createNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(struct node* head){
	while(head!=NULL){
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");
}

void insertNode(struct node** head, int data){
	struct node* newNode = createNode(data);
	if(*head == NULL)
		*head = newNode;
	else{
		struct node *temp = *head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
}

int findElement(struct node* head, int element){
	while(head){
		if(head->data == element)
			return 1;
		head = head->next;
	}
	return 0;
}

struct node* simpleUnion(struct node* list1, struct node* list2, struct node** result){
	struct node* temp = list1;
	while(temp!=NULL){
		if(*result == NULL)
			*result = createNode(temp->data);
		else{
			if(!findElement(*result, temp->data))
				insertNode(result, temp->data);		
		}
		temp=temp->next;
	}
	temp = list2;
	while(temp!=NULL){
		if(!findElement(*result, temp->data))
			insertNode(result, temp->data);         //Here **result is already a reference to *result so just pass the result to change it.
		temp=temp->next;
	}
	printf("Union of these lists is\n");
	printList(*result);
}

void partion(struct node* source, struct node** front, struct node **back){
	struct node *slow, *fast;
	if(source==NULL || source->next==NULL){
		*front=source;
		*back=NULL;
	}
	slow = source;
	fast = source->next;
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	*front = source;
	*back = slow;
}

void printPartition(struct node* source){
	struct node *front, *back;
	partion(source, &front, &back);
	printf("Partition 1:\n");
	while(front!=back){
		printf("%d ", front->data);
		front = front->next;
	}
	printf("%d",front->data);
	printf("\nPartition2:\n");
	while(back!=NULL){
		back=back->next;
		if(back!=NULL)
			printf("%d ", back->data);
	}
	printf("\n");
}

int main(){
	struct node *list1 = NULL, *list2 = NULL, *uni=NULL;
	int n, input;
	printf("Enter the number of inputs of list1\n");
	scanf("%d",&n);
	while(n--){
		printf("Enter the values\n");
		scanf("%d",&input);
		insertNode(&list1, input);
	}
	
	printf("Enter the number of inputs of list2\n");
	scanf("%d",&n);
	while(n--){
		printf("Enter the values\n");
		scanf("%d",&input);
		insertNode(&list2, input);
	}

	simpleUnion(list1, list2, &uni);
	//printf("%d %d\n",list2->data,list2->next->next->next->data);
	
	//printPartition(list1);

	return 0;
}