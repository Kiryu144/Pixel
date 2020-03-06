#include "sdl2texture.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2Texture::SDL2Texture( SDL_Renderer* renderer,
										   const Vector2ui& size,
										   int access )
	: m_size( size )
{
	m_sdlTexture  = createTexture( renderer, size, access );
	m_sdlRenderer = renderer;
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
		renderer, SDL_PIXELFORMAT_RGBA8888, access, size.x, size.y );
	pixel_assert( sdlTexture );
	SDL_SetTextureBlendMode(sdlTexture, SDL_BLENDMODE_BLEND );
	return sdlTexture;
}
void Pixel::Graphics::SDL2Texture::render( const Vector2ui& position )
{
	render( position, m_size );
}

void Pixel::Graphics::SDL2Texture::render( const Vector2ui& position,
										   const Vector2ui& size )
{
	SDL_Rect src{
		0, 0, static_cast< int >( m_size.x ), static_cast< int >( m_size.y )
	};
	SDL_Rect dst{ static_cast< int >( position.x ),
				  static_cast< int >( position.y ),
				  static_cast< int >( size.x ),
				  static_cast< int >( size.y ) };

	SDL_RenderCopy( m_sdlRenderer, m_sdlTexture, &src, &dst );
}
