#include <stdio.h>
#include <stdlib.h>
#include <curses.h> 

/****************************************
 VARIABLE AND FUNCTION DECLARATION
 **************************************/


char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int  player;


void displayBorad();
int checkForWin();
void markBoard(char mark , int choice);
int flag = 0;

/********************************************
 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYER MARK
 *******************************************/

void displayBorad(){
    system("clear");
    printf("\t Tic Tac Toe\t\n\n");
    printf("Player 1 (X)\tPlayer 2 (O)\n");
    printf(" _____ ______ _____\n");
    printf("|     |      |     |\n");
    printf("|  %c  |   %c  |  %c  |\n",square[1],square[2],square[3]);
    printf("|-----|------|-----|\n");
    printf("|  %c  |   %c  |  %c  |\n",square[4],square[5],square[6]);
    printf("|-----|------|-----|\n");
    printf("|  %c  |   %c  |  %c  |\n",square[7],square[8],square[9]);
    printf("|_____|______|_____|\n\n");

    if(flag==1)
        printf("Invalid Move type again : \n");
}
/*********************************************
 SET THE BOARD WITH THE CORRECT CHARACTER,
 X AND O IN THE CORRECT SPOT IN THE ARRAY
 ********************************************/

void markBoard(char mark , int choice){
    if(choice == 1 && square[1] == '1')
        square[1] = mark;
    else if(choice == 2 && square[2]=='2')
        square[2]= mark;
    else if(choice == 3 && square[3]=='3')
        square[3]= mark;
    else if(choice == 4 && square[4]=='4')
        square[4]= mark;
    else if(choice == 5 && square[5]=='5')
        square[5]= mark;
    else if(choice == 6 && square[6]=='6')
        square[6]= mark;
    else if(choice == 7 && square[7]=='7')
        square[7]= mark;
    else if(choice == 8 && square[8]=='8')
        square[8]= mark;  
    else if(choice == 9 && square[9]=='9')
        square[9]= mark;
    else 
    {    
        flag=1;
        player --;
    }
    
}
/****************************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
0 GAME IS OVER AND NO RESULT
***************************************************/


int checkForWin(){
    if(square[1]==square[2] && square[2]==square[3])
        return(1);
    else if(square[1]==square[4] && square[4]==square[7])
        return(1);
    else if(square[7]==square[8] && square[8]==square[9])
        return(1);
    else if(square[3]==square[6] && square[6]==square[9])
       return(1);
    else if(square[1]==square[5] && square[5]==square[9])
        return(1);
    else if(square[3]==square[5] && square[5]==square[7])
        return(1);
    else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4'&& square[5]!='5'&&square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9')
       return(0);
    else 
        return(-1); 

}



int main(){ 
    
    char mark;
    player = 1;
    int choice;
    do{
        displayBorad();
        player = ((player%2) ? 1:2);
        printf("Player %d ,enter a number : ",player);
        scanf("%d",&choice);
        mark = ((player == 1) ? 'X':'O');
        if (mark == 'X' || mark == 'O')
        {
            markBoard(mark,choice);
            player++;
            flag==0;
        }
        else{
            printf("inavlid Entry\n");
        }
        
        
    }while(checkForWin() == -1);
    if(checkForWin()==1){
        printf("player : %d won\n",(player%2 + 1));
    }
    else{
        printf("Opps Game is Tie\n");
    }
    


    return 0;
}



