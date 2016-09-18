#include"stdio.h"
#include"stdlib.h"

typedef struct dataList
{
  int data;
  struct dataList * next;
}dataList,*pDataList;
pDataList creat_list()
{
   pDataList pHead = (pDataList)malloc(sizeof(dataList));
   if( NULL == pHead  )
   {
     printf("creat_list pHead malloc is failed");
	 exit(1);
   }
   pHead->next = NULL;
   pHead->data = 0;
   pDataList pList = pHead;
   int endInt = 999;
   int data = 0;
   int cycle = 1;
   while(cycle)
   {
      scanf("%d",&data);
	  if(data != endInt)
	  {
	     pDataList qList = (pDataList)malloc(sizeof(dataList));
		 if(NULL ==qList )
		 {
		    printf("creat_list qList malloc is failed\n");
			exit(1);
		 }
		 qList ->data = data;
		 qList->next = NULL;
		 pList->next = qList;
		 pList = qList;
	  }
	  else
		  cycle = 0;
   }
   return pHead;
}
int get_length_of_list(pDataList pHead)
{
    pDataList pList = pHead;
	int len = 0;
	while(NULL != pList)
	{
		
	   len++;
	   pList = pList->next;
	}
	return (len-1);
}
void add_list(pDataList pHead)
{
    pDataList pList = pHead;
	int data;
	while(NULL !=pList->next )
	{
		pList = pList->next;
	}
	pDataList qList = (pDataList)malloc(sizeof(dataList));
    if(NULL ==qList )
    {
		   printf("add_list qList malloc is failed\n");
			exit(1);
	 }
	printf("\n input add data:");
	scanf("%d",&data);
	pList->next  = qList;
	qList->data = data;
	qList->next = NULL;
}
int insert_into_list(pDataList pHead,int pos)
{
	pDataList pList = pHead;
   if(pos >get_length_of_list(pHead) )
   {
     printf("excess the length of list\n");
	 return 0;
   }
   else
   {
      while(--pos)
	  {
		  pList = pList->next;
	  }
	  pDataList qList = (pDataList)malloc(sizeof(dataList));
	   if(NULL ==qList )
     {
		   printf("insert_into_list qList malloc is failed\n");
			exit(1);
	 }
	   int data = 0;
    printf("input add data:");
	scanf("%d",&data);
	
	qList->data = data;
	qList->next =pList->next  ;
	pList->next  = qList;
	return 1;
   }
}
int delete_from_list(pDataList pHead,int pos)
{
    pDataList pList = pHead;
	 if(pos >get_length_of_list(pHead) )
   {
     printf("excess the length of list\n");
	 return 0;
   }
  else
  {
	    while( --pos )
		{
			pList = pList->next;
		}
		pList->next =pList->next->next;
		return 1;
	}
}
int sort_to_list(pDataList pHead)
{
  int listSize = get_length_of_list(pHead);
  
  pDataList pList = pHead;
  
  pList= pList->next;
  for(int i = 0; i <listSize - 1;i++)
  {
	  pList = pHead;
	  pList= pList->next;
    for(int j = 0;j<listSize - i - 1;j++)
	  {
		  if(pList->data > pList->next->data)
		  {
		      int temp = pList->data ;
			  pList->data  = pList->next->data;
			  pList->next->data = temp;
		  }
		  pList = pList->next;
	  }
  }
	  
	  return 1;
}
int sort_to_list_second_way(pDataList pHead)
{
    int listSize = get_length_of_list(pHead);
  
  pDataList pList = NULL;
  pDataList qList = NULL;
 
  for(int i = 0; i <listSize - 1;i++)
  {
	  pList = pHead;
	  pList= pList->next;
	  qList = pList->next;
    for(int j = 0;j<listSize - i - 1;j++)
	  {
		  if(pList->data > qList->data)
		  {
		    dataList temp = *(pList);
			temp.next = qList->next;
			*(pList) = *(qList);
			*(qList) = temp;
			pList->next = qList;
		  }
		  pList = pList->next;
		  qList = qList->next;
	  }
  }
	  
	  return 1;
}
void traversal_list(pDataList pHead,bool reversalFlag)//逆置
{
   pDataList pList = pHead;
   if(true == reversalFlag)
   {
	   while(NULL != pList->next)
     {
	   printf(" %d",pList->data);
	   pList = pList->next;
	  
     }
   }
   else
   {
     pList = pList->next;
     while(NULL != pList)
     {
	    printf(" %d",pList->data);
	   pList = pList->next;
	  
     }
   }
   
}
pDataList reversal_list(pDataList pHead)
{
   pDataList pPre = pHead;
   pDataList pCur = pPre->next;
   pDataList pNext = NULL;
   if(NULL == pHead || NULL == pHead->next)
   {
     return 0;
   }
   while(NULL != pCur)
   {
      pNext = pCur->next;
	  pCur->next = pPre;
	  pPre = pCur;
	  pCur = pNext;
	  
   }
   pHead->next = NULL;
   pHead = pPre;
   return pHead;
}
pDataList reversal_list_second_way(pDataList pCur,pDataList &pHead)
{
    if( (NULL==pCur)||(NULL==pCur->next) )  
    {  
            pHead=pCur;  
            return pCur;  
    }  
    else  
    {  
        pDataList pTemp=reversal_list_second_way(pCur->next,pHead); //递归逆置后继结点  
        pTemp->next=pCur;   //将后继结点指向当前结点  
        pCur->next=NULL;  
        return pCur;  
    } 
}
int main()
{
  pDataList pHead =  creat_list();
  pDataList pCur = pHead;
  traversal_list(pHead,false);
  //sort_to_list_second_way(pHead);
  printf("\n");
  traversal_list(reversal_list_second_way(pCur,pHead),true);
}