#include "sdl2texture.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2Texture::SDL2Texture( SDL_Renderer* renderer,
										   const Vector2ui& size )
	: m_size( size )
{
	pixel_assert( renderer );
	pixel_assert( size.x > 0 && size.y > 0 );
	m_sdlTexture = SDL_CreateTexture( renderer,
									  SDL_PIXELFORMAT_RGBA8888,
									  SDL_TEXTUREACCESS_STATIC,
									  m_size.x,
									  m_size.y );
	pixel_assert(m_sdlTexture);
}

Pixel::Graphics::SDL2Texture::~SDL2Texture()
{
	SDL_DestroyTexture( m_sdlTexture );
}

const Vector2ui& Pixel::Graphics::SDL2Texture::getSize() const
{
	return m_size;
}
