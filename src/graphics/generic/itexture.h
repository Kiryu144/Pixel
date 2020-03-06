#ifndef ITEXTURE_H
#define ITEXTURE_H

#include "logic/interface.h"
#include "logic/nocopy.h"
#include "math/vector2.h"

namespace Pixel
{

namespace Graphics
{

class ITexture : public Interface, public NoCopy
{
public:
	ITexture() = default;
	virtual const Vector2ui& getSize() const = 0;
};

} // namespace Graphics
} // namespace Pixel

#endif //ITEXTURE_H
