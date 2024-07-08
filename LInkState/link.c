#include <stdio.h>

int  costMat[20][20],dist[20],last[20],flag[20],src_router;

void readMat(int n){
    int i,j;
    printf("Enter the cost matrix\n");
        for(i=0; i<n; i++)
            for (int j = 0; j <n; j++){
                printf("%d==>%d: ",i,j);
                scanf("%d",&costMat[i][j]);

                if(costMat[i][j]<0)
                    costMat[i][j]=1000;
         }       
}

void calcMat(int n){
 int i,j,min,ind;

 for(i=0;i<n;i++){
    min=1000;
    for(j=0;j<n;j++){
        if(!flag[j])
            if(dist[j]<min){
                min=dist[j];
                ind=j;
            }
    }

    flag[ind]=1;

    for(j=0;j<n;j++){
        if(!flag[j]){
            if(dist[j]>min+costMat[ind][j]){
                dist[j]=costMat[ind][j]+min;
                last[j]=ind;
            }
        }
    }
 }
}

void display(int n){
    int i,j;
    for(i=0;i<n;i++){
        printf("%d==>%d: Path taken:%d ",src_router,i,i);
        j=i;
        while(j!=src_router){
            printf("<--%d",last[j]);
            j=last[j];
        }
        printf("\nShoterst distance : %d \n",dist[i]);      
    }
}

int main(){
    int  i,j,count;

    printf("Enter the number of Routers\n");
    scanf("%d",&count);
    readMat(count);
    printf("Enter the source router := ");
    scanf("%d",&src_router);

    for(i=0;i<count;i++){
        flag[i]=0;
        last[i]=src_router;
        dist[i]=costMat[src_router][i];
    }
    flag[src_router]=1;

    calcMat(count);
    display(count);
}