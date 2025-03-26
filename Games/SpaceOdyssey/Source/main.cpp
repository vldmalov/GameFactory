#include "AppUpdater/AppUpdater.h"

#include "Constants.h"
#include "SpaceOdyssey.h"

int main() {
	SpaceOdyssey game(TextureDir);
	GameFactory::AppUpdater appUpdater(game);
	appUpdater.Init({WindowWidth, WindowHeight}, WindowTitle, FrameRateLimit);
	appUpdater.RunMainLoop();
	appUpdater.Deinit();
}