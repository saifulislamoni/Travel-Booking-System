#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Customer
{
private:
    string name;
    string email;
    string phone;
    string password;

public:
    Customer(){}

    Customer(string _name, string _email, string _phone, string _password)
    {
        name = _name;
        email = _email;
        phone = _phone;
        password = _password;
    }
};

class Package
{
private:
    string place;
    int days;
    string hotelType;
    string transport;
    int costPerDay;

public:
    Package(){}

    Package(string _place, int _days, string _hotelType, string _transport, int _costPerDay)
    {
        place = _place;
        days = _days;
        hotelType = _hotelType;
        transport = _transport;
        costPerDay = _costPerDay;
    }

    int calculateCost(int numOfPersons)
    {
        return numOfPersons * days * costPerDay;
    }

    void Offer_package_1()
    {
        cout<<"-------------- Cox's Bazar Tour --------------"<<endl;
        cout<<"Tittle \t\t: Cox's Bazar couple Tour "<<endl;
        cout<<"Duration \t: 3 days"<<endl;
        cout<<"Hotel Type \t: 5 Star"<<endl;
        cout<<"Transport Type \t: AC  Bus"<<endl;
        cout<<"Cost \t\t: 15000"<<endl;

        Package("Cox's Bazar", 3, "5 Star","AC Bus", 2500);
        calculateCost(2);
    }

    void Offer_package_2()
    {
        cout<<"-------------- Saint Martin Tour --------------"<<endl;
        cout<<"Tittle \t\t: Saint Martin couple Tour "<<endl;
        cout<<"Duration \t: 3 days"<<endl;
        cout<<"Hotel Type \t: 5 Star"<<endl;
        cout<<"Transport Type \t: AC  Bus & Premium Ship"<<endl;
        cout<<"Cost \t\t: 18000"<<endl;

        Package("Cox's Bazar", 3, "5 Star","AC Bus", 3000);
        calculateCost(2);
    }




    void displayReceipt(int totalCost, int numOfPersons) {
        cout << "--------------- Receipt ---------------" << endl;
        cout << "Place: " << place << endl;
        cout << "Days: " << days << endl;
        cout << "Hotel Type: " << hotelType << endl;
        cout << "Transport: " << transport << endl;
        cout << "Number of Persons: " << numOfPersons << endl;
        cout << "Total Cost: " << totalCost << " taka" << endl;
        cout << "---------------Thank you---------------" << endl;
    }
};

void signup()
{
    string name, email, phone, password;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter password: ";
    getline(cin, password);

    ofstream file("customers.txt", ios::app);
    file <<email  << " + " << password << "\n" << name << "," << phone<<"\n"<<"--------------------" << endl;
    file.close();
}

bool login()
{
    string email, password;
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);

    string C_loginInfo = email+" + "+password;

    ifstream fin("customers.txt");
    string StoredInfo;



    while (getline(fin, StoredInfo))
    {
        if (C_loginInfo == StoredInfo)
        {
            fin.close();
            return true;
        }
    }

    fin.close(); // Close the file after reading
    return false;
}

