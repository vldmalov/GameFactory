#include "DebugTools/BenchmarkTimer.h"

#include <iostream>
#include <unordered_map>

namespace GameFactory {

static const std::unordered_map<BenchmarkTimerType, float> BenchmarkTimerRatioMap = {
	{ BenchmarkTimerType::SECONDS, 1.f },
	{ BenchmarkTimerType::MILLISECONDS, 1e3f },
	{ BenchmarkTimerType::MICROSECONDS, 1e6f },
	{ BenchmarkTimerType::NANOSECONDS, 1e9f }
};

static const std::unordered_map<BenchmarkTimerType, std::string> BenchmarkTimerTypePostfixMap = {
	{ BenchmarkTimerType::SECONDS, "seconds" },
	{ BenchmarkTimerType::MILLISECONDS, "milli" },
	{ BenchmarkTimerType::MICROSECONDS, "micro" },
	{ BenchmarkTimerType::NANOSECONDS, "nano" }
};

BenchmarkTimer::BenchmarkTimer(BenchmarkTimerType type)
: mType(type)
, mStartTime{ HighResClock::now() } {
}

BenchmarkTimer::BenchmarkTimer(const std::string& title, BenchmarkTimerType type)
: mTitle(title)
, mType(type)
, mStartTime{ HighResClock::now() } {
}

BenchmarkTimer::~BenchmarkTimer() {
	const HighResTimePoint endTime = HighResClock::now();
	const DurationSeconds elapsedTimeSecond = endTime - mStartTime;

	if(!mTitle.empty()) {
		std::cout << mTitle << ". ";
	}
	const float ratio = BenchmarkTimerRatioMap.at(mType);
	std::cout << "Elapsed time: " << std::fixed << ratio * elapsedTimeSecond.count() << " ";
	std::cout << BenchmarkTimerTypePostfixMap.at(mType) << std::endl;
}
}