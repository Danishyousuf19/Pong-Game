#include "ourBat.h"

Bat :: Bat(float startX, float startY, float startWidth, float startHeight)
{
	m_Position.x = startX;
	m_Position.y = startY; 
	m_Size.x = startWidth;// m_Shape.x = width;
	m_Size.y = startHeight;//m_Shape.y = height;
	m_Bat.setSize(m_Size);//m_Bat.setSize(m_Shape);//sf::Vector2f(50,5)
	m_Bat.setPosition(m_Position);
	
}
RectangleShape Bat::getBat()
{	 return m_Bat; // since m_Bat is private, we pass it through a member function call
}

FloatRect Bat::getBounds()
{
	 return m_Bat.getGlobalBounds();
}

void Bat:: moveLeft()
{
	 m_MovingLeft = true;
}

void Bat:: moveRight()
{
	 m_MovingRight = true;
}
	 
void Bat:: stopLeft()
{
	 m_MovingLeft = false;
}

void Bat:: stopRight()
{
	 m_MovingRight = false;
}
void Bat::update(Time dt)
{	 
          if(m_MovingLeft)
		if(m_Position.x >0)
     		m_Position.x -= m_Speed * dt.asSeconds();
     
         if(m_MovingRight){
         	if(m_Position.x < 910)
         		m_Position.x += m_Speed * dt.asSeconds();
         }       
         m_Bat.setPosition(m_Position);  
}
