#ifndef SDL2WINDOW_H
#define SDL2WINDOW_H

#include "graphics/generic/iwindow.h"

class SDL_Window;

namespace Pixel
{

namespace Graphics
{

class SDL2Window : public IWindow
{
private:
	SDL_Window* m_sdlWindow;
	bool m_isResizeable {false};

public:
	SDL2Window( const Vector2ui& size	= { 400, 400 },
				const std::string& title = "Pixel" );
	virtual ~SDL2Window();

	SDL_Window* getSDLWindow();
	const SDL_Window* getSDLWindow() const;

	void setSize( const Vector2ui& size ) override;
	const Vector2ui& getSize() const override;

	const std::string& getTitle() const override;
	void setTitle( const std::string& title ) override;

	bool getIsResizeable() const override;
	void setResizeable( bool resizeable ) override;
};

} // namespace Graphics
} // namespace Pixel

#endif
