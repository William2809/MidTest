#include<stdio.h>
#include "controller.h"

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);getchar();
	int date, year;
	char month[100], name[255];
	for(int i=0; i<n; i++){
		scanf("%d %s %d - %[^\n]", &date, month, &year, name);getchar();
		
		int total = date + (totalMonth((char*)month)*30) + (year * 365);
		pushMid(date, (char*)month, year, (char*)name, total);
	}
	int temp =n-m;
	int temp1 = m-n;
	if(m>=n)m=n;
	
	for(int i=0; i<m; i++){
		popHead();
	}
	if(n>m){
		printf("Need %d more cure\n", temp);
	}
	else{
		printf("All patients get the cure, %d cure left\n", temp1);
	}
	printLinkedList();
	return 0;
}
