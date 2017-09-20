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
  char choice[100]; //rock,paper,scissors
  int result; //0=tie, 1=userWon, 2=compWon
  printf("\nWhat is your choice? ");
  scanf("%s",choice);

  result = getResult(choice);
  if(result == 0){
    printf("It's a tie!\n");
  }
  else if(result == 1){
    printf("You win this game!\n");
  }
  else if(result == 2){
    printf("You lose this game!\n");
  }


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
