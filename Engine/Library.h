#pragma once
class CommonLibrary
{
public:
	
	bool CalculateCollision(float currentRight, float currentBottom, 
							float objectRight, float objectBottom,
							int currentXPos, int currentYPos,
							int objectXPos, int objectYPos);

};

