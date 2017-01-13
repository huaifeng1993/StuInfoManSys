/**************************************************
             学生信息管理系统任务
***************************************************
从键盘输入包括学号、姓名、性别、出生年月日、籍贯、
所在院系、专业奖惩信息保存在磁盘文件具有单项查询或
多项查询功能具有插入修改和删除信息功能具有输出文件
数据信息功能。
***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
/***************************************************/
/**************************************************
                创建链表
***************************************************/
STNODE *stCreat(){
	STNODE *head,*tail,*pnew;
    char exitFlag;
	head=(STNODE *)malloc(sizeof(STNODE));//开辟STNODE类型内存空间并把地址赋给头节点
	if(head==NULL){                       //判断是否赋值成功
		printf("创建失败！\n");
		return NULL;
	}
	head->next=NULL;
	tail=head;
	while(1){
		do{
		printf("是否退出Y Or N：");
		scanf(" %c",&exitFlag);
		}while(exitFlag !='Y' && exitFlag !='N'&&exitFlag!='y'&&exitFlag!='n');//判断大小写YN是否输入正确

		if(exitFlag=='Y'||exitFlag=='y')
			break;
		pnew=(STNODE *)malloc(sizeof(STNODE));//创建新节点
		if(pnew==NULL)                        //判断创建是否成功
			printf("创建失败！\n");                  

		printf("学号：");                     //输入学生信息
		scanf("%s",pnew->stNumber);                     //利用PNum指针把字符串保存到pnew stNumber中
		printf("姓名：");
		scanf("%s",pnew->name);
		printf("性别：");
		scanf("%s",pnew->sex);
		printf("出生日期：");
		scanf("%s",pnew->birthDate);
		printf("籍贯：");
		scanf("%s",pnew->nativePlace);
		printf("院系：");
		scanf("%s",pnew->department);
		printf("奖惩信息：");
		scanf("%s",pnew->achOrPun);

		pnew->next=NULL; //尾节点指针域为空
		tail->next=pnew; //与前一节点相连接
		tail=tail->next; //tail指向最新的节点
		exitFlag=NULL;
	}
	return head;                              //返回头节点
}
/***************************************************
                  添加学生信息
***************************************************/
void append(STNODE *head)
{
	STNODE *temp,*pnew=NULL;
	pnew=(STNODE *)malloc(sizeof(STNODE));//创建新节点
	if(pnew==NULL)                        //判断创建是否成功
		printf("创建失败！\n");              

	printf("学号：");                     //输入学生信息
	scanf("%s",pnew->stNumber);                     //利用PNum指针把字符串保存到pnew stNumber中
	printf("姓名：");
	scanf("%s",pnew->name);
	printf("性别：");
	scanf("%s",pnew->sex);
	printf("出生日期：");
	scanf("%s",pnew->birthDate);
	printf("籍贯：");
	scanf("%s",pnew->nativePlace);
	printf("院系：");
	scanf("%s",pnew->department);
	printf("奖惩信息：");
	scanf("%s",pnew->achOrPun);
	for(temp=head;temp->next!=NULL;temp=temp->next);//temp跟踪到head尾节点
	temp->next=pnew;                        //尾节点指向新节点
	pnew->next=NULL;
}
/**************************************************
                   插入学生信息
**************************************************/
void insert(STNODE *head,int i)
{
	STNODE *temp;
	STNODE *pnew;
	int j;
	temp=head;
		pnew=(STNODE *)malloc(sizeof(STNODE));//创建新节点
	if(pnew==NULL)                        //判断创建是否成功
		printf("创建失败！\n");         

	printf("学号：");                     //输入学生信息
	scanf("%s",pnew->stNumber);                     //利用PNum指针把字符串保存到pnew stNumber中
	printf("姓名：");
	scanf("%s",pnew->name);
	printf("性别：");
	scanf("%s",pnew->sex);
	printf("出生日期：");
	scanf("%s",pnew->birthDate);
	printf("籍贯：");
	scanf("%s",pnew->nativePlace);
	printf("院系：");
	scanf("%s",pnew->department);
	printf("奖惩信息：");
	scanf("%s",pnew->achOrPun);

	for(j=1;j<i&&temp!=NULL;j++)
		temp=temp->next;
	if(temp==NULL){
		printf("节点不存在！\n");
		return ;
	}
	pnew->next=temp->next;
	temp->next=pnew;

}
/**************************************************
                   删除学生信息
**************************************************/
void stDelete(STNODE *head,int i)
{
	int j;
	STNODE *temp1,*temp2;
	temp1=head;

    for(j=1;j<i&&temp1!=NULL;j++){ //利用for循环使temp指向要删去节点
		temp1=temp1->next;
	}
	if(temp1==NULL){
		printf("删除的节点不存在\n");
		return;
	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);                   //释放删去的结点的内存
}
/**********************************************
                输出单个节点信息
**********************************************/
void displayUnit(STNODE *unit){
	if(unit==NULL){
		printf("信息为空!");
		return;
	}else{
		printf("学号：%s\n",unit->stNumber);
		printf("姓名：%s\n",unit->name);
		printf("性别：%s\n",unit->sex);
		printf("出生日期：%s\n",unit->birthDate);
		printf("籍贯：%s\n",unit->nativePlace);
		printf("院系：%s\n",unit->department);
		printf("奖惩信息：%s\n",unit->achOrPun);
		printf("---------------------------\n");
    }
}
/**********************************************
                输出链表信息
**********************************************/
void displayList(STNODE *head){
	STNODE *temp;
	temp=head;
	for(temp=head->next;temp!=NULL;temp=temp->next){
		 displayUnit(temp);
	}
}
/**********************************************
               修改节点信息
**********************************************/
void stListEdit(STNODE *head,int i){
	STNODE *temp;
	int j;
	char swFlag;
	char *pNum=NULL;

	temp=head;
	for(j=1;j<=i;j++){
		temp=temp->next;
	}
	displayUnit(temp);                    //输出当前学生信息

	do{                                //判断要修改学生信息
		printf("选择要修改的信息\n");
		printf("a.学号 b.姓名 c.性别 d.出生日期 f.籍贯 g.院系 h.奖惩信息 i.退出: ");
		scanf(" %c",&swFlag);
		while(swFlag<'a'||swFlag>'i'){             //判断选择是否有效
			printf("输入有错，请重新选择：");
			scanf(" %c",&swFlag);
		}
		switch(swFlag){
			case 'a':printf("学号：");                    
				scanf("%s",temp->stNumber);break;
			case 'b':printf("姓名：");
				scanf("%s",temp->name);break;
			case 'c':printf("性别：");
				scanf("%s",temp->sex);break;
			case 'd':printf("出生日期：");
				scanf("%s",temp->birthDate);break;
			case 'f':printf("籍贯：");
				scanf("%s",temp->department);break;
			case 'g':printf("院系：");
				scanf("%s",temp->department);break;
			case 'h':printf("奖惩信息：");
				scanf("%s",temp->achOrPun);break;
			case 'i':break;
		}
	}while(swFlag!='i');
}
/************************************************************
                      按字符查询
************************************************************/
int stSearch(STNODE *head,char *character)
{
	STNODE *temp;
	int location=0;
    for(temp=head;strcmp(temp->stNumber,character)!=0;temp=temp->next){
		location++;
	}
	if(location==0){
		printf("没找到！\n");
		return 0;
	}else{
		displayUnit(temp);
		return location;
	}
}
