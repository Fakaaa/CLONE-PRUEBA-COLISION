#include "background.h"

#include "objects/player.h"
#include "screens/all_the_screens.h"

namespace Background
{
	bool stopTransition = false;

	static BACKGROUND backgroundGame1;
	static BACKGROUND backgroundGame2;
	static BACKGROUND backgroundGame3;
	static BACKGROUND backgroundGame4;

	static BACKGROUND backgroundMenu;
	static BACKGROUND backgroundCredits;
	static BACKGROUND backgroundCreditsText1;
	static BACKGROUND backgroundCreditsText2;

	static BACKGROUND backgroundBubbles1;
	static BACKGROUND backgroundBubbles2;
	static BACKGROUND backgroundBubbles3;

	static BACKGROUND logo;
	static BACKGROUND panel;

	static BACKGROUND logoImageCampus;
	static BACKGROUND logoSumerLab;

	static float scrolling_menuBack;
	static float scrolling_gameBack;
	static float scrolling_bubbles1;
	static float scrolling_bubbles2;
	static float scrolling_bubbles3;
	
	static float scrolling_back1;
	static float scrolling_back2;
	static float scrolling_back3;
	static float scrolling_back4;

	static void MoveTransitionsBackgrounds();
	static void MoveBackgroundGameplay();

