#ifndef BUTTON_HPP
#define BUTTON_HPP

# include <SDL2/SDL.h>
# include <string>

#include "text.hpp"

class Button
{
public:
	/* Initicialize a button
	   @w : Width of the Button
	   @h : Height of the Button
	   @text : text that appears on the button
	   @size : size of the text
	   */
	Button( int w, int h, std::string text, int size, SDL_Renderer *renderer );

	/* Set the position of the Button
	   @x : x position of the Button
	   @y : y position of the Button
	   */
	void setPosition( int x, int y );

	/* Set the color of RGBA of the Button
		@r : red color of the Button 
		@g : green color of the Button 
		@b : blue color of the Button 
		@a : alpha color of the Button 
	   */
	void setButtonColor( SDL_Color color );

	void setTextColor( SDL_Color color );

	/* Show the Button on the screen
	   @renderer : the sdl renderer
	   */
	void show( SDL_Renderer *renderer );

private:
	SDL_Rect m_body;
	SDL_Color m_color;

	Text m_text;
};

#endif // BUTTON_HPP
