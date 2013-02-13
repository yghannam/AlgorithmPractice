#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node{	
	public:
		Node *next;
		int data;
		Node(int);
		void addToTail(int d);
};

Node::Node(int d){
	data = d;
	next = NULL;
}

void Node::addToTail(int d){	
	Node *end = new Node(d);		
	Node *n = this;
	while (n->next != NULL){
		n = n->next;
	}
	n->next = end;
}

void printList(Node *llist){
	Node *p1 = llist;
	while(p1 != NULL){
		printf("%d -> ", p1->data);
		p1 = p1->next;
	}
	printf("NULL\n");
}

void removeDuplicates(Node *llist){
	Node *p1 = llist;
	while(p1 != NULL){
		Node *p2 = p1;
		while(p2 != NULL){
			while(p2->next != NULL && p1->data == p2->next->data){
				Node *temp = p2->next;
				p2->next = (p2->next->next != NULL) ? p2->next->next : NULL;
				free(temp);	
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

Node* findKth(Node* n, int k){
	
	int length = 0;
	Node *p1 = n;
	while(p1->next != NULL){
		length++;
		p1 = p1->next;
	}
	
	p1 = n;
	for (int i = 0; i < length-k; i++, p1 = p1->next);
	
	return p1;
	
	//if(n->next == NULL){
//		int *t = new int[2];
//		*t[0] = n;
//		*t[1] = 1;
//	}
//	else{
//		int **t = findKth(n, k);
//		if(t[0] == k){
//			return t;
//		}
//		else{
//			t[0] = n;
//			t[1]++;
//			return t;
//		}
//	}
}

void partition(Node* n, int k){
	Node *p = n;
	Node *s = NULL;
	Node *p2 = s;
	bool head = false;
	
	while(p != NULL){
		if(p->data > k){
			if(p2 == NULL){
				p2 = p;
				s = p2;
				p2->next = NULL;
			}
			else{
				p2->next = p;
				p2 = p2->next;
				p2->next = NULL;
			}
			if(!head && p->next != NULL){
				n = p->next;
			}
		}
		else{
			head = true;
		}
		p = p->next;
		//printList(s);
	}
	p = n;
	while(p->next != NULL)
		p = p->next;
	p->next = s;
	
	//printList(s);
}

int main(){
	
	srand(time(NULL));
	
	Node *llist = new Node(rand()%10);
	for(int i = 1; i < 5; i++)
		llist->addToTail(rand()%10);
	
	printList(llist);
	
	//removeDuplicates(llist);
	
	//Node *p = findKth(llist, 3);
	//printf("%d\n", p->data);
	
	partition(llist, 5);
	
	printList(llist);
	
	return 0;
}
