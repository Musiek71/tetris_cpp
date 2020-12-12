//
// Created by musiek on 16.11.2020.
//

#include <iostream>
#include "../../header/Game/Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() : x(0), y(0) {}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

void Point::print() {
    std::cout << Point::getX() << " " << Point::getY() << std::endl;
}

void Point::setPos(int x, int y) {
    Point::x = x;
    Point::y = y;
}
