struct Match;
struct Match* Match__create();
void Match__init(struct Match* newMatch);
void Match__destroy(struct Match* newMatch);
void Match__setPlayerName(struct Match* newMatch, char playerName[20]);
void Match__increaseUsedAttempts(struct Match* newMatch);
void Match__decreaseAttempts(struct Match* newMatch); 
int  Match__findMatches(struct Match* newMatch, int arrayToCompare);
int  Match__numbersAtTheWrongPlace(struct Match* newMatch);
int  Match__numbersAtTheRightPlace(struct Match* newMatch);
int  Match__usedAttempts(struct Match* newMatch);
int  Match__attempts(struct Match* newMatch);
char* Match__playerName(struct Match* newMatch);




