#pragma once
#include <string>
#include <cassert>
#include "SDL_ttf.h"
#include <iostream>

class Text
{
	int m_size;
	std::string m_fontName;
	SDL_Color m_textColor;
	int m_xPosition;
	int m_yPosition;
	std::string m_text;

	TTF_Font* m_fontSDL;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;

	SDL_Rect m_dstRectangle;
	SDL_Color m_dstRectColor;
	bool m_displayWithRectangle;

	static const std::string path;
public:
	Text();
	Text(const std::string& name, int size, const SDL_Color& color, 
		const std::string& text, int xPosition, int  yPosition, bool displayWithRectangle,
		const SDL_Color& dstRectColor);

	~Text();

	//setters
	void setSize(int size);
	void setTextColor(const SDL_Color& color);
	void setFontName(const std::string& fontName);
	void setPositionX(int xPosition);
	void setPositionY(int yPosition);
	void setTextContent(const std::string& text);
	void setDstRectangleColor(const SDL_Color& dstRectColor);
	void setDisplayWithRectangle();

	void loadFont();
	void loadSurface();
	void loadTexture(SDL_Renderer *renderer);
	void loadDstRectangle();

	//getters
	const std::string& getTextContent();

	void render(SDL_Renderer* renderer);
	SDL_Rect& getDstRectangle();


	void changeText(const std::string& text);
};

