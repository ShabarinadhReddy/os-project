#include<stdio.h>
#include<conio.h>
struct Project
{
int id,at,bt;
}
f[100],s[100],E[100];
int Number,Student=0,Faculty=0,count=0;
void input()
{
	int job,ah,am,bt,j,m=0,id=1;
	printf("\n Enter number of Queries: ");
	scanf("%d",&Number);
	printf("Please Enter  1 for Student and 2 for Faculty...\n");
	for (m=0;m<Number;m++)
	{
		printf("\n               Query %d            \n\n",m+1);
		printf("Enter (1 or 2):");
		scanf("%d",&j);
		if(j==1)
		{
			printf("Query ID: %d\n",id);
			s[Student].id=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ah,&am);
			if((ah<24) && (am<60))
			{
				if((10<=ah) && (ah<12))
				{
					if((am>=0) && (am<60))
					{
						s[Student].at=600-(ah*60)+am;
						printf("Resolving time: ");
						scanf("%d",&s[Student].bt);
						Student++;
					}
					else
					printf("Enter valid minutes\n");
				}
				else
				printf("I am available from 10 to 12 only");
			}
			else
			printf("Not at valid time\n");
		}
		else if(j==2)
		{
			printf("Query ID: %d\n",id);
			f[Faculty].id=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ah,&am);
			if((ah<24) && (am<60))
			{
				if((10<=ah) && (ah<12))
				{
					if((am>=0) && (am<60))
					{
						f[Faculty].at=600-(ah*60)+am;
						printf("Resolving time: ");
						scanf("%d",&f[Faculty].bt);
						Faculty++;
					}
					else
					printf("Enter valid minutes\n");
				}
				else
				printf("I am available from 10 to 12 only");
			}
			else
			printf("Not a valid time\n");
		}
		else
		{
		printf("please enter valid input\n");
		input();
		}
		id++;
	}
}
void Execution_Order()
{
	int ids=0,idf= 0;
	if( Faculty!=0  && Student!=0)
	{
		while(ids<Student && idf<Faculty)
		{
			if(f[idf].at == s[ids].at)
			{
				E[count] = f[idf];
				count++;
				idf++;
				E[count]= s[ids];
				count++;
				ids++;
			}
			else if(f[idf].at < s[ids].at)
			{
				E[count]= f[idf];
				count++;
				idf++;
			}
			else if(f[idf].at > s[ids].at)
			{
				E[count]= s[ids];
				count++;
				ids++;
			}
			else;
		}
		if(count != (Faculty+Student))
		{
			if(Faculty!=idf)
			{
				while(idf!=Faculty)
				{
					E[count]= f[idf];
					count++;
					idf++;
				}
			}
			else if(Student!=ids)
			{
				while(ids!=Student)
				{
					E[count]= s[ids];
					count++;
					ids++;
				}
			}
		}
	}
	else if(Faculty==0)
	{
		while(ids!=Student)
		{
			E[count]= s[ids];
			count++;
			ids++;
		}
	}
	else if(Student==0)
	{
		while(idf!=Faculty)
		{
			E[count]= f[idf];
			count++;
			idf++;
		}
	}
	else 
	{
		printf("\n No valid Jobs available\n");
	}
}
void RoundRobin()
{
	int m,j,i,t,temp,k;
     int aw; float awt;
     int bt[10],w[10],te[10],rt[10],at[10];j=0;
    for(i=0;i<Number;i++)
      {
          at[i]=E[i].at;
          bt[i]=E[i].bt;
          te[i]=0;     w[i]=0;
      }
    for(i=0;i<Number;i++)
      {
        for(j=i+1;j<Number;j++)
         {
             if(at[i]>at[j])
               {
                    temp=at[i];                                          
                    at[i]=at[j];
                    at[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
              }
         }
     }
    printf("\n Please enter time quantum :   ");
    scanf("%d",&t); k=0;
    printf("\nprocess      :")  ;
    for(i=0;i<Number;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrust time   :");
    for(i=0;i<Number;i++)
       {
         printf("  %d",bt[i]); rt[i]=bt[i];
        }
    printf("\nArrival time :");
    for(i=0;i<Number;i++)
      {
          printf("  %d",at[i]);
      }
    printf("\n\n *Daily Report* \n");
    j=0;

    while(j<=Number)
       {
          j++;
          for(i=0;i<Number;i++)
            {
              if(rt[i]==0)  continue;
                   if(rt[i]>t)
                     {
                        printf("\n %d\t P%d",k,i+1);
                        k=k+t;
                        rt[i]=rt[i]-t;
                        te[i]=te[i]+1;
                     }
                  else
                    {
                       printf("\n %d\t P%d",k,i+1);
                       w[i]=k-te[i]*t;
                       k=k+rt[i]; 
                       rt[i]=rt[i]-rt[i];
                    }
            }
       }                                      
	   
	printf("\n"); 
    awt=0;
    printf("\n Process       Waiting time        Turn Around time");
    int ta[Number],tat=0;
	float atat=0;
    for(i=0;i<Number;i++)
       {
       	
                w[i]=w[i]-at[i];
                if(w[i]<0)
				{
				w[i]=w[i]-2*w[i];
				}
                ta[i]=w[i]+bt[i];
                printf("\n P%d\t\t  %d\t\t\t  %d",i+1,w[i],ta[i]);
                tat=tat+ta[i];
				awt=awt+w[i];
        }
    atat=tat;
    printf("\n Total Query Time :  %d",tat);
    printf("\n Average Query Time is:  %f ",(atat/Number));
}
      start()
{
	input();
	Execution_Order();
	RoundRobin();
}
int main()
{
	printf("                      ***Welcome***               \n1.Please enter the time as shown Ex.10 30 \n2.All the timings should be in ascending order \n");
	start();
}
