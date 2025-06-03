#include"ourBat.cpp"
#include"ourBall.cpp"
#include<sstream>
using namespace sf; 
int main()
{
	VideoMode vm(960,540);
	RenderWindow window(vm,"Pong Game");
	int score =0;
	int lives = 3;
	Bat bat(960/2,540-20,50.0,5.0);  
	
	Clock clock; 
	
	// We need to choose a font
        	Font kfont;
        	kfont.loadFromFile("KOMIKAP_.ttf");
        
        	Text hud;     
       	 // Set the font to our message
        	hud.setFont(kfont); 
        	// Assign the actual message
        	hud.setString(" "); //// Set <initial> String
        	// Make it really big
        	hud.setCharacterSize(30); 
        	// Choose a color
        	hud.setFillColor(Color::White);
        	// Position the text
        	hud.setPosition(20, 20);
        
        	int scoreValue=0;
        	int livesValue=3; 
	
	Ball ball(960/2,0); 
	
	
	while(window.isOpen()){
	    	/*
            ****************************************
            Handle the players' input
            ****************************************
            */
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    	window.close();
            }
	    if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                	window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                	bat.moveLeft();
            }
            else
            {
                bat.stopLeft();
            }
            
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                bat.moveRight();
            }
            else
            {
                bat.stopRight();
            } 
             
            Time dt = clock.restart();
            bat.update(dt);
 
	 /*
            ****************************************
            Update the scene
            ****************************************
            */     
            ball.update(dt); 
            
            
            // Update the score text
            std::stringstream ss;
            ss<< "Score = " << scoreValue << " Lives: " << livesValue;
            hud.setString(ss.str());  // Set <Updated> String
            hud.setPosition(20, 20);
            /*
            ****************************************
            Handle the Graphics-elements' Collision
            ****************************************
            */

            if(ball.getBounds().left < 0 || (ball.getBounds().left+ball.getBounds().width >960)){

                  	ball.reboundFromSides();
            }

            if(ball.getBounds().top > 540){

	          ball.reSetFromBottomToTop(scoreValue);//void reboundBottom(); 

	          livesValue--; 

	          if(livesValue==0)
          { 
                    std::stringstream sss;
                    sss<<" Game Over";
                    hud.setString(sss.str());
                    hud.setPosition(20, 20); 

                    scoreValue=0;
                    livesValue=3;           
                }
	    } 

            if(ball.getBounds().top < 0){

	          ball.reboundFromBatOrTop();

	          scoreValue++;
	    }
	    
	    if(ball.getBounds().intersects(bat.getBounds())){

	          ball.reboundFromBatOrTop(); //void reboundBottom();
	    } 
        



            /*
            ****************************************
            Draw the scene
            ****************************************  
            */
            // Draw our game scene here
            // Clear everything from the last frame
	    window.clear();//window.clear(Color::Black);
	    window.draw(hud);
            window.draw(bat.getBat()); // since m_Bat is private, we pass it through a member function call
            window.draw(ball.getBall());
            window.display();
	}
	return 0;

}
