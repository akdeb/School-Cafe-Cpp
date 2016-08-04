//
//  main.cpp
//  Canteen
//
//  Created by Akashdeep Deb on 12/17/14.
//  Copyright (c) 2014 Akashdeep Deb. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

char lusername[30];
char lpass[30];

//_________________________________________________

int login();
int signup();
int menu();

int daily();
int update();
int food_menu();
int paypal();
int bmi();
int suggest();
int logout();

// ^ ^ ^ Put all program function declarations ^ ^ ^



//_____________________________________________________________
// This is the user class which has all the details of the user
//_____________________________________________________________


class user
{
    int age;
    char email_id[30];
    char gender;
    
    public :
    
    int height;
    int weight;
    float BMI;
    int transact;
    int input();
    int output();
    char username[30];
    char pass[30];
};

user u;


//*****************************
// CLASS USER public FUNCTIONS
//*****************************


//______________________________________________________
// This is the input function which accepts user details
//______________________________________________________

int user :: input()
{
    cout << "\nUsername (without spaces): ";
    cin >> username;
    cout << "Password (without spaces) : ";
    cin >> pass;
    cout << "Age: ";
    cin >> age;
    cout << "Gender (M/F/_): ";
    cin >> gender;
    cout << "Email ID: ";
    cin >> email_id;
    cout << "Height: ";
    cin >> height;
    cout << "Weight: ";
    cin >> weight;
    return 0;
}

//______________________________________________________
// This is the output function which shows user  details
//______________________________________________________

int user :: output()
{
    cout << "\nUsername: " << username << endl;
    cout << "Password: " << pass << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Email ID: " << email_id << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
    return 0;
}

//______________________________________________________________
// This is the admin class which has all the details of the food
//______________________________________________________________


class food
{
    char description[40];
    public :
    
    char name[20];
    int ID;
    int calorie;
    int price;
    
    int food_input();
    int food_output();
};

food f;

//*****************************
// CLASS FOOD public FUNCTIONS
//*****************************

//_________________________________
// This is the food output function
//_________________________________


int food :: food_output()
{
    cout << "\nID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "kcal: " << calorie << endl;
    cout << "Price: " << price << endl;
    cout << "Description: " << description << "\n\t_____________________________" << endl;
    return 0;
}

//________________________________
// This is the food input function
//________________________________

int food :: food_input()
{
    cout << "ID: ";
    cin >> ID;                    //starts from 1
    cout << "Name: ";
    cin >> name;
    cout << "kcal: ";
    cin >> calorie;
    cout << "Price: ";
    cin >> price;
    cout << "Description: ";
    cin >> description;
    cout << endl << endl;
    return 0;
}

//_____________
//MAIN FUNCTION
//_____________

int main()
{
    // insert code here...
    cout << "\n";
    cout << "*****************************************************************************************************************\n";
    cout << "Hello, World! Welcome to the Canteen Database - Foody, where we help you start living Healthy and prevent Obesity\n";
    cout << "*****************************************************************************************************************\n";
    
    cout << "\n\"Our goal, here at Foody, is to get you the best and the healthiest food for the cheapest prices. We are a committed bunch and we want the best for you.\" - CEO, Co-founder, Akashdeep Deb\n\n";
    
    cout << "\nStart your  wonderful journey with us by logging in.\n";
    
    login();
    
    return 0;
}

//__________________________________________________
// This is the main menu page for the entire program
//__________________________________________________

int daily();
int update();
int food_menu();
int paypal();
int bmi();
int suggest();

