#define SDL_MAIN_HANDLED

#include "graphics/implementation/sdl2/sdl2renderer.h"
#include "graphics/implementation/sdl2/sdl2dynamictexture.h"
#include "graphics/implementation/sdl2/sdl2window.h"

#include <memory>
#include <iostream>


int main(int argc, char** argv)
{
	using namespace Pixel;

	std::unique_ptr< Graphics::IWindow > window( new Graphics::SDL2Window() );
	std::unique_ptr< Graphics::SDL2DynamicTexture > texture( new Graphics::SDL2DynamicTexture(static_cast< Graphics::SDL2Window* >( window.get() )
			->getSDL2Renderer()
			->getNativeSDL2Renderer(),
		{ 256, 256 } ) );

	uint8_t* data = texture->getPixelData();
	for(int x = 0; x < texture->getSize().x; ++x){
		for(int y = 0; y < texture->getSize().y; ++y){
			int index = y * texture->getSize().x + x;
			data[index*4 + 3] = x;
			data[index*4 + 2] = y;
			data[index*4 + 1] = 64;
			data[index*4 + 0] = 255;
		}
	}
	texture->update();

	while( !window->getShouldClose() )
	{
		texture->render({0, 0}, {256, 256});

		window->update();
	}

	return 0;
}