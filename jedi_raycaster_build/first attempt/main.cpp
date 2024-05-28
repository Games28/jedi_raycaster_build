#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "RC_Misc.h"

#define SCREEN_X 1000
#define SCREEN_Y 600
#define PIXEL_SIZE 2

#define MULTIPLE_LEVELS true
#define RENDER_CEILING !MULTIPLE_LEVELS

#define RENDER_SHADED true
#define OBJECT_INTENSITY 5.0f
#define MULTIPLIER_INTENSITY 5.0f
#define INTENSITY_SPEED 1.0f

#define SHADE_FACTOR_MIN 0.1f
#define SHADE_FACTOR_MAX 1.0f

#define TEXT_COLOR olc::YELLOW
#define HUB_BG_COLOR olc::VERY_DARK_GREEN

#define SPEED_ROTATE          60.0f 
#define SPEED_MOVE             5.0f 
#define SPEED_STRAFE           5.0f 
#define SPEED_LOOKUP         200.0f 
#define SPEED_STRAFE_UP        1.0f 

#define MINIMAP_TILE_SIZE     (32 / PIXEL_SIZE)
#define MINIMAP_SCALE_FACTOR   0.2

#define RADIUS_PLAYER   0.1f
#define RADIUS_ELF      0.2f




#define TEST_OBJ_PERCENTAGE   0.02f 
#define MIN_DYNAMIC_OBJS      2     


class RC_Object
{
public:
	RC_Object() {}
	RC_Object(float fx, float fy, float fs,float fd, float fa, olc::Sprite* pS)
	{
		x = fx;
		y = fy;
		scale = fs;
		fDistToPlayer = fd;
		fAngleToPlayer = fa;
		sprite = pS;
		vx = 0.0f;
		vy = 0.0f;
		UpdateObjAngle();
		UpdateObjSpeed();

	
	}

	void SetX(float fx) { x = fx; }
	void SetY(float fy) { y = fy; }

	float GetX() { return x; }
	float GetY() { return y; }

	void SetPos(float fX, float fY)
	{
		x = fX;
		y = fY;
	}

	void SetScale(float fS) { scale = fS; }
	void SetDistTOPlayer(float fD) { fDistToPlayer = fD; }
	void SetAngleToPlayer(float fA) { fAngleToPlayer = fA; }

	float GetScale() { return scale; }
	float GetDistToPlayer() { return fDistToPlayer; }
	float GetAngleToPlayer() { return fAngleToPlayer; }

	void SetSprite(olc::Sprite* pS) { sprite = pS; }
	olc::Sprite* GetSprite() { return  sprite; }

	float GetVX() { return vx; }
	float GetVY() { return vy; }
	float GetAngle() { return fObjAngle; }
	float GetSpeed() { return fObjSpeed; }

	



	bool bStatic = true;

private:
	void UpdateObjAngle() { fObjAngle = mod2pi(atan2f(vy, vx)); }
	void UpdateObjSpeed() { fObjSpeed = sqrt(vx * vx + vy * vy); }

private:
	float x, y;
	float scale;

	float vx, vy;
	float fObjAngle;
	float fObjSpeed;

	float fDistToPlayer, fAngleToPlayer;
	olc::Sprite* sprite = nullptr;
};


class jediraycaster : public olc::PixelGameEngine
{
public:
	jediraycaster()
	{
		sAppName = "jedi raycaster";
	}


public:


public:

	bool OnUserCreate() override
	{


		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);



		return true;
	}


};



int main()
{
	jediraycaster game;
	if (game.Construct(800, 600, 1, 1))
	{
		game.Start();
	}


	return 0;
}