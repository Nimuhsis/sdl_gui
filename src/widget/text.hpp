# ifndef TEXT_HPP
# define TEXT_HPP

# include <string>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

class Text
{
public:
	Text( std::string text, int size, SDL_Renderer *renderer );
	~Text();

	void show( SDL_Renderer *renderer );

	void set_position( int x, int y );

	void set_color( SDL_Color color );

private:
	SDL_Texture* m_texture;
	SDL_Rect m_body;
	SDL_Color m_color;
};

# endif // TEXT_HPP
