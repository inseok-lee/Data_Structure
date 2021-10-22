#include <cctype>
#include <fstream>
#include <iostream>
#include <cstring>

#include "StrType.h"
#include "cstring.h"
#include <cctype> 
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);


// 5.Exercise 29 A) ComparedTo함수 추가
//RelationType StrType::ComparedTo(StrType& otherString){
//    int val = int strcmp(this->letters, otherString.letters);
//    if(val == -1)
//        return LESS;
//    else if(val == 0)
//        return EQUAL;
//    else
//        return GREATER;
//}

// 5.Exercise 29 B) ComparedTo함수 추가
RelationType StrType::ComparedTo(StrType& otherString){


}


void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
  switch (charsAllowed)
  {
    case ALPHA_NUM : GetAlphaNum(skip, letters, inFile); 
                     break;
//    case ALPHA     : GetAlpha(skip, letters, inFile);
//                     break;
//    case NON_WHITE : GetNonWhite(skip, letters, inFile);
 //                    break;
    case NOT_NEW   : GetTilNew(skip, letters, inFile);
                     break;
  }
}


void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {// skip non-alphanumeric characters
    inFile.get(letter);
    while (!isalnum(letter) && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || !isalnum(letter))
  // No legal character found; empty string returned.
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while (isalnum(letter) && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && isalnum(letter))
      do
      {
        inFile.get(letter);
      } while (isalnum(letter) && inFile);
  }
      
}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
{
  using namespace std;
  char letter;
  int count = 0;
  if (skip)
  {// skip newlines.
      inFile.get(letter);
      while ((letter == '\n') &&inFile)
        inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || letter == '\n')
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while ((letter != '\n') && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && letter != '\n')

    do
    {
      inFile.get(letter);
    } while ((letter != '\n') && inFile);
  }
}

void StrType::PrintToScreen(bool newLine)
// Post:  letters has been sent to the output stream.
{
  if (newLine)
  cout  << endl;
  cout  << letters;
}


void StrType::MakeEmpty()
{
  letters[0] = '\0';
}  


void StrType::PrintToFile(bool newLine, ofstream& outFile)
{
  if (newLine)
    outFile << endl;
    outFile << letters;
}


void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{ 
  strcpy(newString.letters, letters);
}


int StrType::LengthIs()
{
  return strlen(letters);
}

