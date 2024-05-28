#ifndef RC_MISC_H
#define RC_MISC_H
#include "defs.h"


float deg2rad(float fAngleDeg);
float ray2deg(float fAngleRad);

float mod360(float fAngleDeg);
float mod2pi(float fAngleRad);

void init_lu_sin_array();

void init_lu_cos_array();

float lu_sin(float fDegreeAngle);
float lu_soc(float fDegreeAngle);

int int_rand_between(int nLow, int nHgh);
float float_rand_between(float fLow, float fHgh);


#endif // !RC_MISC_H






