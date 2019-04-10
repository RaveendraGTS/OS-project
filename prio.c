#include<stdio.h>
int main()
{
    int BURST_TIME[200];
    int PROCESS[200];
    int WAITING_TIME[200];
    int ARRIVAL_TIME[200];
    int TURN_AROUND_TIME[200];
    int PRIORITY[200];
    int d[200];
    int i,j,n,t,m,pos,temp;
    int TOTAL=0,TURN_AROUND_TIME_TOTAL=0,p=1;
    float av_wt,av_tat;

    printf("enter no of process\n");
    scanf("%d",&n);
    printf("enter the value of burst time\n");//enter burst time
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BURST_TIME[i]);
        if(BURST_TIME[i]<=0)
        {
            printf("entered the wrong value\n");
            return 0;
        }
        PROCESS[i]=i+1;
    }
    printf("enter the value of arrival time\n");//enter arrival time
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&ARRIVAL_TIME[i]);
        if(ARRIVAL_TIME[i]<0)
        {
            printf("entered the wrong value\n");
            return 0;
        }
        PROCESS[i]=i+1;
    }
    for(i=0;i<n;i++)//sorting according to arrival time
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(ARRIVAL_TIME[j]<ARRIVAL_TIME[pos])
                pos=j;
        }
        temp=ARRIVAL_TIME[i];
        ARRIVAL_TIME[i]=ARRIVAL_TIME[pos];
        ARRIVAL_TIME[pos]=temp;

        temp=PROCESS[i];
        PROCESS[i]=PROCESS[pos];
        PROCESS[pos]=temp;

        temp=BURST_TIME[i];
        BURST_TIME[i]=BURST_TIME[pos];
        BURST_TIME[pos]=temp;
    }
    for(i=0;i<n;i++)
    {
        t=t+BURST_TIME[i];
        m=BURST_TIME[p];
        for(j=p;j<n;j++)
        {
            if(t>=ARRIVAL_TIME[j] && BURST_TIME[j]<m)
            {
                temp=PROCESS[p];
                PROCESS[p]=PROCESS[j];
                PROCESS[j]=temp;

                temp=ARRIVAL_TIME[p];
                ARRIVAL_TIME[p]=ARRIVAL_TIME[j];
                ARRIVAL_TIME[j]=temp;

                temp=BURST_TIME[p];
                BURST_TIME[p]=BURST_TIME[j];
                BURST_TIME[j]=temp;
            }
        }
        p++;
    }
    WAITING_TIME[0]=0;
    for(i=1;i<n;i++) //calculating waiting time
    {
        WAITING_TIME[i]=0;
        for(j=0;j<i;j++)
        WAITING_TIME[i]+=BURST_TIME[j];
        WAITING_TIME[i] = WAITING_TIME[i]-ARRIVAL_TIME[i];
        TOTAL +=  WAITING_TIME[i];
    }
    for(i=0;i<n;i++)
    {
        if(WAITING_TIME[i]<0)
        {
            WAITING_TIME[i]=0;
            printf("cpu is idle . After process %d",PROCESS[i-1]);
        }
    }
    for(i=0;i<n;i++)//calculating priority
    {
        d[i]=WAITING_TIME[i]/BURST_TIME[i];
        PRIORITY[i] = 1 + d[i];
    }
    for(i=0;i<n;i++)//sorting according to arrival time
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(PRIORITY[j]<PRIORITY[pos])
                pos=j;
        }
        temp=PRIORITY[i];
        PRIORITY[i]=PRIORITY[pos];
        PRIORITY[pos]=temp;

        temp=ARRIVAL_TIME[i];
        ARRIVAL_TIME[i]=ARRIVAL_TIME[pos];
        ARRIVAL_TIME[pos]=temp;

        temp=PROCESS[i];
        PROCESS[i]=PROCESS[pos];
        PROCESS[pos]=temp;

        temp=BURST_TIME[i];
        BURST_TIME[i]=BURST_TIME[pos];
        BURST_TIME[pos]=temp;
    }
    WAITING_TIME[0]=0;
    for(i=1;i<n;i++) //calculating waiting time
    {
        WAITING_TIME[i]=0;
        for(j=0;j<i;j++)
        WAITING_TIME[i]+=BURST_TIME[j];
        WAITING_TIME[i] = WAITING_TIME[i]-ARRIVAL_TIME[i];
        TOTAL +=  WAITING_TIME[i];
    }
    for(i=0;i<n;i++)
    {
        if(WAITING_TIME[i]<0)
        {
            WAITING_TIME[i]=0;
            printf("cpu is idle . After process %d",PROCESS[i-1]);
        }
    }

    for(i=0;i<n;i++)//calculating turn around time
    {
        TURN_AROUND_TIME[i] = BURST_TIME[i] + WAITING_TIME[i];
        TURN_AROUND_TIME_TOTAL+=TURN_AROUND_TIME[i];
    }
    for(i=0;i<n;i++)//calculating priority
    {
        d[i]=WAITING_TIME[i]/BURST_TIME[i];
        PRIORITY[i] = 1 + d[i];
    }
    printf("\n=====================================================================================================");
    printf("\nPROCESS  \tBURST_TIME \t ARRIVAL_TIME \t PRIORITY \tWAITING_TIME \tTURN_AROUND_TIME ");
    printf("\n-----------------------------------------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t",PROCESS[i],BURST_TIME[i],ARRIVAL_TIME[i],PRIORITY[i],WAITING_TIME[i],TURN_AROUND_TIME[i]);
    }
    printf("\n=====================================================================================================");
    printf("\naverage waiting time=\n%f",(float)TOTAL/n);
    printf("\naverage turn around time=\n%f",(float)TURN_AROUND_TIME_TOTAL/n);

}


