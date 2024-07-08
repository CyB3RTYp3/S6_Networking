#include <stdio.h>

int costMat [20][20];

struct router{
    int dist[20];
    int adj[20];
}node[20];

void readMatrix(int n){
    int i,j;
    printf("Enter the cost matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&costMat[i][j]);
            costMat[i][i]=0;
            node[i].dist[j]=costMat[i][j];
            node[i].adj[j]=j;
        }
    }
}
void display(int n){
    int i,j;
    printf("The Output matrix is \n");
    for(i=0;i<n;i++){
        printf("dvr table for router %d\n",i);
        for(j=0;j<n;j++){
            printf("Node %d via %d : Distance %d\n", j , node[i].adj[j] , node[i].dist[j]);
        }
        printf("\n");
    }
}

void calcRoutes(int n){
    int i,j,k;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            for(k=0;k<n;++k){
                if(node[i].dist[j] > costMat[i][k] +node[k].dist[j]){
                    node[i].dist[j]=costMat[i][k] + node[k].dist[j];
                    node[i].adj[j]=k;
                }
         }
     }
    }
}

void main(){
    int n;
    printf("Enter the numbe of routes\n");
    scanf("%d",&n);
    readMatrix(n);
    calcRoutes(n);
    display(n);
}