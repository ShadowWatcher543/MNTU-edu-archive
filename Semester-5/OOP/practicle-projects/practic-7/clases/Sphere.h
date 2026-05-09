//
// Created by yan on 08.05.26.
//

#ifndef PRACTIC_7_SPHERE_H
#define PRACTIC_7_SPHERE_H
#include "Object.h"

namespace Program {
    class Sphere : public Object {
    private:
        double radius;
    public:
        Sphere();
        Sphere(double x, double y, double z,  double radius);
        Sphere(Point3D cords, double radius);

        virtual ~Sphere() = default;


        double getRadius();

        void setRadius(double radius);


        std::string toString() override;

        std::string getInfo() override;


        void showInfo() override;
    };
} // Program

#endif //PRACTIC_7_SPHERE_H
