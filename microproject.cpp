#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
int temp2;
int available = 200;
int temp;
int amount;
int tempamount;
int count;
int p1;
int p2 = 10112003;
int doz;
int totaldoz = 0;
int tempdoz;
string buyee;
int rateperdoz = 300;
int rateperunit = 50;

void receiptinsert()
{
    cout << " Name of item:NOTEBOOK" << endl;
    ;
    totaldoz = totaldoz + doz;
    cout << "Total Dozens Purchased:" << totaldoz << endl;
    ;
    cout << "Enter name of buyee:" << endl;
    cin >> buyee;
    cout << "Total amount purchased:" << count << endl;
}
void receiptgeneration()
{
    // to view entry of all bills
    ofstream myfile("file.txt", ios::app);
    myfile << "<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><\n<>................................................JMD AAGENCY.........................................................................<>\n<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><" << endl;
    myfile << "NAME OF BUYEE:" << buyee << endl;
    myfile << "\n\n\nITEM NAME\t\t|\t\tQUANTITY(dozens)\t\t|\t\tRATE PER DOZEN \n";
    myfile << "......................................................................." << endl;
    myfile << "NOTEBOOK";
    myfile << "\t\t|\t\t" << totaldoz << "\t\t\t\t\t\t|\t\t" << rateperdoz << "             " << endl;
    myfile << "........................................................................" << endl;
    myfile << " Total Amount=                                           " << count << "Rs" << endl;
    myfile << "........................................................................" << endl;
    myfile << "\n\n\n"
           << endl;
    myfile.close();
    // to view current bill.
    ofstream file("bill.txt");
    myfile << "<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><\n<>................................................JMD AAGENCY.........................................................................<>\n<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><" << endl;
    file << "NAME OF BUYEE:" << buyee << endl;
    file << "\n\n\nITEM NAME\t\t|\t\tQUANTITY(dozens)\t\t|\t\tRATE PER DOZEN \n";
    file << "......................................................................." << endl;
    file << "NOTEBOOK"
         << "\t\t|\t\t" << totaldoz << "\t\t\t\t\t\t|\t\t" << rateperdoz << "             " << endl;
    file << "........................................................................" << endl;
    file << " Total Amount=                                                                " << count << "Rs" << endl;
    file << "........................................................................" << endl;
    file.close();

    //    to view bill in cmd:
    cout << "<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><>" << endl;
    cout << "<>.................................................JMD AAGENCY.........................................................................<>"
         << endl;
    cout << "<><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><><><>"
         << endl;
    cout << "\n\nNAME OF BUYEE:" << buyee << endl;
    cout << "........................................................................................................";
    cout << "\n\n\nITEM NAME\t\t|\t\tQUANTITY(dozens)\t\t|\t\tRATE PER DOZEN " << endl;
    ;
    cout << "......................................................................................................." << endl;
    cout << "NOTEBOOK"
         << "\t\t|\t\t" << totaldoz << "\t\t\t\t|\t\t" << rateperdoz << "             " << endl;
    cout << "........................................................................................................" << endl;
    cout << " Total Amount=                                                                           " << count << " Rs" << endl;
    cout << "........................................................................................................" << endl;
}
int passwords()
{

    cout << "Please enter login password:";
    char pass[10] = {0};
    char temp[10] = "1331";
    for (int j = 0; j < 10; j++)
    {
        pass[j] = _getch();
        if (pass[j] == 13)
        {
            pass[j] = '\0';
            break;
        }
        else
        {
            _putch('*');
        }
    }
    if (strcmp(temp, pass) == 0)
    {
        cout << endl;
        cout << "Login Successful!" << endl;
        return 1;
    }
    else
        return 0;
}

class stockentry
{
public:
    int change;
    string companyname;

    void notebook() //shows default stock
    {
        int a;

        cout << "company name:classmate" << endl;
        cout << "available in stock:" << available << "dozen" << endl;
        cout << "rate per dozen:" << rateperdoz << endl;
        cout << "rate per unit:" << rateperunit << endl;
        cout << "DO YOU WANT TO MAKE ANY CHANGES IN THE STOCK?......if no then press 1 and if yes then press 2:" << endl;
        cin >> a;
        system("CLS");
        if (a == 2) //changes nd displaaying chnged stock
        {

            cout << "Enter the value in dozen you want to add in the stock:" << endl;
            cin >> change;
            temp = available + change;
            cout << "The updated stock is as follows:" << endl;
            cout << "company name:classmate" << endl;
            cout << "available in stock:***" << temp << "***dozen" << endl;
            cout << "rate per dozen:300" << endl;
            cout << "rate per unit:50" << endl;
            available = temp;
            ofstream debug("logsheet.txt", ios::app);
            debug << "stock added:" << change << endl;
            debug << "total stock:" << temp << endl;
            debug << "billing done remaining stock:" << temp2 << endl;
            debug << "............................." << endl;
        }
        else //if dont want to change stock.
        {
            cout << "##################################### Thankyou #################################################################" << endl;
        }
    }
};

