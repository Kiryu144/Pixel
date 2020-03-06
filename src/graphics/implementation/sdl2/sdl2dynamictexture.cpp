#include "sdl2dynamictexture.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2DynamicTexture::SDL2DynamicTexture( SDL_Renderer* renderer,
														 const Vector2ui& size )
	: SDL2Texture( renderer, size, SDL_TEXTUREACCESS_STREAMING ),
	  m_pixelData( new uint8_t[ size.area() ] )
{
}

uint8_t* Pixel::Graphics::SDL2DynamicTexture::getPixelData()
{
	return m_pixelData.get();
}

void Pixel::Graphics::SDL2DynamicTexture::update()
{
	pixel_assert( SDL_UpdateTexture(
		m_sdlTexture, nullptr, m_pixelData.get(), sizeof( uint8_t ) * 4 ) );
}
