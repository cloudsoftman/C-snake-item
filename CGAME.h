#pragma once
#include"MAP.h"
#include"Snake.h"
#include"food.h"
class CGAME:public MAP
{
	public:
		CGAME();
		virtual ~CGAME();
		bool checkFailed();
		bool checkLevel();
		void changeInfo();
		void drawGameArea();
		void DRAWGameInfo();
		void menu();
		void run();

   /*  public:*/
		/* static const int KLEFT;
		 static const int KUP;
		 static const int KWIDTH;
		 static const int KHEIGHT;
		 static const int KSCORE_OFFSET;
		 static const int KLEVEL_OFFSET;*/

      public:
		  food* m_pFood;
		  Snake* m_pSnake;
		  MAP* m_pMAP;
		  int m_iScore;
		  int m_iLevel;

};

