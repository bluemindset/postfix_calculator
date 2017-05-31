#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100

typedef struct qnode { // defining a stract with token as a character
	char data_token ;
	int prio;
	struct qnode* next;
}q_node;

typedef struct stack {
	q_node  *top;
	int size;
}stack;
stack *initialize_stack() {

	stack  *post_stack = (stack *)malloc(sizeof(stack));
	if (post_stack == NULL)
		return NULL;
	post_stack->top = NULL;
	post_stack->size = 0;
	return post_stack;

}


int  push_q(char value, stack *s) {
	q_node *p = NULL;
	p = (q_node*)malloc(sizeof(q_node));
	if (p == NULL)
		return (EXIT_FAILURE);
	p->data_token = value;
	p->next = s->top;
	s->top = p;
	s->size++;
	return EXIT_SUCCESS;
};

int  pop_q(stack *s, char first) {
	q_node *p = NULL;
	if (s == NULL || s->size == 0)
		return EXIT_FAILURE;
	first = (s->top)->data_token;
	p = s->top;
	s->top = p->next;
	(s->size)--;
	free(p);
	return EXIT_SUCCESS;

}

int s_isEmpty(stack *s) {
	return s->size == 0;
}

int isOperand(char ch) {

	return  ( (ch >= '1') && (ch <= '9') ); 
	
}

int priority(char ch){
	if (ch == '+')
		return 1;
	if (ch == '*')
		return 2;
	if (ch == '/')
		return 2;
	if (ch == '-')
		return 1;
	else
		return 0;

}


int main() {
	int i;
	char userinput[MAX_SIZE];
	stack *s = NULL;
	char* p = NULL;
	printf("Welcome.Please enter your infix expression!\n");
	gets(userinput);
	char* ch;
	ch = userinput;
	s = initialize_stack();


	while (*ch != '\0'){
		if (isOperand(*ch)) {
			printf("%c", *ch);
		}
		else {
			if (s_isEmpty(s) || (s->top)->data_token == '(')
				push_q(*ch, s);

			else if (*ch == '(')
				push_q(*ch, s);

			else if (*ch == ')') {
				if (((s->top)->data_token != ')') && ((s->top)->data_token != '('))
					printf("%c", (s->top)->data_token);
				pop_q(s, (s->top)->data_token);
				while ((s->top)->data_token != '(') {
					if (((s->top)->data_token != ')') && ((s->top)->data_token != '('))
						printf("%c", (s->top)->data_token);
					pop_q(s, (s->top)->data_token);
				}
			}

			else if (priority(*ch) > priority((s->top)->data_token)) {
				push_q(*ch, s);
			}

			else if ( priority(*ch) == priority((s->top)->data_token) ) {
				if (((s->top)->data_token != ')') && ((s->top)->data_token != '(')) {
					printf("%c", (s->top)->data_token);
					pop_q(s, (s->top)->data_token);
					push_q(*ch, s);
				}
			
			}
			else if  (priority(*ch) < priority((s->top)->data_token)) {
				printf("%c", (s->top)->data_token);
				pop_q(s, (s->top)->data_token);
				push_q(*ch, s);
				
				while (!s_isEmpty(s) && priority(*ch) < priority((s->top)->data_token) && ((s->top)->data_token != ')') && ((s->top)->data_token != '('))
				{
					if (priority(*ch) > priority((s->top)->data_token)) {
						push_q(*ch, s);
					}

					else if (priority(*ch) == priority((s->top)->data_token)) {
						if (((s->top)->data_token != ')') && ((s->top)->data_token != '(')) {
							printf("%c", (s->top)->data_token);
							pop_q(s, (s->top)->data_token);
							push_q(*ch, s);
						}
					}
				}

			}

		}
		
			
		ch++;
	}


	while(!s_isEmpty(s))
	{
	if (((s->top)->data_token != ')') && ((s->top)->data_token != '('))
			printf("%c", (s->top)->data_token);
			pop_q(s, (s->top)->data_token);
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}