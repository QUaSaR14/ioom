/*
                                    Assignment 1 , IOOM
                                Submitted by : Madhur Trivedi
                                Date : 21/08/2019
                                Enrollment No. : BT17CSE039
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_SHARES 100
#define MAX_STOCKS 10
#define MAX_STOCK_NAME 5
#define MAX 50

class QNode {
    public:
        int key;
        QNode* next;
};

class Queue {
    public:
        QNode *front, *rear;
        int q_capacity;
        Queue(){ q_capacity =0;}
};

class Stack {
    public:
	// Maximum size of Stack
        int top;
        int capacity;
        int a[MAX_SHARES];
        Stack() { top = -1; capacity=0;}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        float get_lifo_sum(int n);
};

class Prices{
    public:
        Stack price_stack;
        Queue *price_queue;
};

class Stock_details
{
    public:
        char stock_id[MAX_STOCK_NAME];
        int no_of_shares;
        Prices prices;
};

// A linked list node
class Stock_List
{
	public:
        Stock_details stock_node;
        Stock_List *next;
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		++capacity;
		//cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		--capacity;
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

float Stack::get_lifo_sum(int n)
{

    if(n > capacity || isEmpty())
	{
		return 0;
	}

	float sum = 0;
	int i=n;
	while(i-- && !isEmpty())
	{
		sum += pop();
	}
	return sum/n;
}

QNode* newNode(int k)
{
	QNode* temp = new QNode();
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
Queue* createQueue()
{
	Queue* q = new Queue();
	q->front = q->rear = NULL;
	return q;
}

// The function to add a key k to q
void enQueue(Queue* q, int k)
{
	// Create a new LL node
	QNode* temp = newNode(k);
    ++(q->q_capacity);
	// If queue is empty, then
	// new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at
	// the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}

// Function to remove
// a key from given queue q
QNode* deQueue(Queue* q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return NULL;

	--(q->q_capacity);
	// Store previous front and
	// move front one node ahead
	QNode* temp = q->front;
	q->front = q->front->next;

	// If front becomes NULL, then
	// change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;
	return temp;
}

float get_fifo_sum(Queue * q, int n)
{
    if(n > q->q_capacity || !(q->front))
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

void Insert_Stock(Stock_List** head_ref)
{
	/* 1. allocate node */
	Stock_List* nptr = new Stock_List();
	int n;

	/* 2. put in the data */
	cout << "\nEnter Name of the Stock : " ;
	cin >> nptr->stock_node.stock_id;
	cout << "\nEnter total number of shares : ";
	cin >> n;
	nptr->stock_node.no_of_shares = n;
	Stack stk;
	Queue *que = createQueue();
	while(n){
        cout << "\nEnter number of shares & its purchase price : ";
        int share, price;
        cin >> share >> price;
        n -= share;
        while(share--)
        {
            stk.push(price);
            enQueue(que,price);
        }
	}
	printf("\nStock added successfully  :) ");
    nptr->stock_node.prices.price_stack = stk;
    nptr->stock_node.prices.price_queue = que;

	/* 3. Make next of new node as head */
	nptr->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = nptr;
}

void Average_Stocks(Stock_List *list_ptr){

	Stock_List *nptr=NULL, *prev=NULL;
    char stock_nm[MAX_STOCK_NAME];
    int sell_share, flag = 0;;

	if(list_ptr == NULL) {
        cout << "No stock is present :( \n" ;
	}
	else {
        cout << "\nFrom which stock you wish to sell shares : ";
        cin >> stock_nm ;

		nptr = list_ptr;
		while(nptr != NULL) {
			if(flag==0 && strcmp(stock_nm, nptr->stock_node.stock_id)==0)
            {
                // stock found , now ask for number of shares to remove
                flag=1;
                cout << "\nHow many shares : ";
                cin >> sell_share;

                //printf("Stock found :)");
                if(sell_share > nptr->stock_node.no_of_shares)
                {
                    cout << "\nInvalid number of shares !!";
                }
                else{
                    int i=sell_share;
                    cout << "\nAverage FIFO price : " << get_fifo_sum(nptr->stock_node.prices.price_queue, sell_share);
                    cout << "\nAverage LIFO price : " << nptr->stock_node.prices.price_stack.get_lifo_sum(sell_share);
                    nptr->stock_node.no_of_shares -= sell_share;
                    cout << "\n\nNow, "<< nptr->stock_node.no_of_shares << " shares are left in stock " << stock_nm;
                }
                break;
            }
            prev = nptr;
			nptr = nptr->next;
		}
	}
	if(flag==0)
        cout << "\n Stock not found :(";
}

int main()
{
    Stock_List *stk_list=NULL;

    cout << "\t************** WELCOME **************\n";
    cout << "\n\nHere is the menu : ";
    int i=1;
    while(i==1 || i==2)
    {
        cout << "\n#################################################";
        cout << "\n\n1. Enter a new stock \n2. TO find the FIFO & LIFO price of a stock \n\n  Press any other key to exit....\n";
        cout << "\n#################################################\n";
        cin >> i;
        switch(i)
        {
            case 1:
                    Insert_Stock(&stk_list);
                    break;

            case 2:
                    Average_Stocks(stk_list);
                    break;

            default :
                    break;
        }
    }

    cout << "\nThanks for using this program :)" << endl;

    return 0;
}

