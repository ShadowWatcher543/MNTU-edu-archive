//
// Created by yan on 09.05.26.
//

#ifndef PRACTIC_7_PYRAMID_H
#define PRACTIC_7_PYRAMID_H
#include "Object.h"


namespace Program {

    class Pyramid : public Object {
    private:
        double hight;
    public:
        Pyramid();
        Pyramid(double x, double y, double z, double hight);
        Pyramid(Point3D cords, double hight);

        virtual ~Pyramid() = default;

        double getHight();

        void setHight(double hight);

        std::string toString() override;

        std::string getInfo() override;

        void showInfo() override;



    };
} // Program

#endif //PRACTIC_7_PYRAMID_H
