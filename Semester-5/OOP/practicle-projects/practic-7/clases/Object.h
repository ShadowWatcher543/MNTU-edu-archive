//
// Created by yan on 08.05.26.
//

#ifndef PRACTIC_7_OBJECT_H
#define PRACTIC_7_OBJECT_H

#include <iostream>



namespace Program {

    class Object {
    public:
        struct Point3D {
            double x, y, z;
        };
    private:
        int id;
        static int count;

        Point3D coords;
    protected:

    public:
        Object();
        Object(double x, double y, double z);
        Object(Point3D coords);

        virtual ~Object() = default;


        int getId();

        double getX();
        double getY();
        double getZ();
        Point3D getCordinate();

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setCordinate(Point3D cords);


        virtual std::string toString();

        virtual std::string getInfo();

        virtual void showInfo();
    };
} // Program

#endif //PRACTIC_7_OBJECT_H
