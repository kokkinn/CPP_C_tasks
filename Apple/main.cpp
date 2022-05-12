#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Apple{
    string colours_arr[3] = {"Yellow", "Green", "Red"};
    bool existing_colour_passed;
    private:
    string colour;
    public:

    Apple(){
        // srand(time(0));
        int num = rand() % 3;
        this->colour = colours_arr[num]; }

    Apple(string col) {
        for (int i = 0; i < sizeof(colours_arr); i++){
            if (col == colours_arr[0]){
                existing_colour_passed = true;
                this->colour = col;}}
        if (existing_colour_passed == false){
            //  srand(time(0));
             int num = rand() % 3;
             this->colour = colours_arr[num];
        }
    }

    string get_colour(){
    return this->colour;
    }

};

void check_for_colour(Apple obj){
    cout << "Your apple is " << obj.get_colour() << "\n";
    }

int main(){
    srand(time(0));
    Apple apple1("Yellow");
    Apple apple2("ABABA");
    Apple apple3;
    check_for_colour(apple1);
    check_for_colour(apple2);
    check_for_colour(apple3);
}
    