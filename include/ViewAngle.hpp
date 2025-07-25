#pragma once
#include <iostream>

class ViewAngle
{
public:
	float pitch;
	float yaw;
	float roll;

public:
	ViewAngle();
	friend std::ostream& operator<<(std::ostream& os, const ViewAngle& viewAngle);

	void NormalizeAngle();
};