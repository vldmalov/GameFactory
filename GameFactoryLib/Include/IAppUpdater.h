#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>

namespace GameFactory {

class IAppDelegate;

class IAppUpdater {
public:
	explicit IAppUpdater(IAppDelegate& delegate) :
		mAppDelegate(delegate) {}
	virtual ~IAppUpdater() = default;

	virtual void Init(sf::Vector2u windowSize, const sf::String& windowTitle) = 0;
	virtual void Deinit() = 0;

	virtual void Run() = 0;
	virtual void SetFrameRate(unsigned short fps) = 0;

protected:
	IAppDelegate& mAppDelegate;
};

}