#include "sdl2renderer.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2Renderer::SDL2Renderer( SDL_Window* sdlWindow )
{
	pixel_assert( sdlWindow );
	m_sdlRenderer
		= SDL_CreateRenderer( sdlWindow,
							  -1,
							  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
								  | SDL_RENDERER_TARGETTEXTURE );
	pixel_assert( m_sdlRenderer );
}

Pixel::Graphics::SDL2Renderer::~SDL2Renderer()
{
	SDL_DestroyRenderer( m_sdlRenderer );
}

SDL_Renderer* Pixel::Graphics::SDL2Renderer::getSDLRenderer()
{
	return m_sdlRenderer;
}

const SDL_Renderer* Pixel::Graphics::SDL2Renderer::getSDLRenderer() const
{
	return m_sdlRenderer;
}
