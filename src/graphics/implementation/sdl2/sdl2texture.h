#ifndef SDL2TEXTURE_H
#define SDL2TEXTURE_H

#include "graphics/generic/itexture.h"

struct SDL_Renderer;
struct SDL_Texture;

namespace Pixel
{

namespace Graphics
{

class SDL2Texture : public ITexture
{
private:
	Vector2ui m_size;
	SDL_Texture* m_sdlTexture;

public:
	SDL2Texture( SDL_Renderer* renderer, const Vector2ui& size );
	virtual ~SDL2Texture();
	const Vector2ui& getSize() const override;
};

} // namespace Graphics
} // namespace Pixel

#endif
