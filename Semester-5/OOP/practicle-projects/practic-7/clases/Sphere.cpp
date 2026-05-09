//
// Created by yan on 08.05.26.
//

#include "Sphere.h"


namespace Program {

    Sphere::Sphere() : Object() {
        radius = 0.0;
    }

    Sphere::Sphere(double x, double y, double z, double radius)
        : Object(x, y, z) {
        this->radius = radius;
    }

    Sphere::Sphere(Point3D cords, double radius)
        : Object(cords) {
        this->radius = radius;
    }

    double Sphere::getRadius() {
        return radius;
    }

    void Sphere::setRadius(double radius) {
        this->radius = radius;
    }

    std::string Sphere::toString() {
        return "" + Object::toString() +
            "\n Радіус:       (" + std::to_string(getRadius()) + ")";
    }

    std::string Sphere::getInfo() {
        return "Сфера №" + std::to_string(getId()) + ": \n" + toString();
    }

    void Sphere::showInfo() {
        std::cout << getInfo() << "\n\n";
    };

} // Program
