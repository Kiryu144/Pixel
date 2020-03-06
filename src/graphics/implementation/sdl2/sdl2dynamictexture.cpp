#include "sdl2dynamictexture.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2DynamicTexture::SDL2DynamicTexture( SDL_Renderer* renderer,
														 const Vector2ui& size )
	: SDL2Texture( renderer, size, SDL_TEXTUREACCESS_STREAMING ),
	  m_pixelData( new uint8_t[ size.area() * 4 ] )
{
}

uint8_t* Pixel::Graphics::SDL2DynamicTexture::getPixelData()
{
	return m_pixelData.get();
}

void Pixel::Graphics::SDL2DynamicTexture::update()
{
	void* pixels;
	int pitch;
	pixel_assert(SDL_LockTexture(m_sdlTexture, nullptr, &pixels, &pitch) == 0);
	memcpy(pixels, m_pixelData.get(), sizeof( uint8_t ) * 4 * m_size.area());
	SDL_UnlockTexture(m_sdlTexture);
}
