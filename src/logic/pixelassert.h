#ifndef PIXELASSERT_H
#define PIXELASSERT_H

#define xstr( a ) str( a )
#define str( a ) #a

#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ ) \
	|| defined( __NT__ )
#define PIXEL_OS_WINDOWS
#elif __APPLE__
#define PIXEL_OS_MAC
#elif defined( __linux__ ) || defined( __unix__ )
#define PIXEL_OS_LINUX
#endif

#include <cstdio>

#ifdef PIXEL_OS_WINDOWS
#include <windows.h>
#define pixel_fatal( message )                                                \
	do                                                                        \
	{                                                                         \
		MessageBox( NULL, __FILE__ "(" xstr(__LINE__) "): " message, NULL, MB_OK ); \
		exit( -1 );                                                           \
	} while( false )
#elif defined( PIXEL_OS_LINUX ) || defined( PIXEL_OS_MAC )
#define pixel_fatal( message)                                    \
	do                                                                 \
	{                                                                  \
		std::cerr << __FILE__ "(" __LINE__ "): " message << std::endl; \
		exit( -1 );                                                    \
	} while( false )
#endif

#ifndef NDEBUG
#define pixel_assert( condition )                                          \
	do                                                                     \
	{                                                                      \
		if( !( condition ) )                                               \
		{                                                                  \
			pixel_fatal( "pixel_assert(" xstr( condition ) ") == false" ); \
		}                                                                  \
	} while( false )

#else
#define pixel_assert( condition ) \
	do                            \
	{                             \
                                  \
	} while( false )
#endif

#endif // PIXELASSERT_H
