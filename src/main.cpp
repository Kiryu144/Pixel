#include "graphics/implementation/sdl2/sdl2renderer.h"
#include "graphics/implementation/sdl2/sdl2texture.h"
#include "graphics/implementation/sdl2/sdl2window.h"

#include <memory>

int main()
{
	using namespace Pixel;

	std::unique_ptr< Graphics::IWindow > window( new Graphics::SDL2Window() );
	std::unique_ptr< Graphics::ITexture > texture( new Graphics::SDL2Texture(
		static_cast< Graphics::SDL2Window* >( window.get() )
			->getSDL2Renderer()
			->getNativeSDL2Renderer(),
		{ 100, 100 } ) );

	while( !window->getShouldClose() )
	{
		window->update();
	}

	return 0;
}