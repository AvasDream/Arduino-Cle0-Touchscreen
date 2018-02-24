#include <CleO.h>


boolean exitConditionDrawKeyPadFloat = true;

void controlKeyPadFloat()
{
  int16_t x, y, dur, tag;
  CleO.TouchCoordinates(x, y, dur, tag);
  if (prevDur == 0 && dur != 0) {
    prevDur = 1;
    if (tag == 5) {
      exitConditionDrawKeyPadFloat = false;
    }
    if (tag == 49) {
      strcat(input, "1");
    }
    if (tag == 50) {
      strcat(input, "2");
    }

    if (tag == 51) {
      strcat(input, "3");
    }

    if (tag == 52) {
      strcat(input, "4");
    }

    if (tag == 53) {
      strcat(input, "5");
    }

    if (tag == 54) {
      strcat(input, "6");
    }

    if (tag == 55) {
      strcat(input, "7");
    }

    if (tag == 56) {
      strcat(input, "8");
    }

    if (tag == 57) {
      strcat(input, "9");
    }
    if (tag == 48) {
      strcat(input, "0");
    }
    if (tag == 46) {
      strcat(input, ".");
    }
    if (tag == 60) {
      LastcharDel(input);
    }
    if (tag == 6) {
      transmission = atof(input);
      exitConditionDrawKeyPadFloat = false;
    }
    drawKeyPadFloat();
  } else if (prevDur == 1 && dur == 0) {
    prevDur = 0;
  }
}

void drawKeyPadFloat() {
  int16_t b1;
  CleO.Start();
  CleO.SetBackgroundcolor(0x93C9DB);
  /*
     Keys get their ASCII value as TAG
  */
  CleO.eve_keys(70 ,100, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "1");
  CleO.eve_keys(125, 100, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "2");
  CleO.eve_keys(180, 100, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "3");
  CleO.eve_keys(70, 170, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "4");
  CleO.eve_keys(125, 170, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "5");
  CleO.eve_keys(180, 170, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "6");
  CleO.eve_keys(70, 240, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "7");
  CleO.eve_keys(125, 240, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "8");
  CleO.eve_keys(180, 240, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "9");
  CleO.eve_keys(70, 310, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, ".");
  CleO.eve_keys(125, 310, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "0");
  CleO.eve_keys(180, 310, 50, 70, FONT_MEDIUM, 0  | OPT_FLAT, "<");
  CleO.Tag(5);
  CleO.eve_button(0, 400, 120, 80, FONT_MEDIUM, OPT_FLAT, "Back");
  CleO.Tag(6);
  CleO.eve_button(200, 400, 120, 80, FONT_MEDIUM, OPT_FLAT, "Enter");
  CleO.StringExt(FONT_MEDIUM, 160, 80, 0x8A3EAD, MM, 0, 0, input);
  CleO.Show();
  while (exitConditionDrawKeyPadFloat) {
    controlKeyPadFloat();
  }
  exitConditionDrawKeyPadFloat = true;
  drawMenu();
}

