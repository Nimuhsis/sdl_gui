# include "button.hpp"

// Initicialize a button
// @w : Width of the Button
// @h : Height of the Button
// @text : text that appears on the button
// @size : size of the text
Button::Button( int w, int h, std::string text, int size, SDL_Renderer *renderer )
	:m_text( text, size, renderer )
{
	m_body.x = 1;
	m_body.y = 1;
	m_body.w = w;
	m_body.h = h;

	m_color = { 0xff, 0xff, 0xff, 0xff };
}

void Button::setPosition( int x, int y )
{
	m_body.x = x;
	m_body.y = y;
	m_text.set_position( ( m_body.w / 2 ) - ( 100 / 2 ) + x , ( m_body.h / 2 ) - ( 50 / 2 ) + y );
}

void Button::setButtonColor( SDL_Color color )
{
	m_color = color;	
}

void Button::setTextColor( SDL_Color color )
{
	m_text.set_color( color );
}

void Button::show( SDL_Renderer *renderer )
{
	SDL_SetRenderDrawColor( renderer, m_color.r, m_color.g, m_color.b, m_color.a );
    SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
    SDL_RenderFillRect( renderer, &m_body );

	m_text.show( renderer );
}
