#include "sdl2window.h"

#include "logic/pixelassert.h"

#include <SDL2/SDL.h>

Pixel::Graphics::SDL2Window::SDL2Window( const Vector2ui& size,
										 const std::string& title )
{
	m_sdlWindow = SDL_CreateWindow( title.c_str(),
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									size.x,
									size.y,
									SDL_WINDOW_INPUT_GRABBED );
	pixel_assert( m_sdlWindow );
}

Pixel::Graphics::SDL2Window::~SDL2Window()
{
	SDL_DestroyWindow( m_sdlWindow );
}

void Pixel::Graphics::SDL2Window::setSize( const Vector2ui& size )
{
	pixel_assert( size.x > 0 && size.y > 0 );
	SDL_SetWindowSize( m_sdlWindow, size.x, size.y );
}

const Vector2ui& Pixel::Graphics::SDL2Window::getSize() const
{
	static Vector2ui size;
	int w, h;
	SDL_GetWindowSize( m_sdlWindow, &w, &h );
	size = { static_cast<unsigned int>(w), static_cast<unsigned int>(h) };
	return size;
}

const std::string& Pixel::Graphics::SDL2Window::getTitle() const
{
	static std::string title;
	title = std::string( SDL_GetWindowTitle( m_sdlWindow ) );
	return title;
}

void Pixel::Graphics::SDL2Window::setTitle( const std::string& title )
{
	SDL_SetWindowTitle( m_sdlWindow, title.c_str() );
}

bool Pixel::Graphics::SDL2Window::getIsResizeable() const
{
	return m_isResizeable;
}
void Pixel::Graphics::SDL2Window::setResizeable( bool resizeable )
{
	SDL_SetWindowResizable( m_sdlWindow, static_cast< SDL_bool >( resizeable ) );
	m_isResizeable = resizeable;
}

SDL_Window* Pixel::Graphics::SDL2Window::getSDLWindow()
{
	return m_sdlWindow;
}

const SDL_Window* Pixel::Graphics::SDL2Window::getSDLWindow() const
{
	return m_sdlWindow;
}
