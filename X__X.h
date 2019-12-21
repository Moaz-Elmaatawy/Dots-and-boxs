#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include<math.h>
#include <dirent.h>

#define clear printf("\e[1;1H\e[2J");
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

FILE *fs;
FILE *p_r;
FILE *fptr;
FILE *fptr2;

int  score1=0 , score2=0 ;
int undo=0;
int case_input=0;
char rank_direct[1000]="./private/save.txt";
char name1[1000] ,name2[1000];
int load=0;
int compu;
clock_t t1;
clock_t t2;
int player1=0,player2=0;
char go[100][100][100];
int step=0;
char op='0';
int cheak_go[10000][10000];
int turns[10000];
int save_score1[10000];
int save_score2[10000];

void go_equal_check (int cheak[],int n,int step){
    ++n;
    n/=2;
    n=2*n*(n-1)+1;
    for(int j=0;j<n;++j){
        cheak_go[step][j]=cheak[j];
    }
}
void cheak_equal_go (int cheak[],int n,int step){
    ++n;
    n/=2;
    n=2*n*(n-1)+1;
    for(int j=0;j<n;++j){
        cheak[j]=cheak_go[step][j];
    }
}



void go_equal_arr (char arr[][1000], int n,int step){
	for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            go[step][i][j]=arr[i][j];
        }
  }
}
void arr_equal_go (char arr[][1000], int n,int step){
	for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            arr[i][j]=go[step][i][j];
        }
  }
}


bool formbox (char arr[][1000],int n,int *score,char c){
    bool k = 0;

    for (int i = 0 ; i < n-2 ; i+=2){
        for (int j = 1 ; j < n-1 ; j+=2){
            if (arr[i][j] != '0' && arr[i+1][j-1] != '0' && arr[i+1][j+1] != '0' && arr[i+2][j] != '0' ){
                  if (arr[i+1][j] == '0' ){
                        arr[i+1][j] = c ;
                        ++*score;
                        k = true ;
                  }

            }

        }
    }

    return k ;
}


//======================================================================================================================================================================/////


void print_grid(char arr[][1000],int n,int score1 ,int score2,int turn ,int remain){
    int counter=0;
    system("");

printf(RED "\t\t\t      DOTS AND BOXS \n\n" RESET) ;
if (turn==1)printf(CYAN "========= IT IS THE %s 'S  TURN ========\n" RESET,name1) ;
if (turn==2)printf(YELLOW "========= IT IS THE %s 'S  TURN ========\n" RESET,name2) ;
    for (int i = 0 ; i < n ; i++){
            printf("\t\t\t\t");
        for (int j = 0 ; j < n ; j++){
            if (arr[j][i]=='0'&&i%2==0&&j%2==0) printf("%c",254) ;
            else if (arr[j][i]=='1' && i%2 ==0){ printf(CYAN"%c%c%c%c" RESET ,196,196,196,196);++counter;}
            else if (arr[j][i]=='1' && i%2 !=0){ printf(CYAN"| " RESET );++counter;}
            else if (arr[j][i]=='2' && i%2 ==0){ printf(YELLOW"%c%c%c%c" RESET ,196,196,196,196);++counter;}
            else if (arr[j][i]=='2' && i%2 !=0) {printf(YELLOW"| " RESET );++counter;}
            else if (arr[j][i]=='A' ) printf(CYAN " %c " RESET,arr[j][i]) ;
            else if (arr[j][i]=='B' ) printf(YELLOW " %c " RESET,arr[j][i]);
            else if (arr[j][i]=='0'&& i%2 !=0&& j%2 !=0&&(i+j)%2==0) printf("   ") ;
            else if (arr[j][i]=='0'&&i%2 !=0) {if(counter<9){printf("%d ",++counter);}else {printf("%d",++counter);}}
            else if (arr[j][i]=='0'&& i%2 ==0) {if(counter<9){printf(" %d  ",++counter);}else {printf(" %d ",++counter);}};
        }
        printf("\n") ;
    }
    t2 = clock() - t1;
    int t = t2/CLOCKS_PER_SEC;
    printf(CYAN "\n\n%s score :%d " YELLOW "%s score :%d " GREEN "Remaining Stacks:%d " CYAN "TIME PASSED :%d minuts %d Seconds \n\n"RESET,name1,score1,name2,score2,remain,t/60,(t%60));
    printf(CYAN"Number of %s MOVES: %d "YELLOW"Number of %s MOVES: %d \n",name1,player1,name2,player2);
    printf(GREEN"Undo:U\tRedo:R\tSave:S\tMain menu : M\tExit:E\n\n"RESET);
}

