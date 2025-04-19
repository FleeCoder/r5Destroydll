#pragma once

class ViewAngle
{
public:
	float pitch;
	float yaw;

public:
	ViewAngle();

	void NormalizeAngle();
};