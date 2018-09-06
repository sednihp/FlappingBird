#pragma once
#include "SDL.h"
#include <string>
#include "ImageCache.h"
#include "FontCache.h"
#include "TextCache.h"
#include "Vectors.h"

class MediaCache
{
	private:	
		const int V_SCREEN_WIDTH{ 512 };
		const int V_SCREEN_HEIGHT{ 288 };
		const int SCREEN_WIDTH{ 1280 };
		const int SCREEN_HEIGHT{ 720 };
		const SDL_Color TEXT_COLOUR{ 255,255,255 };
		const SDL_Color BG_COLOUR{ 91,173,255 };

		SDL_Rect camera{ 0, 0, V_SCREEN_WIDTH, V_SCREEN_HEIGHT };
		SDL_Window* window;
		SDL_Renderer* ren;
		ImageCache imgCache;
		FontCache fontCache;
		TextCache txtCache;

		MediaCache &operator=(const MediaCache&) = delete;
		MediaCache(const MediaCache&) = delete;

	public:
		MediaCache();
		~MediaCache();

		GameTex getImage(const std::string& file);
		TTF_Font* getFont(const int size);
		GameTex getText(const std::string& text, TTF_Font* font);
		GameTex getText(const int text, TTF_Font* font);

		void render(GameTex tex, const int x, const int y);
		void render(GameTex tex, const double x, const double y);
		void render(GameTex tex, const Point2D& position);
		void render(GameTex tex);
		void render(GameTex tex, const Point2D& position, SDL_Rect clip);
		void render(GameTex tex, const Point2D& position, const SDL_RendererFlip flip);
		void render(const SDL_Rect& rect, const SDL_Color& color);

		void clearScreen();
		void updateScreen() { SDL_RenderPresent(ren); }

		const int getScrWidth() const { return V_SCREEN_WIDTH; }
		const int getScrHeight() const { return V_SCREEN_HEIGHT; }
		const SDL_Rect& getCamera() const { return camera; }

		const int centreX(const int gtWidth) const;
		const int centreY(const int gtHeight) const;
		const int centreX(GameTex tex) const;
		const int centreY(GameTex tex) const;
		const Point2D centre(GameTex tex) const;
		const SDL_Color& getTextColor() const { return TEXT_COLOUR; }
};