#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Restaurant {
string name; 
string address; 
double starRating;
int numReviews;
bool isOpen; 
};

//prototypes 
Restaurant populateRestaurantData();
void printRestaurantInfo(const Restaurant& restaurant);

int main() {
vector<Restaurant> topRestaurants; 
char addAnother = 'Y';

while(addAnother == 'Y') {
        topRestaurants.push_back(populateRestaurantData());
        cout << "Would you like to add another restaurant? (Y/N): ";
        cin.ignore();
        cin >> addAnother;  
        addAnother = toupper(addAnother);
        while (addAnother != 'Y' && addAnother != 'N') {
            cout << "Invalid entry. Please enter Y or N: " << endl;
            cin.ignore();
            cin >> addAnother; 
            addAnother = toupper(addAnother);
        }
    }
// output all restaurant info within arrray, for loop was comparing unsigned int so changed to size_t
for (size_t i = 0; i < topRestaurants.size(); i++) {
    cout << "Restaurant #" << i + 1 << ":\n";
    printRestaurantInfo(topRestaurants[i]);
    cout << endl; 
    }

return 0; 
}

Restaurant populateRestaurantData() {
    Restaurant temp; 
    cout << "Enter information with file or manually (F/M)?: " << endl;
    char entry;
    cin >> entry;
    entry = toupper(entry);   
    while (entry != 'F' && entry != 'M') {
        cout << "Invalid entry. Please enter F or M: " << endl;
        cin >> entry; 
    }
    if(entry == 'F') {
        ifstream infile("restaurants.txt");
        if (!infile) {
            cerr << "Error opening file." << endl;
            return temp; 
        }
        getline(infile, temp.name);
        getline(infile, temp.address);
        infile >> temp.starRating >> temp.numReviews >> temp.isOpen;
        infile.close();
    } else if (entry == 'M') {
        cout << "Enter the restaurant's name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, temp.name); // Use getline to allow for spaces in the name and address
        cout << "Enter restaurant address: ";
        getline(cin, temp.address); 
        cout << "Enter star rating (0.0 - 5.0): ";
        cin >> temp.starRating;
        cout << "Enter number of reviews: ";
        cin >> temp.numReviews;
        cout << "Is the restaurant open? (1 for yes, 0 for no): ";
        cin >> temp.isOpen;
    }

    return temp;
};
void printRestaurantInfo(const Restaurant& restaurant) {
    cout << "Name: " << restaurant.name << endl;
    cout << "Address: " << restaurant.address << endl;
    cout << "Star Rating (0.0 - 5.0): " << restaurant.starRating << endl;   
    cout << "Number of Reviews: " << restaurant.numReviews << endl;
    cout << "Is this restaurant open?(1=Yes, 0=No) " << restaurant.isOpen << endl;
};