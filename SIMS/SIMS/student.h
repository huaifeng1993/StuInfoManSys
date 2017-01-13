#ifndef STUDENT_H
#define STUDENT_H
/**************************************************/
struct student{
	char   stNumber[12];
	char name[10];
	char sex[6];
	char birthDate[10];
	char nativePlace[50];
	char department[20];
	char achOrPun[50];
	struct student *next;
};
typedef struct student STNODE;
/**************************************************/
STNODE *stCreat();
void append(STNODE *head);       //在链表末尾添加新节点
void insert(STNODE *head,int i); //在链表中插入新节点
void stDelete(STNODE *head,int i);            //删除第i个节点
void displayUnit(STNODE *unit);               //输出某个节点信息
void displayList(STNODE *head);               //输出整个链表信息
void stListEdit(STNODE *head,int i);          //修改第i个节点的信息
int stSearch(STNODE *head,char *character);//按学号查询
int stSearchName(STNODE *head,char *name);    //按姓名查询信息
#endif