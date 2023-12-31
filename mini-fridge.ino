#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const int buttonPin1 = 7;
const int buttonPin2 = 8;
int aim = 15;
void setup()
{	
    lcd.begin(16, 2); 
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    Serial.begin(9600);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
  
  	pinMode(9, OUTPUT);
    
  	pinMode(13, OUTPUT);
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}


void lccd()
{
  //TEMP
  	int baselineTemp,celsius;
  	baselineTemp = 40;
  
    celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

    // LIGHT
    int sensorValue = 1;
    sensorValue = analogRead(A1);
    sensorValue = map(sensorValue, 0, 1023, 0, 255);
	

    if (sensorValue < 60)
    {
      digitalWrite(9,HIGH);
    }
    else
    {
      digitalWrite(9,LOW);
      
    }
  

  if (celsius > aim)
  {
    digitalWrite(13,HIGH);
//    Serial.println("On");
  }
  else
  {
    digitalWrite(13,LOW);
 //   Serial.println("Off");
  }
  
  if(celsius < 99 && celsius >=0)
  {
    if (celsius >10)
    {
      	lcd.setCursor(0,1);
      	lcd.print("Temp:");    
    	lcd.print(celsius);
    }
    else
    {
      lcd.setCursor(0,1); 
      lcd.print("Temp:");
      lcd.setCursor(5,1);        
      lcd.print(celsius);
      lcd.print(" ");
    }
      
  }
  
  lcd.setCursor(0,0);
  lcd.print("Light Value: ");
  lcd.print(sensorValue); 
  lcd.print("  "); 


}

void loop()
{
  lccd();
  if (digitalRead(buttonPin1) == LOW) {
    // If the button is pressed, increment the aim
    aim++;
    delay(100);
  }
  if (digitalRead(buttonPin2) == LOW) {
    // If the button is pressed, increment the aim
    aim--;
    delay(100);
  }
  // Update the LCD display with the new aim value
  
  lcd.setCursor(7,1);
  lcd.print("   Aim:");
  lcd.print(aim);
  lcd.print(" ");

}
