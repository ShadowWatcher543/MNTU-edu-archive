//
// Created by yan on 09.05.26.
//

#include "TriangularPyramid.h"

namespace Program {
    TriangularPyramid::TriangularPyramid() : Pyramid() {
        areaOfBase = 0.0;
    }

    TriangularPyramid::TriangularPyramid(double x, double y, double z, double hight, double areaOfBase)
        : Pyramid(x, y, z, hight) {
        this->areaOfBase = areaOfBase;
    }

    TriangularPyramid::TriangularPyramid(Point3D cords, double hight, double areaOfBase)
        : Pyramid(cords, hight) {
        this->areaOfBase = areaOfBase;
    }

    double TriangularPyramid::getAreaOfBase() {
        return areaOfBase;
    }

    void TriangularPyramid::setAreaOfBase(double areaOfBase) {
        this->areaOfBase = areaOfBase;
    }

    std::string TriangularPyramid::toString() {
        return "" + Pyramid::toString() +
                   "\n Площа основи: (" + std::to_string(getAreaOfBase()) + ")";
    }

    std::string TriangularPyramid::getInfo() {
        return "Трикутна піраміда №" + std::to_string(getId()) +  ": \n" + toString();
    }

    void TriangularPyramid::showInfo() {
        std::cout << getInfo() << "\n\n";
    }
} // Program