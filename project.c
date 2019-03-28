#include<stdio.h>
int main()
{
    int BT[20];
    int pr[20];
    int WT[20];
    int TAT[20];
    int i,j,n,pos,temp;
    int TOTAL=0,TATTOTAL=0;
    float av_wt,av_tat;
    printf("enter no of process\n");
    scanf("%d",&n);
    printf("enter the value of burst time\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BT[i]);
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
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
        WT[i]+=BT[j];
        TOTAL+=WT[i];
    }
    av_wt=(float)TOTAL/n;
    printf("total waiting time=%d",av_wt);
    for(i=0;i<n;i++)
    {
        TAT[i] = BT[i] + WT[i];
        TATTOTAL+=TAT[i];
    }
    av_tat=TATTOTAL/n;
    printf("\n====================================================================================");
    printf("\nPROCESS  \tBURST TIME \tWAITING TIME \tTURN AROUND TIME");
    printf("\n-------------------------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t",pr[i],BT[i],WT[i],TAT[i]);
    }
    printf("\n====================================================================================");
    printf("\naverage time=\n%f",&av_wt);
    printf("\naverage turn around time=\n%f",&av_tat);
}
