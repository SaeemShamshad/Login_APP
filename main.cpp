#include<iostream>
#include<fstream>
using namespace std;

class temp
{
    string username, email, password;
    fstream file;
    public:
    void login();
    void signup();
    void forgotPassword();

}obj;
int main()
{
    cout<<"____Welcome____"<<endl;
    cout<<"1. SignUP"<<endl;
    cout<<"2. LofIn"<<endl;
    cout<<"3. Forgot Password "<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice : ";
    int Choice;
    cin>>Choice;
    cin.ignore();
    switch(Choice)
    {
    case 1:
        obj.signup();
    break;

    case 2:
            obj.login();
        break;
    case 3:
        obj.forgotPassword();
        break;
    case 4:
        return 0;
        break;


    }
}


void temp::signup()
{
    cout<<"\nEnter username : "<<endl;
    getline(cin, username);
    cout<<"\nEnter email : "<<endl;
    getline(cin, email);
    cout<<"Enter password : "<<endl;
    getline(cin, password);

    file.open("database.txt", ios::out|ios::app);
    file<<username<<"*"<<email<<"*"<<password<<endl;
    file.close();
}

void temp::login()
{
    string searchUsername, searchpassword ;
    bool found = false;
    cout<<"_____________Login bro___________"<<endl;
    cout<<"enter username : "<<endl;
    getline(cin, searchUsername);
    cout<<"enter password : "<<endl;
    getline(cin, searchpassword);
    file.open("database.txt", ios::in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    while (!file.eof())
    {
        if (username==searchUsername)
            if (password==searchpassword)
            {
                cout<<"Welcome "<<username<<" ,login Successful"<<endl;
                cout<<"email : "<<email<<endl;
            }
            else
            {
                cout<<"Wrong password"<<endl;
            }
        found = true;
        break;

        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();

    if (!found)
    {
        cout<<"No User exist"<<endl;
    }
}

void temp::forgotPassword()
{
      string searchUsername, searchEmail ;
    cout<<"Enter username : "<<endl;
    getline(cin, searchUsername);
    cout<<"Enter Email: "<<endl;
    getline(cin,  searchEmail);

    file.open("database.txt", ios::in);
    getline(file,username, '*');
    getline(file,email, '*');
    getline(file, password, '\n');

    while (!file.eof())
    {
        if (username==searchUsername)
        {
            if (email==searchEmail)
            {
                cout<<"your paassword is: "<<password<<endl;

            }else
            {
                cout<<"Not found ... "<<endl;
            }

        }
        else
        {
            cout<<"Not found..."<<endl;
        }

    }
}