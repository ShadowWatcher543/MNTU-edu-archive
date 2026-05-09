//
// Created by yan on 09.05.26.
//

#ifndef PRACTIC_7_QUADRANGULARPYRAMID_H
#define PRACTIC_7_QUADRANGULARPYRAMID_H

#include "Pyramid.h"

namespace Program {

    class QuadrangularPyramid : public Pyramid {
    private:
        double length, width;

    public:
        QuadrangularPyramid();
        QuadrangularPyramid(double x, double y, double z, double hight, double length, double width);
        QuadrangularPyramid(Point3D cords, double hight, double length, double width);

        virtual ~QuadrangularPyramid() = default;

        double getLength();
        double getWidth();

        void setLength(double length);
        void setWidth(double width);

        std::string toString() override;

        std::string getInfo() override;


        void showInfo() override;
    };
} // Program

#endif //PRACTIC_7_QUADRANGULARPYRAMID_H
