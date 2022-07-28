#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>

using namespace std;

class hotel
{

    int room_no;
    char  name[30];
    char address[50];
    char phone[12];
    string ed,od;
    int dy;

public:

    void main_menu();
    void add();
    void customer_details();
    void booked_rooms();
    void edit();
    int check(int);
    void modify(int);
    void delete_rec(int);
    void bill(int);
};

vector<char> code;
char pas[10];
class password
{
    char ch,c;
public:
    void get_pass();
    int check_pass();
} pass;

void password::get_pass()
{
    system("cls");

    char ch;
    cout<<"\t\t\tWelcome to International Hotel of Bengal\n"<<endl<<endl<<endl;
    cout<<"\t\t\t\tHotel Bengal Management System\n"<<endl;
start:
    int i=0;
    cout<<"\n\nEnter your password for your system: ";
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        else if(ch==8)
        {
            if (i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            code.push_back(ch);
            cout<<"*";
        }
    }
    system("cls");

    string check;
    for(int i=0;i<code.size();i++) check.push_back(code[i]);
    if(check!="19103"){
        cout<<"\n\n\n\n\t\t\t\t\tOpss!!! Incorrect Password.\n\n\n";
        system("PAUSE");
        system("cls");
        goto start;
    }
}

int password::check_pass()
{
    int flag=0;
    int i=0;
    while(1)
    {
        c=getch();
        if(c==13)
        {
            break;
        }
        else if(c==8)
        {
            if (i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            pas[i++]=c;
            cout<<"*";
        }
    }
    for(int j=0; j<i; j++)
    {
        if(pas[j]!=code[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return 1;
    else
        return 0;
}


void hotel::main_menu()
{

    int choice;
    while(choice!=6)
    {

        system("cls");
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\t\t\t\t      * MAIN MENU *";
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\n\n\t\t\t1.Book A Room";
        cout<<"\n\t\t\t2.Customer Records";
        cout<<"\n\t\t\t3.Booked Rooms Records ";
        cout<<"\n\t\t\t4.Edit Record";
        cout<<"\n\t\t\t5.Check Out";
        cout<<"\n\t\t\t6.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;
        int r,a;
        switch(choice)
        {

        case 1 :
            add();
            break;

        case 2:
            customer_details();
            break;

        case 3:
            booked_rooms();
            break;

        case 4:
            edit();
            break;

        case 5:
            cout<<"Enter room number : "<<endl;
            int r;
            cin>>r;
            bill(r);
            break;

        case 6:
            break;

        default:
        {

            cout<<"\n\n\t\t\tWrong choice.....!!!";
            cout<<"\n\t\t\tPress any key to   continue....!!";
            getch();

        }

        }

    }

}


void hotel::add()
{

    system("cls");
    int r,flag,days;
    dy=days;
    string ed,od;
    ofstream fout("Record.txt",ios::app);

    cout<<"\n Enter Customer Details";
    cout<<"\n ----------------------";
    cout<<"\n\n Room no: ";
    cout<<"\n Total no. of Rooms : 50";
    cout<<"\n Ordinary Rooms : 1 - 30";
    cout<<"\n Luxury Rooms : 31 - 45";
    cout<<"\n Royal Rooms : 46 - 50";
    cout <<"\n Enter The Room no. you want to stay in : "<<endl;
    cin>>r;
    if(r<1 || r>50)
        cout<<"\n\tInvalid choice...........Try again...."<<endl;
    else{
    flag=check(r);

    if(flag)
        cout<<"\n Sorry..!!!Room is already booked";

    else
    {

        room_no=r;
        cout<<" Name: ";
        cin>>name;
        cout<<" Address: ";
        cin>>address;
        cout<<" Phone No: ";
        cin>>phone;
        cout<<"Entry Date (dd.mm.yy) :";
        cin>>ed;
        cout<<"Check out Date (dd.mm.yy) :";
        cin>>od;
        cout<<"Stayed Days : ";
        cin>>days;


        fout.write((char*)this,sizeof(hotel));
        cout<<"\n Room booking is successfully done...!!!";

    }

    cout<<"\n Press any key to continue.....!!";
    }

    getch();
    fout.close();

}


void hotel::customer_details()
{

    system("cls");

    ifstream fin("Record.txt",ios::in);
    int r,flag;

    cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
    cin>>r;

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            system("cls");
            cout<<"\n --------------------------";
            cout<<"\n    Customer Details";
            cout<<"\n --------------------------";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
            flag=1;
            break;

        }


    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant....!!";
    cout<<"\n\n Press any key to continue....!!";

    getch();
    fin.close();
}


void hotel::booked_rooms()
{

    system("cls");

    ifstream fin("Record.txt",ios::in);
    cout<<"\n\t\t\t    List Of Booked Rooms";
    cout<<"\n\t\t\t    ----------------------";
    cout<<"\n\n Room No.\tName\t\t\t\tAddress\t\t\t\tPhone No.\n";

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        cout<<"\n\n "<<room_no<<"\t\t"<<name;
        cout<<"\t\t\t\t"<<address<<"\t\t\t\t"<<phone;

    }

    cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
    getch();
    fin.close();

}


void hotel::edit()
{

    system("cls");

    int choice,r;
    cout<<"\n EDIT MENU";
    cout<<"\n ---------";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";
    cout<<"\n Enter your choice: ";

    cin>>choice;
    system("cls");

    cout<<"\n Enter room no: " ;
    cin>>r;

    switch(choice)
    {

    case 1:
        modify(r);
        break;

    case 2:
        delete_rec(r);
        break;

    default:
        cout<<"\n Wrong Choice.....!!";

    }
    cout<<"\n Press any key to continue....!!!";

    getch();
}


int hotel::check(int r)
{

    int flag=0;

    ifstream fin("Record.txt",ios::in);

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            flag=1;
            break;

        }

    }

    fin.close();
    return(flag);

}


