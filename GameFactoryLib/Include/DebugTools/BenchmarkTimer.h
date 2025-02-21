#pragma once

#include <chrono>
#include <string>

namespace GameFactory {
using HighResClock = std::chrono::high_resolution_clock;
using HighResTimePoint = std::chrono::time_point<HighResClock>;
using DurationSeconds = std::chrono::duration<double>;
using DurationMilli = std::chrono::duration<double, std::milli>;

enum class BenchmarkTimerType {
	SECONDS = 0,
	MILLISECONDS,
	MICROSECONDS,
	NANOSECONDS
};

class BenchmarkTimer final {
public:
	explicit BenchmarkTimer(BenchmarkTimerType type = BenchmarkTimerType::SECONDS);
	explicit BenchmarkTimer(const std::string& title, BenchmarkTimerType type = BenchmarkTimerType::SECONDS);
	~BenchmarkTimer();

private:
	const std::string mTitle {};
	const BenchmarkTimerType mType { BenchmarkTimerType::SECONDS };
	HighResTimePoint mStartTime;
};
}