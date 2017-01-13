/**************************************************
             学生信息管理系统任务
***************************************************
从键盘输入包括学号、姓名、性别、出生年月日、籍贯、
所在院系、专业奖惩信息保存在磁盘文件具有单项查询或
多项查询功能具有插入修改和删除信息功能具有输出文件
数据信息功能。
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include"student.h"
void gui();
void main()
 {
	 STNODE *head=NULL;
	 char secNum[12];
	 char *pSecNum=secNum;
	 char selectFlag;
	 int index;
	 int seReturn;
	 gui();
	 while(1){
		do{
			printf("输入选择项：");
			scanf(" %c",&selectFlag);
		}while(selectFlag<'a'||selectFlag>'g');

		if(selectFlag=='g')
			break;

		switch(selectFlag){
			case 'a':system("cls");
					 head=stCreat();
					 system("cls");
					 gui();
					 break;
			case 'b':system("cls");
					if(head==NULL){
						 printf("无信息！\n");
						 system("cls");
						 gui();
						 break;
					 }
					 else{
						 system("cls");
						 gui();
				         displayList(head);
					   	 break;
					 }
			case 'c':system("cls");
				     append(head);
					 system("cls");
					 gui();
					 break;
			case 'd':system("cls");
					 if(head==NULL){
						 gui();
						 printf("无信息可供插入!");
				         break;
					 }else{
						 gui();
						 printf("请输入插入的序号:");
						 scanf("%d",&index);
						 insert(head,index);
						 break;
					 }
			case 'e':system("cls");
					 if(head==NULL){
						 gui();
						 printf("无存在信息！");
						 gui();
						 break;
					 }else{
						 gui();
						 printf("请输入要删除的序号:");
						 scanf("%d",&index);
						 stDelete(head,index);
						 break;
					 }
			case 'f':system("cls");
				     gui();
				     printf("请输入查询的学号：");
				     scanf("%s",secNum);
				     index=stSearch(head,pSecNum);
				     printf("所在序号为%d",index);
				     break;
	    }
	 }
 }
void gui()
{
	printf("**************************************************\n");
	printf("*                学生信息管理系统                *\n");
	printf("**************************************************\n");
    printf("*                    a.新建                      *\n");
	printf("*                    b.查看                      *\n");
    printf("*                    c.添加                      *\n");
    printf("*                    d.插入                      *\n");
	printf("*                    e.删除                      *\n");
	printf("*                    f.查询                      *\n");
	printf("*                    g.退出                      *\n");
    printf("**************************************************\n");
}
