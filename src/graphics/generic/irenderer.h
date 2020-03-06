#ifndef IRENDERER_H
#define IRENDERER_H

#include "logic/interface.h"
#include "logic/nocopy.h"

namespace Pixel
{

namespace Graphics
{

class IRenderer : public Interface, public NoCopy
{
public:
	IRenderer() = default;
};

} // namespace Graphics
} // namespace Pixel

#endif // IRENDERER_H
