#pragma once
#include <ostream>

class AppUpdaterFrame final {
public:
	AppUpdaterFrame(unsigned int frameIndex = 0, float ellapsedGameTime = 0.f, float ellapsedAppTime = 0.f)
		: mFrameIndex(frameIndex)
		, mEllapsedGameTime(ellapsedGameTime)
		, mEllapsedAppTime(ellapsedAppTime) {}

	~AppUpdaterFrame() = default;

	unsigned int mFrameIndex{0};
	float mEllapsedGameTime{0.f};
	float mEllapsedAppTime{0.f};

	friend std::ostream& operator<<(std::ostream& os, const AppUpdaterFrame& obj);
};

std::ostream& operator<<(std::ostream& os, const AppUpdaterFrame& obj);
