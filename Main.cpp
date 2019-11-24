#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <mmsystem.h>
using namespace std;
typedef int Queue;
typedef struct queue *QueuePointer;
struct queue
{
    Queue no;
    QueuePointer next;
};
QueuePointer firstQueue, lastQueue ;
struct History
{
    char accountNumber[13];
    char typeOfTransaction[10];
    int debet;
    int saldo;
    char *date;
};
//ADMIN STRUCT
struct AdminAccount
{
    char name[50];
    char address[100];
    char birthDay[20];
    char noKTP[16];
    char noTelp[13];
    char accountID[16];
    char PIN[7];
};
//ADMIN LINK LIST
typedef struct linkListAdmin *adminPointer;
struct linkListAdmin
{
    AdminAccount adminAccounts;
    adminPointer next;
    adminPointer prev;
};
adminPointer firstAdmin, lastAdmin;

struct ClientAccount
{
    History AllHistoryTransaction;
    char name[50];
    char address[100];
    char birthDay[20];
    char noKTP[16];
    char noTelp[13];
    char accountNumber[16];
    char PIN[10];
};
//Struct Client Account[Link List]
typedef struct linkListClient *clientPointer;
struct linkListClient
{
    ClientAccount clientAccounts;
    clientPointer next;
    clientPointer prev;
};
clientPointer firstClient, lastClient;
//ADMIN METHOD
void createAdminAccount();
void deleteAdminAccount();
void updateAdminAccount();
void listAdminAccount();
//LINK LIST ADMIN
bool isEmptyAdminList();
void createAdminList();
void inputAdminList(AdminAccount adminAccount);
bool checkingAdminAccount();
void updateAdminList(AdminAccount tempAdminAccount);
void deleteAdminList(char accountID[16], char PIN[7]);
void listAdminList();
//CLIENT METHOD
void createClientAccount();
void deleteClientAccount();
void updateClientAccount();
void listClientAccount();
bool checkingClientAccount();
bool isEmptyClientList();
//LINK LIST CLIENT
bool isEmptyAdminList();
void createAdminList();
void inputAdminList(AdminAccount adminAccount);
bool checkingAdminAccount(char accountNumber[16],char PIN[7]);
void updateAdminList(AdminAccount tempAdminAccount);

