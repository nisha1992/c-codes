#include<stdio.h>
#include<stdlib.h>
//#define NULL 0;
struct list
{
int data;
struct list *next;
};
struct list *start=NULL,*end;


void insertAtStart(int x)   //insert at start
{
if(start==NULL)
{
start=(struct list *)malloc(sizeof(struct list));
start->data=x;
start->next=NULL;
return;
}
else
{
struct list *new=(struct list *)malloc(sizeof(struct list));
new->data=x;
new->next=start;
start=new;
}

}

void insertAtLast(int x)     //insert at end
{
if(start==NULL)
{
start=(struct list *)malloc(sizeof(struct list));
start->data=x;
start->next=NULL;
return;
}
else
{
end=start;
while(end->next!=NULL)
{
end=end->next;
}

end->next=(struct list *)malloc(sizeof(struct list));
end->next->data=x;
end->next->next=NULL;
}
}

void insertAtPosition(int x,int pos)           //insert at given position
{
end=start;
int count=0;
while(count!=pos-1)
{
count++;
end=end->next;
}
struct list *new=malloc(sizeof(struct list));
new->data=x;
new->next=end->next;
end->next=new;
}  

void deleteStart()    //delete from start
{
struct list *temp;
temp=start;
start=temp->next;
free(temp);
}

void deleteEnd()    //delete from end
{
struct list *temp;
temp=start;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
temp->next=NULL;
}

void deleteNum(int x)   //delete a node
{
struct list *temp,*k;
temp =start;
while(temp->next->data!=x)
{
temp=temp->next;
}
k=temp->next;
temp->next=temp->next->next;
free(k);

}

void count()
{
end=start;
int count=0;
while(end!=NULL)
{
end=end->next;
count++;
}
printf("no of nodes=%d",count);
}

void display()     //display
{
if(start==NULL)
printf("empty");
else
{
end=start;
while(end!=NULL)
{
printf("%d\t",end->data);
end=end->next;
}
}
}


main()
{
int ch;
while(1)
{
printf("\n1.insert at begining\n2.insert at last\n3.insert at ith position\n4.delete from start\n5.delete from end\n6.delete a node\n7.count no. of nodes\n8.display\npress -1 to exit!\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
int x;
printf("Enter the element to insert:");
scanf("%d",&x);
insertAtStart(x);
break;
}

case 2:
{
int x;
printf("Enter the element to insert:");
scanf("%d",&x);
insertAtLast(x);
break;
}

case 3:
{
int x,loc;
printf("Enter the element to insert:");
scanf("%d",&x);
printf("Enter the location:");
scanf("%d",&loc);
insertAtPosition(x,loc-1);
break;
}

case 4:
{
deleteStart();
break;
}

case 5:
{
deleteEnd();
break;
}

case 6:
{
int x;
printf("Enter the element to delete:");
scanf("%d",&x);
deleteNum(x);
}

case 7:
{
count();
break;
}

case 8:
{
display();
break;
}

case -1:
{
exit(0);
}

default:
{
printf("invalid");
break;
}
}


}

}
                                                                                                             
