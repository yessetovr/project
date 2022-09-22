//
//  main.cpp
//  project
//
//  Created by Райымбек Есетов on 18.09.2022.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
//#include <cstdio>

using namespace std;

//bool gameOver;
map <string, int> call_counts;
void call_me_one()
{
    call_counts[__PRETTY_FUNCTION__] += 1;
}
void info();
int dice();
void position();
//int callMe()
//{
//    static int count = 0;
//    cout<<++count<<endl;
//    return 0;
//};
//enum eDirection {STOP = 0};
//eDirection check;
//
//void Setup() {
//    gameOver = false;
//    check = STOP;
//}

struct places {
    string name;
    int price;
    int number;
    int owner;
    int toll;
    string color;
};

struct player {
    int money;
    int position;
    string namePlaces;
    string colors;
    int counter;
    int numberPlaces[];
};

player me[ 10 ];
player fr[ 10 ];
places world[ 8 ];


void info()
{
    me[ 0 ].money = 2000000000;
    //    if (me.money <= 0)
    //        gameOver = true;
    me[ 0 ].position = 0;
    me[ 0 ].namePlaces = "";
    me[ 0 ].counter = 0;
    
    fr[ 0 ].money = 2000000000;
    fr[ 0 ].position = 0;
    fr[ 0 ].namePlaces = "";
    fr[ 0 ].counter = 0;
    
    world[ 0 ].name = "start";
    world[ 0 ].number = 0;
    world[ 0 ].owner = 0;
    
    world[ 1 ].name = "Almaty ";
    world[ 1 ].number = 1;
    world[ 1 ].owner = 0;
    world[ 1 ].price = 650000000;
    world[ 1 ].toll = 3250000;
    world[ 1 ].color = "Red ";
    
    world[ 2 ].name = "Paris ";
    world[ 2 ].number = 2;
    world[ 2 ].owner = 0;
    world[ 2 ].price = 750000000;
    world[ 2 ].toll = 3750000;
    world[ 2 ].color = "Yellow ";
    
    world[ 3 ].name = "New-York ";
    world[ 3 ].number = 3;
    world[ 3 ].owner = 0;
    world[ 3 ].price = 600000000;
    world[ 3 ].toll = 3000000;
    world[ 3 ].color = "Blue ";
    
    world[ 4 ].name = "Moscow ";
    world[ 4 ].number = 4;
    world[ 4 ].owner = 0;
    world[ 4 ].price = 500000000;
    world[ 4 ].toll = 2500000;
    world[ 4 ].color = "Red ";
    
    world[ 5 ].name = "Tokyo ";
    world[ 5 ].number = 5;
    world[ 5 ].owner = 0;
    world[ 5 ].price = 800000000;
    world[ 5 ].toll = 4000000;
    world[ 5 ].color = "Yellow ";
    
    world[ 6 ].name = "Prison ";
    
    world[ 7 ].name = "London ";
    world[ 7 ].number = 7;
    world[ 7 ].owner = 0;
    world[ 7 ].price = 900000000;
    world[ 7 ].toll = 4500000;
    world[ 7 ].color = "Blue ";
}

int dice()
{
    int roll;
    
    roll = (rand() % 6) + 1;
    
    cout<<"You will move "<< roll <<" block(s)" <<endl;
    
    call_me_one();
    
    return roll;
}

void show_money()
{
    cout<< "(P1)You have "<< me[ 0 ].money <<endl;
}

void show_money2()
{
    cout<< "(P2)You have "<< fr[ 0 ].money <<endl;
}

void my_places()
{
    cout<< "(P1)My Places: "<< me[ 0 ].namePlaces <<endl;
}

void my_places2()
{
    cout<< "(P2)My Places: "<< fr[ 0 ].namePlaces <<endl;
}

void my_colors()
{
    cout<< "(P1)My Colors:"<< me[ 0 ].colors <<endl;
}

void my_colors2()
{
    cout<< "(P2)My Colors:"<< fr[ 0 ].colors <<endl;
}

//void test()
//{
//
//}

