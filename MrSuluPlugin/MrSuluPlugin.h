#pragma once
#pragma comment( lib, "bakkesmod.lib" )
#include "bakkesmod\plugin\bakkesmodplugin.h"

#define COLOR_TEXT 255c, 255c, 255c, 255c
#define COLOR_TEXT_UNACTIVE 150c, 150c, 150c, 255c
#define COLOR_TIMER 100c, 100c, 255c, 255c
#define COLOR_TIMER_RESET 255c, 100c, 100c, 255c
#define COLOR_PANEL 64c, 64c, 64c, 192c

inline constexpr char operator "" c(unsigned long long arg) noexcept
{
	return static_cast< char >(arg);
}

struct Color
{
	char r, g, b, a;
};

class CarWrapper;
class BallWrapper;
class CanvasWrapper;

class MrSuluPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
private:
	shared_ptr<bool> enabled;
	shared_ptr<float> waitStartTimer;
	shared_ptr<bool> fastAerials;
	

	int carJustReset;

	bool timerStarted;
	float timerStartTime;

	int timerHitBall, timerHitWorld, timerScore, timerJumpPressed, timerJumpReleased;
	float jumpPressedTime, jumpReleaseTime;

	int timerFastAerialBilan0, timerFastAerialBilan1;
	float timerFastAerialBilan0Time, timerFastAerialBilan1Time;

	Vector lastCarLocation;
	bool carIdle,timerReady;
	float carIdleStartTime;

	//float lastBallTouchTime;

	void enable();
	void disable();
	bool canBeEnabled();
	void timerStart();
	void timerIsReady();
	float timerDisplay(std::string category, float timeElpased=-1.0f);

	bool IsCarReady();
	CarWrapper GetGameCar();
	BallWrapper GetGameBall();
	float GetSecondsElapsed();


	void drawTimerPanel(CanvasWrapper cw); // , int x, int y);
	void drawStringAt(CanvasWrapper cw, std::string text, int x, int y, Color col = { 255c, 255c, 255c, 255c });
	void drawStringAt(CanvasWrapper cw, std::string text, Vector2 loc, Color col = { 255c, 255c, 255c, 255c });

	float getCarTilt();

	void log(std::string msg);
	void canvasLog(std::string msg);

	int canvasLogsIndex;
	int canvasLogsActiveTimerIndex;
	int canvasLogsMaxCount;
	string canvasLogs[12];

public:
	//MrSuluPlugin();
	//~MrSuluPlugin();
	virtual void onLoad();
	virtual void onUnload();

	void OnHitBall(std::string eventName);
	void OnHitWorld(std::string eventName);
	void OnBallHitGoal(std::string eventName);

	void OnJumpPressed(std::string eventName);
	void OnJumpReleased(std::string eventName);
	void OnCarSpawn(std::string eventName);
	void OnFireBall(std::string eventName);

	void OnTick(std::string funcName);
	void OnWorldLoad(std::string eventName);
	void OnWorldDestroy(std::string eventName);
	void OnEnabledChanged(std::string oldValue, CVarWrapper cvar);
};

