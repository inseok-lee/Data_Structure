#include <fstream>
#include <iostream>

const int MAX_CHARS = 100;

enum RelationType {LESS, EQUAL, GREATER};
enum InType {ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW};
class StrType
{
public:

    void MakeEmpty();
    void GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile);
    void PrintToScreen(bool newLine);
    void PrintToFile(bool newLine, std::ofstream& outFile);
    void CopyString(StrType&  newString);
    int LengthIs();

    // 5.Exercise 29 ComparedTo함수 추가
    RelationType ComparedTo(StrType& otherString);

private:
    char letters[MAX_CHARS + 1];
};

