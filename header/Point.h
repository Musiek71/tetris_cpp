//
// Created by musiek on 16.11.2020.
//

#ifndef TETRIS_CPP_POINT_H
#define TETRIS_CPP_POINT_H


class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    Point();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    void setPos(int x, int y);

    void print();
};


#endif //TETRIS_CPP_POINT_H
