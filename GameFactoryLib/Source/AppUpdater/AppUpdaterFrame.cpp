#include "AppUpdater/AppUpdaterFrame.h"

std::ostream& operator<<(std::ostream& os, const AppUpdaterFrame& obj) {
	return os << "Frame: " << obj.mFrameIndex << " Game Time: " << obj.mEllapsedGameTime
			<< " App Time: " << obj.mEllapsedAppTime << std::endl;
}