# include "text.hpp"

# include <iostream>

Text::Text( std::string text, int size, SDL_Renderer *renderer )
{
	std::string font_path = "res/fonts/Roboto/Roboto-Regular.ttf";
	TTF_Font *font = TTF_OpenFont( font_path.c_str(), size );

	if ( font == NULL ) {
		std::cout << "\x1b[31mCould not find font!\x1b[0m" << '\n';
		exit( 1 );
	}

	m_color = { 0xff, 0xff, 0xff, 0xff };
	SDL_Surface* surface = TTF_RenderText_Solid( font, text.c_str(), m_color );
	m_texture = SDL_CreateTextureFromSurface( renderer, surface );

	m_body.x = 1;
	m_body.y = 1;
	m_body.w = 100;
	m_body.h = 50;

	TTF_CloseFont( font );
	SDL_FreeSurface( surface );
}

Text::~Text()
{
	SDL_DestroyTexture( m_texture );
}

void Text::set_position( int x, int y )
{
	m_body.x = x;
	m_body.y = y;
}

void Text::set_color( SDL_Color color )
{
	m_color = color;
}

void Text::show( SDL_Renderer *renderer )
{
	SDL_RenderCopy( renderer, m_texture, NULL, &m_body );
}
