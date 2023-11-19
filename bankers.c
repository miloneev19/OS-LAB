#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int allocation[100][100];
int max[100][100];
int need[100][100];
int available[100];
int safe[100];
bool finished[100];

void bank(int np, int nr){

    
    int work[100];
    int count = 0,j,i ;

    for(i=0;i<nr;i++){
        work[i] = available[i];
    }
    for( i=0;i<100;i++){
        finished[i]=false;
    }

    while(count < np){

        bool allot=false;
        for( i=0;i<np;i++){

                if(finished[i]==false){

                    for( j=0;j<nr;j++){

                        if(work[j] < need[i][j]){
                            break;
                        }
                    }

                    if(j==nr){

                        for( j=0;j<nr;j++ ){

                            work[j] += allocation[i][j];
                        }
                    safe[count++]=i;
                    finished[i]=true;
                    allot=true;
                    
                    }

                }
        }
        if(allot==false){
            printf("System is not in safe state");
            return;
        }
    }

    printf("Safe state");
    for(i=0;i<np;i++){

        printf("%d ",safe[i]);
    }

}
int main(){

    int np,nr,i,j;
    printf("Enter the number of processes = ");
    scanf("%d",&np);

    printf("Enter the number of resources = ");
    scanf("%d",&nr);

    printf("Enter the available ");
    for( i=0;i<nr;i++){
        scanf("%d",&available[i]);  
    }

    printf("Enter the allocation matrix");
    for( i=0;i<np;i++){
        for( j=0;j<nr;j++){
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("Enter the max matrix");
    for( i=0;i<np;i++){
        for( j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
        }
    }

    
    for( i=0;i<np;i++){
        for( j=0;j<nr;j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    bank(np,nr);

}