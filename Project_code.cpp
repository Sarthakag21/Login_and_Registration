#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;
string usn;
int tm;
void valid(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if (tm == 3)
        {
            cout << "\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout << "\nThis username already exists!\nCreate a username:";
        cin >> usn;
        //file.close();
        valid(usn);
    }
}
int main()
{

    int choice, i, exit = 0;
    char psd[20];
    int length = 0, j, h = 0, q = 0;
    string ans, name, fname, occ, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    cout << "----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    while (exit == 0)
    {
        cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username:";
            cin >> usn;
            cout << "\nEnter your password:";
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
                cout << "\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei, usern);
            getline(filei, line);
            getline(filei, pw);
            if (usn == usern)
            {
                cout << "\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
                cout << "User-name:" << usern << endl;
                cout << "Name:" << line << endl;
                getline(filei, line);
                cout << "Occupation:" << line << endl;
                filei.close();
                cout << "\n----------------------------------------Thank you for visiting:)----------------------------------------------\n";
                return 0;
            }
            else
            {
                cout << "\nWrong username or password!\nPlease try Again.\n";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "\nEnter your name:";
            cin.ignore();
            getline(cin, name);
            cout << "\nCreate a username:";
            cin >> usn;
            tm = 0;
            valid(usn);
            if (tm >= 3)
            {
                continue;
            }
        check:
            cout << "\nCreate a password:";
            cin >> psd;
            length = strlen(psd);
            if (length < 5 || length > 20)
            {
                cout << "\n*length of password must be in between 5 to 20";
            }
            for (j = 0; psd[j] != '\0'; j++)
            {
                if (psd[j] == '0' || psd[j] == '1' || psd[j] == '2' || psd[j] == '3' || psd[j] == '4' || psd[j] == '5' || psd[j] == '6' || psd[j] == '7' || psd[j] == '8' || psd[j] == '9')
                {
                    q = 0;
                    break;
                }
                h = 1;
            }
            if (q == 1)
            {
                cout << "\n*password must contain atleast one numeric value";
                q = 1;
            }
            for (j = 0; psd[j] != '\0'; j++)
            {
                if (psd[j] == '~' || psd[j] == '!' || psd[j] == '@' || psd[j] == '#' || psd[j] == '$' || psd[j] == '%' || psd[j] == '^' || psd[j] == '&' || psd[j] == '*')
                {
                    h = 0;
                    break;
                }
                h = 1;
            }
            if (h == 1)
            {
                cout << "\n*password must contain special characters";
                h = 1;
            }
            if (h == 1 || q == 1)
            {
                goto check;
            }
            fname = usn + ".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo << usn << endl
                  << name << endl
                  << psd << endl;
            cout << "\nYou are successfully registered:) ";
            cout << "\nEnter your occupation: ";
            cin.ignore();
            getline(cin, occ);
            fileo << occ << endl;
            cout << "\nYour occupation is saved: " << occ;
            fileo.close();
        }
        else
        {
            exit = 1;
        }
    }
}