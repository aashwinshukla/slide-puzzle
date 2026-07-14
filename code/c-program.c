#include<stdio.h>
#include<stdbool.h>

#define SIZE 4

int board[SIZE][SIZE]={
    {1, 4, 15, 7},
    {8, 10, 2, 11},
    {14, 3, 6, 13},
    {12, 9, 5, 0}
};

int answer[SIZE][SIZE]={
    {1, 2, 3, 4},
    {5, 6, 7, 8}, 
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

int blankRow=3;
int blankColumn=3;
int moves=0;

void printBoard(){
    printf("\n--- MOVES=%d ---\n", moves);
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(board[i][j]==0){
                printf("    ");
            }else{
                printf("%3d", board[i][j]);
            }
        }
        printf("\n");
    }
}

void moveTile(char direction){
    int targetRow=blankRow;
    int targetColumn=blankColumn;

    if(direction == 'w' || direction == 'W'){
        targetRow--;
    }else if(direction == 's' || direction == 'S'){
        targetRow++;
    }else if(direction == 'a' || direction == 'A'){
        targetColumn--;
    }else if(direction == 'd' || direction == 'D'){
        targetColumn++;
    }else return; 


    if(targetRow >= 0 && targetRow < SIZE && targetColumn >= 0 && targetColumn < SIZE){
        int temp;
        temp = board[blankRow][blankColumn];
        board[blankRow][blankColumn]=board[targetRow][targetColumn];
        board[targetRow][targetColumn]=temp;
        blankRow=targetRow;
        blankColumn=targetColumn;
        moves++;
    } 
}

int main(){
    char input;
    bool flag=true;

    printf("\n---welcome to 15-puzzle---\n");
    printf("following are your control:\n");
    printf("W-move the blank tile up\n");
    printf("S-move the blank tile down\n");
    printf("A-move the blank tile right\n");
    printf("D-move the blank tile left\n");
    printf("Q-quit\n");

    while(flag){
        printBoard();
        printf("\n enter your input\n");
        scanf(" %c", &input);

        for(int i=0;i<SIZE;i++){
            for(int j=0; j<SIZE; j++){
                if(board[i][j]!=answer[i][j]){
                    flag=true;
                    break;
                }
            }
        }

        if(board[0][0]==answer[0][0] &&
            board[0][1]==answer[0][1] &&
            board[0][2]==answer[0][2] &&
            board[0][3]==answer[0][3] &&
            board[1][0]==answer[1][0] &&
            board[1][1]==answer[1][1] &&
            board[1][2]==answer[1][2] &&
            board[1][3]==answer[1][3] &&
            board[2][0]==answer[2][0] &&
            board[2][1]==answer[2][1] &&
            board[2][2]==answer[2][2] &&
            board[2][3]==answer[2][3] &&
            board[3][0]==answer[3][0] &&
            board[3][1]==answer[3][1] &&
            board[3][2]==answer[3][2] &&
            board[3][3]==answer[3][3] )
        {   
            printf("\n---YOU WON---\n");
            flag=false;
            break;
        }


        if(input=='q' || input=='Q'){
            printf("\nthanks for playing");
            break;
        }
        
        moveTile(input);
    }
    return 0;
}

    
