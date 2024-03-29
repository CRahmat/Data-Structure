#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <mmsystem.h>
using namespace std;
struct History{
    char accountNumber[13];
    char typeOfTransaction[10];
    int debet;
    int saldo;
    char *date;
};
//ADMIN STRUCT
struct AdminAccount{
    int accountID = 0;
    char PIN[7];
    char name[50];
    char address[100];
    char birthDay[20];
    char noKTP[16];
    char noTelp[13];
};
//ADMIN LINK LIST
typedef struct linkListAdmin *adminPointer;
struct linkListAdmin{
    AdminAccount adminAccounts;
    adminPointer next;
    adminPointer prev;
};
adminPointer firstAdmin, lastAdmin;

struct ClientAccount{
    History AllHistoryTransaction;
    char name[50];
    char address[100];
    char birthDay[20];
    char noKTP[16];
    char noTelp[13];
    char accountNumber[16];
    char PIN[10];
};
typedef struct linkListClient *clientPointer;
struct linkListClient{
    ClientAccount clientAccounts;
    clientPointer next;
    clientPointer prev;
};
clientPointer firstClient, lastClient;
typedef int QueueInfo;
struct QueueData{
    QueueInfo no = 0;
    char accountNumber[16];
    char PIN[7];
};
typedef struct queue *QueuePointer;
struct queue{
    QueueData queueSave;
    QueuePointer next;
};
QueuePointer firstQueue, lastQueue ;
//ADMIN METHOD
void createAdminAccount();
void deleteAdminAccount();
void updateAdminAccount();
void listAdminAccount();
//LINK LIST ADMIN
bool isEmptyAdminList();
void createAdminList();
void inputAdminList(AdminAccount adminAccount);
bool checkingAdminAccount(int accountID, char PIN[7]);
void updateAdminList(AdminAccount tempAdminAccount);
void deleteAdminList(int accountID, char PIN[7]);
void showListAdminAccount();
//CLIENT METHOD
void createClientAccount();
void deleteClientAccount();
void updateClientAccount();
void listClientAccount();
bool checkingClientAccount();
bool isEmptyClientList();
//CLIENT METHOD MENU
void cekSaldo();
void transfer();
void withDraw();
void changePIN();
void allTransactionHistory();
//LINK LIST CLIENT
bool isEmptyClientList();
void createClientList();
void inputClientList(ClientAccount clientAccount);
bool checkingClientAccount(char accountNumber[16],char PIN[7]);
void updateClientList(AdminAccount tempAdminAccount);
void showListClientAccount();
//OTHER
int QueueNumber = 0;
bool checking = true;
void GetPosition(int x, int y);
void GetLoading(int x, int y);
void GetDateSystem();
//MAIN MENU
void mainMenu();
//SUB MENU
void adminMenu();
void clientMenu();
void infoMenu();
void managerMenu();
//ADMIN ASSIGNMENT
void deposito();
void transactionHistory();
//QUEUE
void addEnqueue();
void createQueue();
int isEmptyQueue();
void enqueue();
void dequeue();
//STACK
int isEmptyStack();
void createStack();
void inputStack();
void listStack();
void deleteStack();
int main(){
    createAdminList();
    createClientList();
    system("COLOR 09");
    GetLoading(75, 21);
    mainMenu();
}
void mainMenu(){
    bool running;
    int x;
    int mainMenu;
    int intAdminMenu;
    enum mainMenu {ADMIN = 1, CLIENT, INFO }; //Pointer

    do
    {
        x = 17; //Koordinat Posisi Awal Tanda Panah
        running = true; //Default running = true
        mainMenu = ADMIN; //mainMenu = 1(ADMIN)
        intAdminMenu = 0;
        GetPosition(54,x);
        cout<<"-->";
        while(running)
        {
            GetPosition(57,13);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,14);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            GetPosition(57,15);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            GetPosition(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,17);
            cout<<"| ADMIN"<<setfill(' ')<<setw(52) <<"|";
            GetPosition(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,19);
            cout<<"| CLIENT/CUSTOMER"<<setfill(' ')<<setw(42) <<"|";
            GetPosition(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,21);
            cout<<"| INFO"<<setfill(' ')<<setw(53) <<"|";
            GetPosition(57,22);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,25);
            cout<<" KEY FUNCTION INFO:";
            GetPosition(57,26);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,27);
            cout<<"|" << setfill(' ') << setw(32)<<"ESC = EXIT" <<setfill(' ') <<setw(26) <<"|";
            GetPosition(57,28);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            GetPosition(57,29);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            GetPosition(75,32);
            cout<<"+"<<setw(21)<<setfill('=')<<"+";
            GetPosition(75,33);
            cout<<"|"<<setw(17)<<setfill(' ') <<"  NEXT  |  JUMLAH "<<setw(3)<<"|";
            GetPosition(75,34);
            cout<<"+"<<setw(21)<<setfill('=')<<"+";
            GetPosition(80,35);
            cout << ++QueueNumber;
            GetPosition(90,35);
            cout << ++QueueNumber;
            GetPosition(84,29);
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x+=2; //Memindahkan Posisi Panah
                if(x > 22)
                {
                    x = 17;
                    GetPosition(54,x);//Jika panah pada menu terakhir akan kembali ke menu pertama
                    cout<<"-->";
                    mainMenu = ADMIN; //Main Menu = 1 (enum ADMIN)
                }
                else
                {
                    GetPosition(54,x);//Jika panah masih berada di menu
                    cout<<"-->";
                    mainMenu++;//Menyesesuaikan Menu
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x-=2; //Memindahkan Posisi Panah
                if(x < 16)
                {
                    x = 21;
                    GetPosition(54,x);//Jika panah pada menu pertama akan kembali ke menu terakhir
                    cout<<"-->";
                    mainMenu=INFO; //Main Menu = 3 (enum INFO)
                }
                else
                {
                    GetPosition(54,x);
                    cout<<"-->";
                    mainMenu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE) )  //Action saat buttom ESC di tekan
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                system("CLS");
                exit(0);
            }
            else if(GetAsyncKeyState(VK_SPACE))
            {
                intAdminMenu++;
                GetPosition(54,x);
                cout<<"-->";
                if(intAdminMenu == 3)
                {
                    system("CLS");
                    managerMenu();
                    running = false;
                }
            }
            else if(GetAsyncKeyState(VK_INSERT))
            {
                PlaySound(TEXT("QueueSound.wav"), NULL, SND_SYNC);
                system("CLS");
                addEnqueue();
            }
            else if(GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_RIGHT))
            {
                system("CLS");
                switch(mainMenu)
                {
                case ADMIN :
                {
                    running = false;// Memberhentikan Perulangan While
                    adminMenu();
                    break;
                };
                case CLIENT :
                {
                    running = false;// Memberhentikan Perulangan While
                    clientMenu();
                    break;
                };
                case INFO :
                {
                    running = false; // Memberhentikan Perulangan While
                    infoMenu();
                    break;
                };
                } //SWITCH
            } //If VK_RETURN
            else //Action saat ditekan selain tombol di atas
            {
                GetPosition(54,x); //Jika Di tekan Selain Tombol Atas  Posisi Panah Tetap
                cout<<"-->";
            }
        } //WHILE
    }
    while(mainMenu == ADMIN || CLIENT || INFO);
}
void GetPosition(int x, int y){
    COORD CursorPosition = {x,y}; //Mengatur posisi
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}
void GetLoading(int x, int y){
    for(int i = 0; i < 101 ; i++)
    {
        system("COLOR 09");
        if(i < 30)
        {
            i+=4;
            GetPosition(x,y);
            cout<<"Loading...........";
            GetPosition((x+18),y);
            cout<<i<<"%";
            Sleep(5);
        }
        else if(i < 60 && i > 30)
        {
            i+=3;
            GetPosition((x),y);
            cout<<"Loading Data...........";
            GetPosition((x+22),y);
            cout<<i<<"%";
            Sleep(20);
        }
        else if(i < 97 && i > 60)
        {
            i+=2;
            GetPosition((x),y);
            cout<<"Checking Data...........";
            GetPosition((x+22),y);
            cout<<i<<"%";
            Sleep(40);
        }
        else if(i >97 && i < 101)
        {
            GetPosition((x),y);
            cout<<"Verifikasi Data...........";
            GetPosition((x+22),y);
            cout<<i<<"%";
            Sleep(1000);
        }
    }
}
void GetDateSystem(){
}
void adminMenu(){
    int menu, x;
    bool running;
    string tempIDAdmin;
    string tempPassword;
    enum menu {CREATE = 1, UPDATE, DELETES, LIST, DEPOSITO, HISTORY};
    GetPosition(57,8);
    cout << "+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(57,9);
    cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
    GetPosition(57,10);
    cout << "|" << setfill(' ') << setw(33) << "ADMIN MENU" <<setfill(' ')<<setw(25) << "|";
    GetPosition(57,11);
    cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
    GetPosition(57,12);
    cout << "+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(70,14);
    cout << "  ID ADMIN  : ";
    getline(cin, tempIDAdmin);
    GetPosition(70,16);
    cout << "  PASSWORD  : ";
    getline(cin, tempPassword);
    system("CLS");
    cin.clear();
    do
    {
        x = 13;
        running = true;
        menu = CREATE;
        GetPosition(54,13);
        cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
        while(running)
        {
            GetPosition(57,8);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            GetPosition(57,10);
            cout << "|" << setfill(' ') << setw(32) << "ADMIN MENU" <<setfill(' ')<<setw(26) << "|";
            GetPosition(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            GetPosition(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,13);
            cout<<"| CREATE CLIENT ACCOUNT"<<setfill(' ')<<setw(36) <<"|";
            GetPosition(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,15);
            cout<<"| UPDATE CLIENT ACCOUNT"<<setfill(' ')<<setw(36) <<"|";
            GetPosition(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,17);
            cout<<"| DELETE CLIENT ACCOUNT"<<setfill(' ')<<setw(36) <<"|";
            GetPosition(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,19);
            cout<<"| LIST CLIENT ACCOUNT"<<setfill(' ')<<setw(38) <<"|";
            GetPosition(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,21);
            cout<<"| ADD CLIENT DEPOSITO"<<setfill(' ')<<setw(38) <<"|";
            GetPosition(57,22);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,23);
            cout<<"| CLIENT HISTORY TRANSACTION"<<setfill(' ')<<setw(31) <<"|";
            GetPosition(57,24);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,26);
            cout<<" KEY FUNCTION INFO:";
            GetPosition(57,27);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,28);
            cout<<"|" << setfill(' ') << setw(32)<<"ESC = EXIT" <<setfill(' ') <<setw(26) <<"|";
            GetPosition(57,29);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            GetPosition(57,30);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x+=2;
                if(x > 24)
                {
                    x = 13;
                    GetPosition(54,13);//Jika x lebih besar dari MAX tanda panah berpindah ke MIN
                    cout<<"-->";
                    menu = CREATE;
                }
                else
                {
                    GetPosition(54,x);//Jika kurang dari maka akan berpindah ke bawah
                    cout<<"-->";
                    menu++;
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x-=2;
                if(x < 12)
                {
                    x = 23;
                    GetPosition(54,23);//Jika x kurang dari dari MIN tandah panah berpindah ke MAX
                    cout<<"-->";
                    menu = DELETES;
                }
                else
                {
                    GetPosition(54,x);
                    cout<<"-->";
                    menu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                system("CLS");
                mainMenu();

            }
            else if(GetAsyncKeyState(VK_RETURN)||GetAsyncKeyState(VK_RIGHT))
            {
                switch(menu)
                {
                    system("CLS");
                case CREATE :
                {
                    system("CLS");
                    running = false;
                    createClientAccount();
                    break;
                };
                case LIST :
                {
                    system("CLS");
                    running = false;
                    listClientAccount();
                    break;
                };
                case UPDATE :
                {
                    system("CLS");
                    running = false;
                    updateClientAccount();
                    break;
                };
                case DELETES :
                {
                    system("CLS");
                    running = false;
                    deleteClientAccount();
                    break;
                };
                }
            }else{
                GetPosition(54,x);
                cout<<"-->";
            }
        }
    }
    while(menu > 0 && menu < 7);

}
void clientMenu(){
    int menu, x;
    bool running;
    string tempIDAdmin;
    string tempPassword;
    enum menu {SALDO = 1, TRANSFER, WITHDRAW,CHANGE_PIN,HISTORY};
    GetPosition(57,8);
    cout << "+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(57,9);
    cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
    GetPosition(57,10);
    cout << "|" << setfill(' ') << setw(33) << "CLIENT MENU" <<setfill(' ')<<setw(25) << "|";
    GetPosition(57,11);
    cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
    GetPosition(57,12);
    cout << "+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(70,14);
    cout << "  USERNAME  : ";
    getline(cin, tempIDAdmin);
    GetPosition(70,16);
    cout << "  PASSWORD  : ";
    getline(cin, tempPassword);
    system("CLS");
    do
    {
        GetPosition(54,13);
        cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
        running = true;
        x = 13;
        menu = SALDO;
        while(running)
        {
            GetPosition(57,8);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            GetPosition(57,10);
            cout << "|" << setfill(' ') << setw(32) << "CLIENT MENU" <<setfill(' ')<<setw(26) << "|";
            GetPosition(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            GetPosition(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,13);
            cout<<"| CEK SALDO"<<setfill(' ')<<setw(48) <<"|";
            GetPosition(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,15);
            cout<<"| TRANSFER"<<setfill(' ')<<setw(49) <<"|";
            GetPosition(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,17);
            cout<<"| WITHDRAW"<<setfill(' ')<<setw(49) <<"|";
            GetPosition(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,19);
            cout<<"| CHANGE PIN"<<setfill(' ')<<setw(47) <<"|";
            GetPosition(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,21);
            cout<<"| HISTORY TRANSACTION"<<setfill(' ')<<setw(38) <<"|";
            GetPosition(57,22);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,26);
            cout<<" KEY FUNCTION INFO:";
            GetPosition(57,27);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,28);
            cout<<"|" << setfill(' ') << setw(32)<<"ESC = EXIT" <<setfill(' ') <<setw(26) <<"|";
            GetPosition(57,29);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            GetPosition(57,30);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x+=2;
                if(x > 22)
                {
                    x = 13;
                    GetPosition(54,13);//Jika x lebih besar dari MAX tanda panah berpindah ke MIN
                    cout<<"-->";
                    menu = SALDO;
                }
                else
                {
                    GetPosition(54,x);//Jika kurang dari maka akan berpindah ke bawah
                    cout<<"-->";
                    menu++;
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x-=2;
                if(x < 12)
                {
                    x = 21;
                    GetPosition(54,21);//Jika x kurang dari dari MIN tandah panah berpindah ke MAX
                    cout<<"-->";
                    menu = HISTORY;
                }
                else
                {
                    GetPosition(54,x);
                    cout<<"-->";
                    menu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                system("CLS");
                mainMenu();

            }
            else if(GetAsyncKeyState(VK_RETURN)||GetAsyncKeyState(VK_RIGHT))
            {
                switch(menu)
                {
                case SALDO :
                {
                    system("CLS");
                    running = false;
                    break;
                };
                case TRANSFER :
                {
                    system("CLS");
                    running = false;
                    break;
                };
                case WITHDRAW :
                {
                    system("CLS");
                    running = false;
                    break;
                };
                case CHANGE_PIN :
                {
                    system("CLS");
                    running = false;
                    break;
                };
                case HISTORY:
                {
                    system("CLS");
                    running = false;
                    break;
                };
                }
            }else{
                GetPosition(54,x);
                cout<<"-->";
            }
        }
    }
    while(menu > 0 && menu < 7);

}
void infoMenu(){
    cin.clear();
    GetPosition(57,15);
    cout<<"+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(57,16);
    cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
    GetPosition(57,17);
    cout << "|" << setfill(' ') << setw(32) << "INFO MENU" <<setfill(' ')<<setw(26) << "|";
    GetPosition(57,18);
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
    GetPosition(57,19);
    cout<<"+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(57,20);
    cout << "|" << setfill(' ') << setw(49) << "SILAHKAN HUBUNGI CUSTOMER SERVICE KAMI!!!" <<setfill(' ')<<setw(9) << "|";
    GetPosition(57,21);
    cout << "|" << setfill(' ') << setw(40) << "Telp : (0274) 999 000 11" <<setfill(' ')<<setw(18) << "|";
    GetPosition(57,22);
    cout<<"|" << setfill(' ') << setw(34) <<"TERIMA  KASIH" << setw(24) << "|";
    GetPosition(57,23);
    cout<<"+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(57,24);
    cout<<"|"<<setw(15)<<setfill(' ')<< "ESC = KELUAR" << setw(42) << "HOME = MENU UTAMA    " << "|";
    GetPosition(57,25);
    cout<<"+"<<setw(58)<<setfill('-')<<"+";
    GetPosition(84,25);
    system("PAUSE>NUL");
    if(GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
    {
        PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
        system("CLS");
        mainMenu();
    }
    else
    {
        infoMenu();
    }

}
void managerMenu(){
    int menu = 1;
    bool running;
    string companyID;
    string companyPass;
    enum menu {CREATE =1,LIST, UPDATE, DELETES};
    do
    {
        running = true;
        int x = 13;
        menu = CREATE;
        GetPosition(54,x);
        cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
        while(running)
        {
            GetPosition(57,8);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            GetPosition(57,10);
            cout << "|" << setfill(' ') << setw(34) << "MANAGER MENU" <<setfill(' ')<<setw(24) << "|";
            GetPosition(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            GetPosition(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,13);
            cout<<"| CREATE ADMIN ACCOUNT"<<setfill(' ')<<setw(37) <<"|";
            GetPosition(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,15);
            cout<<"| LIST ADMIN ACCOUNT"<<setfill(' ')<<setw(39) <<"|";
            GetPosition(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,17);
            cout<<"| UPDATE ADMIN ACCOUNT"<<setfill(' ')<<setw(37) <<"|";
            GetPosition(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,19);
            cout<<"| DELETE ADMIN ACCOUNT"<<setfill(' ')<<setw(37) <<"|";
            GetPosition(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,23);
            cout<<" KEY FUNCTION INFO:";
            GetPosition(57,24);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            GetPosition(57,25);
            cout<<"|" << setfill(' ') << setw(32)<<"ESC = EXIT" <<setfill(' ') <<setw(26) <<"|";
            GetPosition(57,26);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            GetPosition(57,27);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            GetPosition(87,27);
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x+=2;
                if(x > 20)
                {
                    x = 13;
                    GetPosition(54,13);//Jika x lebih besar dari MAX tanda panah berpindah ke MIN
                    cout<<"-->";
                    menu = CREATE;
                }
                else
                {
                    GetPosition(54,x);//Jika kurang dari maka akan berpindah ke bawah
                    cout<<"-->";
                    menu++;
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                GetPosition(54,x);
                cout<<"   ";
                x-=2;
                if(x < 12)
                {
                    x = 19;
                    GetPosition(54,19);//Jika x kurang dari dari MIN tandah panah berpindah ke MAX
                    cout<<"-->";
                    menu = DELETES;
                }
                else
                {
                    GetPosition(54,x);
                    cout<<"-->";
                    menu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE))
            {
                PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                system("CLS");
                //Back to Main Menu
                mainMenu();
            }
            else if(GetAsyncKeyState(VK_RETURN)|| GetAsyncKeyState(VK_RIGHT))
            {
                system("CLS");
                GetPosition(57,8);
                cout << "+"<<setw(58)<<setfill('-')<<"+";
                GetPosition(57,9);
                cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
                GetPosition(57,10);
                cout << "|" << setfill(' ') << setw(34) << "MANAGER MENU" <<setfill(' ')<<setw(24) << "|";
                GetPosition(57,11);
                cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
                GetPosition(57,12);
                cout << "+"<<setw(58)<<setfill('-')<<"+";
                GetPosition(70,14);
                cout << "  KODE PERUSAHAAN  : ";
                cin >> companyID;
                if(companyID == "124180026" || companyID == "124180025" )
                {
                    system("CLS");

                    switch(menu)
                    {
                    case CREATE :
                    {
                        system("CLS");
                        running = false;
                        createAdminAccount();
                        system("CLS");
                        break;
                    };
                    case LIST :
                    {
                        system("CLS");
                        running = false;
                        showListAdminAccount();
                        system("CLS");
                        break;
                    };
                    case UPDATE :
                    {
                        system("CLS");
                        running = false;
                        updateAdminAccount();
                        system("CLS");
                        break;
                    };
                    case DELETES :
                    {
                        system("CLS");
                        running = false;
                        deleteAdminAccount();
                        system("CLS");
                        break;
                    };
                    }
                }
                else
                {
                    GetPosition(65,14);
                    cout << "KODE PERUSAHAAN YANG ANDA MASSUKAN SALAH\n";
                    GetPosition(45,15);
                    system("PAUSE>NUL");
                    system("CLS");
                    //Back To Main Menu
                    mainMenu();
                }
            }else{
                GetPosition(54,x);
                cout<<"-->";
            }
        }
    }
    while(menu > 0 && menu < 5);
}
//MANAGER MENU
void createAdminAccount(){//OK
    AdminAccount temp;
    if(isEmptyAdminList()){
        temp.accountID = 0;
    }
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "CREATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<" ACCOUNT ID\t: "<<++temp.accountID;cin.ignore();
    cout << endl <<endl;
    cout<<" PIN\t\t: ";
    cin.getline(temp.PIN, sizeof(temp.PIN));
    cout << endl;
    cout<<" NO KTP\t\t: ";
    cin.getline(temp.noKTP, sizeof(temp.noKTP));
    cout << endl;
    cout<<" NAME\t\t: ";
    cin.getline(temp.name, sizeof(temp.name));
    cout << endl;
    cout<<" BIRTH DAY\t: ";
    cin.getline(temp.birthDay, sizeof(temp.birthDay));
    cout << endl;
    cout<<" ADDRESS\t: ";
    cin.getline(temp.address, sizeof(temp.address));
    cout << endl;
    cout<<" NO TELP\t: ";
    cin.getline(temp.noTelp, sizeof(temp.noTelp));
    GetLoading(1,19);
    inputAdminList(temp);
}
void listAdminAccount(){//OK
    showListAdminAccount();
}
void deleteAdminAccount(){
    if(isEmptyAdminList()){
        cout << "UNABLE TO SAVE THE DATA, THE STORAGE IS EMPTY";
    }else{
    int accountID;
    char PIN[7];
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "DELETE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cin.ignore();
    cout<<" ACCOUNT ID\t: ";
    cin>>accountID;
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(PIN, sizeof(PIN));
    deleteAdminList(accountID, PIN);
    }
}
void updateAdminAccount(){
    if(isEmptyAdminList()){
        cout << "UNABLE TO SAVE THE DATA, THE STORAGE IS EMPTY";
    }else{
    AdminAccount temp;
    int accountID;
    char PIN[7];
    char newPIN[7];
    char address[100];
    char noTelp[13];
    adminPointer check, help;
    check = firstAdmin;
    bool result = true;
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "UPDATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";cin.ignore();
    cout<<" ACCOUNT ID\t: ";
    cin>>accountID;
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(PIN, sizeof(PIN));
     while(help -> next != NULL)
    {
        if((help->adminAccounts.accountID == accountID) && (strcmp(help->adminAccounts.PIN,PIN)==0)){
            result = true;
            break;
        }else{
            result = false;
        }
        help = help -> next;
    };
    if(result == true){
            system("CLS");
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "UPDATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<" ACCOUNT ID\t: "<<check->adminAccounts.accountID;
    cout << endl<<endl;
    cout<<" PIN\t\t: ";
    cin.getline(newPIN, sizeof(newPIN));
    cout << endl;
    cout<<" ADDRESS\t: ";
    cin.getline(address, sizeof(address));
    cout << endl;
    cout<<" NO TELP\t: ";
    cin.getline(noTelp, sizeof(noTelp));
    temp.accountID = check->adminAccounts.accountID;
    strcpy(temp.PIN,PIN);
    strcpy(temp.address,address);
    strcpy(temp.noTelp,noTelp);
    strcpy(temp.name,check->adminAccounts.name);
    strcpy(temp.birthDay, check->adminAccounts.birthDay);
    strcpy(temp.noKTP, check->adminAccounts.noKTP);
    updateAdminList(temp);
        }else {
        cout << "\n\n UNABLE TO SAVE THE DATA, ";
        }
    }
}
//LINK LIST MENU MANAGER
bool isEmptyAdminList(){//OK
    if(firstAdmin == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
void createAdminList(){//OK
    adminPointer List;
    List = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    List = NULL;
    firstAdmin = List;
    lastAdmin = firstAdmin;
};
void inputAdminList(AdminAccount tempAdminAccount){
    //Variable bantu dengan type pointer
    adminPointer newData, check;
    bool result = true;
    newData = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    newData -> adminAccounts = tempAdminAccount;
    newData -> next = NULL;
    newData -> prev = NULL;
    if(isEmptyAdminList())
    {
        firstAdmin = newData;
        lastAdmin = firstAdmin;
        cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
    }else{
        adminPointer help;
        help = firstAdmin;
        bool resultAccountID = true;
        bool resultNoTelp = true;
        bool resultNoKTP = true;
        if((tempAdminAccount.accountID == firstAdmin -> adminAccounts.accountID)||(strcmp(tempAdminAccount.noTelp,firstAdmin -> adminAccounts.noTelp)==0)||(strcmp(tempAdminAccount.noKTP,firstAdmin -> adminAccounts.noKTP)==0)){
        if((tempAdminAccount.accountID == firstAdmin -> adminAccounts.accountID)){
           cout << "\n\n CANT CREATE THE ACCOUNT, USERNAME ALREADY USED\n";
        }
        if((strcmp(tempAdminAccount.noTelp,firstAdmin -> adminAccounts.noTelp)==0)){

            cout << "\n\n CANT CREATE THE ACCOUNT, TELP NUMBER ALREADY USED\n";
        }
        if((strcmp(tempAdminAccount.noKTP,firstAdmin -> adminAccounts.noKTP)==0)){

            cout << "\n\n CANT CREATE THE ACCOUNT, NO KTP ALREADY USED\n";
        }
        }else if((tempAdminAccount.accountID == lastAdmin -> adminAccounts.accountID)||(strcmp(tempAdminAccount.noTelp,lastAdmin -> adminAccounts.noTelp)==0)||(strcmp(tempAdminAccount.noKTP,lastAdmin-> adminAccounts.noKTP)==0)){
        if(tempAdminAccount.accountID ==lastAdmin -> adminAccounts.accountID){
            cout << "\n\n CANT CREATE THE ACCOUNT, USERNAME ALREADY USED\n";
        }
        if((strcmp(tempAdminAccount.noTelp,lastAdmin -> adminAccounts.noTelp)==0)){

            cout << "\n\n CANT CREATE THE ACCOUNT, TELP NUMBER ALREADY USED\n";
        }
        if((strcmp(tempAdminAccount.noKTP,lastAdmin -> adminAccounts.noKTP)==0)){

           cout << "\n\n CANT CREATE THE ACCOUNT, NO KTP ALREADY USED\n";
        }
        }else{
        while(help -> next != NULL){
            if(tempAdminAccount.accountID == help -> adminAccounts.accountID){
                resultAccountID = false;
            }if(strcmp(tempAdminAccount.noTelp,help -> adminAccounts.noTelp)==0){
                resultNoTelp = false;
            }if(strcmp(tempAdminAccount.noKTP,help -> adminAccounts.noKTP)==0){
                resultNoTelp = false;
            }
            help = help -> next;
        }
        if((resultAccountID == false)||(resultNoTelp == false)||(resultNoKTP == false)){
        if(resultAccountID == false){
        cout << "\n\n CANT CREATE THE ACCOUNT, USERNAME ALREADY USED\n";
        }if(resultNoTelp == false){
        cout << "\n\n CANT CREATE THE ACCOUNT, TELP NUMBER ALREADY USED\n";
        }if(resultNoKTP == false){
        cout << "\n\n CANT CREATE THE ACCOUNT, NO KTP ALREADY USED\n";
        }
        }else{
        help -> next = newData;
        newData -> prev = help;
        lastAdmin = newData;
        cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
        }
    }
    }
    cout<<endl;
    system(" PAUSE");
    system("CLS");
};
void showListAdminAccount(){
     if(isEmptyAdminList())
    {
        cout << "SORRT CANT DELETE THE DATA, NOT FOUND THE DATA";
    }else{
    adminPointer help;
    help = firstAdmin;
    int no = 0;
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(77) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(53) << "|\n";
    cout<<"|" << setfill(' ') << setw(70) << "LIST  ACCOUNT" <<setfill(' ')<<setw(60) << "|\n";
    cout<<"|" << setfill(' ') << setw(83) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(47) << "|\n";
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+\n";
    cout<<"|"<<"NO |ACCOUNT ID"<<setw(15)<<setfill(' ')<<"|PIN"<<setw(12)<<setfill(' ')<< "|NAME"<<setw(20)<<setfill(' ')<< "|NO KTP"<<setw(16)<<setfill(' ')<< "|ADDRESS"<<setw(30)<<setfill(' ')<< "|BIRTH DAY"<<setw(15)<<setfill(' ')<< "|NO TELP"<<setfill(' ')<< setw(8)<<"|\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+\n";
    do{
        cout<<"|"<<++no<<setfill(' ')<<setw(3)<<"|"<<left<<setfill(' ')<<setw(21)<<help->adminAccounts.accountID<<setfill(' ')<<"|"<<setw(10)<<help->adminAccounts.PIN<<setfill(' ')<<"|"<<setw(17)<<help->adminAccounts.name<<setfill(' ')<<"|"<<setw(14)<<help->adminAccounts.noKTP<<setfill(' ')<<"|"<<setw(27)<<help->adminAccounts.address<<setfill(' ')<<"|"<<setw(16)<<help->adminAccounts.birthDay<<setfill(' ')<<"|"<<setw(13)<<help->adminAccounts.noTelp<<setfill(' ')<<"|"<<right<<endl;
        help = help -> next;
    }while(help != NULL);
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    }
    system("\nPAUSE");
    system("CLS");
};
void deleteAdminList(int accountID, char PIN[7]){
    if(isEmptyAdminList())
    {
        cout << "SORRT CANT DELETE THE DATA, NOT FOUND THE DATA";
    }else if (accountID > lastAdmin->adminAccounts.accountID){
            cout << "SORRT CANT DELETE THE DATA, NOT FOUND THE DATA";
    }else{
    if((firstAdmin->next == NULL) &&(firstAdmin -> adminAccounts.accountID == accountID) && (strcmp(firstAdmin -> adminAccounts.PIN, PIN)==0))
            {
                adminPointer Delete;
                Delete = firstAdmin;
                free(Delete);
                firstAdmin = NULL;
                lastAdmin = firstAdmin;
                cout << "\n\n DELETE DATA SUCCESFULLY";
            }else if((firstAdmin->next == lastAdmin) &&(lastAdmin -> adminAccounts.accountID == accountID) && (strcmp(lastAdmin -> adminAccounts.PIN, PIN)==0))
            {
                adminPointer Delete;
                Delete = lastAdmin;
                free(Delete);
                lastAdmin = firstAdmin;
                firstAdmin -> next = NULL;
                firstAdmin -> prev = NULL;
                cout << "\n\n DELETE DATA SUCCESFULLY";
            }else if((firstAdmin->next == lastAdmin) &&(firstAdmin -> adminAccounts.accountID == accountID) && (strcmp(firstAdmin -> adminAccounts.PIN, PIN)==0))
            {
                adminPointer Delete;
                Delete = firstAdmin;
                free(Delete);
                firstAdmin = lastAdmin;
                firstAdmin -> next = NULL;
                firstAdmin -> prev = NULL;
                cout << "\n\n DELETE DATA SUCCESFULLY";
            }
            else if((firstAdmin -> adminAccounts.accountID == accountID) && (strcmp(firstAdmin -> adminAccounts.PIN, PIN)==0))
            {
                adminPointer Delete;
                Delete = firstAdmin;
                firstAdmin = firstAdmin -> next;
                firstAdmin -> prev = NULL;
                free(Delete);
                cout << "\n\n DELETE DATA SUCCESFULLY";
            }
            else if((lastAdmin -> adminAccounts.accountID == accountID) && (strcmp(lastAdmin -> adminAccounts.PIN, PIN)==0))
            {
                adminPointer Delete, help;
                Delete = lastAdmin;
                help = lastAdmin -> prev;
                lastAdmin = help;
                lastAdmin -> next = NULL;
                free(Delete);
                cout << "\n\n DELETE DATA SUCCESFULLY";
            }
            else
            {
        adminPointer help, Delete;
        help = firstAdmin;
        bool result = true;
        while(help->next != NULL ){
            if((help -> adminAccounts.accountID == accountID) && (strcmp(help -> adminAccounts.PIN, PIN)==0))
            {
                result = true;
                break;
            }
            else
            {
                result = false;
            }
            help = help -> next;
        };
        if(result == true)
        {
                Delete = help -> next;
                help -> next = Delete -> next;
                Delete -> next -> prev = Delete -> prev;
                free(Delete);
                GetLoading(1,5);
                cout << "\n\n DELETE DATA SUCCESFULLY";
        }
    }
    }
    cout<<endl;
    system(" PAUSE");
    system("CLS");
};
void updateAdminList(AdminAccount tempAdminAccount){
    adminPointer update, help, Delete, help2;
    update = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    update -> adminAccounts = tempAdminAccount;
    update-> next = NULL;
    update -> prev = NULL;
    bool result = true;
    if((firstAdmin->adminAccounts.accountID == tempAdminAccount.accountID) && (strcmp(firstAdmin->adminAccounts.PIN,tempAdminAccount.PIN)==0)){
        help2 = firstAdmin->next;
        help -> next = help2;
        help2 -> prev = help;
        Delete = firstAdmin;
        firstAdmin = help;
        free(Delete);
    }else{
    while(help -> next != NULL)
    {
        if((help -> next ->adminAccounts.accountID == tempAdminAccount.accountID) && (strcmp(help -> next->adminAccounts.PIN,tempAdminAccount.PIN)==0)){
            result = true;
            break;
        }else{
            result = false;
        }
        help = help -> next;
    };
    if(result == true)
    {
        adminPointer Delete, tempUpdate;
        Delete = help;
        tempUpdate = help -> next;
        update -> next = tempUpdate;
        tempUpdate -> prev = update;
        free(Delete);
    }
    else
    {
        cout << "NOT FOUND ADMIN ACCOUNT !!!\n";
    }
    }
}
//CLIENT MENU
bool isEmptyClientList(){
    if(firstClient == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
void createClientAccount(){
    ClientAccount temp;
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "CREATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<" Username\t: ";
    cin.getline(temp.accountNumber, sizeof(temp.accountNumber));
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(temp.PIN, sizeof(temp.PIN));
    cout << endl;
    cout<<" Nama\t\t: ";
    cin.getline(temp.name, sizeof(temp.name));
    cout << endl;
    cout<<" Alamat\t\t: ";
    cin.getline(temp.address, sizeof(temp.address));
    cout << endl;
    cout<<" Tanggal Lahir\t: ";
    cin.getline(temp.birthDay, sizeof(temp.birthDay));
    cout << endl;
    cout<<" No.KTP\t\t: ";
    cin.getline(temp.noKTP, sizeof(temp.noKTP));
    cout << endl;
    cout<<" No.Telephon\t: ";
    cin.getline(temp.noTelp, sizeof(temp.noTelp));
    inputClientList(temp);
}
void deleteClientAccount(){
}
void updateClientAccount(){
}
void listClientAccount(){
}
void transactionHistory(){
}
void deposito(){
}
void createClientList(){
    clientPointer List;
    List = (linkListClient *)malloc(sizeof(linkListClient));
    List = NULL;
    firstClient = List;
    lastClient = firstClient;
};
void inputClientList(ClientAccount tempClientAccounts){
    //Variable bantu dengan type pointer
    //Variable bantu dengan type pointer
    clientPointer help, check;
    bool result = true;
    help = (linkListClient *)malloc(sizeof(linkListClient));
    help -> clientAccounts = tempClientAccounts;
    help -> next = NULL;
    help -> prev = NULL;
    if(isEmptyAdminList())
    {
        firstClient = help;
        lastClient = firstClient;
        cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
    }else if((firstClient == lastClient)&&(strcmp(firstClient -> clientAccounts.accountNumber,tempClientAccounts.accountNumber)!=0) && (strcmp(firstClient -> clientAccounts.PIN,tempClientAccounts.PIN)!=0)){
            firstClient -> next = help;
            lastClient = help;
            lastClient-> prev = firstClient;
            lastClient -> next = NULL;
            cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
        }else{
        check = firstClient;
        while(check -> next != NULL){
            if((strcmp(tempClientAccounts.accountNumber,check -> clientAccounts.accountNumber)==0) && (strcmp(tempClientAccounts.PIN,check -> clientAccounts.PIN)==0))
            {
                result = true;
            }
            else
            {
                result = false;
            }
            check= check -> next;
        };
        if (result == true){
        cout << "\n\n CANT CREATE THE ACCOUNT, USERNAME ALREADY USED\n";
        }else
        {
            lastClient -> next = help;
            help -> prev = lastClient;
            lastClient = help;
            help -> next = NULL;
            cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
        }
    }
    cout<<endl;
    system(" PAUSE");
    system("CLS");
};
void deleteClientList(char accountNumber[16], char PIN[7]){

};
void showListClientAccount(){
    clientPointer help;
    help = firstClient;
    int no = 0;
    cout<<"+"<<setw(146)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(84) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(62) << "|\n";
    cout<<"|" << setfill(' ') << setw(80) << "LIST  ACCOUNT" <<setfill(' ')<<setw(66) << "|\n";
    cout<<"|" << setfill(' ') << setw(90) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(56) << "|\n";
    cout<<"+"<<setw(146)<<setfill('-')<<"+\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(12)<<setfill('-')<<"+"<<setw(19)<<setfill('-')<<"+\n";
    cout<<"|"<<"NO |ACCOUNT ID"<<setw(15)<<setfill(' ')<<"|PIN"<<setw(12)<<setfill(' ')<< "|NAME"<<setw(20)<<setfill(' ')<< "|NO KTP"<<setw(16)<<setfill(' ')<< "|ADDRESS"<<setw(30)<<setfill(' ')<< "|BIRTH DAY"<<setw(15)<<setfill(' ')<< "|NO TELP"<<setw(12)<<setfill(' ')<< "|BALANCE"<<setw(12)<<setfill(' ') <<"|\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(12)<<setfill('-')<<"+"<<setw(19)<<setfill('-')<<"+\n";
    while(help -> next != NULL)
    {
        cout<<"|"<<++no<<setfill(' ')<<setw(3)<<"|"<<left<<setfill(' ')<<setw(21)<<"CATUR"<<setfill(' ')<<"|"<<setw(10)<<"CATUR"<<setfill(' ')<<"|"<<setw(17)<<"NAME"<<setfill(' ')<<"|"<<setw(14)<<"KTP"<<setfill(' ')<<"|"<<setw(27)<<"ADDRESS"<<setfill(' ')<<"|"<<setw(16)<<"BIRTH DAY"<<setfill(' ')<<"|"<<setw(11)<<"TELP"<<setfill(' ')<<"|"<<right<<setfill(' ')<<setw(17)<<"BALANCE"<<"|";
        cout<<"+"<<setw(146)<<setfill('-')<<"+\n";
        help = help -> next;
    }
    system("PAUSE");
    system("CLS");
};
bool checkingClientAccount(char accountNumber[16], char PIN[6]){
    clientPointer help;
    do
    {
        if((strcmp(accountNumber,help -> clientAccounts.accountNumber)==0) && (strcmp(PIN,help -> clientAccounts.PIN)==0))
        {
            return true;
        }
        else
        {
            return false;
        }
        help = help -> next;
    }
    while(help != NULL);
}
void createQueue(){
    QueuePointer NewQueue;
    NewQueue = (queue*)malloc(sizeof(queue));
    NewQueue = NULL;
    firstQueue = NewQueue;
    lastQueue   = NewQueue;
}//OK
int isEmptyQueue(){
    if(firstQueue == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}//KOSONG
void enqueue(QueueData newData){
    clientPointer help;
    QueuePointer inputData;
    bool result = false;
    help = firstClient;
    if(isEmptyClientList()){
        cout << "\n\n SORRY CANT FOUND THE CLIENT ACCOUNT, CLIENT ACCOUNT IS EMPTY\n";
    }
    while(help->next!=NULL){
        if((strcmp(help->clientAccounts.accountNumber, newData.accountNumber)==0) && (strcmp(help->clientAccounts.PIN, newData.PIN)==0)){
            result = true;
        }
        help = help->next;
    }
    if(result == true){
    inputData = (queue *)malloc(sizeof(queue));
    inputData -> queueSave = newData;
    inputData -> next = NULL;
    if(isEmptyQueue())
    {
        firstQueue = inputData;
        lastQueue   = firstQueue;
    }
    else
    {
        if(firstQueue == lastQueue)
        {
            firstQueue -> next = inputData;
            lastQueue = inputData;
            lastQueue -> next = NULL;
        }
        else
        {
            lastQueue->next = inputData;
            lastQueue =inputData;
            lastQueue -> next = NULL;
        }
    }
    }else{
    cout << "\n\n NOT FOUND DATA, PLEASE REGISTER THE ACCOUNT!!!\n";
    }
system("PAUSE");
system("CLS");
}//PUSH DATA
void dequeue(){
    if(isEmptyQueue())
    {
        cout << "DATA NOT FOUND, QUEUE IS EMPTY!!!\n";
        system("PAUSE");
        system("CLS");

        }else{
        QueuePointer help;
        if(lastQueue == firstQueue){
        	free(firstQueue);
        	firstQueue = NULL;
        	lastQueue   = firstQueue;
        	cout << "ALL DATA DELETED!!!\n";
        	system("PAUSE");
        	system("CLS");
        }else{
        	help = firstQueue -> next;
        	free(firstQueue);
        	firstQueue = help;
        	firstQueue -> next = help -> next;
        }
    }
    system("PAUSE");
    system("CLS");
}//POP
void addEnqueue(){
    if(isEmptyClientList()){
        cout << "\n SORRY CANT FOUND THE CLIENT ACCOUNT, CLIENT ACCOUNT IS EMPTY\n\n";
        system("PAUSE");
        system("CLS");
    }else{
    QueueData temp;
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(36) << "INPUT ACCOUNT" <<setfill(' ')<<setw(22) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<" QUEUE NO\t: "<<++temp.no<<endl<<endl;
    cout<<" ACCOUNT ID\t: ";
    cin.getline(temp.accountNumber, sizeof(temp.accountNumber));
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(temp.PIN, sizeof(temp.PIN));
    cout << endl;
    enqueue(temp);
    }
}
