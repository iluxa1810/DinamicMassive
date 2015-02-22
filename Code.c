#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <malloc.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

struct Matrix{
	int n;
	struct Line *l;
};

struct Line{
	int m;
	int *num;
};

int CreateMatrix(struct Matrix *);
struct Line CreateLine(struct Line);
void PrintMatrix(struct Matrix);
void DeleteMatrix(struct Matrix *);
int FindMaxLine(struct Matrix);
void OrderMaxLine(struct Matrix*);
int CheckValue(int *);
int _tmain(int argc, _TCHAR* argv[])
{
	struct Matrix M;
	int flag=0;
	for (;;)
	{
	puts("Enter kol-vo strok");
	flag=CreateMatrix(&M);
	if (flag==1) {
	  break;
	}
	puts("Vivod ishodnoy Matritsi na ecran");
	PrintMatrix(M);
	OrderMaxLine(&M);
	puts("Vivod novoy Matritsi na ecran");
	PrintMatrix(M);
	puts("Udalenie Matritsi");
	DeleteMatrix(&M);
	//system("pause");
		}
	return 0;
}

int CreateMatrix(struct Matrix *M){
	int i;
	CheckValue(&M->n);
	if (M->n==0) {
	return 1;
	}
   //	scanf("%d",&M->n);
	M->l=malloc(M->n*sizeof(struct Line));
  for (i = 0; i <=M->n-1; i++) {
   M->l[i]=CreateLine(M->l[i]);
   }
  return 0;

}
struct Line CreateLine(struct Line l)
{   int i,flag;
	puts("Vvedite Kol-Vo elementov stroki");
	CheckValue(&l.m);
	//scanf("%d",&l.m);
	puts("Zapolnenie stroki");
	l.num=malloc(l.m*sizeof(int)) ;
	for (i = 0; i <=l.m-1; i++)  {

		CheckValue(&l.num[i]);
	}
	return l;
}

void PrintMatrix(struct Matrix M){
 int i,j;
 for (i = 0; i <=M.n-1; i++) {
	 for (j = 0; j <= M.l[i].m-1; j++) {
			  printf("%d ",M.l[i].num[j]);
	 }
	 printf("\n");
 }
 return 0;
}
void DeleteMatrix(struct Matrix *M)
{
 int i;
 for (i = 0; i < M->n-1; i++) {
	 free(M->l[i].num);
 }
 free(M->l);
 M=NULL;
return 0;
}

int CheckValue(int *a){
int flag;
for (;;){
flag=scanf("%d",a);
 if (!flag){
	 printf("Chislo mojet bitb tolko celim\nvvedite korrectnie dannie\n");
	 scanf("%*s");
	 }
	 else return 0;
	}

 }
int FindMaxLine(struct Matrix M){
  int i,j,bufSum=0,sum=0,maxLine;
 for (i = 0; i <=M.n-1; i++) {
	for (j = 0; j <=M.l[i].m-1; j++) {
	  sum+= M.l[i].num[j];
	}
	if (bufSum<sum){
	bufSum=sum;
	maxLine=i;
	}
	sum=0;
   }
   return maxLine;
 }


void OrderMaxLine(struct Matrix *M){
int flag=0,buf,i,MaxLine=FindMaxLine(*M);
printf("Maximalnaya stroke %d i bude otsortirovana\n",MaxLine+1);
while (flag==0){
	flag=1;
	for (i=0;i<=M->l[MaxLine].m-1;i++)
		{
		if (i==M->l[MaxLine].m-1) {
		  break;
		}
		 if (M->l[MaxLine].num[i]>M->l[MaxLine].num[i+1])
		 {
			buf=M->l[MaxLine].num[i];
			M->l[MaxLine].num[i]=M->l[MaxLine].num[i+1];
			M->l[MaxLine].num[i+1]=buf;
			flag=0;
		 }
		}
	}
}

