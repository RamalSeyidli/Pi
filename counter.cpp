/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/

/* @Author
Student Name: Ramal Seyidli
Student ID : 150180901
Date: 07/11/2020 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream> //Added this library for file operations
#include "counter.h"

using namespace std;


int Counter::findindex(Token *arr,char elem[]){
    //THIS FUNCTION WILL BE CODED BY YOU
    for(int k=0; k<token_count; k++)
    {
        if(token_array[k].token[0] == elem[0] && token_array[k].token[1] == elem[1])
        {
            return k;
        }
    }
    return -1;
}

bool Counter::contains(char *token, char target){
    //THIS FUNCTION WILL BE CODED BY YOU
    //This function checks if program includes "." as a token or not
    //target is "."

    for(int i=0; i<TOKEN_LENGTH; i++)
    {
        if(token[i] == target)
        {
            return true; //if true, then we don't include this token to the list
        }
    }

    return false;
}

void Counter::read_and_count(){
    //THIS FUNCTION WILL BE CODED BY YOU
    ifstream file("pi_approximate");

    char fileChars[200];
    int i=0;

    while(!file.eof())
    {
        file >> fileChars[i];
        i++; //this loop takes all number to the array
    }

    for(int j=0; j<i-1; j++)
    {
        char currentToken[2] = {fileChars[j], fileChars[j+1]};

        if(!contains(currentToken, '.' ))
        {
            bool found = false;
            for(int k=0; k<token_count; k++)
            {
                if(token_array[k].token[0] == currentToken[0] && token_array[k].token[1] == currentToken[1])
                {
                    token_array[k].count += 1;
                    found = true;
                }
            }

            if(!found)
            {
                token_array[token_count].token[0] = currentToken[0];
                token_array[token_count].token[1] = currentToken[1];
                token_array[token_count].count = 1;
                token_count++;
            }
        }
    }

//    for(int l=0; l<ARRAY_SIZE; l++)
//    {
//        cout << token_array[l].token[0] << token_array[l].token[1] << " " << token_array[l].count<< endl;
//    }
}


Token *Counter::get_most_common_three(){
    //THIS FUNCTION WILL BE CODED BY YOU
    int skipIndex[2] = {-1, -1};

    int currentMostIndex = -1;
    int currentMostCount = 0;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<token_count; j++)
        {
            if(token_array[j].count > currentMostCount)
            {
                if(j == skipIndex[0] || j == skipIndex[1])
                {
                    continue;
                }
                else
                {
                    currentMostCount = token_array[j].count;
                    currentMostIndex = j;
                }
            }
        }

        mostCommonThree[i].token[0] = token_array[currentMostIndex].token[0];
        mostCommonThree[i].token[1] = token_array[currentMostIndex].token[1];
        mostCommonThree[i].count = token_array[currentMostIndex].count;

        if(i != 2)
        {
            skipIndex[i] = currentMostIndex;
        }

        currentMostCount = 0;
        currentMostIndex = -1;
    }

    return mostCommonThree;
}
