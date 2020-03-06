#ifndef NOCOPY_H
#define NOCOPY_H

namespace Pixel
{

class NoCopy
{
public:
	NoCopy() = default;
	NoCopy( const NoCopy& other ) = delete;
	NoCopy& operator=( const NoCopy& other ) = delete;
};

} // namespace Pixel

#endif // NOCOPY_H
