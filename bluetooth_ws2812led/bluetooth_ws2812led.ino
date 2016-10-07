#include <SoftwareSerial.h>
#include <Wire.h>//引用二個函式庫SoftwareSerial及Wire
#include "FastLED.h"

// How many leds are in the strip?
#define NUM_LEDS 16
// Data pin that led data will be written out over
#define DATA_PIN 6
int LED = 13;

//mic聲音偵測
int soundPin = 0;   // Microphone is attached to this analog pin
int soundVal = 0;    

// used to make basic mood lamp colour fading feature
int fade_h;
int fade_direction = 1;

CRGB leds[NUM_LEDS];

SoftwareSerial I2CBT(2,4);//定義PIN2及PIN4分別為RX及TX腳位

///////////////////////////////////設定/////////////////////////////////////////////
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
   delay(2000);
   // For safety (to prevent too high of a power draw), the test case defaults to
   // setting brightness to 25% brightness
   //LEDS.setBrightness(64);
   LEDS.setBrightness(90);
   LEDS.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
   
   Serial.begin(9600); //Arduino起始鮑率：9600
   I2CBT.begin(9600); 
//藍牙鮑率：57600(注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
//   pinMode(13, OUTPUT);  //設定 pin13 為輸出，LED就接在這
}

////////////////////////主程式///////////////////////////////////////
void loop() {
byte cmmd[20];
cmmd[0]=99;               //初始使用"c"暫存字元
//cmmd[0]=98;               //初始使用"b"暫存字元
int insize;	
while(1){
   
   detect_sound();  //sound detection
   if ((insize=(I2CBT.available()))>0){  //讀取藍牙訊息
      Serial.print("input size = ");
      Serial.println(insize);
      for (int i=0; i<insize; i++){
               Serial.print(cmmd[i]=char(I2CBT.read()));
               Serial.print(" ");
      }//
   }
   switch (cmmd[0]) { //讀取第一個字
      case 97: //97為"a"的ASCII CODE
         
         //Serial.println("Get a");
         strips_LED();
         break;

      case 98://98為"b"的ASCII CODE
         //Serial.println("Get b");        
         all_flash();    
              
         break;
         
      case 99://99為"c"的ASCII CODE
         //Serial.println("Get c");
         //digitalWrite(13,LOW);   //熄滅LED
         breath();         
         break;
         
       case 100://100為"d"的ASCII CODE
         //Serial.println("Get d");
         //digitalWrite(13,LOW);   //熄滅LED
         acid_cloud();
         delay(50);
         break;
         
       case 101://101為"e"的ASCII CODE
         all_off();
         break;
     } //Switch
   } //while
}//loop

/////////////////////////////////////副程式//////////////////////////////////////
//跑馬燈三色變換
void strips_LED()
{
     for(int i = 0; i < 3; i++) {
		for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
			memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));

			switch(i) { 
				// You can access the rgb values by field r, g, b
			 	case 0: leds[iLed].r = 128; break;

			 	// or by indexing into the led (r==0, g==1, b==2) 
			 	case 1: leds[iLed][i] = 128; break;

			 	// or by setting the rgb values for the pixel all at once
			 	case 2: leds[iLed] = CRGB(0, 0, 128); break;
			}

			// and now, show your led array! 
			LEDS.show();
			delay(100);
		} //for iLED
     } //for i
}