class billing : public stockentry
{
public:
    void insert() //if first selecting billing or selecting billing without doing changes in stock.
    {
        cout << "Enter purchased value in dozens:" << endl;
        cin >> doz;
        tempdoz = doz;
        temp2 = available - doz;
        amount = rateperdoz * doz;
        cout << "The purchase amount=" << rateperdoz * doz << endl;
        cout << "remaining stock=" << temp2 << "dozens" << endl;
        available = temp2;
        tempamount = amount;
        amount = 0;
        count = tempamount + count;
        ofstream debug("logsheet.txt", ios::app);
        debug << "After  Billing:" << temp2 << " doz" << endl;
        cout << "........................................................................................................................" << endl;
    }
};

class change : public billing
{
public:
    void notebookchange() //shows stock after billing.
    {
        cout << "company name:------------------------------------------------------------------------------------>classmate" << endl;
        cout << "available in stock:------------------------------------------------------------------------------>" << temp2 << "dozen" << endl;
        cout << "rate per dozen:---------------------------------------------------------------------------------->" << rateperdoz << endl;
        cout << "rate per unit:----------------------------------------------------------------------------------->" << rateperunit << endl;
    }
};
int main()
{
    int a;
    a = passwords();
    if (!a)
    {
        for (int i = 0; i < 2; i++)
        {
            cout << "\nWrong password try once more\a\n";
            if (passwords())
            {
                goto last;
            }
            else
            {
                cout << "\n\n\t\t\t all attempts failed.....";
                cout << "\n\n\n\t\t\t see you..................\a ";
                exit(0);
            }
        }
        cout << "\t\t\t sorry all attempts failed............. \n\a \t\t\tinactive";
    }
    else
    {
    last:;

        int b;
        int c;
        cout << "login successfull...........";
        system("PAUSE");
        system("CLS");
    f:
        cout << "##################################################################" << endl;
        cout << "#                  stock management and billing               #" << endl;
        cout << "##################################################################" << endl;
        ;
        cout << "What you want to do?" << endl;
        cout << "1.\tTo fetch bill\n2.\tTo view stock\n3.\tExit\n";
        cout << "\n\nEnter your option: ";
        cin >> b;
        system("CLS");
        if (b == 2)

        {
            cout << "###############################################################################################################################"
                 << endl;
            cout << "#...................................................... STOCK ................................................................#" << endl;
            cout << "###############################################################################################################################"
                 << endl;
            stockentry s;
            s.notebook();

            int b;
            cout << "  press 1 to billing else press 2 to stock or press any key to exit" << endl;
            cin >> b;
            cout << "...................................................................................................." << endl;
            if (b == 1)
            {
                goto here;
            }
            else if (b == 2)
            {
                cout << "###############################################################################################################################"
                     << endl;
                cout << "#...................................................... STOCK ..................................................................#" << endl;
                cout << "###############################################################################################################################"
                     << endl;
                change c;
                c.notebookchange();
            }
            else
            {
                cout << "::::::::::::::::::::::::::::::::::::::: THANKS ::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
                system("CLS");
                goto here;
            }
        }
        else if (b == 1)
        {
        here:
            cout << "###############################################################################################################################"
                 << endl;
            cout << "#...................................................... Billing ..................................................................#" << endl;
            cout << "###############################################################################################################################"
                 << endl;

            billing r;

            r.insert();
            int x;
            cout << "press 1 to continue for other bill or press 2 key to check stock and press any key to exit." << endl;
            cin >> x;
            if (x == 1)
            {
                goto here;
            }
            else if (x == 2)
            {
                stockentry s;
                s.notebook();
                goto here;
            }
            else
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ RECEIPT @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

            {

                receiptinsert();
                system("CLS");
                system("PAUSE");
                receiptgeneration();
            }
            cout << "Press 1 if you want to continue  in the software or press any key to exit application" << endl;
            int f;
            cin >> f;
            if (f == 1)
            {
                goto f;
            }
            else
            {
                cout << "Thankyou for shopping\a" << endl;
            }
        }

        else
        {
            cout << "INVALID CHOICE" << endl;
            cout << "\a" << endl;
        }

        return 0;
    }
}
