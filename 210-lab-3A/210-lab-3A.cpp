//*****************************************************************************
// COMSC-210 | Lab 3 | Gabriel Marquez
// Description: this program manipulates data about restaurants and leverages
// struct variables.
//*****************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

int NUM_RESTAURANTS = 4;

struct Restaurant
{
    string name;
    string address;
    int capacity;
    double sq_feet;
    bool franchise;
};

Restaurant populateRestaurant();
void outputRestaurant(const Restaurant &); 

int main()
{
    //demonstrate with a single struct using console input
    Restaurant myRest = populateRestaurant();
    outputRestaurant(myRest);
    cout << endl << endl;

    //demonstrate with multiple structs using file input
    Restaurant restaurantLog[NUM_RESTAURANTS];
    ifstream fin("restaurant.txt");
    string in_name, in_address;
    int in_capacity;
    double in_sq_feet;
    char in_franchise;
    int index = 0;

    //read data from file and add struct elements to array
    while (fin >> in_name)
    {
        
    }
    
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
    char entry;
    cin >> entry;
    entry = toupper(entry);
    while (entry != 'Y' and entry != 'N')
    {
        cout << "ERROR: Y/N only - try again: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.franchise = entry == 'Y' ? true : false;
    return temp;
}

// outputRestaurant() receives a struct object and outputs its data in a
// presentable format
// arguments: a struct object r
// returns: n/a
void outputRestaurant(const Restaurant &r)
{
    cout << "Restaurant Name: " << r.name << endl;
    cout << "Address: " << r.address << endl;
    cout << "Capacity: " << r.capacity << endl;
    cout << "Square-Footage: " << r.sq_feet << endl;
    cout << "Franchise: "; 
    if (r.franchise) cout << "yes"; 
    else cout << "no" << endl << endl;
}