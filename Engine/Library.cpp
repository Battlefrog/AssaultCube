#include "Library.h"

bool CommonLibrary::CalculateCollision(float currentRight, float currentBottom, 
								float objectRight, float objectBottom, 
								int currentXPos, int currentYPos, 
								int objectXPos, int objectYPos)
{
	return (currentRight >= currentXPos &&
			objectXPos <= float(currentRight) &&
			objectBottom >= currentYPos &&
			objectYPos <= float(currentBottom));
}