	void LoadBackground()
	{
		scrolling_menuBack = 0.0f;
		scrolling_gameBack = 0.0f;

		scrolling_bubbles1 = 0.0f;
		scrolling_bubbles2 = 0.0f;
		scrolling_bubbles3 = 0.0f;

		scrolling_back1 = 0.0f;
		scrolling_back2 = 0.0f;
		scrolling_back3 = 0.0f;

		Image menu;
		Image logoImage;
		Image panelImage;

		Image creditsText1;
		Image creditsText2;
		Image credits;

		Image imageCampus;
		Image sumerLab;

		Image bubbles1;
		Image bubbles2;
		Image bubbles3;

		Image gamePlayBack1;
		Image gamePlayBack2;
		Image gamePlayBack3;
		Image gamePlayBack4;

		//--------------------
		// gameplay

		backgroundGame1.x = 0;
		backgroundGame1.y = 0;
		gamePlayBack1 = LoadImage("assets/background/bgGP1.png");
		ImageResize(&gamePlayBack1, GetScreenWidth(), GetScreenHeight());
		backgroundGame1.texture = LoadTextureFromImage(gamePlayBack1);
		
		backgroundGame2.x = 0;
		backgroundGame2.y = 0;
		gamePlayBack2 = LoadImage("assets/background/bgGP2.png");
		ImageResize(&gamePlayBack2, GetScreenWidth(), GetScreenHeight());
		backgroundGame2.texture = LoadTextureFromImage(gamePlayBack2);
		
		backgroundGame3.x = 0;
		backgroundGame3.y = 0;
		gamePlayBack3 = LoadImage("assets/background/bgGP3.png");
		ImageResize(&gamePlayBack3, GetScreenWidth(), GetScreenHeight());
		backgroundGame3.texture = LoadTextureFromImage(gamePlayBack3);
		
		backgroundGame4.x = 0;
		backgroundGame4.y = 0;
		gamePlayBack4 = LoadImage("assets/background/bgGP4.png");
		ImageResize(&gamePlayBack4, GetScreenWidth(), GetScreenHeight());
		backgroundGame4.texture = LoadTextureFromImage(gamePlayBack4);

		//--------------------
		// menu
		
		backgroundMenu.x = 0;
		backgroundMenu.y = 0;
		menu = LoadImage("assets/background/BGMuelleV2.png");
		ImageResize(&menu, GetScreenWidth(), GetScreenHeight());
		backgroundMenu.texture = LoadTextureFromImage(menu);
		
		logoImage = LoadImage("assets/background/logo.png");
		ImageResize(&logoImage, GetScreenWidth() / 4, GetScreenWidth() / 4);
		logo.texture = LoadTextureFromImage(logoImage);
		logo.x = static_cast<float>(GetScreenWidth() / 2 - logo.texture.width / 2);
		logo.y = static_cast<float>(GetScreenHeight() / 20);

		panelImage = LoadImage("assets/background/panel.png");
		ImageResize(&panelImage, GetScreenWidth() / 2 + GetScreenWidth() / 3, GetScreenHeight() / 2);
		panel.texture = LoadTextureFromImage(panelImage);
		panel.x = static_cast<float>(GetScreenWidth() / 2 - panel.texture.width / 2);
		panel.y = static_cast<float>(GetScreenHeight() / 2);
		
		// -------------------
		// credits

		creditsText1 = LoadImage("assets/background/BGCreditos1.png");
		ImageResize(&creditsText1, 900, 500);
		backgroundCreditsText1.texture = LoadTextureFromImage(creditsText1);

		creditsText2 = LoadImage("assets/background/BGCreditos2.png");
		ImageResize(&creditsText2, 900, 500);
		backgroundCreditsText2.texture = LoadTextureFromImage(creditsText2);
		
		credits = LoadImage("assets/background/BGCreditos.png");
		ImageResize(&credits, GetScreenWidth(), GetScreenHeight());
		backgroundCredits.texture = LoadTextureFromImage(credits);

		sumerLab = LoadImage("assets/logos/Logo Lab.png");
		ImageResize(&sumerLab, GetScreenWidth() / 8, GetScreenWidth() / 8);
		logoSumerLab.texture = LoadTextureFromImage(sumerLab);
		logoSumerLab.x = static_cast<float>(GetScreenWidth() - logoSumerLab.texture.width);
		logoSumerLab.y = static_cast<float>(GetScreenHeight() - logoSumerLab.texture.height);
		
		imageCampus = LoadImage("assets/logos/Logo Image si el fondo es oscuro.png");
		ImageResize(&imageCampus, GetScreenWidth() / 6, GetScreenHeight() / 6);
		logoImageCampus.texture = LoadTextureFromImage(imageCampus);
		logoImageCampus.x = static_cast<float>(logoSumerLab.x - logoImageCampus.texture.width);
		logoImageCampus.y = static_cast<float>(GetScreenHeight() - logoImageCampus.texture.height);

		//--------------------
		// transicion		

		backgroundBubbles1.x = 0;
		backgroundBubbles1.y = 0;
		bubbles1 = LoadImage("assets/background/BGburbujas.png");
		ImageResize(&bubbles1, GetScreenWidth(), GetScreenHeight());
		backgroundBubbles1.texture = LoadTextureFromImage(bubbles1);
		
		backgroundBubbles2.x = 0;
		backgroundBubbles2.y = 0;
		bubbles2 = LoadImage("assets/background/BGburbujas1.png");
		ImageResize(&bubbles2, GetScreenWidth(), GetScreenHeight());
		backgroundBubbles2.texture = LoadTextureFromImage(bubbles2);
		
		backgroundBubbles3.x = 0;
		backgroundBubbles3.y = 0;
		bubbles3 = LoadImage("assets/background/BGburbujas2.png");
		ImageResize(&bubbles3, GetScreenWidth(), GetScreenHeight());
		backgroundBubbles3.texture = LoadTextureFromImage(bubbles3);

		// ------------------

		UnloadImage(gamePlayBack1);
		UnloadImage(gamePlayBack2);
		UnloadImage(gamePlayBack3);
		UnloadImage(gamePlayBack4);
		UnloadImage(menu);
		UnloadImage(logoImage);
		UnloadImage(panelImage);
		UnloadImage(credits);
		UnloadImage(creditsText1);
		UnloadImage(creditsText2);
		UnloadImage(imageCampus);
		UnloadImage(sumerLab);
		UnloadImage(bubbles1);
		UnloadImage(bubbles2);
		UnloadImage(bubbles3);
	}

