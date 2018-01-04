#include<iostream>
using namespace std;

//Working fine

int dequeue(int a[], int *front,int capacity, int *count){
	int temp;

	if(*count==0)
		cout<<"Underflow\n";
	else{
		temp = a[*front];
		a[*front] = 0;
		(*front) = ((*front)+1)%capacity;
		(*count) = (*count)-1;
	}
	return temp;
}

void enqueue(int a[], int element, int *rear, int capacity, int *count){
	
	if(*count==capacity)
		cout<<"Overflow\n";
	else{
		
		a[*rear] = element;
		(*rear) = ((*rear)+1)%capacity;
		(*count)=(*count)+1;
	}

}

int main(){
	int capacity = 4;
	int a[capacity];
	int front=0, rear=0, count=0;
	enqueue(a, 1, &rear, capacity, &count);
	enqueue(a, 2, &rear, capacity, &count);
	enqueue(a, 3, &rear, capacity, &count);
	enqueue(a, 4, &rear, capacity, &count);
	cout << dequeue(a, &front, capacity, &count)<< endl;
	enqueue(a, 1, &rear, capacity, &count);
	cout<<a[rear]<<endl;
	enqueue(a, 1, &rear, capacity, &count);
	//cout<<"count="<<count<<endl;
	//cout << dequeue(a, &front, capacity, &count)<<endl;
	//cout<<"count="<<count<<endl;
	//cout<<dequeue(a, &front, capacity, &count)<<endl;

}