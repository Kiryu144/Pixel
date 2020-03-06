#ifndef IWINDOW_H
#define IWINDOW_H

#include "logic/interface.h"
#include "logic/nocopy.h"
#include "math/vector2.h"

#include <string>

namespace Pixel
{

namespace Graphics
{

class IWindow : public Interface, public NoCopy
{
public:
	IWindow() = default;

	virtual void setSize(const Vector2ui& size) = 0;
	virtual const Vector2ui& getSize() const = 0;

	virtual const std::string& getTitle() const = 0;
	virtual void setTitle(const std::string& title) = 0;

	virtual bool getIsResizeable() const = 0;
	virtual void setResizeable( bool resizeable ) = 0;

	virtual bool getShouldClose() const = 0;
	virtual void update() = 0;
};

} // namespace Graphics
} // namespace Pixel

#endif //IWINDOW_H
