#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void play(int*,int*);
int getResult(char*);

int main(){
  char toPlay;
  int player = 0;
  int computer = 0;
  int* playerLoc = &player;
  int* computerLoc = &computer;
  printf("Welcome to Rock, Paper, Scissors\n");
  printf("\nWould you like to play? (y/n)");
  scanf("%c",&toPlay);


  if(toPlay == 'y'){
    play(playerLoc,computerLoc);
  }
  else if(toPlay == 'n'){
    printf("Fine then. Go play with someone else.\n");
  }

  return 0;
}

void play(int* playerLoc, int* computerLoc){
  char* choice; //rock,paper,scissors
  int result; //0=tie, 1=userWon, 2=compWon
  printf("What is your choice? ");
  scanf(" %s\n",choice);
  printf("Your choice is %s\n",choice); //for debugging
  result = getResult(choice);
  if(result == 0){
    printf("It's a tie!\n");
  }
  else if(result == 1){
    printf("You won this game!\n");
  }
  else if(result == 2){
    printf("You lost this game!\n");
  }


}

int getResult(char* c){
  int whoWon;
  int randInt;
  char* compChoice;
  srand((unsigned int)time(NULL));
  randInt = rand() % 3;
  printf("Random int is: %d",randInt);
  if(randInt == 0){
    compChoice = "rock";
    //printf("The computer chooses rock. "); // delete this if successfull
  }
  else if(randInt == 1){
    compChoice = "paper";
    //printf("The computer chooses paper. ");
  }
  else if(randInt == 2){
    compChoice = "scissor";
    //printf("The computer chooses scissors. ");
  }
  printf("The computer chooses %s.",compChoice);


  if(strcmp(c,"rock") == 0){
    printf("\nplayer chose rock\n");

    if(strcmp(compChoice,"rock") == 0)
      whoWon = 0;
    if(strcmp(compChoice,"scissors") == 0)
      whoWon = 1;
    if(strcmp(compChoice,"paper") == 0)
      whoWon = 2;

  }
  else if(strcmp(c,"paper") == 0){
    if(strcmp(compChoice,"paper") == 0)
      whoWon = 0;
    if(strcmp(compChoice,"rock") == 0)
      whoWon = 1;
    if(strcmp(compChoice,"scissors") == 0)
      whoWon = 2;
  }
  else if(strcmp(c,"scissors") == 0){
    if(strcmp(compChoice,"scissors") == 0)
      whoWon = 0;
    if(strcmp(compChoice,"paper") == 0)
      whoWon = 1;
    if(strcmp(compChoice,"rock") == 0)
      whoWon = 2;
  }
  printf("%d",whoWon);
  return whoWon; //0 = tie, 1 = player, 2 = computer
}
