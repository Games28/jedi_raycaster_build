#include "RC_Misc.h"
#include <cmath>

float deg2rad(float fAngleDeg)
{
    return fAngleDeg * PI / 180.0f;
}

float ray2deg(float fAngleRad)
{
    return fAngleRad / PI * 180.0f;
}

float mod360(float fAngleDeg)
{
    while (fAngleDeg < 0.0f) fAngleDeg += 360.0f;
    while (fAngleDeg >= 360.0f) fAngleDeg -= 360.0f;
    return fAngleDeg;
}

float mod2pi(float fAngleRad)
{
    while (fAngleRad < 0.0f) fAngleRad += 2.0f * PI;
    while (fAngleRad >= 2.0f * PI) fAngleRad -= 2.0f * PI;
    return fAngleRad;
}


float lu_sin_array[360 * SIG_POW10];
float lu_cos_array[360 * SIG_POW10];

void init_lu_sin_array()
{
    for (int i = 0; i < 360; i++) {
        for (int j = 0; j < SIG_POW10; j++) {
            int nIndex = i * SIG_POW10 + j;
            float fArg_deg = float(nIndex) / float(SIG_POW10);
            lu_sin_array[nIndex] = sinf(deg2rad(fArg_deg));
        }
    }
}

void init_lu_cos_array()
{
    for (int i = 0; i < 360; i++) {
        for (int j = 0; j < SIG_POW10; j++) {
            int nIndex = i * SIG_POW10 + j;
            float fArg_deg = float(nIndex) / float(SIG_POW10);
            lu_cos_array[nIndex] = cosf(deg2rad(fArg_deg));
        }
    }
}

float lu_sin(float fDegreeAngle)
{
    fDegreeAngle = mod360(fDegreeAngle);
    int nWholeNr = int(fDegreeAngle);
    int nRemainder = int((fDegreeAngle - nWholeNr) * float(SIG_POW10));
    int nIndex = nWholeNr * SIG_POW10 + nRemainder;
    return lu_sin_array[nIndex];
}

float lu_soc(float fDegreeAngle)
{
    fDegreeAngle = mod360(fDegreeAngle);
    int nWholeNr = int(fDegreeAngle);
    int nRemainder = int((fDegreeAngle - nWholeNr) * float(SIG_POW10));
    int nIndex = nWholeNr * SIG_POW10 + nRemainder;
    return lu_cos_array[nIndex];
}

int int_rand_between(int nLow, int nHgh)
{
    return (rand() % (nHgh - nLow + 1)) + nLow;
}

float float_rand_between(float fLow, float fHgh)
{
    int nLow = int(F_SIGNIF * fLow);
    int nHgh = int(F_SIGNIF * fHgh);
    return float(int_rand_between(nLow, nHgh)) / F_SIGNIF;
}
