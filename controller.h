#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int totalMonth(char*month){
	int total =0;
	if(strcmp(month, "january")==0){
		total =1;
	}
	else if(strcmp(month, "february")==0){
		total = 2;
	}
	else if(strcmp(month, "march")==0){
		total = 3;
	}
	else if(strcmp(month, "april")==0){
		total = 4;
	}
	else if(strcmp(month, "may")==0){
		total = 5;
	}
	else if(strcmp(month, "june")==0){
		total = 6;
	}
	else if(strcmp(month, "july")==0){
		total = 7;
	}
	else if(strcmp(month, "august")==0){
		total = 8;
	}
	else if(strcmp(month, "september")==0){
		total = 9;
	}
	else if(strcmp(month, "october")==0){
		total = 10;
	}
	else if(strcmp(month, "november")==0){
		total = 11;
	}
	else if(strcmp(month, "december")==0){
		total = 12;
	}
}

struct Node{
    int date;
    char month[100];
    int year;
    char name[255];
    int total;
    Node *next, *prev;
} * head, *tail, *curr;

Node *createNode(int date, char* month, int year, char* name, int total){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->date = date;
    strcpy(temp->month, month);
    temp->year = year;
    strcpy(temp->name, name);
    temp->total = total;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushHead(int date, char* month, int year, char* name, int total){
    Node *temp = createNode(date, (char*)month, year, (char*)name, total);

    if(!head){
        head = tail = temp;
    }
    else{
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void pushTail(int date, char* month, int year, char* name, int total){
    Node *temp = createNode(date, (char*)month, year, (char*)name, total);

    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(int date, char* month, int year, char* name, int total){
    Node *temp = createNode(date, (char*)month, year, (char*)name, total);
    if(!head){
        head = tail = temp;
    }
    else if(total < head->total){
        pushHead(date, (char*)month, year, (char*)name, total);
    }
    else if(total > tail->total){
        pushTail(date, (char*)month, year, (char*)name, total);
    }
    else{
        curr = head;

        while(curr->total<total){
            curr = curr->next;
        }

        temp->prev = curr ->prev;
        temp->next = curr;

        curr->prev->next = temp;
        curr->prev = temp;

    }
}


void popHead(){
    if(head && head == tail){
        head = tail = NULL;
        free(head);
    }
    else{
        Node *newHead = head->next;

        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}

void popTail(){
    if(head && head == tail){
        head = tail = NULL;
        free(head);
    }
    else{
        Node *newTail = tail->prev;
        tail->prev = newTail->next = NULL;
        free(tail);
        tail = newTail;
    }
}

void popMid(int date, char* month, int year, char* name, int total){

    if(!head){
        return;
    }
    else if(head->total == total){
        popHead();
    }
    else if(tail->total == total){
        popTail();
    }
    else{
        curr = head;
        
        while(curr && curr->total != total){
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        curr->prev = curr->next = NULL;
        free(curr);
    }
}



void printLinkedList(){
    curr = head;

    while(curr){
        printf("%d %s %d - %s\n", curr->date, curr->month, curr->year, curr->name);
        curr = curr->next;
    }
}

