#include <iostream>
using namespace std;

//GeometricShapes is Abstract Class
class GeometricShapes {
protected:
    char *name;

public:
    //Constructor
    GeometricShapes(const char *name_) {
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
    }
    //Destructor
    ~GeometricShapes() { delete [] name;}

    //Pure Virtual Functions
    virtual void getInput() = 0;
    virtual double calculateArea() const = 0;
};


//--------------------------------------------------------------------------------------------
//Square Class extends GeometricShapes
class Square: public GeometricShapes {
    int   side;

public:
    Square() : GeometricShapes("Area of Square") {}

    //Get Data from User
    virtual void getInput() {
        cout << "\nEnter the Value for Side of the Square\n ";
        cin >> side;

    }

    //Calculate the area of Square
    virtual double calculateArea() const {
        return ( side * side );
    }

};


//--------------------------------------------------------------------------------------------
//Rectangle Class extends GeometricShapes
class Rectangle: public GeometricShapes {
    int   longSide, shortSide;

public:
    Rectangle() : GeometricShapes("Area of Rectangle") {}

    //Get Data from User
    virtual void getInput() {
        cout << "\nEnter the Value for Long Side of the Rectangle\n ";
        cin >> longSide;

        cout << "\nEnter the Value for Short Side of the Rectangle\n ";
        cin >> shortSide;

    }

    //Calculate the area of Rectangle
    virtual double calculateArea() const {
        return (longSide * shortSide );
    }

};


//--------------------------------------------------------------------------------------------
//Triangle Class extends GeometricShapes
class Triangle: public GeometricShapes {
    int   base, height;

public:
    Triangle() : GeometricShapes("Area of Triangle") {}

    //Get Data from User
    virtual void getInput() {
        cout << "\nEnter the Value for Floor of the Triangle\n ";
        cin >> base;

        cout << "\nEnter the Value for Height of the Triangle\n ";
        cin >> height;

    }

    //Calculate the area of Triangle
    virtual double calculateArea() const {
        return (base * (height/2) );
    }

};


//--------------------------------------------------------------------------------------------
//Main program
int main() {

    GeometricShapes *shapes = NULL;
    char choice;

    while ( choice != 'E'){
    cout <<"\nMenu for Calculating the Area of Geometric Shapes\n";
    cout <<"1) Press (S) for the Area Square\n";
    cout <<"2) Press (R) for the Area Rectangle\n";
    cout <<"3) Press (T) for the Area Triangle\n";
    cout <<"4) Press (E) for the Exit\n";

    cout << "Enter your Choice\n";
    cin >> choice;

    switch (choice){

        case 'S':
            //invoke Square
            shapes = new Square();
            shapes->getInput();
            cout << "Area of the Square is:\n" << shapes->calculateArea() << endl;
            delete shapes;
            break;

        case 'R':
            //invoke Rectangle
            shapes = new Rectangle();
            shapes->getInput();
            cout << "Area of the Rectangle is:\n" << shapes->calculateArea() << endl;
            delete shapes;
            break;

        case 'T':
            //invoke Triangle
            shapes = new Triangle();
            shapes->getInput();
            cout << "Area of the Triangle is:\n" << shapes->calculateArea() << endl;
            delete shapes;
            break;

        default:
            cout << "End!\n";
    }

    }

    return 0;
}