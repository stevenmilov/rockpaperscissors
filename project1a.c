#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void play(int*,int*);
int getResult(char*);

int main(){
  char toPlay[10];
  int player = 0;
  int computer = 0;
  int* playerLoc = &player;
  int* computerLoc = &computer;
  printf("Welcome to Rock, Paper, Scissors\n");
  do{
    printf("\nWould you like to play? (yes/no) ");
    scanf("%s",toPlay);
  }while(strcmp(toPlay,"yes") != 0 && strcmp(toPlay,"no") != 0);

  if(strcmp(toPlay,"yes") == 0){
    play(playerLoc,computerLoc);
  }
  else if(strcmp(toPlay,"no") == 0){
    printf("Fine then. Go play with someone else.\n");
  }
  else
    printf("This isn't possible.");


  return 0;
}

void play(int* playerLoc, int* computerLoc){

  char playAgain[10];
  char choice[100]; //rock,paper,scissors
  int result; //0=tie, 1=userWon, 2=compWon

  do{
    printf("\nWhat is your choice? ");
    scanf("%s",choice);
  }while(strcmp(choice,"rock") != 0 && strcmp(choice,"paper") != 0 && strcmp(choice,"scissors") != 0);

  result = getResult(choice);
  if(result == 0){
    printf("It's a tie!\n");
  }
  else if(result == 1){
    printf("You win this game!\n");
    *playerLoc = *playerLoc +1;
  }
  else if(result == 2){
    printf("You lose this game!\n");
    *computerLoc = *computerLoc+1;
  }

  printf("\nThe score is now you: %d computer: %d\n",*playerLoc,*computerLoc);


  if(*playerLoc == 3){
    printf("You win this match!");
    *playerLoc = 0;
    *computerLoc = 0;
    do{
      printf("\nWould you like to play again? (yes/no) ");
      scanf("%s",playAgain);
    }while(strcmp(playAgain,"yes") != 0 && strcmp(playAgain,"no") != 0);
  }
  else if(*computerLoc == 3){
    printf("\nThe computer wins this match!\n");
    *computerLoc = 0;
    *playerLoc = 0;
    do{
      printf("\nWould you like to play again? (yes/no) ");
      scanf("%s",playAgain);
    }while(strcmp(playAgain,"yes") != 0 && strcmp(playAgain,"no") != 0);
  }
  else{
    play(playerLoc,computerLoc);
  }
  if(strcmp(playAgain,"yes") == 0)
    play(playerLoc,computerLoc);
}

int getResult(char* c){
  int whoWon;
  int randInt;
  char* compChoice;
  srand((unsigned int)time(NULL));
  randInt = rand() % 3;

  if(randInt == 0){
    compChoice = "rock";
  }
  else if(randInt == 1){
    compChoice = "paper";
  }
  else if(randInt == 2){
    compChoice = "scissors";
  }
  printf("The computer chooses %s. ",compChoice);


  if(strcmp(c,"rock") == 0){

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

  return whoWon; //0 = tie, 1 = player, 2 = computer
}