int menu()
{
    system("clear");
    int option;
    cout << "\t\t######################" << endl;
    cout << "\t\t#       Welcome!     #" << endl;
    cout << "\t\t######################" << endl << endl;
    cout << "\n\t1. Today's Foody Special!" << endl;
    cout << "\t_________________________" << endl;
    cout << "\t2. Update my details" << endl;
    cout << "\t____________________" << endl;
    cout << "\t3. Show today's menu of Foody items!" << endl;;
    cout << "\t____________________________________" << endl;;
    cout << "\t4. Order canteen food online and make your transaction!" << endl;
    cout << "\t_______________________________________________________" << endl;
    cout << "\t5. Caclulate my BMI" << endl;
    cout << "\t___________________" << endl;
    cout << "\t6. Suggest me some healthy, good food" << endl;
    cout << "\t_____________________________________" << endl;
    cout << "\t7. Logout" << endl;
    cout << "\t_________" << endl;
    cout << "\nWhere would you like to go (1-7)? --> ";
    cin >> option;
    
    switch (option)
    {
        case 1 : daily();
            break;
        case 2 : update();
            break;
        case 3 : food_menu();
            break;
        case 4 : paypal();
            break;
        case 5 : bmi();
            break;
        case 6 : suggest();
            break;
        case 7 : logout();
            break;
        default : cout << "Enter a number form 1-7";
    }
    return 0;
}


//__________________________________________________
// This is the signup function if login unsuccessful
//__________________________________________________

int signup()
{
    system("clear");
    cout << "Don't have an account? Make one now! We're delighted to have you onboard with us.\n ";
    ofstream o1;
    o1.open("Student.dat", ios::binary | ios::app);
    u.input();
    o1.write((char*)&u, sizeof(u));
    o1.close();
    menu();
    return 0;
}

//________________________
//function to logout
//________________________

int logout()
{
    main();
    return 0;
}

//________________________
//function caluclating bmi
//________________________

int bmi()
{
    float bmih, bmiw;
    int return_choice;
    system("clear");
    ifstream i5;
    i5.open("Student.dat", ios::binary);
    cout << "Enter your height (in m) : ";
    cin >> bmih;
    cout << "Enter your weight (in kilos) : ";
    cin >> bmiw;
    cout << "Your Body Mass index: " << bmiw/pow(bmih, 2);
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
        menu();
    return 0;
}

//________________________
//function suggesting food
//________________________

int suggest()
{
    int buy;
    int calorie_in;
    int return_choice;
    system("clear");
    ifstream i6;
    i6.open("Foodstuff.dat", ios::binary);
    cout << "\nWhat's your calorie intake? ";
    cin >> calorie_in;
    cout << "\nThese are some healthy suggestions: " << endl;
    while(i6.read((char*)&f, sizeof(f)))
    {
        if(calorie_in > f.calorie)
        {
            f.food_output();
        }
    }
    i6.close();
    cout << "/nWant to buy something?(1/0) ";
    cin >> buy;
    if(buy == 1)
        paypal();
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
        menu();

    return 0;
}

//________________________________
//function performing transactions
//________________________________

int paypal()
{
    int return_choice;
    int ID_num;
    system("clear");
    cout << "\nEnter the ID number of what you want to buy: ";
    cin >> ID_num;
    ifstream i4;
    i4.open("Foodstuff.dat", ios::binary);
    cout << "You have bought 1: ";
    while(i4.read((char*)&f, sizeof(f)))
    {
        u.transact = 0;
        if(ID_num == f.ID)
        {
            f.food_output();
            u.transact ++;
            break;
        }
    }
    i4.close();
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
        menu();
    return 0;
}

//__________________________
//update data values of user
//__________________________

int update()
{
    system("clear");
    int return_choice;
    ifstream i3;
    ofstream o5;
    i3.open("Student.dat", ios::binary);
    o5.open("Student.dat", ios::binary | ios::app);
    while(i3.read((char*)&u, sizeof(u)))
    {
        if (strcmp (u.username, lusername) == 0 && strcmp (u.pass, lpass) == 0)
        {
            u.input();
            o5.write((char*)&u, sizeof(u));
        }
    }
    o5.close();
    i3.close();
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
        menu();
    return 0;
}

