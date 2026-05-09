//
// Created by yan on 09.05.26.
//

#include "Pyramid.h"

namespace Program {
    Pyramid::Pyramid() : Object() {
        hight = 0.0;
    }

    Pyramid::Pyramid(double x, double y, double z, double hight) : Object(x, y ,z) {
        this->hight = hight;
    }

    Pyramid::Pyramid(Point3D cords, double hight) : Object(cords) {
        this->hight = hight;
    }

    double Pyramid::getHight() {
        return hight;
    }

    void Pyramid::setHight(double hight) {
        this->hight = hight;
    }

    std::string Pyramid::toString() {
        return "" + Object::toString() +
           "\n Висота:       (" + std::to_string(getHight()) + ")";
    }

    std::string Pyramid::getInfo() {
        return "Піраміда №" + std::to_string(getId()) + ": \n" + toString();
    }

    void Pyramid::showInfo() {
        std::cout << getInfo() << "\n\n";
    }
} // Program