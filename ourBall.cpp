#include "ourBall.h"

Ball :: Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setRadius(m_Radius); //10.0f
	m_Shape.setPosition(m_Position);
}

FloatRect Ball::getBounds()
{
	 return m_Shape.getGlobalBounds();
}

CircleShape Ball::getBall()
{
        	return m_Shape;
}

void Ball::reboundFromSides()
{
	m_DirectionX = -m_DirectionX;
}


void Ball::reboundFromBatOrTop()
{
        	m_DirectionY = - m_DirectionY;
}

void Ball::reSetFromBottomToTop(int scoreV)
{
        m_Position.y = 11;
        
        //m_Position.x = 500;//ie. 480+20
        
        srand((int) time(0)+scoreV);
        m_Position.x=480+(rand()%20);//500, ie. 480+20 
// MyIdea: to randomize (480-20,480+20)  

        m_DirectionY = - m_DirectionY;
}	
void Ball::update(Time dt)
{
   	m_Position.y = m_Position.y +  m_DirectionY * m_Speed * dt.asSeconds();   
        	m_Position.x = m_Position.x + m_DirectionX * m_Speed * dt.asSeconds();

       	m_Shape.setPosition(m_Position);
}
