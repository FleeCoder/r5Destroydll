#include "ViewAngle_Cfg.hpp"
#include "ViewAngle.hpp"

ViewAngle::ViewAngle():pitch(0.0),yaw(0.0)
{

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