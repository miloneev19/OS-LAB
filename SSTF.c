#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct request{

    int track_no;
    bool visited;
};

int main(){

    int no_request,head;
    printf("Enter the number of request= ");
    scanf("%d" , &no_request);

    struct request req[no_request];

    printf("Enter the requests = ");
    for(int i=0;i<no_request;i++){

        scanf("%d",&req[i].track_no);
        req[i].visited==false;

    }

    printf("Enter the initial head of R/W = ");
    scanf("%d", &head);

    int seek_time=0;
    int n=no_request;

    while(n){

        int min = 1e9;
        int min_track;
        int position;
        for(int i=0;i<no_request;i++){

            if(abs(head - req[i].track_no) < min && req[i].visited==false){

                min = abs(head - req[i].track_no);
                position=i;
            }
        }
        head = req[position].track_no;
        req[position].visited=true;
        printf("Track number =%d",req[position].track_no);
        seek_time += min;
        n--;
    }

    printf("Total seek time is =%d",seek_time);
}