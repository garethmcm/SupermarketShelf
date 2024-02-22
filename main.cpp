#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

class Item {
public:

    Item();
    Item(int useBy, bool isItBlank);
    string print() const;
    void setUseBy(int u);
    int getUseBy() const;
    void setIsItBlank(bool b);
    bool getIsItBlank() const;

private:
    int useBy;
    bool isItBlank;
};

Item::Item() : useBy(5), isItBlank(false){}
Item::Item(int useBy, bool isItBlank) : useBy(useBy), isItBlank(isItBlank) {}

string Item::print() const {
    if(useBy>0 && isItBlank == false) {
        return to_string(useBy);
        } else if(useBy == 0 && isItBlank==false) {
        return "b";
        } else if (isItBlank == true) {
        return "-";
    }
}

void Item::setUseBy(int u) {
    useBy = u;
}

int Item::getUseBy() const {
    return useBy;
}

void Item::setIsItBlank(bool b) {
    isItBlank = b;
}
bool Item::getIsItBlank() const {
    return isItBlank;
}

void printShelf(vector<vector<Item>> &shelf) {
    for(int i=0; i<shelf.size(); i++) {
        for(int j=0; j<shelf[i].size(); j++) {
            cout << shelf[i][j].print() << " ";
        }
        cout << endl;
    }
}

int randomIzer(int scale) {
    scale /= 2;
    default_random_engine dre(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uid(0, scale);
    return uid(dre);
}

void dailyLifts(vector<vector<Item>> &shelf, int depth, int width) {
    for(int i=0; i<width; i++) {
        int rando = randomIzer(depth-i);
        for (int j=0; j<depth; j++) {
            if (j<=rando) {
                shelf[j][i].setIsItBlank(true);
            }
        }
    }
    cout << "After lifting items the shelf looks like this: \n";
    printShelf(shelf);
}

void moveItems(vector<vector<Item>> &shelf) {
    int start = 0;
    int end = 0;
    int scope = 0;
    for (int i=0; i<shelf.size(); i++) {
        for (int j=0; j<shelf[i].size(); j++) {
            if(!shelf[i][j].getIsItBlank()) {
                start = j;
            }
            if(shelf[i][j].getIsItBlank()) {
                end = j;
            }
        }
        if(start > end) {
            scope = end - start;
        } else {
            scope = shelf.size() - start;
        }
    }
    for(int i=0; i<shelf.size(); i++) {
        for(int j=0; j<shelf[i].size(); j++) {
            int k = j+scope;
            shelf[i][j] = shelf[i][k];
            shelf[i][k] = *new Item(0, true);
        }
    }
    cout << "After moving items the shelf looks like this: \n";
    printShelf(shelf);
}

int main() {

    int width = 3;
    int depth = 10;

    vector<vector<Item>> shelf(depth, vector<Item>(width, Item()));
    cout << "At first the shelf looks like this: \n";
    printShelf(shelf);
    dailyLifts(shelf, depth, width);
    moveItems(shelf);

    return 0;
}
