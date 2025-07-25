#include "ViewAngle.hpp"
#include "ViewAngle_Cfg.hpp"

ViewAngle::ViewAngle() :pitch(0.0), yaw(0.0), roll(0.0)
{

}

std::ostream& operator<<(std::ostream& os, const ViewAngle& viewAngle)
{
    os << "Pitch: "<<viewAngle.pitch << std::endl;
    os << "Yaw: " << viewAngle.yaw << std::endl;
    return os;
}

void ViewAngle::NormalizeAngle()
{
    // Wrap yaw (x) to [yawMin, yawMax] (e.g., [-180, 180])
    while (yaw > YAWMAX)
        yaw -= (YAWMAX - YAWMIN);
    while (yaw < YAWMIN)
        yaw += (YAWMAX - YAWMIN);

    // Wrap pitch (y) to [pitchMin, pitchMax] (e.g., [-89, 89])
    while (pitch > PITCHMAX)
        pitch -= (PITCHMAX - PITCHMIN);
    while (pitch < PITCHMIN)
        pitch += (PITCHMAX - PITCHMIN);
}