#ifndef SDL2RENDERER_H
#define SDL2RENDERER_H

#include "graphics/generic/irenderer.h"

class SDL_Window;
class SDL_Renderer;

namespace Pixel
{
namespace Graphics
{

class SDL2Renderer : public IRenderer
{
private:
	SDL_Renderer* m_sdlRenderer;

public:
	SDL2Renderer( SDL_Window* sdlWindow );
	virtual ~SDL2Renderer();

	SDL_Renderer* getSDLRenderer();
	const SDL_Renderer* getSDLRenderer() const;
};

} // namespace Graphics
} // namespace Pixel

#endif
