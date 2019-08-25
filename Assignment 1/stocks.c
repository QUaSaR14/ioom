/*
                                    Assignment 1 , IOOM
                                Submitted by : Madhur Trivedi
                                Date : 21/08/2019
                                Enrollment No. : BT17CSE039
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHARES 100
#define MAX_STOCKS 10
#define MAX_STOCK_NAME 5

typedef struct Stack_type {
	int top;
	unsigned capacity;
	int* array;
}Stack;

typedef struct QNode_type {
    int key;
    struct QNode_type* next;
} QNode;

typedef struct Queue_type {
    QNode *front, *rear;
    int capacity;
}Queue;

typedef struct Purchase_Price
{
    Stack *price_stack;
    Queue *price_queue;
}Prices;

typedef struct Stock_details
{
    char stock_id[MAX_STOCK_NAME];
    int no_of_shares;
    Prices prices;
}Stock;

typedef struct Node {
	Stock stock_node;
	struct Node * next;
} Stock_List;


Stack* createStack(unsigned capacity)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack)
{
	return stack->top == -1;
}

void stack_push(Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	//printf("%d pushed to stack\n", item);
}

int stack_pop(Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

float get_lifo_sum(Stack * stack, int n)
{
	if(n>stack->capacity || isEmpty(stack))
	{
		return 0;
	}

	float sum = 0;
	int i=n;
	while(i-- && !isEmpty(stack))
	{
		sum += stack_pop(stack);
	}
	return sum/n;
}

QNode* newNode(int k)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->capacity = 0;
    return q;
}

void enQueue(Queue* q, int k)
{
    QNode* temp = newNode(k);

    ++(q->capacity);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    //printf("%d \n", q->capacity);
}

QNode* deQueue(Queue* q)
{
    if (q->front == NULL)
    return NULL;

    QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    q->rear = NULL;
    --(q->capacity);
    return temp;
}

float get_fifo_sum(Queue * q, int n)
{
    if(n>q->capacity || !(q->front))
        return 0;
    float sum=0;
    int i = n;
    while(i-- && q->front && q->rear)
    {
        QNode *elem = deQueue(q);
        sum += elem->key;
    }
    return sum/n;
}

Stock_List *Insert_Stock(Stock_List *list_ptr){

	Stock_List *nptr;
    int n;
	nptr = (Stock_List *)malloc(sizeof(Stock_List));
	//insert values into Stocks
	printf("\nEnter Name of the Stock : ");
	scanf("%s", nptr->stock_node.stock_id);
	printf("\nEnter total number of shares : ");
	scanf("%d", &n);
	nptr->stock_node.no_of_shares = n;
	Stack *stk = createStack(n);
	Queue *que = createQueue();
	while(n){
        printf("\nEnter number of shares & its purchase price : ");
        int share, price;
        scanf("%d %d", &share, &price);
        n -= share;
        while(share--)
        {
            stack_push(stk, price);
            enQueue(que,price);
        }
	}
	printf("\nStock added successfully  :) ");
    nptr->stock_node.prices.price_stack = stk;
    nptr->stock_node.prices.price_queue = que;
    if (nptr != NULL){
        nptr->next = list_ptr;
        list_ptr = nptr;
	}
	return list_ptr;
}

void Average_Stocks(Stock_List *list_ptr){

	Stock_List *nptr=NULL, *prev=NULL;
    char stock_nm[MAX_STOCK_NAME];
    int sell_share, flag = 0;;

	if(list_ptr == NULL) {
		printf("No stock is present :( \n");
	}
	else {
        printf("\nFrom which stock you wish to sell shares : ");
        scanf("%s", stock_nm);

		nptr = list_ptr;
		while(nptr != NULL) {
			if(flag==0 && strcmp(stock_nm, nptr->stock_node.stock_id)==0)
            {
                // stock found , now ask for number of shares to remove
                flag=1;
                printf("\nHow many shares : ");
                scanf("%d", &sell_share);

                //printf("Stock found :)");
                if(sell_share > nptr->stock_node.no_of_shares)
                {
                    printf("\nInvalid number of shares !!");
                }
                else{
                    int i=sell_share;
                    printf("\nAverage FIFO price : %f ", get_fifo_sum(nptr->stock_node.prices.price_queue, sell_share));
                    printf("\nAverage LIFO price : %f ", get_lifo_sum(nptr->stock_node.prices.price_stack, sell_share));
                    nptr->stock_node.no_of_shares -= sell_share;
                    printf("\n\nNow, %d shares are left in stock %s",nptr->stock_node.no_of_shares, stock_nm);
                }
                break;
            }
            prev = nptr;
			nptr = nptr->next;
		}
	}
	if(flag==0)
        printf("\n Stock not found :(");
}


int main()
{
    Stock_List *stk_list=NULL;

    printf("\t************** WELCOME **************\n");
    printf("\n\n Here is the menu : ");
    int i=1;
    while(i==1 || i==2)
    {
        printf("\n#################################################");
        printf("\n\n1. Enter a new stock \n2. TO find the FIFO & LIFO price of a stock \n\n  Press any other key to exit....\n");
        printf("\n#################################################\n");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                    stk_list = Insert_Stock(stk_list);
                    break;

            case 2:
                    Average_Stocks(stk_list);
                    break;

            default :
                    break;
        }
    }

    printf("\nThanks for using this program :)");

    return 0;
}
