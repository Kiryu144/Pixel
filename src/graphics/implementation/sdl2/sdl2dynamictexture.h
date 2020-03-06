#ifndef SDL2DYNAMICTEXTURE_H
#define SDL2DYNAMICTEXTURE_H

#include "graphics/implementation/sdl2/sdl2texture.h"

#include <memory>

namespace Pixel
{

namespace Graphics
{

class SDL2DynamicTexture : public SDL2Texture
{
protected:
	std::unique_ptr<uint8_t[]> m_pixelData;

public:
	SDL2DynamicTexture( SDL_Renderer* renderer, const Vector2ui& size );

	uint8_t* getPixelData();
	void update();
};

} // namespace Graphics
} // namespace Pixel

#endif
