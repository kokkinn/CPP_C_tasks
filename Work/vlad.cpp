#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void negative_position_finder(int *arr, int arrSize){
    int leftPos;
    int rightPos;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] < 0){
        leftPos = i;
        cout << "The first negative value is on position " << leftPos << " in an array" << endl;

        break;
        }
    }
    for(int i = arrSize-1; i >=0 ; i--){
        if(arr[i] < 0){
        rightPos = i;
         cout << "The last negative value is on position " << rightPos << " in an array" << endl;
        break;
    }
    }
}

int main(){
    srand(time(NULL)); 
    const int size = 100;
    int arr[size];
    int max = 20; int min = -20;
    for(int i = 0; i<size; i++){
        arr[i] = -20 + rand()% (max-min+1);
    }
    negative_position_finder(arr, sizeof(arr)/sizeof(arr[0]));
}