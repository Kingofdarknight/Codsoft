#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    
    int sp, number_range , real_number , guess_number , guess_count=0;
    start:
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"----------------- WELCOME TO THE GAME ------------------------"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<" Choose your option ----> "<<"\n"<<endl;
    cout<<"1. play the game  (Enter  1) "<<endl;
    cout<<"2. See the last Game Score (Enter 2) "<<endl;
    cout<<"3. Exit from the Game  (Enter 3)"<<endl;
    cout<<"Enter Your Option : ";
    cin>>sp;
    switch(sp)
    {
        case 1:
            cout<<"\n"<<"Let's Start the Game..."<<"\n"<<endl;
            goto play;
            break;
        case 2:
            if(guess_count == 0)
            {
                cout<<"\n"<<"You haven't played the game once yet..."<<"\n"<<endl;
            }
            else if(guess_count == 1)
            {
                cout<<"\n"<<"In the Last Game, you won the game in "<<guess_count<<"st Try...!"<<"\n"<<endl;
            }
            else
            {
                cout<<"\n"<<"In the Last Game, you won the game in "<<guess_count<<" Tries..."<<"\n"<<endl;
            }
            goto start;
            break;
        case 3:
            cout<<"\n"<<"Thanks for Playing the Game...!"<<"\n"<<endl;
            exit(0);
            break;
        default:
            cout<<"\n"<<"Invalid Option Choice... Please Try Again..."<<"\n"<<endl;
            goto start;
            break;
    }
    play:
    guess_count=1;
    cout<<"\n"<<"Enter what would you like the range of the number to be : ";
    cin>>number_range;
    srand(time(0));
    real_number = rand() % (number_range);
    do
    {
        cout<<"\n"<<"Enter your guess number : ";
        cin>>guess_number;
        if(guess_number > real_number)
        {
            guess_count += 1;
            cout<<"The number is lower than you guess...";
        }
        else if(guess_number < real_number)
        {
            guess_count += 1;
            cout<<"The number is higher than you guess...";
        }
        else
        {
            cout<<"\n"<<"Great.! You guessed the correct number...!!!";
            if(guess_count == 1)
            {
                cout<<"\n"<<"You guessed the number in "<< guess_count <<"st Try.!!!"<<"\n"<<endl;
            }
            else
            {
                cout<<"\n"<<"You guessed the number in "<< guess_count <<" Tries...!"<<"\n"<<endl;
            }
            goto start;
        }
    }
    while(guess_number != real_number);

    return 0;
}