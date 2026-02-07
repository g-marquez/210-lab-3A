//*****************************************************************************
// COMSC-210 | Lab 3 | Gabriel Marquez
// Description: this program manipulates data about restaurants and leverages
// struct variables.
//*****************************************************************************

#include <iostream>
using namespace std;

struct Restaurant
{
    string name;
    string address;
    int capacity;
    double sq_feet;
    char franchise;
};

Restaurant populateRestaurant();
void outputRestaurant(const Restaurant &); 

int main()
{
    //demonstrate with a single struct using console input
    Restaurant myRest = populateRestaurant();
    
    return 0;
}

// populateRestaurant() creates a Restaurant object based on user input
// arguments: none
// returns: a Restaurant object
Restaurant populateRestaurant()
{
    Restaurant temp;
    cout << "Enter restaurant name: ";
    cin >> temp.name;
    cin.ignore();
    cout << "Enter address: ";
    getline(cin, temp.address);
    cout << "Enter restaurant capacity: ";
    cin >> temp.capacity;
    cout << "Enter the restaurant square footage: ";
    cin >> temp.sq_feet;
    cout << "Is this restaurant a franchise? (Y/N):  ";
    cin >> temp.stars;
    return temp;
}

// outputRestaurant() receives a struct object and outputs its data in a
// presentable format
// arguments: a struct object r
// returns: n/a
void outputRestaurant(const Restaurant &r)
{
    cout << "Restaurant Name: " << r.name
}