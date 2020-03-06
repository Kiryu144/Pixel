#ifndef VECTOR2_H
#define VECTOR2_H

template< typename T >
struct Vector2
{
	T x, y;

	Vector2( const T& x, const T& y ) : x( x ), y( y ) {}
	Vector2( const T& v = 0 ) : x( v ), y( v ) {}

	Vector2 operator+( const Vector2& other ) const
	{
		return Vector2( x + other.x, y + other.y );
	}

	Vector2 operator-( const Vector2& other ) const
	{
		return Vector2( x - other.x, y - other.y );
	}

	Vector2 operator*( const Vector2& other ) const
	{
		return Vector2( x * other.x, y * other.y );
	}

	Vector2 operator/( const Vector2& other ) const
	{
		return Vector2( x / other.x, y / other.y );
	}

	Vector2 operator*( const T& v ) const
	{
		return Vector2( x * v, y * v );
	}

	Vector2 operator/( const T& v ) const
	{
		return Vector2( x * v, y * v );
	}

	void operator+=( const Vector2& other )
	{
		x += other.x;
		y += other.y;
	}

	void operator-=( const Vector2& other )
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=( const Vector2& other )
	{
		x *= other.x;
		y *= other.y;
	}

	void operator/=( const Vector2& other )
	{
		x /= other.x;
		y /= other.y;
	}

	void operator*=( const T& v )
	{
		x *= v;
		y *= v;
	}

	void operator/=( const T& v )
	{
		x /= v;
		y /= v;
	}

	template <typename TT>
	bool operator==( const TT& v1) const
	{
		return v1.x == x && v1.y == y;
	}
};

typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<float> Vector2float;
typedef Vector2<double> Vector2double;

#endif
