#ifndef SDL2WINDOW_H
#define SDL2WINDOW_H

#include "graphics/generic/iwindow.h"
#include "graphics/implementation/sdl2/sdl2renderer.h"

#include <memory>

class SDL_Window;

namespace Pixel
{

namespace Graphics
{

class SDL2Renderer;

class SDL2Window : public IWindow
{
protected:
	SDL_Window* m_sdlWindow;
	std::unique_ptr<SDL2Renderer> m_renderer;
	bool m_isResizeable {false};
	bool m_closeWindow {false};

public:
	SDL2Window( const Vector2ui& size	= { 400, 400 },
				const std::string& title = "Pixel" );
	virtual ~SDL2Window();

	SDL_Window* getNativeSDLWindow();
	const SDL_Window* getNativeSDLWindow() const;

	SDL2Renderer* getSDL2Renderer();
	const SDL2Renderer* getSDL2Renderer() const;

	void setSize( const Vector2ui& size ) override;
	const Vector2ui& getSize() const override;

	const std::string& getTitle() const override;
	void setTitle( const std::string& title ) override;

	bool getIsResizeable() const override;
	void setResizeable( bool resizeable ) override;

	bool getShouldClose() const override;
	void update() override;
};

} // namespace Graphics
} // namespace Pixel

#endif
