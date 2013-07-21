#include<stdio.h>
#include<stdlib.h>
//#define NULL 0;
struct list
{
int data;
struct list *diff;
};
struct list *start=NULL;

void insertAtStart(int x)   //insert at start
{
struct list *prev=NULL,*next=NULL,*end;
if(start==NULL)
{
start=(struct list *)malloc(sizeof(struct list));
start->data=x;
start->diff=(struct list*)((unsigned int)(prev)^(unsigned int)(next));
return;
}
else
{
struct list *new=(struct list *)malloc(sizeof(struct list));
new->data=x;
new->diff=(struct list*)((unsigned int)(NULL)^(unsigned int)(start));
start->diff=(struct list*)((unsigned int)(new)^(unsigned int)(start->diff));
start=new;
}

}

void insertAtLast(int x)     //insert at end
{
struct list *prev=NULL,*next=NULL,*end;
if(start==NULL)
{
start=(struct list *)malloc(sizeof(struct list));
start->data=x;
start->diff=(struct list*)((unsigned int)(prev)^(unsigned int)(next));
return;
}
else
{
end=start;
printf("a=%d",end->data);
while(end!=NULL)
{
if(end->diff == prev)
break;
else
{
next=(struct list*)((unsigned int)(end->diff)^(unsigned int)(prev));
prev=end;
end=next;
}
}
printf("a=%d",end->data);
struct list *new=(struct list *)malloc(sizeof(struct list));
new->data=x;
new->diff=end;
printf("n=%d",new->data);
if(prev==NULL)
{
end->diff=new;
}
else
end->diff=(struct list*)((unsigned int)(prev)^(unsigned int)(new));
}
}

void insertAtPosition(int x,int pos)           //insert at given position
{
struct list *temp,*temp1,*next=NULL,*end=NULL,*prev=NULL;
end=start;
int count=0;
while(count!=pos-1)
{
count++;
next=(struct list*)((unsigned int)(end->diff)^(unsigned int)(prev));
prev=end;
end=next;
}
next=(struct list*)((unsigned int)(prev)^(unsigned int)(end->diff));
temp=(struct list*)((unsigned int)(end)^(unsigned int)(next->diff));
struct list *new=malloc(sizeof(struct list));
new->data=x;
end->diff=(struct list*)((unsigned int)(prev)^(unsigned int)(new));
new->diff=(struct list*)((unsigned int)(end)^(unsigned int)(next));
next->diff=(struct list*)((unsigned int)(new)^(unsigned int)(temp));


}  


void deleteStart()    //delete from start
{
struct list *prev=NULL,*next=NULL;
struct list *temp,*temp1;
temp=start;
temp1=(struct list*)((unsigned int)(temp->diff)^(unsigned int)(prev));
next=(struct list*)((unsigned int)(temp1->diff)^(unsigned int)(temp));
start=temp1;
start->diff=(struct list*)((unsigned int)(next)^(unsigned int)(NULL));
free(temp);
}

void deleteEnd()    //delete from end
{
struct list *prev=NULL,*next=NULL,*end;
struct list *temp,*temp1;
end=start;
while(end!=NULL)
{
if(end->diff == prev)
break;
else
{
next=(struct list*)((unsigned int)(end->diff)^(unsigned int)(prev));
prev=end;
end=next;
}
}
temp=end;
temp1=(struct list*)((unsigned int)(prev->diff)^(unsigned int)(temp));
prev->diff=(struct list*)((unsigned int)(temp1)^(unsigned int)(NULL));
free(temp);

}

/*void deleteNum(int x)   //delete a node
{
struct list *temp,*k;
temp =start;
while(temp->data!=x)
{
temp=temp->next;
}
temp->prev->next=temp->next;;
temp->next->prev=temp->prev;
free(temp);

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
}*/

void display()     //display
{
struct list *prev=NULL,*next=NULL,*end;
if(start==NULL)
printf("empty");
else
{
end=start;
while(end!=NULL)
{
printf("%d\t",end->data);
if(end->diff == prev)
break;

else
{
next=(struct list*)((unsigned int)(end->diff)^(unsigned int)(prev));
prev=end;
end=next;
}
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
insertAtPosition(x,loc);
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

/*case 6:
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
}*/

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
                                                                                                             