void hotel::modify(int r)
{

    long pos,flag=0;

    fstream file("Record.txt",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {

        pos=file.tellg();
        file.read((char*)this,sizeof(hotel));

        if(room_no==r)
        {

            cout<<"\n Enter New Details";
            cout<<"\n -----------------";
            cout<<"\n Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone no: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(hotel));
            cout<<"\n Record is modified....!!";
            flag=1;
            break;

        }

    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant...!!";
    file.close();

}

void hotel::delete_rec(int r)
{

    int flag=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.txt",ios::out);

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)

        {

            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;

            if(ch=='n')
                fout.write((char*)this,sizeof(hotel));
            flag=1;

        }

        else
            fout.write((char*)this,sizeof(hotel));

    }

    fin.close();
    fout.close();

    if(flag==0)
        cout<<"\n Sorry room no. not found or vacant...!!";

    else
    {

        remove("Record.txt");
        rename("temp.txt","Record.txt");

    }

}

void hotel::bill(int r)
{
    ifstream fin("Record.txt",ios::in);
    int flag=0;
    int days;

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            system("cls");
            cout<<"\n Customer Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone<<endl;
            flag=1;
            cout<<"Stayed Days : ";
            cin>>days;
            if(r>=1&&r<=30){
                cout<<"Your bill is  for "<<days<<" Days is : TK. "<<2000*days<<endl;
            }
            else if(r>=31&&r<=45){
                cout<<"Your bill is  for "<<days<<" Days is : TK. "<<3000*days<<endl;
            }
            else{
                cout<<"Your bill is  for "<<days<<" Days is : TK. "<<5000*days<<endl;
            }

        }
    }
    fin.close();
    if(flag==0){
        cout<<"Room not found"<<endl;
    }

    getch();

}


int main()
{
    system("Color 1A");
    Sleep(200);
    system("Color 2B");
    Sleep(200);
    system("Color 3C");
    Sleep(200);
    system("Color 70");
    Sleep(200);
    system("Color 4D");
    Sleep(200);
    system("Color 5E");
    Sleep(200);
    system("Color 6F");
    Sleep(200);
    system("Color D9");
    Sleep(200);
    system("Color F0");
    hotel h;

    system("cls");

    cout<<"\n\t\t\t****************************";
    cout<<"\n\t\t\t****************************";
    pass.get_pass();
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

    getch();

    h.main_menu();
    return 0;
}
