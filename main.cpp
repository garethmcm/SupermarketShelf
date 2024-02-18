#include <iostream>
#include <string>
#include <random>
using namespace std;

class Item;

typedef Item* ItemPtr;

class Item {
public:
    Item(int useBy, bool isItBlank);
    int useBy;
    bool isItBlank;

    string rep(int useBy, bool isItBlank) {
        if(useBy>0 && isItBlank == false) {
            return to_string(useBy);
        } else if(useBy == 0 && isItBlank==false) {
            return "b";
        } else if (isItBlank == true) {
            return "-";
        }
    }

    void lifts(ItemPtr** shelf, int depth, int width) {
        for (int i = 0; i < width; i++) {
            int random = rand() % (depth / 2) + 1;  // Random number between 1 and depth/2
            for (int j = 0; j < random; j++) {
                int randomIndex = rand() % depth;  // Random index between 0 and depth-1
                shelf[randomIndex][i]->isItBlank = true;
            }
        }
    }
};

Item::Item(int useBy, bool isItBlank) : useBy(useBy), isItBlank(isItBlank) {}


int main() {

    int width = 3;
    int depth = 10;
    int useBy = 5;
    bool isItBlank = false;

    ItemPtr** m = new ItemPtr*[depth];

    for(int i=0; i<depth; i++) {
        m[i] = new ItemPtr[width];
        for (int j=0; j<width; j++) {
            m[i][j] = new Item(useBy, isItBlank);
        }
    }

    m.lifts(m, depth, width);

    for(int i=0; i<depth; i++) {
        for(int j=0; j<width; j++) {
            cout << m[i][j]->rep(useBy, isItBlank) << " ";
        }
        cout << endl;
    }


    for (int i=0; i<depth; i++) {
        delete[] m[i];
    }
    delete[] m;

    return 0;
}
