#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

//cout<<""<<endl;

using namespace std;

int TimePerOperation, Repeat;
int TimeStart;
int NumberOfOperations;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//handler do kolorow

void StatisticsAndEnd(){
    int option;

    cout<<"The calculation is complete"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_RED );//koloruje na zulto
    cout<<"RESULTS OF TESTS "<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    cout<<"Time execution tests: "<< TimePerOperation*Repeat<<"s"<<endl;
    cout<<"FLOPs: "<<NumberOfOperations<<endl;
    cout<<"MegaFlops MFLOPs: "<<NumberOfOperations/10000000<<endl;

    Sleep(3000);
    cout<<"Thank you for using our program"<<endl;
    Sleep(60000);
    exit(0);
}

void Calculating(){
    srand( time(NULL) );
    cout<<"The processes are ongoing"<<endl;
    cout<<"Be patient. This may take a while"<<endl;
    int wynik, operation, i = 0;
    while(i<=Repeat-1){
        operation = 0;BOOL WINAPI SetConsoleTitle( LPCTSTR lpConsoleTitle );
        TimeStart = clock();
        while(clock()-TimeStart<=TimePerOperation*1000){
            rand()+rand();
            operation++;
        }
        NumberOfOperations = NumberOfOperations + operation/2;
        i++;
        cout<<"Numbers of operations:"<<operation<<endl;
    }
    StatisticsAndEnd();
}

int main()
{
    string start;
    SetConsoleTitle("FLOPs measurement system");

    cout<<"Welcome in FLOPs measurement system!"<<endl;
    Sleep(900);
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_RED );//koloruje na zulto
    cout<<"INFORMATIONS"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    cout<<"For best results, please turn off all of apps"<<endl;
    cout<<"Please go to Task Manager -> Details -> find this process and click right button-> Set priority -> High"<<endl;
    cout<<"This program get you rounded down to integer result. Unit: FLOPs"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_RED );//koloruje na czerwono
    cout<<"!!!WARNINGS!!!Computer most likely will start working full power. It's OK!!!"<<endl;
    cout<<"!!!This is test program, result not must be correct!!!"<<endl<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    Sleep(900);

    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_RED );//koloruje na zulto
    cout<<"SETTINGS"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    cout<<"Enter time per one test(only integer in seconds)(Recommend time: 10s-15s): ";
    cin>>TimePerOperation;
    cout<<endl;
    cout<<"Enter how many times test execute(Recommended amount repeat: 5-10): ";
    cin>>Repeat;
    cout<<endl;
    Sleep(900);

    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_RED );//koloruje na zulto
    cout<<"INFORMATIONS BEFORE START"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    cout<<"Time execution tests: "<< TimePerOperation*Repeat<<"s"<<endl;//mnozy czas na jeden pomiar razy ilosc powturzen razy 4(operacje: dodawanie, odejmowanie, mnozenie, dzielenie)

    SetConsoleTextAttribute( hConsole, FOREGROUND_RED );//koloruje na czerwono
    cout<<"!!!WARNINGS!!!Computer most likely will start working full power!!!"<<endl;
    SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );//odwo³uje kolor
    cout<<"To start testing, please write 'STaRT': ";
    cin>>start;
    cout<<endl;
    if(start=="STaRT"){
        Calculating();
    }
    return 0;
}
