#include <iostream>

#include "AppUpdater.h"

#include "Constants.h"
#include "TheFirstGame.h"

int main() {
	TheFirstGame game(TextureDir);
	GameFactory::AppUpdater appUpdater(game);
	appUpdater.Init({WindowWidth, WindowHeight}, WindowTitle);
	appUpdater.SetFrameRate(FrameRateLimit);
	appUpdater.Run();
	appUpdater.Deinit();
}