#ifndef IDYNAMICTEXTURE_H
#define IDYNAMICTEXTURE_H

#include "graphics/generic/itexture.h"

#include <cstdint>

namespace Pixel
{

namespace Graphics
{

class IDynamicTexture : public ITexture
{
public:
	IDynamicTexture() = default;

	virtual uint8_t* getPixelData() = 0;
	virtual void update() = 0;
};

} // namespace Graphics
} // namespace Pixel

#endif // IDYNAMICTEXTURE_H
