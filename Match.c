/*
@(#)File:           Match.h
@(#)Author:         Andrea Cirioni
*/

#include <stdlib.h>
#include "Utility.h"
#include "Player.h"


#define LENGHTPLAYERNAME 20
#define WIDTHCODE 4

static const int _defaultAttempts = 9;
static const int _minSecretCode = 1000;
static const int _maxSecretCode = 9999;

struct Match
{
    short Attempts;
    int SecretCode[WIDTHCODE];  
    int NumbersAtTheRightPlace; 
    int NumbersAtTheWrongPlace;
    struct Player player;
    short UsedAttempts;

};


void Match__init(struct Match* newMatch) 
{
    newMatch->NumbersAtTheRightPlace = 0;
    newMatch->NumbersAtTheWrongPlace = 0;

    
    newMatch->Attempts = _defaultAttempts;

    
    newMatch->UsedAttempts = 0;

    
    int _secretCodeTmp = GetRandomNumberInRange(_minSecretCode,_maxSecretCode);

    
    int _arrSecretCodeTmp[WIDTHCODE];
    int size = SplitIntToArrayInt(_arrSecretCodeTmp, _secretCodeTmp);

    
    int i;
    for(i = 0; i < WIDTHCODE; i++){
        newMatch->SecretCode[i] = _arrSecretCodeTmp[i];
    }
    
    //TODO Debug
    printf("Secret number: %d", _secretCodeTmp);
    printf("\n\n");
    printf("\n\n");
 }



struct Match* Match__create() 
{
   struct Match* result = (struct Match*) malloc(sizeof(struct Match));
   Match__init(result);
   return result;
}


void Match__destroy(struct Match* match) 
{
  free(match);
}

void Match__setPlayerName(struct Match* newMatch, char playerName[LENGHTPLAYERNAME] ) 
{
  int i;
  for(i = 0; i < LENGHTPLAYERNAME; i++){
        newMatch->player.name[i] = playerName[i];
  }
}



void Match__increaseUsedAttempts(struct Match* newMatch)
{
    newMatch->UsedAttempts = (newMatch->UsedAttempts + 1);
}


void Match__decreaseAttempts(struct Match* newMatch)
{
    newMatch->Attempts = (newMatch->Attempts - 1);
}



int Match__usedAttempts(struct Match* newMatch) 
{
   return newMatch->UsedAttempts;
}


int Match__attempts(struct Match* newMatch)
{
    return newMatch->Attempts;
}

char* Match__playerName(struct Match* newMatch)
{
    return (char*) &(newMatch->player.name);
}


int Match__numbersAtTheRightPlace(struct Match* newMatch)
{
    return newMatch->NumbersAtTheRightPlace;
}


int Match__numbersAtTheWrongPlace(struct Match* newMatch)
{
    return newMatch->NumbersAtTheWrongPlace;
}


int Match__findMatches(struct Match* newMatch, int arrayToCompare[])
{
    
    int arraySource[WIDTHCODE];
    int z;
    for(z = 0; z < WIDTHCODE; z++){
       arraySource[z] = newMatch->SecretCode[z];
    }
    

    int countCorrect = 0;
    int countCorrectInDifferentPosition = 0;
    int j,i;

    
    for(j=0;j<WIDTHCODE;j++){
        if (arraySource[j] == arrayToCompare[j]){
                countCorrect++;
        }
    }

    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
            if(arraySource[j]==arrayToCompare[i])
            {
                countCorrectInDifferentPosition++;
                arrayToCompare[i]=0; 
                break;
            }
        }
    }

    
    countCorrectInDifferentPosition-=countCorrect;
    
    newMatch->NumbersAtTheRightPlace = countCorrect;
    newMatch->NumbersAtTheWrongPlace = countCorrectInDifferentPosition;
    
    if(newMatch->NumbersAtTheRightPlace == WIDTHCODE)
        return 1;
    else
        return 0;
}


