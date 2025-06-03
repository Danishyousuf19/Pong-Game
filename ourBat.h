#include<SFML/Graphics.hpp>
using namespace sf;

class Bat
{
private:
	 Vector2f m_Size;//m_Shape
	 Vector2f m_Position;
	 RectangleShape m_Bat;//m_batShape//m_Shape
	 
	 float m_Speed = 600.0f;
	 bool m_MovingLeft = false;
	 bool m_MovingRight = false;
	 
	
public:
	Bat(float startX, float startY, float width, float height) ;
	
	RectangleShape getBat();//getShape()
	FloatRect getBounds();
	
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	
	void update(Time dt);
	
};