int main()
{
    Customer customer;
    Package package;
    bool loggedIn = false;
    char choice;

    do
    {
        cout << "Welcome to Travel Management System" << endl<<endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            loggedIn = login();
            if (loggedIn)
            {
                system("cls");
                cout << "Login Successful!" << endl;
            }
            else
            {
                system("cls");
                cout << "Login Failed. Invalid email/password." << endl;
                cout << "---------------Try Again---------------" << endl<<endl<<endl;
            }
            break;
        case '2':
            signup();
            system("cls");
            cout << "Signup Successful!" << endl;
            break;
        case '3':
            system("cls");
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != '3' && !loggedIn);

    if (loggedIn)
    {
        cout<<endl<<"Which Package do you want to book now?"<<endl<<endl;
        cout<<"1.   Current Offer!"<<endl;
        cout<<"2.   Custom made Package"<<endl<<endl;

        char opt;
        cout<<"Enter your Choice: ";
        cin>>opt;

        switch(opt)
        {
        case '1':
            system("cls");
            cout<<"Here are the available Offers! "<<endl;
            cout<<"1. Cox's Bazar Tour"<<endl;
            cout<<"2. Saint Martin Tour"<<endl<<endl;

            int opt2;
            cout<<"Enter your Choice: ";
            cin>>opt2 ;
            if(opt2==1)
            {
                system("cls");
                package.Offer_package_1();

                cout<<"Do you want to book Now?"<<endl<<endl;
                cout<<"press Y for yes & N for no!"<<endl;

                char opt3;
                cin>>opt3;
                if(opt3=='Y'||opt3=='y')
                {
                    system("cls");
                    cout<<endl<<"You have successfully booked the package!"<<endl;
                    cout << "---------------Thank you---------------" << endl;
                }
                if(opt3=='N'||opt3=='n')
                {
                    system("cls");
                    cout<<endl<<"You booking has been disrupted successfully!"<<endl;
                    cout << "---------------Thank you---------------" << endl;
                }
            }
            else if(opt2==2)
            {
                system("cls");
                package.Offer_package_2();
                cout<<"Do you want to book Now?"<<endl<<endl;
                cout<<"press Y for yes & N for no!"<<endl;

                char opt3;
                cin>>opt3;
                if(opt3=='Y'||opt3=='y')
                {
                    system("cls");
                    cout<<endl<<"You have successfully booked the package!"<<endl;
                    cout << "---------------Thank you---------------" << endl;
                }
                if(opt3=='N'||opt3=='n')
                {
                    system("cls");
                    cout<<endl<<"You booking has been disrupted successfully!"<<endl;
                    cout << "---------------Thank you---------------" << endl;
                }
            }
            break;
        case '2':
            system("cls");

            int place,days,H_type,T_type, person;

            cout<<"Please enter the following info: "<<endl<<endl;
            cout<<"1. Which place do you want to visit? "<<endl;

            cout<<"A. Cox's Bazar or"<<endl;
            cout<<"B.Saint Martin Tour"<<endl<<endl;
            cout<<"Enter your choise: (1/2)"<<endl;

            cin>>place;

            cout<<"How many days do want to stay?"<<endl<<endl;
            cin>>days;

            cout<<"Which type Hotel do you want?"<<endl;
            cout<<"1. 5 Star"<<endl;
            cout<<"2. 3 Star"<<endl;
            cout<<"2. 2 Star"<<endl;
            cout<<"Enter your choise: (1/2/3)"<<endl;
            cin>>H_type;

            cout<<"Which type of transportation do you need? "<<endl;
            cout<<"1. AC Bus & Premium ship"<<endl;
            cout<<"2. Non-AC bus & Normal ship"<<endl;
            cout<<"Enter your choise: (1/2)"<<endl;
            cin>>T_type;

            cout<<"How many person do you want to travel? "<<endl;
            cin>>person;



            if(place==1 && H_type==1 && T_type==1)
            {
                Package Package1("Cox's Bazar", days, "5 Star", "AC Bus", 2550);
                int totalPrice= Package1.calculateCost(person);
                Package1.displayReceipt(totalPrice,person);
            }

            else if(place==1 && H_type==1 && T_type==2)
            {
               Package Package2("Cox's Bazar", days, "5 Star", "Non-AC Bus", 2150);
               int totalPrice= Package2.calculateCost(person);
                Package2.displayReceipt(totalPrice,person);
            }

            else if(place==1 && H_type==2 && T_type==1)
            {
                Package Package3("Cox's Bazar", days, "3 Star", "AC Bus ", 2150);
                int totalPrice= Package3.calculateCost(person);
                Package3.displayReceipt(totalPrice,person);
            }

            else if(place==1 && H_type==2 && T_type==2)
            {
                Package Package4("Cox's Bazar", days, "3 Star", "Non-AC Bus", 2150);
                int totalPrice= Package4.calculateCost(person);
                Package4.displayReceipt(totalPrice,person);
            }

            else if(place==1 && H_type==3 && T_type==1)
            {
                Package Package5("Cox's Bazar", days, "2 Star", "AC Bus", 1950);
                int totalPrice= Package5.calculateCost(person);
                Package5.displayReceipt(totalPrice,person);
            }

            else if(place==1 && H_type==3 && T_type==2)
            {
                Package Package6("Cox's Bazar", days, "2 Star", "Non-AC Bus", 1850);
                int totalPrice= Package6.calculateCost(person);
                Package6.displayReceipt(totalPrice,person);
            }


            //-----------------------------Saint Martin---------------------------------------------//

            if(place==2 && H_type==1 && T_type==1)
            {
                Package Package7("Saint Martin", days, "5 Star", "AC Bus & Premium ship", 3550);
                int totalPrice= Package7.calculateCost(person);
                Package7.displayReceipt(totalPrice,person);
            }

            else if(place==2 && H_type==1 && T_type==2)
            {
                Package Package8("Saint Martin", days, "5 Star", "Non-AC Bus & Normal ship", 3150);
                int totalPrice= Package8.calculateCost(person);
                Package8.displayReceipt(totalPrice,person);
            }

            else if(place==2 && H_type==2 && T_type==1)
            {
                Package Package9("Saint Martin", days, "3 Star", "AC Bus & Premium ship", 3150);
                int totalPrice= Package9.calculateCost(person);
                Package9.displayReceipt(totalPrice,person);
            }

            else if(place==2 && H_type==2 && T_type==2)
            {
                Package Package10("Saint Martin", days, "3 Star", "Non-AC Bus & Normal ship", 3150);
                int totalPrice= Package10.calculateCost(person);
                Package10.displayReceipt(totalPrice,person);
            }

            else if(place==2 && H_type==3 && T_type==1)
            {
                Package Package11("Saint Martin", days, "2 Star", "AC Bus & Premium ship", 2950);
                int totalPrice= Package11.calculateCost(person);
                Package11.displayReceipt(totalPrice,person);
            }

            else if(place==2 && H_type==3 && T_type==2)
            {
                Package Package12("Saint Martin", days, "2 Star", "Non-AC Bus & Normal ship", 2850);
                int totalPrice= Package12.calculateCost(person);
                Package12.displayReceipt(totalPrice,person);
            }

            break;

        }
    }

    return 0;
}
