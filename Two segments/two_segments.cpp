#include <iostream>
#include <string>
using namespace std;
#define find_y_intersection(k,x,b) (k*x)+b
#define find_k_from_eq(yF, yS, xF, xS) (yS-yF)/(xS-xF) // F,S - first, second (which of the pair goes firstly, which after). 
#define find_b_from_eq(y, k, x) y - (k*x)
#define x_diff(xF, xS) xS-xF
#define y_diff(yF, yS) yS - yF

void check_and_cout(float x1, float x2, float x3, float x4, float intersectX, float intersectY, string TrueFalse){
    if ((x1 <= intersectX && x2 >= intersectX) && (x3 <= intersectX && x4 >= intersectX)){ //проверка на вхождение точки пересечения в точки отрезков
        TrueFalse = "Segments intersect";
            }
    else {
        TrueFalse = "Segments dont intersect";
        }
    cout << "Lines:" << endl << "X intersection cord: " << intersectX << endl << "Y intersection cord: " << intersectY << endl << "Segments:" << endl << TrueFalse << endl;

    }
void check_and_cout(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
    if ((x1 == x3) && (x2 == x4) && (y1 == y3) && (y2 == y4)){
        cout << "Segments are equal";
                }
    else if (y2 >= y3 ){
        cout << "Segments overlap each other";
    }
    else{
        cout << "Segments dont intersect";
    }
    }
void check_and_cout(float intersectX, float intersectY){
        cout << "Segments are perpendicular" << endl << "Intersection point: (" << intersectX << ", " << intersectY << ")";
    }


int intersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){

    float k1, k2, b1, b2, intersectX, intersectY;
    string TrueFalse;

    //пусть К и B это коэффициенты уравнения прямой y=kx+b

    if (x_diff(x1, x2) == 0 && x_diff(x3, x4) == 0 && x1 != x3){ //отрезки - вертикальные параллельные линии
        cout << "Lines are parallel";
        return 0;        
    }
    else if(x_diff(x1, x2) == 0 && x_diff(x3, x4) == 0 && x1 == x3){ //отрезки - вертикальные наложенные линии
        check_and_cout(x1, y1, x2, y2, x3, y3, x4, y4);
        return 0;
    }

    else if (x_diff(x1, x2) == 0 && (x_diff(x3, x4) != 0 && y_diff(y3, y4) != 0))  { //первый вертикальный, второй - не вкртикальный и не горизонтальный
        k2 = find_k_from_eq(y3, y4, x3, x4);
        b2 = y3 - (k2*x3);
        intersectX = x1;
        intersectY = find_y_intersection(k2, x1, b2);
        check_and_cout(x1, x2, x3, x4, intersectX, intersectY, TrueFalse);
        return 0;
    
    }
    else if ((x_diff(x1, x2) != 0 && y_diff(y1, y2) != 0) && x_diff(x3, x4) == 0)  { //второй вертикальный, первый - не вертикальный и не горизонтальный
        k1 = find_k_from_eq(y1, y2, x1, x2);
        b1 = find_b_from_eq(y1, k1, x1);   
        intersectX = x3;
        intersectY = find_y_intersection(k1, x3, b1);
        check_and_cout(x1, x2, x3, x4, intersectX, intersectY, TrueFalse);
        return 0;
    }
    
    // we defined that each line is not verical (xS-xF != 0), so a slope could be found

    k1 = find_k_from_eq(y1, y2, x1, x2);
    k2 = find_k_from_eq(y3, y4, x3, x4);
    b1 = find_b_from_eq(y1, k1, x1);
    b2 = find_b_from_eq(y3, k2, x3);

    if (k1 == k2 && b1 == b2){ //отрезки имеют одинаковое уравнение прямой
        check_and_cout(x1, y1, x2, y2, x3, y3, x4, y4);
        return 0;
        }

    else if (k1 == 0 && k2 == 0){ //отрезки горизонтально-паралельные
        cout << "Lines are parallel (horizontal direction)";
        return 0;
        }

    else if (k1 == 0 && (-x3+x4) == 0){ //одна верт вторая гориз
        check_and_cout(x3, b1);
        return 0;

        }
    else if (k2 == 0 && (-x1+x2) == 0){ //одна верт вторая гориз
        check_and_cout(x1, b2);
        return 0;
    }
    else {
        intersectX = (b1-b2)/(-k1+k2); // прямые не параллельны осИ Х или осИ У
        intersectY = find_y_intersection(k1, intersectX, b1);  
        check_and_cout(x1, x2, x3, x4, intersectX, intersectY, TrueFalse);
        return 0;
        }        
    }

    // cout << "Equation of the first line is y=" << k1 << "x+" << b1 << endl;
    // cout << "Equation of the second line is y=" << k2 << "x+" << b2 << endl;
    

int main(){
    float i = 1;
    intersection(1, 0, 6, 2, 0, 5, 5, -1);

}
