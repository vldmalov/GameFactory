#pragma once

#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {

class IAppDelegate;

class IAppUpdater {
public:
	explicit IAppUpdater(IAppDelegate& delegate) :
		mAppDelegate(delegate) {}
	virtual ~IAppUpdater() = default;

	virtual void Init(sf::Vector2u windowSize, const sf::String& windowTitle, unsigned int frameRate) = 0;
	virtual void Deinit() = 0;
	virtual void RunMainLoop() = 0;

protected:
	IAppDelegate& mAppDelegate;
};

}