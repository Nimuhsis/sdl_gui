# include <SDL2/SDL.h>
# include "widget/button.hpp"
# include "widget/text.hpp"

int WIDTH = 640;
int HEIGHT = 480;

void init() {
	if ( TTF_Init() == -1 ) {
        SDL_Log( "Unable to initialize TTF: %s", TTF_GetError() );
		exit( 1 );
	}

	if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {
        SDL_Log( "Unable to initialize SDL: %s", SDL_GetError() );
        exit( 1 );
	}
}

int main( /*int argc, char** argv*/ )
{
	init();

	SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_Event event;
	bool running = 1;

	window = SDL_CreateWindow( "Change Color Screen",   // Title
							   SDL_WINDOWPOS_UNDEFINED, // Pos_x
							   SDL_WINDOWPOS_UNDEFINED, // Pos_y
							   WIDTH, HEIGHT,           // Width, Height
							   SDL_WINDOW_SHOWN );      // State

	renderer = SDL_CreateRenderer( window, -1, 0 );

	Button bt( 200, 50, "New Button", 30, renderer );
	bt.setPosition( 245, 218 );
	bt.setButtonColor( SDL_Color{ 0xf, 0xff, 0xff, 0xf0 } );
	bt.setTextColor( SDL_Color{ 0x0, 0x0, 0x0, 0xf0 } );

	while ( running ) {
        while ( SDL_PollEvent( &event ) != 0 ) {
			switch ( event.type ) {
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					switch ( event.key.keysym.sym ) {
						case SDLK_b:
							break;
						default:
							break;
					}
					break;
				default: break;
			}
        }

        SDL_SetRenderDrawColor( renderer, 0xf, 0xf, 0xf, 0xff );
        SDL_RenderClear( renderer );

		bt.show( renderer );

        SDL_RenderPresent( renderer );
		SDL_Delay( 33 );
	}

	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	SDL_Quit();

	return 0;
}
