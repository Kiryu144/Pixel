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
protected:
	Vector2ui m_size;
	SDL_Renderer* m_sdlRenderer;
	SDL_Texture* m_sdlTexture;

	SDL2Texture(SDL_Renderer* renderer, const Vector2ui& size, int access);
	SDL_Texture* createTexture(SDL_Renderer* renderer, const Vector2ui& size, int access);

public:
	SDL2Texture( SDL_Renderer* renderer, const Vector2ui& size );
	~SDL2Texture();
	const Vector2ui& getSize() const override;

	void render( const Vector2ui& position ) override;
	void render( const Vector2ui& position, const Vector2ui& size ) override;
};

} // namespace Graphics
} // namespace Pixel

#endif
