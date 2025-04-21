  
/* Includes ------------------------------------------------------------------*/
#include "display.h"
#include "ssd1306_oled.h"


void display_Init(void)
{
	// MENSAJES INICIO //
	SSD1306_GotoXY(5,0);
	SSD1306_Puts("HOLA, BIENVENIDO!", &Font_7x10, WHITE);
	SSD1306_GotoXY(25,20);
	SSD1306_Puts("EUGENIO", &Font_11x18, WHITE);
	SSD1306_GotoXY(15,40);
	SSD1306_Puts("SIMULATOR", &Font_11x18, WHITE);
	SSD1306_GotoXY(54,60);
	SSD1306_Puts("3000", &Font_7x10, WHITE);
	SSD1306_UpdateScreen();
	HAL_Delay(2000);

	SSD1306_Clear();
	SSD1306_GotoXY(12,0);
	SSD1306_Puts("INGENIERIA UCC", &Font_7x10, WHITE);
	SSD1306_GotoXY(0,20);
	SSD1306_Puts("Profesores:", &Font_7x10, WHITE);
	SSD1306_GotoXY(0,30);
	SSD1306_Puts("*Agustin Laprovitta", &Font_7x10, WHITE);
	SSD1306_GotoXY(0,40);
	SSD1306_Puts("*Martin Molina", &Font_7x10, WHITE);
	SSD1306_GotoXY(0,50);
	SSD1306_Puts("Alumno: Mateo C.", &Font_7x10, WHITE);
	SSD1306_UpdateScreen();
	HAL_Delay(2000);

	 // PANTALLA HOME //
	SSD1306_Clear();
	SSD1306_GotoXY(30,0);
	SSD1306_Puts("STATUS", &Font_11x18, WHITE);
	SSD1306_GotoXY(8,25);
	SSD1306_Puts("Reproduciendo...", &Font_7x10, WHITE);
	SSD1306_GotoXY(18,40);
	SSD1306_Puts("* Normal 60bpm", &Font_7x10, WHITE);
	SSD1306_UpdateScreen();
}

void display_cancion(int idx)
{
	switch(idx){

	case 0:
		SSD1306_Clear();
		HAL_Delay(200);
		SSD1306_GotoXY(30,0);
		SSD1306_Puts("STATUS", &Font_11x18, WHITE);
		SSD1306_GotoXY(8,25);
		SSD1306_Puts("Reproduciendo...", &Font_7x10, WHITE);
		SSD1306_GotoXY(18,40);
		SSD1306_Puts("* Normal 60bpm", &Font_7x10, WHITE);
		SSD1306_UpdateScreen();
		HAL_Delay(200);
		break;


	case 1:
		SSD1306_Clear();
		HAL_Delay(200);
		SSD1306_GotoXY(30,0);
		SSD1306_Puts("STATUS", &Font_11x18, WHITE);
		SSD1306_GotoXY(8,25);
		SSD1306_Puts("Reproduciendo...", &Font_7x10, WHITE);
		SSD1306_GotoXY(18,40);
		SSD1306_Puts("* Murmullo 60bpm", &Font_7x10, WHITE);
		SSD1306_UpdateScreen();
		HAL_Delay(200);
		break;

	case 2:
		SSD1306_Clear();
		SSD1306_GotoXY(30,0);
		SSD1306_Puts("STATUS", &Font_11x18, WHITE);
		SSD1306_GotoXY(8,25);
		SSD1306_Puts("Reproduciendo...", &Font_7x10, WHITE);
		SSD1306_GotoXY(18,40);
		SSD1306_Puts("* Estereo ", &Font_7x10, WHITE);
		SSD1306_UpdateScreen();
		break;



	case 3:
		SSD1306_Clear();
		SSD1306_GotoXY(30,0);
		SSD1306_Puts("STATUS", &Font_11x18, WHITE);
		SSD1306_GotoXY(8,25);
		SSD1306_Puts("Reproduciendo...", &Font_7x10, WHITE);
		SSD1306_GotoXY(18,40);
		SSD1306_Puts("* Cancion", &Font_7x10, WHITE);
		SSD1306_UpdateScreen();

	}

}
