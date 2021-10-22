#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "파라메터 개수 = " << argc << endl;
    
    for(int i = 0; i < argc; i++){
        cout << i << "-th argument = " << *(argv + i) << endl;
    }
    
    // 입력파일이름과 출력파일이름은 argument를 이용하여 받을것.
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    char ch;
    
    while(!fin.eof()) //파일의 끝이 아닐때까지 루프를 반복함
    {
        // 공백문자 여부 상관없이 한 문자만큼 읽음
        fin.get(ch);
        cout << ch << endl;
        
        if(!fin){ //입력 파일 스트림에 에러비트가 존재한다면 루프를 빠져나감
            break;
        }
        
        if(ch == '\r') // ch가 LF('\r')이라면
            fout.put('\n');
        else
            fout.put(ch);
    }

    
//    if(!fin){
//        cout << "File open error" << endl;
//        exit(100);
//    }
//
//    while(true){
//        fin.get(ch);
//        cout << ch << endl;
//        if(fin.eof()){
//            break;
//        }
//        else if(ch == '\r')
//            fout.put('\n');
//        else
//            fout.put(ch);
//
//    }
    
    fin.close();
    fout.close();
    
    return 0;
}

