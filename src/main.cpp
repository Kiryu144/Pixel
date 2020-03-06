#include "graphics/implementation/sdl2/sdl2renderer.h"
#include "graphics/implementation/sdl2/sdl2texture.h"
#include "graphics/implementation/sdl2/sdl2window.h"

#include <memory>

int main()
{
	using namespace Pixel;

	std::unique_ptr<Graphics::SDL2Window> window(new Graphics::SDL2Window());
	std::unique_ptr<Graphics::SDL2Renderer> renderer(new Graphics::SDL2Renderer(window->getSDLWindow()));
	std::unique_ptr<Graphics::SDL2Texture> texture(new Graphics::SDL2Texture(renderer->getSDLRenderer(), {100, 100}));

	return 0;
}