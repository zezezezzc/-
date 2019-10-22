#include<stdio.h>
#include<stdlib.h>
#include<time.h>	                                        
														//srand(time(0));
                                                        //sum=rand()/(float)(RAND_MAX/10); sum=10*(float)rand()/RAND_MAX  随机产生0到10的浮点数
                                                        //sum=(rand()%10);
typedef struct hongbao
{
	float h;
	int x;
}NODE;

void SUIJI(int n,float sum);

int main()
{
	int n;                                     //n为人数，sum为红包总金额
	float sum;

	printf("输入人数：");
	scanf("%d",&n);
	printf("输入红包金额:");
	scanf("%f",&sum);
	SUIJI(n,sum);
	getch();
	return 0;
}

void SUIJI(int n,float sum)
{
	NODE *p,q;
	int i,j,k,temp1;
	float temp;
	p=(NODE *)malloc(n*sizeof(NODE));
	if(p==NULL)
	{
		puts("error");
		return;
	}
	p[0].h=0;
	srand((int)time(0));
	for(i=0;i<n;++i)                   
	{
		if(i==(n-1))
			p[i].h=sum;
		else
		{
			temp=sum*((float)rand()/RAND_MAX);            //随机生成红包金额   每次随机上限为上次剩余
			temp1=temp*100+0.5;                           //随机金额的四舍五入
			temp=temp/100.0;
			if(temp==0||temp==(sum-p[i].h))
				continue;

			p[i].h=temp;
			sum-=temp;
		}

		/*p++;*/                              //      i的值增加相当于移动指针  p再次++出错
	}
	for(i=0;i<n;++i)                           //第二次随机过程   随机产生数  排序分配给人 
		p[i].x=rand()%100;
	for(i=0;i<n-1;++i)
	{
		k=i;
		for(j=1+i;j<n;++j)
		{
			if(p[k].x>p[j].x)
				k=j;
		}
		if(k!=i)
		{
			q=p[i];
			p[i]=p[k];
			p[k]=q;
		}
	}
	for(i=1;i<=n;++i)
		printf("第%d个人金额：%.2f\n",i,p[i-1].h);
}
