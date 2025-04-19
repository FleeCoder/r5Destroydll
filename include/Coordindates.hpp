#pragma once
#include <math.h>

class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	Vector3();
	Vector3(const float x, const float y, const float z);
	Vector3 operator - (const Vector3& rhs) const;
	Vector3& operator -= (const Vector3& rhs);
	float Distance(const Vector3& rhs) const;
	void PrintCoordinates();
};