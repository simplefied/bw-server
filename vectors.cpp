#include "vectors.hpp"

using namespace std;

point2f::point2f()
{
    x = y = 0;
}

point2f::point2f(float px, float py)
{
    this->x = px;
    this->y = py;
}

point2f& point2f::operator=(const point2f& right)
{
    x = right.x;
    y = right.y;
	return *this;
}

point2f& point2f::operator+=(const vector2f& right)
{
    x += right.x;
    y += right.y;
	return *this;
}

const point2f operator+(const point2f& left, const vector2f& right)
{
    return point2f(left.x + right.x, left.y + right.y);
}

const point2f operator+(const vector2f& left, const point2f& right)
{
    return right + left;
}

const vector2f operator-(const point2f& left, const point2f& right)
{
    return vector2f(left.x - right.x, left.y - right.y);
}

vector2f::vector2f()
{
    x = 0;
    y = 1;
}

vector2f::vector2f(float vx, float vy)
{
    this->x = vx;
    this->y = vy;
}

vector2f& vector2f::operator=(const vector2f& right)
{
    x = right.x;
    y = right.y;
	return *this;
}

vector2f& vector2f::operator+=(const vector2f& right)
{
    x += right.x;
    y += right.y;
	return *this;
}

vector2f& vector2f::operator-=(const vector2f& right)
{
    x -= right.x;
    y -= right.y;
	return *this;
}

const vector2f operator+(const vector2f& left, const vector2f& right)
{
    return vector2f(left.x + right.x, left.y + right.y);
}

const vector2f operator-(const vector2f& left, const vector2f& right)
{
    return vector2f(left.x - right.x, left.y - right.y);
}

const vector2f operator*(const vector2f& left, const float& right)
{
    return vector2f(left.x*right, left.y*right);
}

const vector2f operator*(const float& left, const vector2f& right)
{
    return right*left;
}

const vector2f operator/(const vector2f& left, const float& right)
{
    return vector2f(left.x/right, left.y/right);
}

const float operator*(const vector2f& left, const vector2f& right)
{
    return left.x*right.x + left.y*right.y;
}

const float operator&(const vector2f& left, const vector2f& right)
{
    return left.x*right.y - left.y*right.x;
}

const float length(const vector2f& vector)
{
    return sqrt(vector.x*vector.x + vector.y*vector.y);
}

const vector2f normalize(const vector2f& vector)
{
    return vector/length(vector);
}

Line_t::Line_t()
{
    p2 = point2f(0, 1);
}

Line_t::Line_t(point2f first, point2f second)
{
    p1 = first;
    p2 = second;
}

Line_t::Line_t(float first_x, float first_y, float second_x, float second_y)
{
    p1 = point2f(first_x, first_y);
    p2 = point2f(second_x, second_y);
}

const vector2f normal(const Line_t& line)
{
    return normalize(vector2f(line.p2.y - line.p1.y, line.p1.x - line.p2.x));
}

const float distance(const point2f &left, const point2f &right){
    return sqrt(pow(left.x-right.x, 2) + pow(left.y-right.y, 2));
}
