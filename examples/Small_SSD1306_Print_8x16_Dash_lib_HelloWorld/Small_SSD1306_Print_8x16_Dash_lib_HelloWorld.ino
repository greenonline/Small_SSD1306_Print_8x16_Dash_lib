// Small_SSD1306_Print_8x16_Dash_lib_HelloWorld.ino
// Prints "Hello World"
//
// connect display SCL to pin A5, and SDA to pin A4
// connect LED to pin 4 (it will blink in case of I2C error)


#include <Small_SSD1306_Print_8x16_Dash_lib.h>

Small_SSD1306_Print_8x16_Dash_lib lcd = Small_SSD1306_Print_8x16_Dash_lib();

void setup() {
  lcd.begin();
  lcd.setCursorMode(true);
}

void loop() {
  printHelloWorld();
  lcd.D_DRAW_VERT_DASHED(120,0,31);
  delay(2000);
  scrollHelloWorld();
  lcd.setPrint8x16CharacterMode(false);
  printHelloWorld();
  delay(2000);
  scrollHelloWorld();
  lcd.setPrint8x16CharacterMode(true);
}

void printHelloWorld(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(9,1);
  lcd.print("World");
}

void scrollHelloWorld(){
  lcd.clear();
  for (int x=0;x<11;x++)
    for (int y=0;y<3;y++){
      lcd.setCursor(x,y);
      lcd.print(" Hello ");
      lcd.setCursor(x+1,y+1);
      lcd.print(" World ");
      delay(100);
    }
}
