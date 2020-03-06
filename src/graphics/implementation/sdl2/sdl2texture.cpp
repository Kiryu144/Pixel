#include "sdl2texture.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2Texture::SDL2Texture( SDL_Renderer* renderer,
										   const Vector2ui& size,
										   int access )
{
	m_sdlTexture = createTexture( renderer, size, access );
}

Pixel::Graphics::SDL2Texture::SDL2Texture( SDL_Renderer* renderer,
										   const Vector2ui& size )
	: m_size( size )
{
	m_sdlTexture = createTexture( renderer, size, SDL_TEXTUREACCESS_STATIC );
}

Pixel::Graphics::SDL2Texture::~SDL2Texture()
{
	SDL_DestroyTexture( m_sdlTexture );
}

const Vector2ui& Pixel::Graphics::SDL2Texture::getSize() const
{
	return m_size;
}

SDL_Texture* Pixel::Graphics::SDL2Texture::createTexture( SDL_Renderer* renderer,
														  const Vector2ui& size,
														  int access )
{
	pixel_assert( renderer );
	pixel_assert( size.x > 0 && size.y > 0 );
	SDL_Texture* sdlTexture = SDL_CreateTexture(
		renderer, SDL_PIXELFORMAT_RGBA8888, access, m_size.x, m_size.y );
	pixel_assert( sdlTexture );
	return sdlTexture;
}
