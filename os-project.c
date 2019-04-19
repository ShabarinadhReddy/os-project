#include<stdio.h>

struct process{
    int pid;
    int arrivaltime;
    int bursttime;
    int completetime;
    int roundbacktime;
}f[100], s[100], m[100];

int n, fc=0, sc=0, mc=0;
int quanta;

void input();
void input8();
void prmapping();
void roundrobin();
void display();

//struct Project
//{
//int id,at,bt;
//}
//f[100],s[100],E[100];

int main()
{
        printf("                      ***Welcome***               \n1.Please enter the time as shown Ex.10 30 \n2.All the timings should be in ascending order \n");

    input8();
    prmapping();
    roundrobin();
    display();      
        
}

int Number,Student=0,Faculty=0,count=0;

void input8()
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
			s[Student].pid=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ah,&am);
			if((ah<24) && (am<60))
			{
				if((10<=ah) && (ah<12))
				{
					if((am>=0) && (am<60))
					{
						s[Student].arrivaltime=600-(ah*60)+am;
						printf("Resolving time: ");
						scanf("%d",&s[Student].bursttime);
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
			f[Faculty].pid=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ah,&am);
			if((ah<24) && (am<60))
			{
				if((10<=ah) && (ah<12))
				{
					if((am>=0) && (am<60))
					{
						f[Faculty].arrivaltime=600-(ah*60)+am;
						printf("Resolving time: ");
						scanf("%d",&f[Faculty].bursttime);
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
		input8();
		}
		id++;
	}
}

void prmapping(){
    int isc=0, ifc= 0, min, flag;
    if( fc!=0  && sc!=0){
        while(isc<sc && ifc<fc){
            if(f[ifc].arrivaltime == s[isc].arrivaltime){
                m[mc] = f[ifc];
                mc++;
                ifc++;
                m[mc]= s[isc];
                mc++;
                isc++;
            }
            else if(f[ifc].arrivaltime < s[isc].arrivaltime){
                m[mc]= f[ifc];
                mc++;
                ifc++;
            }
            else if(f[ifc].arrivaltime > s[isc].arrivaltime){
                m[mc]= s[isc];
                mc++;
                isc++;
            }
            else;
        }
        if(mc != (fc+sc)){
            if(fc!=ifc){
                while(ifc!=fc){
                    m[mc]= f[ifc];
                    mc++;
                    ifc++;
                }
            }
            else if(sc!=isc){
                while(isc!=sc){
                    m[mc]= s[isc];
                    mc++;
                    isc++;
                }
            }
        }
    }
    else if(fc==0){
        while(isc!=sc){
            m[mc]= s[isc];
            mc++;
            isc++;
        }
    }
    else if(sc==0){
        while(ifc!=fc){
            m[mc]= f[ifc];
            mc++;
            ifc++;
        }
    }
    else {
        printf("\n No valid Jobs available\n");
    }
}

void roundrobin(){
    int time= m[0].arrivaltime, mark=0, cc=0, i, rc;
    while(time!=120 && cc!=mc){
        for(i=0; i<=mark; i++){
            if(m[i].roundbacktime > quanta){
                time += quanta;
                m[i].roundbacktime -= quanta;
            }
            else if(m[i].roundbacktime <=quanta && m[i].roundbacktime !=0){
                time += m[i].roundbacktime;
                m[i].roundbacktime =0;
                m[i].completetime = time;
                cc++;
            }
            else;
        }
        int start = mark+1;
        for(rc= start; rc<mc; rc++){
            if(m[rc].arrivaltime <= time){
                mark++;
            }
        }
    }   
}

void display(){
    int i=0, total=0, sum=0; 
    double avg;
    printf("\nSummary for the Execution\n");
    printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
    for(i; i<mc; i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
        m[i].pid, (m[i].arrivaltime+1000), m[i].bursttime, (m[i].completetime+1000), (m[i].completetime-m[i].arrivaltime), ((m[i].completetime-m[i].arrivaltime)- m[i].bursttime));
        total= m[i].completetime;
        sum+= (m[i].completetime-m[i].arrivaltime);
    }
    avg = sum/mc;
    printf("\n\nTotal time Spent for all queries: %d", total);
    printf("\nAverage query time: %lf", avg);
    printf("\nProcess Execution Complete");
}

