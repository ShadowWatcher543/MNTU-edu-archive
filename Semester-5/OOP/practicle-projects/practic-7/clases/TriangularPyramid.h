//
// Created by yan on 09.05.26.
//

#ifndef PRACTIC_7_TRIANGULARPYRAMID_H
#define PRACTIC_7_TRIANGULARPYRAMID_H

#include "Pyramid.h"

namespace Program {

    class TriangularPyramid : public Pyramid {
    private:
        double areaOfBase;

    public:
        TriangularPyramid();
        TriangularPyramid(double x, double y, double z, double hight, double areaOfBase);
        TriangularPyramid(Point3D cords, double hight, double areaOfBase);

        virtual ~TriangularPyramid() = default;

        double getAreaOfBase();

        void setAreaOfBase(double areaOfBase);

        std::string toString() override;

        std::string getInfo() override;


        void showInfo() override;
    };
} // Program

#endif //PRACTIC_7_TRIANGULARPYRAMID_H