//_____________________________
//function providing daily spec
//_____________________________

int daily()
{
    system("clear");
    int return_choice;
    cout << "Today's special is: " << endl;
    ifstream i4;
    i4.open("Foodstuff.dat", ios::binary);
    while(i4.read((char*)&f, sizeof(f)))
    {
        if(f.ID == 26)
        f.food_output();
    }
    i4.close();
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
        menu();
    return 0;
}

//__________________________________________________________________________
//This is the food menu function which outputs the menu from the binary file
//__________________________________________________________________________

int food_menu()
{
    system("clear");
    int return_choice;
    ifstream i1;
    i1.open("Foodstuff.dat", ios::binary);
    while(i1.read((char*)&f, sizeof(f)))
    {
        f.food_output();
    }
    i1.close();
    cout << "\nExit? (1/0) ";
    cin >> return_choice;
    if(return_choice == 1)
    menu();
    return 0;
}

//__________________________________________________
// This is the login function at beginning for login
//__________________________________________________

int login()
{
    int choice, ychoice, flag = 0;
    
    try_again :
    
    cout << "_______________________________________________________________\n";
    cout << "\nUsername: "; cin >> lusername;
    cout << "Password: "; cin >> lpass;
    cout << "_______________________________________________________________\n";
    
    if(strcmp (lusername, "admin") == 0 && strcmp (lpass, "admin") == 0) //for the admin to enter some new data
    {
        int return_choice;
        system("clear");
        cout << "1. Enter more food items." << endl;
        cout << "2. Enter more users. " << endl;
        cout << "3. Want to see the users now? " << endl;
        cout << "4. Want to go into your account? " << endl << endl;
        cout << "Hello admin; what do you want to do first? (1-4): ";
        cin >> ychoice;
        cout << endl;
        switch (ychoice)
        {
            case 1 :
                
            {
                ofstream o2;
                o2.open("Foodstuff.dat", ios::binary | ios::app);
                cout << "Hi Akashdeep, you are now entering the food stuff and menu. Enter 11 things.\n\n";
                for(int i = 0; i<11; ++i)
                {
                    f.food_input(); //the order of entry is ID, food name, calorie, price, description
                    o2.write((char*)&f, sizeof(f));
                }
                o2.close();
            }
                break;
            
            case 2 :
            {
                ofstream o3;
                o3.open("Student.dat", ios::binary | ios::app);
                cout << "Hi Akashdeep, you are now entering the user entry. Enter 5 names.\n\n";
                for(int j = 0; j < 5; ++j)
                {
                    u.input();
                    o3.write((char*)&u, sizeof(u));
                }
                o3.close();
            }
                break;
                
            case 3 :
            
            {
                ifstream i1;
                i1.open("Student.dat", ios::binary);
                while(i1.read((char*)&u, sizeof(u)))
                {
                    u.output();
                    cout << endl;
                }
                i1.close();
            }
                break;
              
            case 4 : menu();
                break;
            
        }
        cout << "\nExit? (1/0) ";
        cin >> return_choice;
        if(return_choice == 1)
            main();
    }

    ifstream i2;
    i2.open("Student.dat", ios::binary);
    while(i2.read((char*)&u, sizeof(u)))
    {
        if (strcmp (u.username, lusername) == 0 && strcmp (u.pass, lpass) == 0) //not working when accesor is present; now it is public.
        {
            flag = 1;
            menu();
            break;
        }
    }
    
    if (flag == 0)
    {
        choice_only :
        cout << "Oops! There was an error." << endl;
        cout << "\n1. Try again. or" << endl;
        cout << "2. Sign up with Foody today. " << endl;
        cout << "\nChoose one option: ";
        cin >> choice;
        if(choice == 1)
            goto try_again;
        else if (choice == 2)
        {
            signup();
        }
        else
        {
            cout << "\n Please enter 1 or 2 only";
            goto choice_only;
        }
    }
    return 0;
}
