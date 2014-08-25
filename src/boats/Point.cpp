#include "boats/Point.hpp"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point::Point(const Point& orig) {
    this->x = orig.x;
    this->y = orig.y;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}
void Point::setY(int y) {
    this->y = y;
}

const Point& Point::operator=(const Point& point) {
    this->x = point.x;
    this->y = point.y;
    return *this;
}
