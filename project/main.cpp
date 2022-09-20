//
//  main.cpp
//  project
//
//  Created by Райымбек Есетов on 18.09.2022.
//

#include <iostream>
#include <string>
//#include <cstdio>

using namespace std;

//bool gameOver;
void info();
int dice();
void position();
//enum eDirection {STOP = 0};
//eDirection check;

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
};

player me;
places world[ 8 ];


void info()
{
    me.money = 2000000000;
//    if (me.money <= 0)
//        gameOver = true;
    me.position = 0;
    
    world[ 0 ].name = "start";
    world[ 0 ].number = 0;
    world[ 0 ].owner = 0;
    world[ 0 ].price = 0;
    world[ 0 ].toll = 0;
    
    world[ 1 ].name = "Almaty";
    world[ 1 ].number = 1;
    world[ 1 ].owner = 0;
    world[ 1 ].price = 650000000;
    world[ 1 ].toll = 3250000;
    world[ 1 ].color = "Red";
    
    world[ 2 ].name = "Paris";
    world[ 2 ].number = 2;
    world[ 2 ].owner = 0;
    world[ 2 ].price = 750000000;
    world[ 2 ].toll = 3750000;
    world[ 2 ].color = "Yellow";
    
    world[ 3 ].name = "New-York";
    world[ 3 ].number = 3;
    world[ 3 ].owner = 0;
    world[ 3 ].price = 600000000;
    world[ 3 ].toll = 3000000;
    world[ 3 ].color = "Blue";
    
    world[ 4 ].name = "Moscow";
    world[ 4 ].number = 4;
    world[ 4 ].owner = 0;
    world[ 4 ].price = 500000000;
    world[ 4 ].toll = 2500000;
    world[ 4 ].color = "Red";
    
    world[ 5 ].name = "Tokyo";
    world[ 5 ].number = 5;
    world[ 5 ].owner = 0;
    world[ 5 ].price = 800000000;
    world[ 5 ].toll = 4000000;
    world[ 5 ].color = "Yellow";
    
    world[ 6 ].name = "Madrid";
    world[ 6 ].number = 7;
    world[ 6 ].owner = 0;
    world[ 6 ].price = 900000000;
    world[ 6 ].toll = 4500000;
    world[ 6 ].color = "Blue";
    
    world[ 7 ].name = "London";
    world[ 7 ].number = 6;
    world[ 7 ].owner = 0;
    world[ 7 ].price = 1000000000;
    world[ 7 ].toll = 50000000;
    world[ 7 ].color = "Black";
}

int dice()
{
    int roll;
    
    roll= (rand()%6) + 1;
    
    cout<<"You will move "<< roll <<" block(s)"<<endl;
    
    return roll;
}

void show_money()
{
    cout<<"You have "<< me.money <<endl;
}

void position()
{
    int choose;
    int n = me.position;
    
    cout<< "You are at "<< world[ n ].name << '\n' << "Color: " << world[ n ].color << '\n' << "Price: " << world [ n ].price << '\n';
    
    if( me.position != 0 & world[ n ].owner == 0)
    {
        cout<< "1.Buy\n";
        cout<< "2.Dont buy\n";
        cin>> choose;
        
        switch(choose)
        {
            case 1:
                me.money -= world[ n ].price;
                world[ n ].owner = 1;
            case 2:
                cout<< "Okey, you can move on:D\n";
        }
    }
    
    else if( me.position != 0 & world[ n ].owner != 0)
    {
        cout<< "You paid " << world[ n ].toll << " as toll\n";
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
        
        show_money();
        
        me.position += x;
        
        if( me.position >= 8)
        {
            me.position -= 8;
            me.money += 500000;
        }
        
        position();
        
    } while( me.money >= 0);
    cout << "Game Over:(\n";
    
    
    return 0;
}
