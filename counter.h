/*
PLEASE DO NOT REMOVE ANY FUNCTION OR VARIABLE IN THE STRUCT, IF YOU NEED YOU CAN ADD NEW ONES
*/

/* @Author
Student Name: Ramal Seyidli
Student ID : 150180901
Date: 07/11/2020 */

#ifndef _H
#define _H
#include <stdio.h>
#include <fstream>

#define ARRAY_SIZE 100

#include "token.h"

struct Counter{
    int token_count=0;
    Token token_array[ARRAY_SIZE];
    Token mostCommonThree[3]; // New added
    void read_and_count();
    bool contains(char *,char);
    int findindex(Token [],char[]);
    Token *get_most_common_three();
};
#endif
