//
// Created by musiek on 16.11.2020.
//

#ifndef TETRIS_CPP_POINT_H
#define TETRIS_CPP_POINT_H

/**
 * Point class representing a single point on the gameboard.
 */
class Point {
private:
    /// The X coordinate.
    int x;
    /// The Y coordinate.
    int y;
public:
    /// Default constructor, X and Y equals 0.
    Point();

    /// Constructor, setting coordinates.
    Point(int x, int y);

    /// Get the X coordinate.
    int getX() const;

    /// Set the X coordinate.
    void setX(int x);

    /// Get the Y coordinate.
    int getY() const;

    /// Set the y coordinate.
    void setY(int y);

    /// Set both coordinates.
    void setPos(int x, int y);

    /// Print the point to stdout.
    void print();
};


#endif //TETRIS_CPP_POINT_H