int QueueNumber = 0;
bool checking = true;
void GetPosition(int x, int y);
void GetLoading(int x, int y);
void mainMenu();
void adminMenu();
void clientMenu();
void infoMenu();
void managerMenu();
void showListClientAccount();
void showListAdminAccount();
void transactionHistory();
void createClientList();
void createQueue();
int isEmptyQueue();
void enqueue();
void dequeue();
void printQueue();
int isEmptyStack();
void createStack();
void inputStack();
void listStack();
void deleteStack();
void deposito();
int main()
{
    int no = 0;
    createAdminList();
    createClientList();
    system("COLOR 09");
    time_t now = time(0);
    char * time = ctime(&now);
    tm *gmtm = gmtime(&now);
    time = asctime(gmtm);
    GetLoading(75, 21);
    mainMenu();
}
void mainMenu()
{
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
            cout<<"|"<<setw(17)<<setfill(' ') <<"STATUS ANTRIAN"<<setw(4)<<"|";
            GetPosition(75,34);
            cout<<"+"<<setw(21)<<setfill('=')<<"+";
            GetPosition(86,35);
            cout << QueueNumber;
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
                QueueNumber++;
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
void GetPosition(int x, int y)
{
    COORD CursorPosition = {x,y}; //Mengatur posisi
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}
void GetLoading(int x, int y)
{
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
void adminMenu()
{
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
                main();

            }
            else
            {
                GetPosition(54,x); //Jika Di tekan Selain Tombol Atas Bawah tanda Panah Tetap
                cout<<"-->";
            }
            if(GetAsyncKeyState(VK_RETURN)||GetAsyncKeyState(VK_RIGHT))
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
            }
        }
    }
    while(menu > 0 && menu < 7);

}
void clientMenu()
{
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
                main();

            }
            else
            {
                GetPosition(54,x); //Jika Di tekan Selain Tombol Atas Bawah tanda Panah Tetap
                cout<<"-->";
            }
            if(GetAsyncKeyState(VK_RETURN)||GetAsyncKeyState(VK_RIGHT))
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
            }
        }
    }
    while(menu > 0 && menu < 7);

}
void infoMenu()
{
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
        main();
    }
    else
    {
        infoMenu();
    }

}
void managerMenu()
{
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
            else
            {
                GetPosition(54,x); //Jika Di tekan Selain Tombol Atas Bawah tanda Panah Tetap
                cout<<"-->";
            }
            if(GetAsyncKeyState(VK_RETURN )|| GetAsyncKeyState(VK_RIGHT))
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
            }
        }
    }
    while(menu > 0 && menu < 5);
}
void createAdminAccount()
{
    AdminAccount temp;
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "CREATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cin.ignore();
    cout<<" ACCOUNT ID\t: ";
    cin.getline(temp.accountID, sizeof(temp.accountID));
    cout << endl;
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
void listAdminAccount()
{
    adminPointer help;
    int no = 0;
    cout<<"+"<<setw(144)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(83) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(61) << "|\n";
    cout<<"|" << setfill(' ') << setw(79) << "CREATE ACCOUNT" <<setfill(' ')<<setw(65) << "|\n";
    cout<<"|" << setfill(' ') << setw(89) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(55) << "|\n";
    cout<<"+"<<setw(144)<<setfill('-')<<"+\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(9)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(12)<<setfill('-')<<"+"<<setw(19)<<setfill('-')<<"+\n";
    cout<<"|"<<"NO |ACCOUNT ID"<<setw(15)<<setfill(' ')<<"|PIN"<<setw(10)<<setfill(' ')<< "|NAME"<<setw(20)<<setfill(' ')<< "|NO KTP"<<setw(16)<<setfill(' ')<< "|ADDRESS"<<setw(30)<<setfill(' ')<< "|BIRTH DAY"<<setw(15)<<setfill(' ')<< "|NO TELP"<<setw(12)<<setfill(' ')<< "|BALANCE"<<setw(12)<<setfill(' ') <<"|\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(9)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(12)<<setfill('-')<<"+"<<setw(19)<<setfill('-')<<"+\n";
}
void deleteAdminAccount()
{
    char accountID[16];
    char PIN[7];
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "DELETE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cin.ignore();
    cout<<" ACCOUNT ID\t: ";
    cin.getline(accountID, sizeof(accountID));
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(PIN, sizeof(PIN));
    deleteAdminList(accountID, PIN);
}
void updateAdminAccount()
{
    AdminAccount temp;
    char accountID[16];
    char PIN[7];
    char newPIN[7];
    char address[100];
    char noTelp[13];
    adminPointer check;
    check = firstAdmin;
    bool result = true;
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
    cout<<"|" << setfill(' ') << setw(35) << "UPDATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
    cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
    cout<<" ACCOUNT ID\t: ";
    cin.getline(accountID, sizeof(accountID));
    cout << endl;
    cout<<" PIN\t\t: ";
    cin.getline(PIN, sizeof(PIN));
        while((strcmp(check->adminAccounts.accountID,accountID)!= 0)&&(strcmp(check->adminAccounts.PIN,PIN)!= 0))
        {
            if((strcmp(check->adminAccounts.accountID,accountID)!= 0)&&(strcmp(check->adminAccounts.PIN,PIN)!= 0))
            {
            result = true;
            }else{
            cout <<"\n\nNOT FOUND DATA\n";
            result = false;
            }
            check = check -> next;
        }
        if(result){
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
    cout << endl<<endl;
    cout<<" ADDRESS\t: ";
    cin.getline(address, sizeof(address));
    cout << endl;
    cout<<" NO TELP\t: ";
    cin.getline(noTelp, sizeof(noTelp));
    strcpy(temp.accountID,check->adminAccounts.accountID);
    strcpy(temp.PIN,PIN);
    strcpy(temp.address,address);
    strcpy(temp.noTelp,noTelp);
    strcpy(temp.name,check->adminAccounts.name);
    strcpy(temp.birthDay, check->adminAccounts.birthDay);
    strcpy(temp.noKTP, check->adminAccounts.noKTP);
    updateAdminList(temp);
        }
}
bool isEmptyAdminList()
{
    if(firstAdmin == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
void createAdminList()
{
    adminPointer List;
    List = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    List = NULL;
    firstAdmin = List;
    lastAdmin = firstAdmin;
};
void inputAdminList(AdminAccount tempAdminAccount)
{
    //Variable bantu dengan type pointer
    adminPointer help, check;
    bool result = true;
    help = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    help -> adminAccounts = tempAdminAccount;
    help -> next = NULL;
    help -> prev = NULL;
    if(isEmptyAdminList())
    {
        firstAdmin = help;
        lastAdmin = firstAdmin;
        cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
    }
    else
    {
        do
        {
            if((strcmp(tempAdminAccount.accountID,help -> adminAccounts.accountID)==0) && (strcmp(tempAdminAccount.PIN,help -> adminAccounts.PIN)==0))
            {
                result = true;
            }
            else
            {
                result = false;
            }
            help = help -> next;
        }
        while(help != NULL);

        if(firstAdmin == lastAdmin && !result)
        {
            firstAdmin -> next = help;
            help -> prev = firstAdmin;
            lastAdmin = help;
            cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
        }else if(!result)
        {
            lastAdmin -> next = help;
            help -> prev = lastAdmin;
            lastAdmin = help;
            cout << "\n\n SUCCESSFULY ADD ADMIN ACCOUNT\n";
        }else{
        cout << "\n\n CANT CREATE THE ACCOUNT, USERNAME ALREADY USED\n";
        }
    }
    system("PAUSE>NUL");
    system("CLS");
};
void showListAdminAccount()
{
    adminPointer help;
    help = firstAdmin;
    int no = 0;
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    cout<<"|" << setfill(' ') << setw(77) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(53) << "|\n";
    cout<<"|" << setfill(' ') << setw(70) << "LIST ACCOUNT" <<setfill(' ')<<setw(60) << "|\n";
    cout<<"|" << setfill(' ') << setw(83) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(47) << "|\n";
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+\n";
    cout<<"|"<<"NO |ACCOUNT ID"<<setw(15)<<setfill(' ')<<"|PIN"<<setw(12)<<setfill(' ')<< "|NAME"<<setw(20)<<setfill(' ')<< "|NO KTP"<<setw(16)<<setfill(' ')<< "|ADDRESS"<<setw(30)<<setfill(' ')<< "|BIRTH DAY"<<setw(15)<<setfill(' ')<< "|NO TELP"<<setfill(' ')<< setw(8)<<"|\n";
    cout<<"+"<<setw(4)<<setfill('-')<<"+"<<setw(22)<<setfill('-')<<"+"<<setw(11)<<setfill('-')<<"+"<<setw(18)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+"<<setw(28)<<setfill('-')<<"+"<<setw(17)<<setfill('-')<<"+"<<setw(15)<<setfill('-')<<"+\n";
    while(help != NULL)
    {
        cout<<"|"<<++no<<setfill(' ')<<setw(3)<<"|"<<left<<setfill(' ')<<setw(21)<<help->adminAccounts.accountID<<setfill(' ')<<"|"<<setw(10)<<help->adminAccounts.PIN<<setfill(' ')<<"|"<<setw(17)<<help->adminAccounts.name<<setfill(' ')<<"|"<<setw(14)<<help->adminAccounts.noKTP<<setfill(' ')<<"|"<<setw(27)<<help->adminAccounts.address<<setfill(' ')<<"|"<<setw(16)<<help->adminAccounts.birthDay<<setfill(' ')<<"|"<<setw(13)<<help->adminAccounts.noTelp<<setfill(' ')<<"|"<<right<<endl;
        help = help -> next;
    };
    cout<<"+"<<setw(130)<<setfill('-')<<"+\n";
    system("PAUSE>NUL");
    system("CLS");
};
void deleteAdminList(char accountID[16], char PIN[7])
{
    if(isEmptyAdminList())
    {
        cout << "NOT FOUND DATA";
    }
    else
    {
        adminPointer help, Delete;
        help = firstAdmin;
        bool result = true;
        while(help->next != NULL){
            if((strcmp(help -> adminAccounts.accountID, accountID)!=0) && ((strcmp(help -> adminAccounts.PIN, PIN)!=0)))
            {
                result = true;
            }
            else
            {
                result = false;
            }

            help = help -> next;
        };

        if(result)
        {
            if(firstAdmin -> adminAccounts.accountID == accountID && firstAdmin -> adminAccounts.PIN == PIN)
            {
                Delete = firstAdmin;
                free(Delete);
                firstAdmin = NULL;
                lastAdmin = firstAdmin;
            }
            else if(lastAdmin -> adminAccounts.accountID == accountID && lastAdmin -> adminAccounts.PIN == PIN)
            {
                Delete = lastAdmin;
                help = lastAdmin -> prev;
                free(Delete);
                lastAdmin = help;
                lastAdmin -> next = NULL;
            }
            else
            {
                Delete = help;
                help = help -> prev;
                help -> next = Delete -> next;
                Delete -> prev = help;
                free(Delete);
            }
        }
    }
};
void updateAdminList(AdminAccount tempAdminAccount)
{
    adminPointer update, help, Delete;
    update = (linkListAdmin *)malloc(sizeof(linkListAdmin));
    update -> adminAccounts = tempAdminAccount;
    firstAdmin -> next = NULL;
    firstAdmin -> prev = NULL;
    bool result = true;
    do
    {
        if(help -> adminAccounts.accountID == tempAdminAccount.accountID && help -> adminAccounts.PIN == tempAdminAccount.PIN )
        {
            result = true;
        }
        else
        {
            result = false;
        }
        help = help -> next;
    }
    while(help != NULL);
    if(result)
    {
        help = Delete;
        update -> next = help -> next;
        update -> prev = help -> prev;
        free(Delete);
    }
    else
    {
        cout << "NOT FOUND ADMIN ACCOUNT !!!\n";
    }

}
bool isEmptyClientList()
{
    if(firstClient == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
void createClientAccount()
{
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
}
void deleteClientAccount()
{
}
void updateClientAccount()
{
}
void listClientAccount()
{
}
void transactionHistory()
{
}
void deposito()
{
}
//Buat Link List
void createClientList()
{
    clientPointer List;
    List = (linkListClient *)malloc(sizeof(linkListClient));
    List = NULL;
    firstClient = List;
    lastClient = firstClient;
};
//Input Link List
void inputClientList(ClientAccount tempClientAccounts)
{
    //Variable bantu dengan type pointer
    clientPointer help;
    help = (linkListClient *)malloc(sizeof(linkListClient));
    help -> clientAccounts = tempClientAccounts;
    firstClient -> next = NULL;
    firstClient -> prev = NULL;
    if(isEmptyClientList())
    {
        firstClient = help;
        lastClient = firstClient;
    }
    else
    {
        clientPointer check;
        bool result = false;
        check = firstClient;
        while(check -> next != NULL )
        {
            if(check -> clientAccounts.accountNumber == tempClientAccounts.accountNumber)
            {
                result = true;
            }
            check = check -> next;
        }
    }
};
void deleteClientList(string accountNumber, string PIN)
{

};
void showListClientAccount()
{
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
bool checkingClientAccount(char accountNumber[16], char PIN[6])
{
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
void createQueue()
{

    QueuePointer NewQueue;
    NewQueue = (queue*)malloc(sizeof(queue));
    NewQueue = NULL;
    firstQueue = NewQueue;
    lastQueue   = NewQueue;
}//OK
int isEmptyQueue()
{
    if(NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}//KOSONG
void enqueue()
{
    QueuePointer inputData;
    inputData = (queue *)malloc(sizeof(queue));
    //inputData -> dataSave;
    inputData -> next = NULL;
    //inputData -> prev = NULL;
    if(isEmptyQueue())
    {
        firstQueue = inputData;
        lastQueue   = firstQueue;
        system("PAUSE");
    }
    else
    {
        //lastQueue -> next = inputData;
        //inputData -> prev = lastQueue;
        //lastQueue = inputData;
    }
}//PUSH DATA
void dequeue()
{
    if(isEmptyQueue())
    {
        cout << "DATA NOT FOUND!!!\n";
        system("PAUSE");
        system("CLS");

        /**else{
        cout << "                        INFO DEQUEUE\n";
        cout << "+=======+====================+===========================+\n";
        cout << "|  ID   |        NAMA        |          KEPERLUAN        |\n";
        cout << "+=======+====================+===========================+\n";
        typeptr help;
        if(top == first){
        	enqueueHistory(top -> dataSave);
        	cout <<"|" << setw(5) << first -> dataSave.no <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
        	free(first);
        	first = NULL;
        	top   = first;
        	cout << "ALL DATA DELETED!!!\n";
        	system("PAUSE");
        	system("CLS");
        }else{
        	help = first -> next;
        	enqueueHistory(first -> dataSave);
        	cout <<"|" << setw(5) << first -> dataSave.no <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
        	free(first);
        	first = help;
        	first -> prev = NULL;
        	first -> next = help -> next;
        }*/
    }
    system("PAUSE");
    system("CLS");
}//POP