void position()
{
    int choose;
    int n = me[ 0 ].position;
    int m = fr[ 0 ].position;
    
    
    cout<< "(P1)You are at "<< world[ n ].name << '\n' << "Color: " << world[ n ].color << '\n' << "Price: " << world [ n ].price << '\n';

    if( me[ 0 ].position != 0 && world[ n ].owner == 0 && world[ m ].owner == 0)
    {
        cout<< "1.Buy\n";
        cout<< "2.Dont buy\n";
        cin>> choose;
        
        switch(choose)
        {
            case 1:
                if(me[ 0 ].colors == world[ n ].color)
                {
                    me[ 0 ].money += 500000000;
                    cout << "(P1)You have collected all the places of the same color!\n+500000000\n";
                }
                me[ 0 ].money -= world[ n ].price;
                world[ n ].owner = 1;
                me[ 0 ].namePlaces += world[ n ].name;
                me[ 0 ].colors += world[ n ].color;
                me[ 0 ].counter++;
                
                cout << "(P1)Congrats, you bought this place\n";
            case 2:
                cout<< "(P1)Okey, you can move on\n##################\n##################\n";
//            default:
//                cout <<"Error, bad input, quitting\n";
//                break;
        }
    }
    
    
    
    else if( me[ 0 ].position != 0 && world[ n ].owner != 0)
    {
        cout<< "(P1)You paid " << world[ n ].toll << " as toll\n";
    }
    
}

void position2()
{
    int choose2;
    int n = me[ 0 ].position;
    int m = fr[ 0 ].position;
    
    
    cout<< "(P2)You are at "<< world[ m ].name << '\n' << "Color: " << world[ m ].color << '\n' << "Price: " << world [ m ].price << '\n';

    if( fr[ 0 ].position != 0 && world[ m ].owner == 0 && world[ n ].owner == 0)
    {
        cout<< "1.Buy\n";
        cout<< "2.Dont buy\n";
        cin>> choose2;
        
        switch(choose2)
        {
            case 1:
                if(fr[ 0 ].colors == world[ m ].color)
                {
                    fr[ 0 ].money += 500000000;
                    cout << "(P2)You have collected all the places of the same color!\n+500000000\n";
                }
                fr[ 0 ].money -= world[ m ].price;
                world[ m ].owner = 1;
                fr[ 0 ].namePlaces += world[ m ].name;
                fr[ 0 ].colors += world[ m ].color;
                fr[ 0 ].counter++;
                
                cout << "(P2)Congrats, you bought this place\n";
            case 2:
                cout<< "(P2)Okey, you can move on\n##################\n##################\n";
//            default:
//                cout <<"Error, bad input, quitting\n";
//                break;
        }
    }
    
    
    
    else if( fr[ 0 ].position != 0 && world[ m ].owner != 0)
    {
        cout<< "(P2)You paid " << world[ m ].toll << " as toll\n";
    }
    
}

int main()
{
    info();
    
    
    
    srand( (unsigned int) time(NULL) );
    
    do
    {
        int x;
        x = dice();
        
        //        for (auto it = call_counts.begin(); it != call_counts.end(); ++it)
        //                cout << (*it).first << " was being called "
        //                    << (*it).second << " times.\n";
        
        for( auto it = call_counts.begin(); it != call_counts.end(); ++it)
        {
            if( (*it).second % 2 == 1)
            {
                show_money();
                
                my_places();
                
                my_colors();
                
                //                test();
                
                me[ 0 ].position += x;
                
                if( me[     0 ].position == 6)
                {
                    cout << "(P1)You are in Prison! You miss 1 step.\n";
                }
                
                if( me[ 0 ].position >= 8)
                {
                    me[ 0 ].position -= 8;
                    me[ 0 ].money += 500000;
                }
                
                position();
            }
            else
                show_money2();
                
                my_places2();
                
                my_colors2();
                
                //                test();
                
                fr[ 0 ].position += x;
                
                if( fr[ 0 ].position == 6)
                {
                    cout << "(P2)You are in Prison! You miss 1 step.\n";
                }
                
                if( fr[ 0 ].position >= 8)
                {
                    fr[ 0 ].position -= 8;
                    fr[ 0 ].money += 500000;
                }
                
                position();
        }
    } while( me[ 0 ].money || fr[ 0 ].money >= 0);
            cout << "Game Over:(\n";
            return 0;
}
