#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkwin(int arr[3][3]){
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][0]!=0){
            if(arr[i][0]==1){
                return 1;
            }else{
                return 2;}}
        if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i]!=0){
            if(arr[0][i]==1){
                return 1;
            }else{
                return 2;}
        }
        
    }
        if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0]!=0){
            if(arr[0][0]==1){
                return 1;
            }else{
                return 2;}
        }
        if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[0][2]!=0){
            if(arr[0][2]==1){
                return 1;
            }else{
                return 2;}
        }
    return 0;
    }

void printb(int arr[3][3]){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==0){
                    printf("|   |");
                }else if(arr[i][j]==1){
                    printf("| X |");
                }else{
                    printf("| O |");
                }
            }
            printf("\n---------------\n");
        }

    }

void printar(int arr[3][3],FILE *fp){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==0){
                    fprintf(fp,"|   |");
                }else if(arr[i][j]==1){
                    fprintf(fp,"| X |");
                }else{
                    fprintf(fp,"| O |");
                }
            }
            fprintf(fp,"\n---------------\n");
        }

    }


int main(){
    int arr[3][3]={0};
    int uip=0;
    FILE *fp=NULL;
    fp=fopen("Game.txt","a");
    fprintf(fp,"===========================================================");

    while(uip<10){
        printb(arr);

        int inpx,inpy;
        if(uip%2==0){
            printf("Player X: ");}
        else{
            printf("Player O: ");}
            
        scanf("%d %d",&inpx,&inpy);

        if(arr[inpx-1][inpy-1]!=0 || inpx<1 || inpx>3 || inpy<1 || inpy>3){
            printf("Invalid move\n");
            continue;
        }
        


        if(arr[inpx-1][inpy-1]==0){
            if(uip%2==0){
                arr[inpx-1][inpy-1]=1;
            }else{
                arr[inpx-1][inpy-1]=2;
            }
            uip++;
        }
        printb(arr);
	printar(arr,fp);
	
        printf("\n");
        int res=checkwin(arr);
        if(res==1){
            printf("Player 1 wins\n");
            break;
        }else if(res==2){
            printf("Player 2 wins\n");
            break;
        }else if(uip==9){
            printf("Draw\n");
            break;
        }
    printf(fp,"\n\n------------------\n\n");
    fprintf(fp,"\n\n------------------\n\n");
    }

        fclose(fp);
        return 0;
        
}
