#include<stdio.h>
int main()
{
    int BT[200];
    int pr[200];
    int WT[200];
    int TAT[200];
    int PRIOR[200];
    int d[200];
    int i,j,n,pos,temp;
    int TOTAL=0,TATTOTAL=0;
    float av_wt,av_tat;
    printf("enter no of process\n");
    scanf("%d",&n);
    printf("enter the value of burst time\n");//enter burst time
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BT[i]);
        if(BT[i]<=0)
        {
            printf("entered the wrong value\n");
            return 0;
        }
        pr[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[pos])
                pos=j;
        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
    }
    WT[0]=0;
    for(i=1;i<n;i++) //calculating waiting time
    {
        WT[i]=0;
        for(j=0;j<i;j++)
        WT[i]+=BT[j];
        TOTAL += WT[i];
    }

    for(i=0;i<n;i++)//calculating turn around time
    {
        TAT[i] = BT[i] + WT[i];
        TATTOTAL+=TAT[i];
    }
    for(i=0;i<n;i++)//calculating priority
    {
        d[i]=WT[i]/BT[i];
        PRIOR[i] = 1 + d[i];
    }
    printf("\n====================================================================================");
    printf("\nPROCESS  \tBURST TIME \tWAITING TIME \tTURN AROUND TIME \t PRIORITY");
    printf("\n-------------------------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t",pr[i],BT[i],WT[i],TAT[i],PRIOR[i]);
    }
    printf("\n====================================================================================");
    printf("\naverage waiting time=\n%f",(float)TOTAL/n);
    printf("\naverage turn around time=\n%f",(float)TATTOTAL/n);
}
