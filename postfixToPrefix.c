#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
struct stackk{
	char stack[MAX];
};
struct stackk s[MAX];
int top=-1;

int isFull();
int isEmpty();
void push(char*);
int isOperator(char);
int isOperand(char);
char *pop();

int main(){
	char postfix[MAX],temp[2];
	int i=0,j=0;
	printf("Enter an postfix expression: ");
	gets(postfix);
	while(postfix[i]!='\0'){
		char exp[MAX]={'\0'},op1[MAX]={'\0'},op2[MAX]={'\0'};
		temp[0]=postfix[i];
		temp[1]='\0';
		if(isOperand(temp[0])){
			push(temp);
		}else if(isOperator(temp[0])){
			strcpy(op2,pop());
			strcpy(op1,pop());
			strcat(exp,temp);
			strcat(exp,op1);
			strcat(exp,op2);
			push(exp);
		}else{
			printf("Invalid Arithmetix expression!\n");
			exit(0);
		}
		i++;
	}
	printf("The prefix expression is: ");
	puts(s[0].stack);
}

void push(char *item){
	if(isFull()){
		printf("Overflow detected!\n");
	}else{
		top++;
		strcpy(s[top].stack,item);
	}
}

int isFull(){
	if(top==MAX-1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}

int isOperator(char sym){
	if(sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='^'){
		return 1;
	}else{
		return 0;
	}
}

char *pop(){
	if(isEmpty()){
		exit(0);
	}
	return s[top--].stack;
}

int isOperand(char sym){
	if(sym>='A'&&sym<='Z'||sym>='a'&&sym<='z'){
		return 1;
	}else{
		return 0;
	}
}
