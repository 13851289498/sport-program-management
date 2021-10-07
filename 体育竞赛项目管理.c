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
    printf("===================校运动会项目管理系统==================\n");
    printf("* 作者:孙某 班级:自动化201 学号:202002070115            *\n");
    printf("*                                                       *\n");
    printf("*          1>. 录入运动会项目信息                       *\n");
    printf("*          2>. 查找某个运动会项目信息                   *\n");
    printf("*          3>. 修改某个运动会项目信息                   *\n");
    printf("*          4>. 删除某个运动会项目信息                   *\n");
    printf("*          5>. 添加某个运动会项目信息                   *\n");
	printf("*          6>. 输出运动会项目信息                       *\n");
	printf("*          7>. 输出运动会简略项目信息                   *\n");
    printf("*          0>. 退出管理系统                             *\n");
    printf("*                                        欢迎使用本系统!*\n");
    printf("=========================================================\n");
    printf("输入选项，按回车进入选项:                                \n");


	scanf("%d",&a);
	switch(a)
	{
        
        case 1:head=creatlist(head);  break;
        case 2:printf("输入要查询的项目号：");
		       scanf("%d",&b);
		       find(head,b);
               break;
        case 3:printf("输入要修改的项目号：");
		       scanf("%d",&b);
			xiugai(head,b);
            break;
        case 4:
            printf("输入要删除的项目号：");
		    scanf("%d",&b);
			head=del(head,b);
            break;
        case 5:
			printf("请输入添加项目的项目序号：");
			scanf("%d",&instert->num);
			printf("请输入添加项目的项目名称：");
			scanf("%s",&instert->ming);
			printf("请输入添加项目的项目类：");
			scanf("%s",&instert->lei);
			printf("请输入添加项目的参赛人数：");
			scanf("%d",&instert->renshu);
			printf("请输入添加项目的竞赛时间：");
			scanf("%s",&instert->shijian);
			ins(head,instert);
            break;
		case 6:
            putlist(head);
            break;
		case 7:
            printf("一共有%d个项目\t",o);
			printf("一共有%d个参赛人\t",numb(head));
			system("pause");
            break;
        case 0:
            printf("即将退出校运动会项目管理系统.....");
			g--;break;
       ;
        default:
            printf("您输入的指令不正确，请重新输入");break;
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
	printf("你想要录入多少个项目：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("请输入第%d个项目的项目序号：",i+1);
		scanf("%d",&p->num);
		printf("请输入第%d个项目的项目名称：",i+1);
		scanf("%s",&p->ming);
		printf("请输入第%d个项目的项目类：",i+1);
		scanf("%s",&p->lei);
		printf("请输入第%d个项目的参赛人数：",i+1);
		scanf("%d",&p->renshu);
		printf("请输入第%d个项目的竞赛时间：",i+1);
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
	printf("已经全部录入完毕");
	system("pause");
	return head;
}
void putlist(node *head)
{


	int i=0;node *p;
	printf("项目序号\t项目名称\t项目类  \t参赛人数\t竞赛时间\n");
	if(head==NULL)
	{
		printf("空");
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
	printf("输出完毕");
	system("pause");
}


node  *del(node *head,int a)
{ 
	node *p1,*p2;
   if(head==NULL)
   {
	   printf("\n 空 \n");
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
       printf("已删除的项目号为: %d\n",a);
	   o--;
    }
   else printf("%d 没有被发现 ! \n",a);
    
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
			printf("项目序号\t项目名称\t项目类  \t参赛人数\t竞赛时间\n");
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
				printf("未查找到");
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
  printf("已添加");
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
			printf("已经找到位置，选择修改项，\n1.项目序号\n2.项目名称\n3.项目类  \n4.参赛人数\n5.竞赛时间");
			scanf("%d",&j);
			switch(j)
			{
				case 1:printf("输入修改内容；"); 
						scanf("%d",&p->num);
						 break;
				case 2:printf("输入修改内容；"); 
						scanf("%s",&p->ming);
						 break;
				case 3:printf("输入修改内容；"); 
						scanf("%s",&p->lei);
						break;
				case 4:printf("输入修改内容；"); 
						scanf("%d",&p->renshu);
						break;
				case 5:printf("输入修改内容；"); 
					scanf("%s",&p->shijian);
					break;
			}
			printf("\n修改完毕\n");
			i-=2;
			printf("项目序号\t项目名称\t项目类  \t参赛人数\t竞赛时间\n");
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
				printf("未查找到");
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
