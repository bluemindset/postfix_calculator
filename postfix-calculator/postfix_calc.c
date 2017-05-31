#include "stdio.h"
#include "stdlib.h"



typedef struct stack_node {

	int data;
	struct stack_node *next;


}node;


typedef struct stack {
	int size;
	node *top;
}stack;



int initialize_stack(stack **s ) {
	*s = (stack *)malloc(sizeof(stack)); // standards initialization
	if (*s == NULL)
		return EXIT_FAILURE;
	(*s)->top = NULL;
	(*s)->size = 0;

	return EXIT_SUCCESS;

}

void push_n(stack *s, int value)
{
	node *new_node = (node *) malloc(sizeof(node));
	
	new_node->next = s->top; // (new pointer)-> top
	s->top = new_node;	// top -> node 
	new_node->data = value;
	(s->size)++;

}

void pop(stack *s) {

	node *pop = NULL;
	
	pop = s->top;
	s->top	= pop->next  ;
	(s ->size)--;
	free(pop);
	
}

int isOperand(char ch) {
	if (ch == '1'|| ch == '2'||ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0' )
		return 1;
	return 0;
}
void  exp_(int topstack,int temp, char symbol, stack* s) {

	int re=0;
	switch (symbol) {

	case '+':
		re = topstack + temp;
		break;
	case '-':
		re =    topstack- temp  ;
		break;
	case '/': 
		re = topstack / temp;
		break;
	case '*': 
		re = topstack * temp;
		break;
	default: return;
	}
		pop(s);
	push_n(s, re);
}



int isOperator(char ch) {
	if (ch == '+' || ch== '-' || ch== '*' || ch == '/')
		return 1;

	return 0;
}
int main() {

	stack *s = NULL; 
	char userinput[20];
	initialize_stack(&s);
	char* ch;
	printf("Please enter the correct postfix expression:\n");
	gets(userinput);
	int temp;
	ch = userinput;
	
	while (*ch != '\0') {
		if (isOperand(*ch)){
			push_n(s,abs( (int)(*ch)-48 ));
		}

		if (isOperator(*ch)) {
				temp= (s->top)->data;
				pop(s);
				exp_((s->top)->data, temp ,*ch,s);
			}
		ch++;	
		}
	

	printf("\n\nThe expression evaluation is: %d\n", (s->top)->data);
	system("pause");
	return 0;
}