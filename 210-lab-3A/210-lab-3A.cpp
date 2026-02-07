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
    cout << endl << endl << endl;

    //demonstrate with multiple structs using file input
    Restaurant restaurantLog[NUM_RESTAURANTS];
    ifstream fin("restaurant.txt");
    string in_name, in_address;
    int in_capacity;
    double in_sq_feet;
    char in_franchise;
    int index = 0;

    //read data from file and add struct elements to array
    while (getline(fin, in_name))
    {
        getline(fin, in_address);
        fin >> in_capacity;
        fin >> in_sq_feet;
        fin >> in_franchise;
        fin.ignore();

        Restaurant temp;
        temp.name = in_name;
        temp.address = in_address;
        temp.capacity = in_capacity;
        temp.sq_feet = in_sq_feet;
        if (in_franchise == 'Y') temp.franchise = true;
        else temp.franchise = false;
        restaurantLog[index] = temp;
        index++;
    }

    //output restaurant log using for loop
    cout << "Outputting restaurant log: " << endl;
    for (int i = 0; i < NUM_RESTAURANTS; ++i)
    {
        cout << "Restaurant #" << i + 1 << ":\n";
        outputRestaurant(restaurantLog[i]);
        cout << endl << endl;
    }

    fin.close();
    
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
    cout << endl;
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