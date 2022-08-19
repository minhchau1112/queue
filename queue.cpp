// Queue
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Queue {
	Node* front;
	Node* rear;
};

void Init(Queue& q) {
	q.front = NULL;
	q.rear = NULL;
}

Node* CreateNewNode(int value) {
	Node* p = new Node;
	if (p == NULL)return NULL;
	p->data = value;
	p->next = NULL;
	return p;
}

void Enqueue(Queue& q, int value) {
	Node* temp = CreateNewNode(value);
	if (q.rear == NULL) {
		q.rear = temp;
		q.front = temp;
		return;
	}
	q.rear->next = temp;
	q.rear = temp;
}

void Dequeue(Queue& q) {
	if (q.front == NULL) return;
	Node* temp = q.front;
	q.front = q.front->next;
	if (q.front == NULL) {
		q.rear = NULL;
	}
	delete temp;

}

void Display(Queue q) {
	Node* cur = q.front;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main() {
	Queue q;
	Init(q);
	Enqueue(q, 10);
	Enqueue(q, 30);
	Enqueue(q, 50);
	Enqueue(q, 20);
	Enqueue(q, 15);
	Enqueue(q, 60);
	Display(q);
	return 0;
}