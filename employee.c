#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee{
    char name[100],phoNo[100],empId[100],age[10];
    char address[1000],salary[100],busId[10],post[100];
    struct employee *link;
};
struct employee *cur,*first,*last;

void addEmp();
void dispEmp();
void delEmp();

int main(){
    int ch,n;
    while(1){
        printf("\n\n1.Add Employee\n2.Employee Information\n3.Employee Deletion\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch){
        case 1:
            addEmp();
            break;
        case 2:
            dispEmp();
            break;
        case 3:
            delEmp();
            break;
        // default:
        //     printf("invalid choice!!");
        }
    }
}


void addEmp(){
    char empId[100],post[10],name[100],phoNo[10],age[10],address[100],busId[10],salary[100];
    cur = (struct employee *)malloc(sizeof(struct employee));
    printf("Enter the Id of the employee: \n");
    scanf("%s",cur->empId);
    printf("Enter the post of the employee: \n");
    scanf("%s",cur->post);
    printf("Enter the name of the employee: \n");
    scanf("%s",cur->name);
    printf("Enter the phone Number of the employee: \n");
    scanf("%s",cur->phoNo);
    printf("Enter the age of the employee: \n");
    scanf("%s",cur->age);
    printf("Enter the address of the employee: \n");
    scanf("%s",cur->address);
    printf("Enter the bus ID for the employee: \n");
    scanf("%s",cur->busId);
    printf("Enter the salary for the employee: \n");
    scanf("%s",cur->salary);
    
    if(first == NULL){
        cur->link=NULL;
        first=cur;
        last=cur;
    }
    else{
        last->link=cur;
        cur->link=NULL;
        last=cur;
    }
}

void dispEmp(){
    char id[100];
    struct employee *t=first;
    printf("Enter the id of the employee: ");
    scanf("%s",id);
    while(t!=NULL){
        if(strcmp(id,t->empId)==0){
            printf("\nName = %s",t->name);
            printf("\nEmployeeID = %s",t->empId);
            printf("\nDesignation = %s",t->post);
            printf("\nAge = %s",t->age);
            printf("\nPhoneNumber = %s",t->phoNo);
            printf("\nAddress = %s",t->address);
            printf("\nSalary = %s",t->salary);
            printf("\nBusID = %s",t->busId);
        }
        t=t->link;
    }
}

void delEmp(){
	char id[100];
    printf("Enter the id of the employee: ");
    scanf("%s",id);
    struct employee *cur=first,*temp1;
    while(cur!=NULL){
        if(strcmp(id,cur->empId)==0)
        {
        	
			if(cur->link==NULL)
			{
				printf("Deleted emp=%s",cur->name);
				free(cur);
				first=NULL;
				return;
			}
			else
			{
				while(cur->link!=NULL)
				{
					temp1=cur;
					cur=cur->link;
				}
				printf("Deleted emp=%s",cur->name);
				free(cur);
				temp1->link=NULL;
			}
		}
		cur=cur->link;
	}
}