	void Unload()
	{
		UnloadTexture(backgroundGame1.texture);
		UnloadTexture(backgroundGame2.texture);
		UnloadTexture(backgroundGame3.texture);
		UnloadTexture(backgroundGame4.texture);
		UnloadTexture(backgroundMenu.texture);
		UnloadTexture(logo.texture);
		UnloadTexture(panel.texture);
		UnloadTexture(backgroundCredits.texture);
		UnloadTexture(backgroundCreditsText1.texture);
		UnloadTexture(backgroundCreditsText2.texture);
		UnloadTexture(logoImageCampus.texture);
		UnloadTexture(logoSumerLab.texture);
		UnloadTexture(backgroundBubbles1.texture);
		UnloadTexture(backgroundBubbles2.texture);
		UnloadTexture(backgroundBubbles3.texture);
	}

	void DrawMenu()
	{
		scrolling_menuBack = 0.0f;
		scrolling_gameBack = 0.0f;

		scrolling_bubbles1 = 0.0f;
		scrolling_bubbles2 = 0.0f;
		scrolling_bubbles3 = 0.0f;

		scrolling_back1 = 0.0f;
		scrolling_back2 = 0.0f;
		scrolling_back3 = 0.0f;

		if (Screens::state == Screens::menu)
		{
			DrawTextureV(backgroundMenu.texture, Vector2{ backgroundMenu.x, backgroundMenu.y }, WHITE);

			DrawTexture(logo.texture, static_cast<int>(logo.x), static_cast<int>(logo.y), WHITE);
			DrawTexture(panel.texture, static_cast<int>(panel.x), static_cast<int>(panel.y), WHITE);
		}
		else if (Screens::state == Screens::tablePoints)
		{
			DrawTextureV(backgroundMenu.texture, Vector2{ backgroundMenu.x, backgroundMenu.y }, WHITE);
		}
	}

	void DrawCredits()
	{
		DrawTextureV(backgroundCredits.texture, Vector2{ backgroundMenu.x, backgroundMenu.y }, WHITE);

		DrawTexture(backgroundCreditsText1.texture, GetScreenWidth() / 2 - backgroundCreditsText1.texture.width / 2, GetScreenHeight() / 2 - (backgroundCreditsText1.texture.height / 2 + backgroundCreditsText1.texture.height / 3), WHITE);
		DrawTexture(backgroundCreditsText2.texture, GetScreenWidth() / 2 - backgroundCreditsText2.texture.width / 2, GetScreenHeight() / 2, WHITE);

		DrawTexture(logoImageCampus.texture, static_cast<int>(logoImageCampus.x), static_cast<int>(logoImageCampus.y), WHITE);
		DrawTexture(logoSumerLab.texture, static_cast<int>(logoSumerLab.x), static_cast<int>(logoSumerLab.y), WHITE);
	}

	void DrawTransition()
	{
		MoveTransitionsBackgrounds();

		DrawTextureV(backgroundMenu.texture, Vector2{ backgroundMenu.x, scrolling_menuBack }, WHITE);

		DrawTextureV(backgroundGame4.texture, Vector2{ backgroundGame4.x, backgroundGame4.texture.height + scrolling_gameBack }, WHITE);
		DrawTextureV(backgroundGame3.texture, Vector2{ backgroundGame3.x, backgroundGame3.texture.height + scrolling_gameBack }, WHITE);
		DrawTextureV(backgroundGame2.texture, Vector2{ backgroundGame2.x, backgroundGame2.texture.height + scrolling_gameBack }, WHITE);
		DrawTextureV(backgroundGame1.texture, Vector2{ backgroundGame1.x, backgroundGame1.texture.height + scrolling_gameBack }, WHITE);	
		
		DrawTextureV(backgroundBubbles3.texture, Vector2{ backgroundBubbles3.x, backgroundBubbles3.texture.height + scrolling_bubbles3 }, WHITE);
		DrawTextureV(backgroundBubbles3.texture, Vector2{ backgroundBubbles3.x, backgroundBubbles3.texture.height + backgroundBubbles3.texture.height + scrolling_bubbles3 }, WHITE);
		
		DrawTextureV(backgroundBubbles2.texture, Vector2{ backgroundBubbles2.x, backgroundBubbles2.texture.height + scrolling_bubbles2 }, WHITE);
		DrawTextureV(backgroundBubbles2.texture, Vector2{ backgroundBubbles2.x, backgroundBubbles2.texture.height + backgroundBubbles2.texture.height + scrolling_bubbles2 }, WHITE);
		
		DrawTextureV(backgroundBubbles1.texture, Vector2{ backgroundBubbles1.x, backgroundBubbles1.texture.height + scrolling_bubbles1 }, WHITE);
		DrawTextureV(backgroundBubbles1.texture, Vector2{ backgroundBubbles1.x, backgroundBubbles1.texture.height + backgroundBubbles1.texture.height + scrolling_bubbles1 }, WHITE);
	}

