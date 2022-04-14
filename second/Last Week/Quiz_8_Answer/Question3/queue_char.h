
#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 100

typedef char QType;

typedef struct {
	int front, rear;
	QType data[QUEUE_SIZE];
} queue_t;

void initialize_q(queue_t *q) {
q->front = 0;
q->rear = -1;
}

int is_empty_q(queue_t *q) {
if (q->front > q->rear)
return 1;
return 0;
}

int is_full_q(queue_t *q) {
if (q->rear == QUEUE_SIZE - 1)
return 1;
return 0;
}

void insert_q(queue_t *q, QType item) {
	if (is_full_q(q))
	printf("Error : Queue is full!\n"); 
	else {
		q->rear = q->rear + 1;
		q->data[q->rear] = item;
	}
}

QType remove_q(queue_t *q) {
	QType item;
	if (is_empty_q(q)) {
		printf("Error : Queue is empty!\n");
	}
	else {
		item = q->data[q->front];
		q->front = q->front + 1;
	}
return (item);
}

/*  PART of STRING */

typedef struct{
	char wordstring[40];
}wordp;

typedef struct {
	int front, rear;
	wordp data[QUEUE_SIZE];
} queue_str_t;


void initialize_str_q(queue_str_t *q) {
q->front = 0;
q->rear = -1;
}

int is_empty_str_q(queue_str_t *q) {
	if (q->front > q->rear)
	return 1;

return 0;
}

int is_full_str_q(queue_str_t *q) {
	if (q->rear == QUEUE_SIZE - 1)
	return 1;

return 0;
}


void insert_str_q(queue_str_t *q, QType item[]) {
	int i, len = strlen(item);
	if (is_full_str_q(q))
	printf("Error : Queue is full!\n"); 
	else {
		q->rear = q->rear + 1;
		for(i=0; i<len; i++)
		q->data[q->rear].wordstring[i] = item[i];
	//	memcpy(q->data[q->rear], item, len);
	}
}

char *remove_str_q(queue_str_t *q, char *item) {
	int i, length;
	if (is_empty_str_q(q)) {
		printf("Error : Queue is empty!\n");
	//	item = QUEUE_EMPTY;
	}
	else {
		for(i=0; i<20; i++)
		*(item+i) = q->data[q->front].wordstring[i];
	//	memcpy(item, q->data[q->front], 40);
		q->front = q->front + 1;
	}
	
	length = strlen(item);
	item[length]='\0';
	
return item;
}
