// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Helicopter.h"
#include "OOPUtils.h"

// UML (x)
// fixing de cin
// pointers (fun times)
// work a bit with vectors
// read files

int main2()
{
    std::cout << "Este es mi código para el proyecto!" << std::endl;

    // declared outside because of scope
    int opcionDeUsuario = 0;
    std::string stringInput;

    do
    {
        std::cout << "choose a number!" << std::endl;
        std::cin >> opcionDeUsuario;

        // we need to flush the line before we read a whole line
        // std::cin.ignore(amountOfCharactersToIgnore, characterToSearchFor);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "write a string!" << std::endl;
        std::getline(std::cin, stringInput);

        std::cout << "your input: " << opcionDeUsuario << " " << stringInput << std::endl;


        // A THING TO CONSIDER!
        // when you do your project you WILL have a big structure here
        // (if - else if, switch)
        // DISTRIBUTE YOUR CODE!
        // antipattern - GOD CLASS
    } while (opcionDeUsuario != 9);
    return -1;
}

void main3() {
    
    //Vehicle v1;

    // let's do some memory leaks! 
    // yay!!

    // this happens in unmanaged code 
    // 2 categories of code based on memory management:
    // 1. Managed - Objects that have no reference are cleaned up
    // by the garbage collector
    // 2. Unmanaged - when we allocate an object in memory 
    // we MUST clean after ourselves

    // pointer - a numeric value that represents a memory address
    // old school pointers and smart pointers
    // smart pointers link - https://learn.microsoft.com/es-es/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170

    //Vehicle* v2 = new Vehicle();

    // POINTERS
    // upside - you can reference a particular object anywhere! (YAY!)
    // downside - you are responsible of cleaning it after use! (AWW!)

    // new vs malloc
    // both allocate memory
    // new creates an object, specific type

    // RULE!!! 
    // when we do a pointer
    // we must have a delete somewhere

    // vectors 
    // lineal data structures
    // can be used to save objects created from strings in a file
    
    // vectors can be initialized with no values
    //std::vector<int> numbers;

    // they can have some values to begin with
    std::vector<int> numbers = {1, 5, 10, 15, 20};

    // how to add new stuff at the end
    numbers.push_back(32);
    
    // print content
    for (int i = 0; i < numbers.size(); i++) {
        // how to access a particular member
        // vector[index]
        std::cout << numbers[i] << std::endl;
    }

    // range-based for loop
    for (int currentNumber : numbers) {
        std::cout << currentNumber << std::endl;
    }

    // how to remove last element
    numbers.pop_back();

    // range-based for loop
    for (int currentNumber : numbers) {
        std::cout << currentNumber << std::endl;
    }

    //delete v2;
}

void main4() {

    // POLYMORPHISM
    // poly + morphism

    // a single object can represent different types / classes
    Helicopter h1;
    Motorcycle m1;

    std::cout << h1.move() << std::endl;
    std::cout << m1.move() << std::endl;


    // polymorphism in action!
    // remember * is for a pointer
    // & - reference, get memory address of an object
    // we MUST use destroy where we do NEW
    Vehicle* v1 = &h1;
    Vehicle* v2 = &m1;

    // can I invoke move() on a vehicle?
    // YES! the object contains a reference to a subclass' object
    // arrow operator 
    // when using a pointer instead of . we use ->
    // it is used to access a member (same as .)
    std::cout << v1->move() << std::endl;
    std::cout << v2->move() << std::endl;

    std::vector<Vehicle*> vehicleContainer;

    vehicleContainer.push_back(v1);
    vehicleContainer.push_back(&m1);

    std::cout << "**** PRINTING A VECTOR ****" << std::endl;
    for (Vehicle* currentVehicle : vehicleContainer) {
    
        std::cout << currentVehicle->move() << std::endl;
    }

    // HOW TO ACCESS A STATIC MEMBER
    // Class::member()

    OOPUtils::staticTest();

    // this doesn't work:
    // Vehicle v1 = h1;


}

// operator overload
std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << v.anio << " modelo: " << v.modelo;
    return os;
}

int main() {
    
    // splitting a string
    std::string source = "some%!test%!hello!";
    std::string delimiter = "%!";

    std::vector<std::string> parts = OOPUtils::split(source, delimiter);
    for (std::string current : parts) {
        std::cout << "PART: " << current << std::endl;
    }

    // file reading

    // get reference to file
    // IMPORTANT NOTE 
    // path - string that indicates a resource's location
    // 2 choices:
    // 1 - relative path
    // 2 - absolute path
    std::ifstream file("input.txt");
    // std::ifstream file("C:/Users\Memo\OOP\Project2\input.txt");

    std::string currentLine;

    // do the actual reading
    if (file.is_open()) {

        // go through the file and read line by line
        while (std::getline(file, currentLine)) {
            std::cout << "FILE READING: " << currentLine << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "FATAL AND TERRIBLE ERROR OPENING FILE!" << std::endl;
    }

    // operator << overload example
    Motorcycle motito;

    std::cout << motito << std::endl;
}

/*
    TOPICS FOR YOUR EXAM (YAY!):
    - Classes
    - Objects
    - access modifiers (private, protected, public)
    - Inheritance (polymorphism)
    - Abstract methods (pure virtual)
    - Pointers (new, delete)
    - using vector 
    - std::cout, std::endl

*/