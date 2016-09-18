#include<iostream>
#include"stdio.h"
using namespace std;
typedef struct studentList
{
   int data;
   struct studentList* prio;
   struct studentList* next;
}stuList,*pStuList;
pStuList creat_list(int length)
{
   pStuList pHead = new stuList;
   if(NULL == pHead)
   {
     cout<<"failed new memory:"<<__LINE__<<endl;
	 exit(1);
   }
   pHead->data = 0;
   pHead->next = NULL;
   pHead->prio = NULL;
   pStuList pTail = pHead;
   for(int i = 0;i<length;i++)
   {
      pStuList pNew = new  stuList;
	  if(NULL == pNew)
	  {
	    cout<<"failed new memory:"<<__LINE__<<endl;
	    exit(1);
	  }
	  pNew->data = i;
	  pNew->next = NULL;
	  pNew->prio = pTail;
	  pTail->next = pNew;// important
	  pTail = pNew;
   }
   return pHead;
} 
int add_node_in_list(pStuList pHead,int data)//add node in end list
{
   pStuList pt = pHead; 
   while(NULL != pt->next)// important
   {
	  pt = pt->next;
   }
   pStuList addPtr = new stuList;
   if(NULL == addPtr)
	  {
	    cout<<"failed new memory:"<<__LINE__<<endl;
	    exit(1);
	  }
   pt->next = addPtr;
   addPtr->prio = pt;
   addPtr->next = NULL;
   addPtr->data = data;
   return 1;
}
int get_length_of_list(pStuList pHead)
{
  pStuList pt = pHead;
  int listLength = 0; //important
  while(NULL != pt->next)//important pt->next
  {
	  listLength++;
	  pt = pt->next;
  }
  return listLength;
}
int insert_node_in_list(pStuList pHead,int pos,int data)
{
   pStuList pt = pHead; 
   if(pos < get_length_of_list(pHead))
   {
     while(pos--)
   {
	   pt = pt->next;
   }
   pStuList insertPtr = new stuList;
   if(NULL == insertPtr)
	  {
	    cout<<"failed new memory:"<<__LINE__<<endl;
	    exit(1);
	  }
   insertPtr->next = pt->next;
   insertPtr->prio = pt;
   insertPtr->data = data;

   pt->next = insertPtr;
   pStuList ptTemp = pt;
   ptTemp->next->prio = insertPtr;
   }
   else
   {
      cout<<"pos overflow"<<endl;
	  exit(1);  //exit programme
   }
   return 1;
}
int delete_node_in_list(pStuList pHead,int pos)
{
   pStuList pt = pHead; 
   while(--pos)
   {
	   pt = pt->next;
   }
   pStuList ptPrio = pt->prio;
   ptPrio->next = pt->next;
   pt->next->prio = ptPrio;
   return 1;
}
int traversal_list(pStuList pHead)
{
  pStuList pt = pHead; 
  while(NULL != pt)
  {
     cout<<"data:"<<pt->data<<endl;
	 pt = pt->next;
  }
  return 1;
}
int inverse_traversal_list(pStuList pHead) 
{
  pStuList pt = pHead; 
  while(NULL != pt->next)
  {
	 pt = pt->next;
  }
  while(NULL != pt)
  {
	  cout<<"data:"<<pt->data<<endl;
	pt = pt->prio;
  }
  return 1; 
}
int main1()
{
 pStuList pHead = creat_list(10);
 
 add_node_in_list(pHead,100);
 insert_node_in_list(pHead,15,5000000);
 traversal_list(pHead);
 cout<<endl;
 delete_node_in_list(pHead,5);
 traversal_list(pHead);
 cout<<endl;
 inverse_traversal_list(pHead);

 int length = get_length_of_list(pHead);
 cout<<"length:"<< length <<endl;
 return 1;
}