	void DrawGamePlay()
	{
		MoveBackgroundGameplay();
	}

	// -------------------------------------------

	static void MoveTransitionsBackgrounds()
	{
		float SPEED_BACKS = 240;

		float SPEED_BUBBLES3 = SPEED_BACKS * 3;
		float SPEED_BUBBLES2 = SPEED_BACKS * 4;
		float SPEED_BUBBLES1 = SPEED_BACKS * 5;

		scrolling_bubbles3 -= SPEED_BUBBLES3 * GetFrameTime();
		scrolling_bubbles2 -= SPEED_BUBBLES2 * GetFrameTime();
		scrolling_bubbles1 -= SPEED_BUBBLES1 * GetFrameTime();


		if ((backgroundMenu.texture.height * 2) - scrolling_menuBack > 0)
		{
			scrolling_menuBack -= SPEED_BACKS * GetFrameTime();
		}
		if (backgroundGame4.texture.height + scrolling_gameBack < backgroundGame4.y)
		{
			stopTransition = true;
		}
		else
		{
			scrolling_gameBack -= SPEED_BACKS * GetFrameTime();
		}
	}

	static void MoveBackgroundGameplay()
	{
		const float DIV_SPEED = 20.0f;

		scrolling_back1 -= (90.0f + Player::player.distaceRecord / DIV_SPEED) * GetFrameTime();
		scrolling_back2 -= (60.0f + Player::player.distaceRecord / DIV_SPEED) * GetFrameTime();
		scrolling_back3 -= (30.0f + Player::player.distaceRecord / DIV_SPEED) * GetFrameTime();

		if (scrolling_back1 <= -backgroundGame1.texture.width)
			scrolling_back1 = 0;
		if (scrolling_back2 <= -backgroundGame2.texture.width)
			scrolling_back2 = 0;
		if (scrolling_back3 <= -backgroundGame3.texture.width)
			scrolling_back3 = 0;

		DrawTextureV(backgroundGame4.texture, Vector2{ backgroundGame4.x,backgroundGame4.y }, WHITE);

		DrawTextureV(backgroundGame3.texture, Vector2{ scrolling_back3, backgroundGame3.y }, WHITE);
		DrawTextureV(backgroundGame3.texture, Vector2{ backgroundGame3.texture.width + scrolling_back3, backgroundGame3.y }, WHITE);
		
		DrawTextureV(backgroundGame2.texture, Vector2{ scrolling_back2, backgroundGame2.y }, WHITE);
		DrawTextureV(backgroundGame2.texture, Vector2{ backgroundGame2.texture.width + scrolling_back2, backgroundGame2.y }, WHITE);
		
		DrawTextureV(backgroundGame1.texture, Vector2{ scrolling_back1, backgroundGame1.y }, WHITE);
		DrawTextureV(backgroundGame1.texture, Vector2{ backgroundGame1.texture.width + scrolling_back1, backgroundGame1.y }, WHITE);
	}	
}
