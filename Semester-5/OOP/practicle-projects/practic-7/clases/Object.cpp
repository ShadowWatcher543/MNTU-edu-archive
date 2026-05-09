//
// Created by yan on 08.05.26.
//

#include "Object.h"

#include <string>

namespace Program {
    Object::Object() {
        id = ++count;

        coords.x = 0.0;
        coords.y = 0.0;
        coords.z = 0.0;
    }
    Object::Object(double newX, double newY, double newZ) {
        id = ++count;

        coords.x = newX;
        coords.y = newY;
        coords.z = newZ;
    }

    Object::Object(Point3D newCords) {
        id = ++count;

        coords = newCords;

    }

    int Object::count = 0;


    int Object::getId() {
        return id;
    }


    double Object::getX() {
        return coords.x;
    }
    double Object::getY() {
        return coords.y;
    }
    double Object::getZ() {
        return coords.z;
    }

    Object::Point3D Object::getCordinate() {
        return coords;
    }



    void Object::setX(double x) {
        this->coords.x = x;
    }
    void Object::setY(double y) {
        this->coords.y = y;
    }
    void Object::setZ(double z) {
        this->coords.z = z;
    }

    void Object::setCordinate(Point3D cords) {
        this->coords = cords;
    }

    std::string Object::toString() {
        return " Координати:   (" + std::to_string(coords.x) + ", " +
                             std::to_string(coords.y) + ", " +
                             std::to_string(coords.z) + ")";
    }

    std::string Object::getInfo() {
        return "Обєкт №" + std::to_string(getId()) + ": \n" + toString();
    }

    void Object::showInfo() {
        std::cout << getInfo() << "\n\n";
    }
} // Program