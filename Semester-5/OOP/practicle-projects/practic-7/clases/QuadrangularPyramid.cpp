//
// Created by yan on 09.05.26.
//

#include "QuadrangularPyramid.h"

namespace Program {
    QuadrangularPyramid::QuadrangularPyramid() : Pyramid() {
        length = 0.0;
        width = 0.0;
    }

    QuadrangularPyramid::QuadrangularPyramid(double x, double y, double z, double hight, double length, double width)
        : Pyramid(x, y, z, hight) {
        this->length = length;
        this->width = width;
    }

    QuadrangularPyramid::QuadrangularPyramid(Point3D cords, double hight, double length, double width)
        : Pyramid(cords, hight) {
        this->length = length;
        this->width = width;
    }

    double QuadrangularPyramid::getLength() {
        return length;
    }

    double QuadrangularPyramid::getWidth() {
        return width;
    }

    void QuadrangularPyramid::setLength(double length) {
        this->length = length;
    }

    void QuadrangularPyramid::setWidth(double width) {
        this->width = width;
    }

    std::string QuadrangularPyramid::toString() {
        return "" + Pyramid::toString() +
            "\n   Довжина основи: (" + std::to_string(getLength()) + ")" +
            "\n   Ширина основи:  (" + std::to_string(getWidth()) + ")";
    }

    std::string QuadrangularPyramid::getInfo() {
        return "Чотирикутна піраміда №" + std::to_string(getId()) + ": \n" + toString();
    }

    void QuadrangularPyramid::showInfo() {
        std::cout << getInfo() << "\n\n";
    }
} // Program