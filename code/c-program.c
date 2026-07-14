#include<stdio.h>
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
        targetColumn++;
    }else if(direction == 'd' || direction == 'D'){
        targetColumn--;
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

    printf("\n---welcome to 15-puzzle---\n");
    printf("following are your control:\n");
    printf("W-move the blank tile up\n");
    printf("S-move the blank tile down\n");
    printf("A-move the blank tile right\n");
    printf("D-move the blank tile left\n");
    printf("Q-quit\n");

    while(1){
        printBoard();
        printf("\n enter your input\n");
        scanf("%d", &input);

        for(int i=0;i<SIZE;i++){
            for(int j=0; j<SIZE; j++){
                if(board[i][j]!=answer[i][j]){
                    return 0;
                }else{
                    printf("\n---YOU WON---\n ");
                }
            }
        }

        if(input=='q' || input=='Q'){
            printf("\nthanks for playing");
            break;
        }
        
        moveTile(input);
    }
    return 0;
}

    
