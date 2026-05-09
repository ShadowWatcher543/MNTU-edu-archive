#include <iostream>
#include <vector>   // Вектор для зберігання об'єктів фігур



#include "Menu.h"

#include "Object.h"
#include "Pyramid.h"
#include "QuadrangularPyramid.h"
#include "Sphere.h"
#include "TriangularPyramid.h"



using namespace Program;




    int main() {

        Menu* menu = new Menu();


        //menu->generateTestPresets();
        menu->displayMainMenu();

        delete menu;


        return 0;
    }




