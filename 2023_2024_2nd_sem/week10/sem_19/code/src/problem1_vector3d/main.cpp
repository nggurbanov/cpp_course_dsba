#include <iostream>
#include <cmath>
#include <set>
#include <random>

class Vector3D
{
public:
    // Task 1, empty constructor
    Vector3D() : _x(0.0), _y(0.0), _z(0.0) {}

    // Task 2, constructor with arguments
    Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    // Task 3, copy constructor
    Vector3D(const Vector3D& v2) : _x(v2._x), _y(v2._y), _z(v2._z) {}

    // Task 4. Getters and setters
    double getX() const { return _x; }
    double getY() const { return _y; }
    double getZ() const { return _z; }

    void setX(double x) { _x = x; }
    void setY(double y) { _y = y; }
    void setZ(double z) { _z = z; }

    // Task 8. Magnitude
    double magnitude() const
    {
        return std::sqrt(_x * _x + _y * _y + _z * _z);
    }

private:
    double _x;
    double _y;
    double _z;
};

// Task 5. Operator +
Vector3D operator+ (const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

// Task 6. Operator * (dot product)
double operator* (const Vector3D& v1, const Vector3D& v2)
{
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

// Task 7. Operator * (scalar multiplication)
Vector3D operator* (const Vector3D& v1, double d)
{
    return Vector3D(v1.getX() * d, v1.getY() * d, v1.getZ() * d);
}

// Task 9. Operator <
bool operator<(const Vector3D& v1, const Vector3D& v2)
{
    return v1.magnitude() < v2.magnitude();
}

// Task 10. Operator << (printing)
std::ostream& operator<< (std::ostream& out, const Vector3D& v)
{
    out << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return out;
}

// Task 11. Operator >> (reading)
std::istream& operator>> (std::istream& in, Vector3D& v)
{
    double x, y, z;
    in >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return in;
}

void fillMultiset(size_t n, std::multiset<Vector3D>& mset)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-1, 1);

    for (size_t i = 0; i < n; i++)
    {
        double x = distr(gen);
        double y = distr(gen);
        double z = distr(gen);
        mset.insert(Vector3D(x, y, z));
    }
}

int main()
{
    std::multiset<Vector3D> s;
    const size_t setSize = 100;
    fillMultiset(100, s);

    for (const Vector3D& v : s)
    {
        std::cout << v << std::endl;
    }

    double totalMagnitude = 0.0;
    for (const Vector3D& v : s)
    {
        totalMagnitude += v.magnitude();
    }
    double averageMagnitude = totalMagnitude / setSize;
std::cout << "Average magnitude is " << averageMagnitude << std::endl;

return 0;
}
