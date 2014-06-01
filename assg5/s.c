#include<stdio.h>
#include<stdlib.h>

struct pque
{
	int data;
	int pri;
};
typedef struct pque prq;
//typedef prq *link;
int heapsize = -1;

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
int left(int i)
{
	return (2*(i+1)-1);
}
int right(int i)
{
	return (2*(i+1));
}
int parent(int i)
{
	return(((i+1)/2)-1);
}
prq * min_heapify(prq *a,int i)
{
	int smallest;
	int l = left(i);
	int r = right(i);
	if(r <= heapsize && ((a+r)->pri) < ((a+i)->pri))
		smallest = r;
	else
		smallest = i;
	if(l <= heapsize && ((a+l)->pri) < ((a+smallest)->pri))
		smallest = l;
	if(smallest != i)
	{
		prq *temp;
		temp = malloc(1*sizeof(prq));
		temp->data = (a+i)->data;
		temp->pri = (a+i)->pri;
		(a+i)->data = (a+smallest)->data;
		(a+i)->pri = (a+smallest)->pri;
		(a+smallest)->data = temp->data;
		(a+smallest)->pri = temp->pri;
		min_heapify(a,smallest);
	}
	return a;
}
void pe
prq * removee(prq *pq)
{
	if (heapsize < 0)
	printf("EMPTY\n");
	else
	{
		printf("%d(%d)\n",(pq->data),(pq->pri));
		(pq)->data = (pq+heapsize)->data;
		pq->pri = (pq+heapsize)->pri;
		heapsize--;
		pq = min_heapify(pq,0);
	}
	return pq;
}
int search(prq *p,int dat)
{
	int i=0;
	while(i<=heapsize)
	{
		if ((p+i)->data == dat)
		return i;
		i++;
	}
	return -1;
}
prq * increase_pri(prq *pq,int dat,int pr)
{
	int i = search(pq,dat);
	if(i != -1)
	{
		(pq+i)->pri = pr;
		while(i>0 && (((pq+(parent(i)))->pri) > (pq+i)->pri))
		{
			prq *temp;
			temp = malloc(1*sizeof(prq));
			temp->data = (pq+i)->data;
			temp->pri = (pq+i)->pri;
			(pq+i)->data = (pq+parent(i))->data;
			(pq+i)->pri = (pq+parent(i))->pri;
			(pq+parent(i))->pri = temp->pri;
			(pq+parent(i))->data = temp->data;
			i = parent(i);
		}
	}
	printf("\n");
	return pq;	
}
prq * insert(prq *pq,int key,int da)
{
	heapsize = heapsize+1;
	(pq+heapsize)->data = da;
	(pq+heapsize)->pri = 1000000;
	pq = increase_pri(pq,da,key);
	printf("\n");
	return pq;
}

void main()
{
	char *a;
	a = malloc(20*sizeof(char));
	printf("enter the input file name\n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	do_it(p);
}
