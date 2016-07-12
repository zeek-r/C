/** C Program for basic model of stack operations **/
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct{
	int array[MAX];
	int tos;
}stack;

void PUSH(stack *s, int psh);
int POP(stack *s);
void Display(stack *s);

int main(void)
{
	stack *s; 
	//s = malloc(sizeof(stack));
	s->tos = -1;
	int n, ch;
	//ask user for the size of the stack
	printf("Please enter the size of the stack: ");
	scanf("%d", &n);
	//Call stack_builder function for building the stack
	//int flag = stack_builder(s, n);
	/**if(flag != 0)
	{
		printf("Sorry the stack can't be created :(\n");
	}**/
	do
	{
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Plese select stack operation: ");
		scanf("%d", &ch);
	
	
	switch(ch)
	{
		//If the selection by the user is PUSH
		case 1:
		{
			int el;
			printf("Please enter the element to PUSH into the stack: ");
			scanf("%d", &el);
			PUSH(s, el);
			break;
		}
		// If the selection by the user is POP
		case 2:
		{
			if (s->tos == -1)
			{
				printf("No element to POP, please build the stack at first\n");
				return 0;
			}
			
			int dt;
			dt = POP(s);
			printf("The element popped from the stack is %d", dt);
			break;
		}
		//If the selection by the user is Display
		case 3:
		{
			Display(s);
			break;
		}
		//If the user want to exit from the program
		case 4:
		{
			exit(0);
			break;
		}
		
		default:
		{
			printf("!!Runtime error!!:\nPlease check for the syntactical error\n");
			exit(0);
		}
	}
	}while(ch < 1 || ch >4);
	return 0;
}


//function for the PUSH operatuion
void PUSH(stack *s, int psh)
{
	s->tos++;
	s->array[s->tos] = psh;
}
//Function for the POP operation
int POP(stack *s)
{
	int d;
	d = s->array[s->tos];
	s->tos--;
	return d;
}

void Display(stack *s)
{
	for(int i = 0; i <= s->tos; i++)
	{
		printf("[%d]\n", s->array[i]);
	}
}

