#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXR 15//B数组行数
#define MAXC 15 //B数组列数


#define AM 5//A数组行数
#define AN 5 //A数组列数

void init(char ds[][MAXC]);//给数组初始化值(给数组随机大写字母)
void prfDS(char ds[][MAXC]);//打印数组
void initnum(char ts[][AN]);
void prfTS(char ts[][AN]);
void pern(char *p0,char *p1,int x,int y);
int main()
{
    char ds[MAXR][MAXC],*p0=&ds[0][0];
    char ts[AM][AN],*p1=&ts[0][0];

    srand(time(NULL));
    init(ds);
	initnum(ts);
	//初始化数组
    printf("初始化B的值为：\n        ");
    prfDS(ds);
	printf("初始化A的值为：\n        ");
	prfTS(ts);
	
	//置换函数
	pern(p0,p1,AM,AN);
	printf("置换的值为：\n        ");
    prfDS(ds);
    return 0;
}
void init(char ds[][MAXC])//给数组初始化值(给数组随机大写字母)
{
    int i,j,rn;
    for(i=0;i<MAXR;i++)
        for(j=0;j<MAXC;j++,rn=rand()%26)
            ds[i][j]=65+rn;
 
}
void initnum(char ts[][AN])
{
    int i,j,rn;
    for(i=0;i<AM;i++)
        for(j=0;j<AN;j++,rn=rand()%9)
            ts[i][j]=48+rn;
 
}
void prfDS(char ds[][MAXC])//打印数组
{
    int i,j;
    for(i=0;i<MAXR;i++,printf("\n        "))
        for(j=0;j<MAXC;j++)
            printf("%c",ds[i][j]);
    printf("\n");
}
void prfTS(char ts[][AN])//打印数组
{
    int i,j;
    for(i=0;i<AM;i++,printf("\n        "))
        for(j=0;j<AN;j++)
            printf("%c",ts[i][j]);
    printf("\n");
}
//置换函数
void pern(char *p0,char *p1,int x,int y)
{
    int i;
    for(i=0;i<x;i++)
		memcpy(p0+(x+i)*MAXC+y,p1+i*y,y);
}
