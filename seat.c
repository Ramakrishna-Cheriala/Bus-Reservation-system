#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include"ticket_booking.h"
#define BUS_NUM 84
#define TOTAL_SEATS 32
struct Passenger{
	char name[20];
    char phoneno[20],age[10];
    int seat,id;
    struct Passenger *link;
};
struct Bus {
    int unqID;
    struct Passenger *firstPassenger;
};
struct Bus *arr[BUS_NUM];
struct Passenger *cur,*first,*last;
void create(int);
void nodecreation(int i);
void display(int i);
void cancellation(int i);

void nodecreation(int i){
	int j,k;
    first = NULL;
	for(j=0;j<BUS_NUM;j++){
		if(j==i){
			for(k=0;k<TOTAL_SEATS;k++){
				cur = (struct Passenger *)malloc(sizeof(struct Passenger));
				strcpy(cur->age," ");
				// cur->busnum=NULL;
				strcpy(cur->name," ");
				strcpy(cur->phoneno," ");
				cur->id=NULL;
				if(first==NULL){
					first=cur;
					cur->link=NULL;
					last=cur;
					struct Bus *bus = (struct Bus *)malloc(sizeof(struct Bus));
                    // bus->busno = busno;
                    bus->unqID = i;
                    bus->firstPassenger = cur;
                    arr[i] = bus;
				}
				else{
					last->link=cur;
					cur->link=NULL;
					last=cur;
				}
			}
		}
	}
}


int main(){
	int i;
	printf("Please Enter the Bus ID ");
    scanf("%d",&i);
	while(1){
		int ch,k,n;
		printf("\n\n1.Seat Selection\n2.Tickect Info\n3.Cancellation\n4.Menu\n\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("ee");
				k=0;
                if (arr[i] == NULL) {
                    nodecreation(i);
                }
				printf("\nNumber of seats to be booked: ");
				scanf("%d",&n);
				while(k<n && k<=5){
					create(i);
					k++;
				}
				break;
			case 2:
				if(arr[i]==NULL){
					printf("Bus is empty\n");
				}
				else{
					display(i);
				}
				break;
			case 3:
				if(arr[i] == NULL){
					printf("Bus is empty!!\n");
				}
				else{
					cancellation(i);
				}
				break;
			case 4:
				return(1);
//			default:
//				printf("Invalid Choice!!");
		}
	}
}
	
	

void create(int c){
    int seatNo,i,j1,j,seatNum;
    int c1=0,c2=0; 
	char name[20],phone[20],age[10];
	struct Passenger *t=arr[c]->firstPassenger; 
	struct Passenger *t2=arr[c]->firstPassenger; 
	
	for(j1=0;j1<BUS_NUM;j1++){
        if(j1==c){
	        for(seatNo=1;seatNo<=TOTAL_SEATS;seatNo++){
	        	if(strcmp(t2->name," ")==0 && strcmp(t2->phoneno," ")==0){
					printf("[%02d]",seatNo);
					c1++;
					c2++;
				}
				else{
					printf("[XX]");
					c1++;
					c2++;
				}
				if(c1==2){
					printf("\t");
					c1=0;
				}
				if(c2==4){
					printf("\n");
					c2=0;
				}
				t2=t2->link;
			}
		}      
    }
	
	
	printf("\nEnter the seat number (1-32): ");
	scanf("%d",&seatNum);
	for(j=0;j<BUS_NUM;j++){
		if(j==c){
			for(i=1;i<seatNum;i++){
				t=t->link;
			}
			
			if(strcmp(t->age," ")==0){
				printf("\nEnter the name: ");
				scanf("%s",name);
				printf("\nEnter the phone number: ");
			    scanf("%s",phone);
			    printf("\nenter the age: ");
			    scanf("%s",age);
				strcpy(t->name,name);
			    strcpy(t->phoneno,phone);
			    strcpy(t->age,age);
//			    t->busnum=busno;
			    t->seat=seatNum;
			    t->id=c;
			    // bus_details(busno,name,age,phone,seatNum);
			}
			else{
				printf("Already reserved!!\n");
				create(c);
			}
			
		}
	}
}

void cancellation(int i){
	struct Passenger *t;
	int j,seatNo,Id;
	char name[200],ph[10];
	printf("\nEnter the bus ID: ");
    scanf("%d",&Id);
    for(j=0;j<BUS_NUM;j++){
    	if(Id==j){
    		t=arr[j]->firstPassenger;
    		printf("Enter the name and phone number : ");
    		scanf("%s%s",name,ph);
    		for(seatNo=0;seatNo<TOTAL_SEATS;seatNo++){
    			if(strcmp(t->name,name)==0 && strcmp(t->phoneno,ph)==0){
    				strcpy(t->age," ");
    				strcpy(t->name," ");
    				strcpy(t->phoneno," ");
//    				t->busnum=NULL;
    				printf("ticket cancelled!!\n");
                    return;
				}
				t=t->link;
			}
            //return;
		}
	}
}

void display(int i){
    int j,id,k=0,count=0;
    char ph[10];
    struct Passenger *t2;
    printf("\nEnter your bus ID: ");
	scanf("%d",&id);
	
	for(j=0;j<BUS_NUM;j++){
	    if(id==j){
	    	t2=arr[j]->firstPassenger;
	    	printf("enter the ph: ");
			scanf("%s",ph);
			for(k=0;k<TOTAL_SEATS;k++){
			    if(strcmp(ph,t2->phoneno)==0){
			    	if(t2->age!=NULL){
			        	printf("Name = %s\tPhone Number = %s\tAge = %s\t\tSeat number = %d\tBus ID = %d\t",t2->name,t2->phoneno,t2->age,t2->seat,t2->id);
			        	printf("\n");
					}
				}
				else{
					count++;
				}
				t2=t2->link;    
			}
			if(count==32){
				printf("Details not found!!");
			}
			return;  
		}       
	}
}
