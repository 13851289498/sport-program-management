#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int o=0;

typedef struct node
{
	int num;
	char ming[10];
	char lei;
	int renshu;
	char shijian[12];
	struct node *next;
}node;

node *creatlist();
void putlist();
node *del();
void find();
node *ins();
node *xiugai();
int numb();

main()
{
	int a,b,g=1;
node *head=NULL,*instert=(node*)malloc(sizeof(node));;

while(g)
{
	system("cls");

	printf("\n\n");
    printf("===================У�˶�����Ŀ����ϵͳ==================\n");
    printf("* ����:��ĳ �༶:�Զ���201 ѧ��:202002070115            *\n");
    printf("*                                                       *\n");
    printf("*          1>. ¼���˶�����Ŀ��Ϣ                       *\n");
    printf("*          2>. ����ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("*          3>. �޸�ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("*          4>. ɾ��ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("*          5>. ���ĳ���˶�����Ŀ��Ϣ                   *\n");
	printf("*          6>. ����˶�����Ŀ��Ϣ                       *\n");
	printf("*          7>. ����˶��������Ŀ��Ϣ                   *\n");
    printf("*          0>. �˳�����ϵͳ                             *\n");
    printf("*                                        ��ӭʹ�ñ�ϵͳ!*\n");
    printf("=========================================================\n");
    printf("����ѡ����س�����ѡ��:                                \n");


	scanf("%d",&a);
	switch(a)
	{
        
        case 1:head=creatlist(head);  break;
        case 2:printf("����Ҫ��ѯ����Ŀ�ţ�");
		       scanf("%d",&b);
		       find(head,b);
               break;
        case 3:printf("����Ҫ�޸ĵ���Ŀ�ţ�");
		       scanf("%d",&b);
			xiugai(head,b);
            break;
        case 4:
            printf("����Ҫɾ������Ŀ�ţ�");
		    scanf("%d",&b);
			head=del(head,b);
            break;
        case 5:
			printf("�����������Ŀ����Ŀ��ţ�");
			scanf("%d",&instert->num);
			printf("�����������Ŀ����Ŀ���ƣ�");
			scanf("%s",&instert->ming);
			printf("�����������Ŀ����Ŀ�ࣺ");
			scanf("%s",&instert->lei);
			printf("�����������Ŀ�Ĳ���������");
			scanf("%d",&instert->renshu);
			printf("�����������Ŀ�ľ���ʱ�䣺");
			scanf("%s",&instert->shijian);
			ins(head,instert);
            break;
		case 6:
            putlist(head);
            break;
		case 7:
            printf("һ����%d����Ŀ\t",o);
			printf("һ����%d��������\t",numb(head));
			system("pause");
            break;
        case 0:
            printf("�����˳�У�˶�����Ŀ����ϵͳ.....");
			g--;break;
       ;
        default:
            printf("�������ָ���ȷ������������");break;
        }

	}



}

node *creatlist()
{
	node *head= (node*)malloc(sizeof(node));
	node *p,*q;
	int n,i;
	o=0;
	head->next=NULL;
	q=head;
	printf("����Ҫ¼����ٸ���Ŀ��");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("�������%d����Ŀ����Ŀ��ţ�",i+1);
		scanf("%d",&p->num);
		printf("�������%d����Ŀ����Ŀ���ƣ�",i+1);
		scanf("%s",&p->ming);
		printf("�������%d����Ŀ����Ŀ�ࣺ",i+1);
		scanf("%s",&p->lei);
		printf("�������%d����Ŀ�Ĳ���������",i+1);
		scanf("%d",&p->renshu);
		printf("�������%d����Ŀ�ľ���ʱ�䣺",i+1);
		scanf("%s",&p->shijian);
		if(i==0)
		{
			head=q;
			p->next=NULL;
			q->next=p;
			q=p;
		}
		else
		{
			p->next=NULL;
			q->next=p;
			q=p;
		}
		o++;
	}
	printf("�Ѿ�ȫ��¼�����");
	system("pause");
	return head;
}
void putlist(node *head)
{


	int i=0;node *p;
	printf("��Ŀ���\t��Ŀ����\t��Ŀ��  \t��������\t����ʱ��\n");
	if(head==NULL)
	{
		printf("��");
		return;
	}
	p=head->next;
	do
	{
		printf("%d\t\t",p->num);
		printf("%s\t\t",p->ming);
		printf("%c\t\t",p->lei);
		printf("%d\t\t",p->renshu);
		printf("%s\t\t\n",p->shijian);

		p=p->next;
	}while(p!=NULL);
	printf("������");
	system("pause");
}


node  *del(node *head,int a)
{ 
	node *p1,*p2;
   if(head==NULL)
   {
	   printf("\n �� \n");
	   goto  end; 
   }
   p1=head->next;
   while(a!=p1->num && p1->next!=NULL)
   {
	   p2=p1; p1=p1->next; 
   }
   if(a==p1->num)
   { 
	   if(p1==head) 
		   head=p1->next;
       else p2->next=p1->next;
       printf("��ɾ������Ŀ��Ϊ: %d\n",a);
	   o--;
    }
   else printf("%d û�б����� ! \n",a);
    
 end: system("pause");
	  return(head);
	   
}

void find(node *head,int a)
{
	int i=2;
	node *p=head;
	while(i>0 && p->num!='\0')
	{
		
		if(p->num == a)
		{
			i-=2;
			printf("��Ŀ���\t��Ŀ����\t��Ŀ��  \t��������\t����ʱ��\n");
			printf("%d\t\t",p->num);
			printf("%s\t\t",p->ming);
			printf("%c\t\t",p->lei);
			printf("%d\t\t",p->renshu);
			printf("%s\t\t\n",p->shijian);
		}
		else
		{
			if(p->next!=NULL)
				p=p->next;
			else
			{
				printf("δ���ҵ�");
				goto end;
			}

		}

	}
end:
	system("pause");
}


node  *ins(node *head, node *stud)
{ node  *p0, *p1, *p2;
  p1=head;         
  p0=stud;
  o++;
  if(head==NULL)      
    {head=p0; p0->next=NULL; }   
  else
    {
	  while((p0->num>p1->num) && (p1->next!=NULL))
      {
		  p2=p1;                   
           p1=p1->next; 
	  }    
      if(p0->num<=p1->num)
      { 
		  if(head==p1)
		  {
			  head=p0; 
			  p0->next=p1;}
          else 
			p2->next=p0;   
          p0->next = p1; 
	  }
       else {p1->next=p0; p0->next=NULL; } 
     };           
  return head;
  printf("�����");
  system("pause");
}

node *xiugai(node *head,int a)
{
	
	int i=2,j;
	node *p=head;
	while(i>0 && p->num!='\0')
	{
		
		if(p->num == a)
		{
			printf("�Ѿ��ҵ�λ�ã�ѡ���޸��\n1.��Ŀ���\n2.��Ŀ����\n3.��Ŀ��  \n4.��������\n5.����ʱ��");
			scanf("%d",&j);
			switch(j)
			{
				case 1:printf("�����޸����ݣ�"); 
						scanf("%d",&p->num);
						 break;
				case 2:printf("�����޸����ݣ�"); 
						scanf("%s",&p->ming);
						 break;
				case 3:printf("�����޸����ݣ�"); 
						scanf("%s",&p->lei);
						break;
				case 4:printf("�����޸����ݣ�"); 
						scanf("%d",&p->renshu);
						break;
				case 5:printf("�����޸����ݣ�"); 
					scanf("%s",&p->shijian);
					break;
			}
			printf("\n�޸����\n");
			i-=2;
			printf("��Ŀ���\t��Ŀ����\t��Ŀ��  \t��������\t����ʱ��\n");
			printf("%d\t\t",p->num);
			printf("%s\t\t",p->ming);
			printf("%c\t\t",p->lei);
			printf("%d\t\t",p->renshu);
			printf("%s\t\t\n",p->shijian);
		}
		else
		{
			if(p->next!=NULL)
				p=p->next;
			else
			{
				printf("δ���ҵ�");
				goto end;
			}

		}

	}
end:
	system("pause");
	return head;


}

int numb(node *head)
{
	node *p=head;
	int sum=0;
	while(p->next)
	{
		p=p->next;
		sum+=p->renshu;
	}
	return sum;

}
