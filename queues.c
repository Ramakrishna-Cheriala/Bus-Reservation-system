#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define QUEUESIZE 4
int count=0;
struct bus{
	char from[100],to[100],type[10],busid[5],driver_name[100],conductor_name[100];   
    struct node *link;  
};
 
struct busdup{
	char fromd[100],tod[100],typed[10],busidd[5],driver_named[100],conductor_named[100];
}b; 
struct bus *front,*rear,*temp1,*cur,*temp2;  

int main()
{
    int ch,n;
    while(1){
        printf("\n\n1.ADD BUS\n2.BUS DETAILS\n3.DELETE BUS\n4.RETURN\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch){
        case 1:
            add_bus();
            break;
        case 2:
            dispbus();
            break;
        // case 3:
        //     del_bus();
        //     break;
        case 4:
        	return;
        default:
            printf("invalid choice!!");
        }
    }
}

void add_bus(){
	int s=1;
    char frm[20];
	printf("\t\t\t*ADD EMPLOYEE*\t\t\t\n");
	while((s!=0)&&(count<QUEUESIZE)){
        printf("\nEnter FROM:");
        scanf("%s",b.fromd);
        strcpy(frm,b.fromd);
        printf("Enter TO:");
        scanf("%s",b.tod);
        printf("Type:");
        scanf("%s",b.typed);
        printf("Bus ID:");
        scanf("%s",b.busidd);
        printf("Driver name:");
        scanf("%s",b.driver_named);
        printf("Conductor name:");
        scanf("%s",b.conductor_named);
        enqueue();
		count=count+1;
		if(count<QUEUESIZE){
			printf("\nDo you want to continue???(0/1)\n");
		    scanf("%d",&s);
		}
		if(count==QUEUESIZE){
			printf("\nQUEUE IS FULL\n");
		}	
	}
	dequeue(count,frm);	
}
void enqueue(){
	cur=(struct bus*)malloc(sizeof(struct bus));
	strcpy(cur->from,b.fromd);
    strcpy(cur->to,b.tod);
    strcpy(cur->type,b.typed);
    strcpy(cur->busid,b.busidd);
    strcpy(cur->driver_name,b.driver_named);
    strcpy(cur->conductor_name,b.conductor_named);	
	if(front==NULL){
		cur->link=NULL;
		front=cur;
	    rear=cur;
	}
	else{
		cur->link=NULL;
		rear->link=cur;
		rear=cur;
	}
}
void dequeue(int c, char frm[20]){
	if(c==0){
		printf("Queue is empty\n");
	}
	else{
        FILE *fp;
		temp1=front;
        strcat(frm,".txt");
	    fp=fopen(frm,"a+");
		temp1=front;
      	while(temp1!=NULL && c>=0)
	    { 
	        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n",temp1->from,temp1->to,temp1->type,temp1->busid,temp1->driver_name,temp1->conductor_name);
	        temp2=temp1;
	        temp1=temp1->link;
	        // front=front->link;
	        free(temp2);
            c--;
     	}
     	fclose(fp);
     	
	}
	count=0;
	
}
dispbus(){
	char fr[50],ch;
	printf("Enter FROM:");
	scanf("%s",fr);
    strcat(fr,".txt");
    // printf("%s",fr);
	FILE *fp;
	fp=fopen(fr,"r+");
	if(fp==NULL){
		printf("Unable to open the file...");
	}
	do{
		ch=fgetc(fp);
		printf("%c",ch);
	}while(ch!=EOF);
}