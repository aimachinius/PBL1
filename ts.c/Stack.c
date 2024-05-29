#include <stdio.h>
#include <stdlib.h>
#define Emptypos -1
#define Minsize 5
struct Element
{
	int value;
};
struct StackRecord
{
	unsigned int capacity;
	int tos;
	struct Element *stack_array;
};
typedef struct StackRecord *Stack;
int Isempty(Stack S)
{
	return S->tos == Emptypos;
}
int isfull(Stack S)
{
	return S->tos == S->capacity - 1
}
void makeNull(Stack S)
{
	S->tos = Emptypos;
}
void dispose(Stack S)
{
	if (S != NULL)
	{
		free(S->stack_array);
		free(S);
	}
}
Stack createStack(unsigned int capacity)
{
	if (capacity < Minsize)
	{
		printf("The stack's capacity is at least %d\n", Minsize);
		return NULL;
	}
	Stack S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
	{
		printf("Not enough memory !! \n");
		return;
	}
	S->stack_array = malloc(sizeof(struct ElementRecord) * capacity);
	if (S->stack_array == NULL)
	{
		printf("Not enough memory \n");
		return;
	}
	S->capacity = capacity;
	S->tos = Emptypos;
	return S;
}
void Push(Stack S, struct Element x)
{
	if (isfull(S))
	{
		printf("The stack is full \n");
		return;
	}
	S->stack_array[++S->tos] = x;
}
#define EmptyValue -1000000
struct Element Pop(S)
{
	if (Isempty(S))
	{
		printf("The stack is empty now \n");
		struct Element e;
		e.value = EmptyValue;
		return e;
	}
	return S->stack_array[S->tos--];
}
void Display(Stack S)
{
	if (Isempty(S))
	{
		printf("The stack is empty \n");
		return;
	}
	while (S->tos > -1)
	{
		printf("%d ", S->stack_array[++S->tos].value);
		S->tos--;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("%s", argv);
	struct Element a, b, c, d;
	a.value = 5, b.value = 7, c.value = 7, d.value = 20;
	Stack S = createStack(100);
	Push(S, a);
	Push(S, b);
	Push(S, c);
	Push(S, d);
	Display(S);
}
// #include <stdio.h>
// struct ElementType
// {
// 	/* data */
// 	unsigned long ID;
// 	char *name;
// };
// typedef struct ElementType sv;
// struct Node
// {
// 	/* data */
// 	struct ElementType value;
// 	struct Node *next;
// };
// typedef struct Node *Stack;
// int IsEmty(Stack S ){
// 	return S->next == NULL;
// }
// Stack CreateStack(){
// 	Stack header = malloc(sizeof(struct Node ));
// 	header->next == NULL;
// 	return header;
// }
// void makeNULL(Stack S){
// 	if(S!=NULL){
// 		S->next = NULL;
// 	}else{
// 		printf("You must use createStack first\n");
// 	}
// }
// typedef struct Node *StackNode;

// void push(Stack S,struct ElementType x ){
// 	StackNode node = malloc(sizeof(struct Node ));
// 	node->value = x ;
// 	node->next = S->next;
// 	S->next = node ;
// }
// StackNode top(Stack S){
// 	if(IsEmty(S)){
// 		printf("Stack is empty \n");
// 		return NULL;
// 	}else{
// 		return S->next;
// 	}
// }
// void pop(Stack S ){
// 	if(IsEmty(S)){
// 		printf("Stack is empty\n");
// 		return NULL;
// 	}else{
// 		StackNode firstNode = S->next ;
// 		struct ElementType returnValue = S->value;
// 		S->next = S->next->next;
// 		free(firstNode);
// 	}
// }
// void display(Stack S){
// 	S = S->next;
// 	printf("Current Stack is \n");
// 	while(S!=NULL){
// 		printf(" %ld ",S->value.v);
// 		S = S->next;
// 	}
// 	printf("\n");
// }
// int main(){
// 	Stack S = CreateStack();
// 	struct ElementType v1,v2,v3,v4;
// 	v1.v = 10; v2.v = 13 ; v3.v = 24;v4.v = 19;
// 	push(S,v1);
// 	push(S,v2);
// 	push(S,v3);
// 	push(S,v4);

// 	pop(S);

// 	display(S);

// 	return 0;
// }