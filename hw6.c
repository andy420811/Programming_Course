#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Nmax 30
void prtarr(int *a[],int n);
void cal(int *a[],int n);
void Guess(int *a[]);

int main(int argc,char *argv[]){
	int N,M;int c=0,d=0;
	N=atol(argv[1]);M=atol(argv[2]);
	if(N>30){printf("N larger than 30"); return -1;}	
	int a[30][30]={0};
	srand(time(NULL));
	for(int i=0;i<M;i++){
		c=N*((float)rand()/RAND_MAX);
		d=N*((float)rand()/RAND_MAX);
		if(*(a[c]+d)==1){i--;}
		else a[c][d]=1;
	}
	int *b[N];
	for(int i=0;i<N;i++){
		b[i]=&a[i][0];
	}
	cal(b,N);
	prtarr(b,N);


	return 0;
}
void cal(int *a[],int n){
	int *p;
	int *check[8],count=0;
	for(p=&(a[0][0]);p<&(a[n][0]);p++){//跑不進迴圈
		count=0;
		if(*p==-1){
			check[0]=(p-n-1);check[1]=(p-n);check[2]=(p-n+1);
			check[3]=(p  -1);               check[4]=(p  +1);
			check[5]=(p+n-1);check[6]=(p+n);check[7]=(p+n+1);
			for(int i=0;i<8;i++){
				if(*(check[i])==-1){count-=*check[i];}
			}
			*p=count;
		}
	}
}
void prtMine(int *a[],int n){
	
}
void prtarr(int *a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(a[i]+j));}printf("\n");}}

void Guess(int *a[]){
	int row,col;
	scanf("%d%d",&row,&col);
}	
	
