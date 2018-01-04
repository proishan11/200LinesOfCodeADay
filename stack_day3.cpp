//Contains errors in prefix to postfix. Fix them whenever you get some time

#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

char push(char a[], int top, char data){
	if(top>=MAX){
		cout<<"Stack Overflow\n";
		return -1;
	}
	else{
		a[++top] = data;
		return top;
	}
}

char pop(char a[], int *top){
	if(*top<0){
		cout<<"Stack underflow\n"<<endl;
		return NULL;
	}
	else{
		int temp = a[(*top)--];
		return temp;
	}
}

bool isEmpty(char a[], int top){
	if(top<0)
		return true;
}

char peek(char a[], int top){
	return a[top];
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

string infixToPostfix(char expression[], char a[], int top){
	int i=0;
	string result="";
	for(int i=0; expression[i]; ++i){
		if(isOperand[expression[i]])
			result+=expression[i];

		else if(expression[i]=='(')
			push(a, &top, expression[i]);

		else if(expression[i] == ')'){
			while(!isEmpty(a, top) && peek(a, top) !='(')
				result+=pop(a, &top);
			pop(a, &top);
		}

		else{
			while(!isEmpty(a, top) && Precedence(expression[i]) <= Precedence(peek(a, top)))
				result += pop(a, &top);
			push(a, &top, expression[i]);

		}
	}

	while(!isEmpty(a,top))
		result+=pop(a,top);

	return result;
}

int main(){
	//initialize stack
	char a[MAX], top=-1;
	char expression[] = "a+b*(c^d-e)^(f+g*h)-i"
	string result = infixToPostfix(expression, a, top);
	cout<<result<<endl;

}