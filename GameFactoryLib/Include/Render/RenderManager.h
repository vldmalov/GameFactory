#pragma once

#include "IRenderManager.h"
#include <vector>

namespace GameFactory {
class RenderManager final : public IRenderManager {
public:
	explicit RenderManager(sf::RenderTarget& renderTarget);
	~RenderManager() = default;

	void Init() override;
	void Deinit() override;

	void Render() override;

	void AddDrawable(IDrawable*) override;
	void RemoveDrawable(IDrawable*) override;

private:
	sf::RenderTarget& mRenderTarget;
	std::vector<IDrawable*> mDrawables;
};
}