//全部閃電
void all_flash()
{		
   leds[0] = CRGB::White; 
   leds[1] = CRGB::White;
   leds[2] = CRGB::White;
   leds[3] = CRGB::White;
   leds[4] = CRGB::Blue;
   leds[5] = CRGB::Blue;
   leds[6] = CRGB::White;
   leds[7] = CRGB::Blue;
   leds[8] = CRGB::Blue;
   leds[9] = CRGB::White;
   leds[10] = CRGB::Blue;
   leds[11] = CRGB::Blue;
   leds[12] = CRGB::White;
   leds[13] = CRGB::Blue;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(50);
   leds[0] = CRGB::White; 
   leds[1] = CRGB::White;
   leds[2] = CRGB::White;
   leds[3] = CRGB::White;
   leds[4] = CRGB::White;
   leds[5] = CRGB::White;
   leds[6] = CRGB::White;
   leds[7] = CRGB::White;
   leds[8] = CRGB::White;
   leds[9] = CRGB::White;
   leds[10] = CRGB::White;
   leds[11] = CRGB::White;
   leds[12] = CRGB::White;
   leds[13] = CRGB::White;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(500);
   leds[0] = CRGB::White; 
   leds[1] = CRGB::White;
   leds[2] = CRGB::White;
   leds[3] = CRGB::White;
   leds[4] = CRGB::White;
   leds[5] = CRGB::White;
   leds[6] = CRGB::White;
   leds[7] = CRGB::White;   
   FastLED.show();
   delay(50);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;   
   FastLED.show();
   delay(50);
   leds[8] = CRGB::White;
   leds[9] = CRGB::White;
   leds[10] = CRGB::White;
   leds[11] = CRGB::White;
   leds[12] = CRGB::White;
   leds[13] = CRGB::White;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(500);
   leds[0] = CRGB::White; 
   leds[1] = CRGB::White;
   leds[2] = CRGB::White;
   leds[3] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   FastLED.show();
   delay(50);
   leds[4] = CRGB::White;
   leds[5] = CRGB::White;
   leds[6] = CRGB::White;
   leds[7] = CRGB::White;   
   FastLED.show();
   delay(50);
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;   
   FastLED.show();
   delay(500);
   leds[8] = CRGB::White;
   leds[9] = CRGB::White;
   leds[10] = CRGB::White;
   leds[11] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   FastLED.show();
   delay(50);
   leds[12] = CRGB::White;
   leds[13] = CRGB::White;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(50);
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(500);
   
}

//呼吸燈
void breath()
{
/*  // yellow	
  LEDS.showColor(CRGB(128, 128, 0));                        
  delay(500);
    for(int x = 0; x < 128; x++) { 
	// The showColor method sets all the leds in the strip to the same color
		LEDS.showColor(CRGB(x, 0, 0));
                        
		delay(10);
	}

	// fade down
	for(int x = 128; x >= 0; x--) { 
		LEDS.showColor(CRGB(x, 0, 0));
                        
		delay(10);
	}
        // let's fade up by scaling the brightness
     	for(int scale = 0; scale < 128; scale++) { 
		LEDS.showColor(CRGB(0, 128, 0), scale);
		delay(10);
        	}
	// let's fade down by scaling the brightness
	for(int scale = 128; scale > 0; scale--) { 
		LEDS.showColor(CRGB(0, 128, 0), scale);
		delay(10);
		}
*/
	  //mood mood lamp that cycles through colours
        for (int i=0;i<NUM_LEDS;i++){
               leds[i] = CHSV( fade_h, 255, 255);
               }
        if(fade_h >254){
                 fade_direction = -1; //reverse once we get to 254
                 }
         else if(fade_h < 0){
                fade_direction = 1;
                 }
    
        fade_h += fade_direction;
        FastLED.show();
        delay(100);	
}

//ACID多顏色跳燈
void acid_cloud(){
    // a modification of the rolling lightning which adds random colour. trippy. 
    //iterate through every LED
    for(int i=0;i<NUM_LEDS;i++){
      if(random(0,100)>90){
        leds[i] = CHSV( random(0,255), 255, 255); 

      }
      else{
        leds[i] = CHSV(0,0,0);
      }
    }
    FastLED.show();
    delay(random(5,100));
    reset();
    
  //}
}


//reset
// utility function to turn all the lights off.  
void reset(){
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV( 0, 0, 0);
  }
  FastLED.show();
   
}

/////////////////////////////////////////////////////////////////
//聲音雷雲
//sound detection
void detect_sound() {
   soundVal=analogRead(soundPin);//read sensor value
   //Serial.print("sound reads ");
   //Serial.println(soundVal);
   //I2CBT.println(soundVal);
   
   if (soundVal > 80) {
      leds[0] = CRGB::White; 
      leds[1] = CRGB::White;
      leds[2] = CRGB::White;
      leds[3] = CRGB::White;
      leds[4] = CRGB::White;
      leds[5] = CRGB::White;
      leds[6] = CRGB::White;
      leds[7] = CRGB::White;
      leds[8] = CRGB::White;
      leds[9] = CRGB::White;
      leds[10] = CRGB::White;
      leds[11] = CRGB::White;
      leds[12] = CRGB::White;
      leds[13] = CRGB::White;
      leds[14] = CRGB::White;
      leds[15] = CRGB::White;
      FastLED.show();
      digitalWrite(LED,HIGH); 
      delay(20);
      leds[0] = CRGB::Black; 
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[5] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[13] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[15] = CRGB::Black;
      FastLED.show();
      digitalWrite(LED,LOW);
      delay(20);   
   }
   
}

//全部off
void all_off()
{		
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(30);
}
  
