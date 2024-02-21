#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Item {
public:

    Item();
    string print() const;
//    void dailyLifts(vector<vector<Item>> &shelf, int width, int depth);
    void setUseBy(int u);
    int getUseBy() const;
    void setIsItBlank(bool b);
    bool getIsItBlank() const;

private:
    int useBy;
    bool isItBlank;
};

Item::Item() : useBy(5), isItBlank(false){}

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
void dailyLifts(vector<vector<Item>> &shelf, int depth, int width) {

    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> distribution(1, 6);
    int randomNumber = distribution(generator);

    for (int i=0; i<depth; i++) {
        if (i<=randomNumber) {
            shelf[i][0].setIsItBlank(true);
        }
    }
    random_device randomDevice2;
    mt19937 generator2(randomDevice());
    uniform_int_distribution<int> distribution2(1, 4);
    int randomNumber2 = distribution2(generator2);

    for (int i=0; i<depth; i++) {
        if (i<=randomNumber2) {
            shelf[i][1].setIsItBlank(true);
        }
    }
    random_device randomDevice3;
    mt19937 generator3(randomDevice());
    uniform_int_distribution<int> distribution3(1, 2);
    int randomNumber3 = distribution3(generator3);

    for (int i=0; i<depth; i++) {
        if (i<=randomNumber3) {
            shelf[i][2].setIsItBlank(true);
        }
    }

}

int main() {

    int width = 3;
    int depth = 10;

    vector<vector<Item>> shelf(depth, vector<Item>(width, Item()));

    dailyLifts(shelf, depth, width);

    for(int i=0; i<depth; i++) {
        for(int j=0; j<width; j++) {
            cout << shelf[i][j].print() << " ";
        }
        cout << endl;
    }

    return 0;
}
