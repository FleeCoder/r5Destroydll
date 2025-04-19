#include "Coordindates.hpp"
#include <iostream>

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) 
{
}

Vector3::Vector3(const float x, const float y, const float z): x(x), y(y), z(z) 
{
}

Vector3 Vector3::operator - (const Vector3& rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); 
}

Vector3& Vector3::operator -= (const Vector3& rhs)
{ 
	return *this = *this - rhs; 
}

float Vector3::Distance(const Vector3& rhs) const
{
	Vector3 delta = *this - rhs;
	return sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}

void Vector3::PrintCoordinates()
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
}