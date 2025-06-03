#include<SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
	 Vector2f m_Position;
	 float m_Radius = 10.0f;
	 CircleShape m_Shape;
	 
	 float m_Speed = 800.0f;
	 float m_DirectionX = 0.2f;
	 float m_DirectionY = 0.2f;	 
	 
public:
	Ball(float startX, float startY);
	FloatRect getBounds();
	CircleShape getBall();
	
	void reboundFromSides();
	void reboundFromBatOrTop();
	void reSetFromBottomToTop(int);//void reboundBottom();
	
	void update(Time dt);
};
