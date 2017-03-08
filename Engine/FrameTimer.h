/*
AssaultCube
Class: FrameTimer
Purpose: DeltaTime and Frame-rate Idependence

@author Battlefrog
*/

#pragma once
#include <chrono> 

class FrameTimer
{
public:

	FrameTimer();

	float Mark();

private:

	std::chrono::steady_clock::time_point last;
};