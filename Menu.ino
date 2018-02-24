#include <CleO.h>

boolean exitConditionSubMenu1 = true;

void drawMainMenu() {
  CleO.Start();
  CleO.SetBackgroundcolor(0x93C900);
  CleO.Tag(1);
  CleO.eve_button(60, 100, 200, 100, FONT_MEDIUM, OPT_FLAT, "SubMenu1");
  CleO.Tag(2);
  CleO.eve_button(60, 250, 200, 100, FONT_MEDIUM, OPT_FLAT, "SubMenu2");

  
  CleO.StringExt(FONT_MEDIUM, 160, 50, WHITE, MM, 0, 0, "Application Name");
  CleO.Show();
  while (1) {
    controlMainMenu();
  }
}

void controlMainMenu()
{
  int16_t x, y, dur, tag;
  CleO.TouchCoordinates(x, y, dur, tag);
  if (prevDur == 0 && dur != 0) {
    prevDur = 1;
    if (tag == 1) {
      // Add Custom Submenu here
    }
    if (tag == 2) {
      drawSubMenu1();
    }
  } else if (prevDur == 1 && dur == 0) {
    prevDur = 0;
  }
}

void controlSubMenu1()
{
  /*
     Variablen Für Touchscreen
  */
  int16_t a, x, y, dur, tag;
  CleO.TouchCoordinates(x, y, dur, tag);
  if (prevDur == 0 && dur != 0) {
    prevDur = 1;
    if (dur != 0 && tag == 3) {
      drawKeyPadFloat();
    }
    if (dur != 0 && tag == 7) {
      drawKeyPadInteger();
    }
    if (dur != 0 && tag == 8 && millis() >= waitms) {
      /*
         Check values and begin to calculate
      */
      Serial.println("Enter pressed");
      Serial.println(millis());
      if (transmission <= 0.0 || transmission >= 100.0 || dosis <= 0 || dosis >= 500) {
        invalidInput = true;
        drawSubMenu1();
      } else {
        invalidInput = false;
        drawCalculationMenu();
      }
    } 
    if (dur != 0 && tag == 4) {
      exitConditionSubMenu1 = false;
    }
  } else if (prevDur == 1 && dur == 0) {
    prevDur = 0;
  }
}

void drawSubMenu1() {
  CleO.Start();
  CleO.SetBackgroundcolor(0x9009DB);
  CleO.Tag(3);
  CleO.eve_button(60, 120, 200, 50, FONT_MEDIUM, OPT_FLAT, "Variable");
  CleO.Tag(4);
  CleO.eve_button(0, 400, 120, 80, FONT_MEDIUM, OPT_FLAT, "Back");
  CleO.Tag(8);
  CleO.eve_button(200, 400, 120, 80, FONT_MEDIUM, OPT_FLAT, "Enter");

  CleO.Show();
  while (exitConditionSubMenu1) {
    controlSubMenu1();
  }
  exitConditionSubMenu1 = true;
  loop();
}
