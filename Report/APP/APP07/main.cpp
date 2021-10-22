#include <iostream>
#include <string>

using namespace std;


string recursive(string input){
    int frontidx = input.find('(');
    int rearidx = input.rfind(')');

    if(frontidx == string::npos){
        return input;
    }
    else{
        string str = recursive(input.substr(frontidx + 1, rearidx - frontidx - 1));
        string result = input.substr(0, frontidx - 1);
        int n = input.at(frontidx - 1) - '0';

        for(int i = 0; i < n; i++){
            result += str;
        }
        return result;
    }
}

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str; // str의 길이는 50이하

    string result = recursive(str);

    cout << "Final string: ";
    cout << result << endl;
    cout << "Length of final string: ";
    cout << result.length() << endl;

    return 0;
}
