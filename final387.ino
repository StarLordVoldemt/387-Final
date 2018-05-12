#include <LiquidCrystal.h>
//Declaring all Global variables that will be useful later. 
const int rs = 2, en = 3, rw =4, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
char input[20];
char output[20];
char player[20];
boolean hasGun=false;
boolean hasUmb=false;
boolean hasCube=false;
boolean task1=false;
boolean mary=true;
boolean aquaman=true;
boolean savedTheDay=false;
boolean haveYouTriedShootingIt=false;
boolean gaveUmb=false;
boolean answered=false;

//Declares the LCD screen based on our hardware
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  player[0]=' ';
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Starts reading input to the serial monitor and 
  //prints blank text because it works so much better at clearing the screen than lcd.clear();
  Serial.begin(9600);
  lcd.print(" ");
  beginGame();
  playGame();
  getName();
}

void loop() {

}

//Method from Robin2 on arduino forums to see if there's new data. 
void recvOneChar() {
 if (Serial.available() > 0) {
 Serial.readBytes(input,20);
 }
}

void beginGame(){
hasGun=false;
hasUmb=false;
hasCube=false;
task1=false;
mary=true;
aquaman=true;
  lcd.println("     Type Start to Start        ");
  int i=0;
   while(input[1]!='t' or input [2]!='a' or input[3]!='r' or input[4]!='t' 
  or (input[0]!='S' and input[0]!='s')){
 recvOneChar();
  while(i< 15) {
    // scroll one position right:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
    i++;
  }
  while(i>6) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
    i--;
  }
  }
}


void playGame(){
  lcd.clear();
  lcd.println("You are flown to");
  delay(2000);
  lcd.clear();                        
  lcd.println("the lab of your"); 
  delay(2000);
  
  lcd.clear();
  lcd.println("uncle,");  
  delay(2000);
  lcd.clear();                               
  lcd.println("Dr. Rick Brown."); 
  delay(2000);

  lcd.clear();
  lcd.println("Brown: Cuz!");
  delay(2000);
  lcd.clear();
  lcd.println("Sup, Dawg!");
  delay(2000);

  lcd.clear();
  lcd.println("Uh, I got hit in");
  delay(2000);
  lcd.clear();
  lcd.println("the head with");
  delay(2000);

  lcd.clear();
  lcd.println("a coconut.What's");
  delay(2000);
  lcd.clear();
  lcd.println("your name again?");
  delay(5000);

  
}

void getName() {
  while(player[0]==' '){
  enterName();
  }
  lab();
}


void enterName(){
  if (Serial.available() > 0) {
 Serial.readBytes(player,20);
  }
}

void lab(){
  lcd.clear();
  lcd.println("Aloha! ");
  lcd.print(player);
  delay(2000);

  lcd.clear();
  lcd.println("Brown: I have");
  delay(2000);
  lcd.clear();
  lcd.println("some research");
  delay(2000);

  lcd.clear();
  lcd.println("Want to do that");
  delay(2000);
  lcd.clear();
  lcd.println("or look around");
  delay(2000);

  lcd.clear();
  lcd.println("the lab?");
  delay(2000);

  while((input[1]!='o' or input [2]!='o' or input[3]!='k' 
  or (input[0]!='l' and input[0]!='L')) and 
  (input[1]!='e' or input [2]!='s' or input[3]!='e'
  or input[4]!='a' or input [5]!='r' or input[6]!='c' or
  input[7]!='h' or (input[0]!='r' and input[0]!='R'))){
    recvOneChar();
  }

  if(input[0]=='L' or input[0] == 'l'){
    lookAroundTheLab();
  }
  else{
    onTheTrail();
  }
}

void lookAroundTheLab(){
  lcd.clear();
  lcd.println("Around the lab");
  delay(2000);
  lcd.clear();
  lcd.println("you see a gun,");
  delay(2000);

  lcd.clear();
  lcd.println("an umbrella and");
  delay(2000);
  lcd.clear();                         
  lcd.println("a small ice cube");
  delay(2000);

  while(input[1]!='e' or input [2]!='a' or input[3]!='v' or input[4]!='e' 
  or (input[0]!='L' and input[0]!='l')){
    recvOneChar();
    if((input[0]=='P' or input[0]=='p') and input[1] == 'i' and input[2] == 'c' 
    and input[3] == 'k' and input[4] == ' ' and input[5] == 'u' and input[6] == 'p'
    and input[7]== ' ' and (input[8]=='G' or input[8]=='g') 
    and input[9] == 'u' and input[10] == 'n'){
      hasGun=true;
      lcd.clear();
      lcd.println("You picked up");
      delay(2000);
      lcd.clear();
      lcd.println("the gun");
      delay(2000);
    }
    else if((input[0]=='P' or input[0]=='p') and input[1] == 'i' and input[2] == 'c' 
    and input[3] == 'k' and input[4] == ' ' and input[5] == 'u' and input[6] == 'p'
    and input[7]== ' ' and (input[8]=='U' or input[8]=='u') 
    and input[9] == 'm' and input[10] == 'b' and input[11] == 'r' and input[12] == 'e'
    and input[13]== 'l' and input[14]=='l' and input[15] == 'a'){
      hasUmb =true;
      lcd.clear();
      lcd.println("You picked up");
      delay(2000);
      lcd.clear();
      lcd.println("the umbrella");
      delay(2000);
    }
    else if((input[0]=='P' or input[0]=='p') and input[1] == 'i' and input[2] == 'c' 
    and input[3] == 'k' and input[4] == ' ' and input[5] == 'u' and input[6] == 'p'
    and input[7]== ' ' and (input[8]=='I' or input[8]=='i') 
    and input[9] == 'c' and input[10] == 'e' and input[11] == ' ' and (input[12] =='C' 
    or  input[12] == 'c') and input[13]=='u' and input[14]=='b' and input[15]=='e'){
    hasCube =true;
      lcd.clear();
      lcd.println("You pick up the");
      delay(2000);
      lcd.clear();
      lcd.println("small ice cube");
      delay(2000);
    }
    else{
      
    }
  }
  onTheTrail();
}



void onTheTrail(){
     lcd.clear();
     lcd.println("Let's go!");
     lcd.print(player);   
     delay(3000);

     lcd.clear();
     lcd.println("Okay cuz, My");
     delay(2000);
     lcd.clear();
     lcd.println("research involves");
     delay(2000);

     lcd.clear();
     lcd.println("the volcano in");
     delay(2000);
     lcd.clear();
     lcd.println("the center of");
     delay(2000);

     lcd.clear();
     lcd.println("the island. So");
     delay(2000);
    
     lcd.clear();
     lcd.println("We need to get");
     delay(2000);
     lcd.clear();
     lcd.println("up there.");
     delay(2000);

     lcd.clear();
     lcd.println("Which way is it?");
     delay(2000);
     lcd.clear();
     lcd.println("left or right?");
     delay(2000);

     while(((input[0]!= 'l' and input[0]!='L') or input[1]!='e' or input[2]!= 'f' or input[3]!= 't')
     and ((input[0]!= 'r' and input[0]!='R') or input[1]!='i' or input[2]!= 'g' or input[3]!= 'h' or
     input[4]!= 't')){
      recvOneChar();
     }
     if(input[1]=='e'){
      pathLeft();
     }
     else{
      pathRight();
     }
}


void pathLeft(){
  lcd.clear();
  lcd.println("You head left.");
  delay(2000);
  
  lcd.clear();
  lcd.println("For what seems");
  delay(2000);
  
  lcd.clear();
  lcd.println("like an hour");
  delay(2000);
  
  lcd.clear();
  lcd.println("You walk until");
  delay(2000);
  
  lcd.clear();
  lcd.println("you see a woman");
  delay(2000);
  
  lcd.clear();
  lcd.println("Standing in");
  delay(2000);
  lcd.clear();
  lcd.println("your path");
  delay(500);
  
  while(task1==false){
    recvOneChar();
    delay(5000);
    if((input[0]=='S' or input[0]=='s') and input[1]=='h' and 
    input[2]=='o' and input[3]=='o' and input[4]=='t' and hasGun==true){
      mary=false;
      lcd.clear();
      lcd.println("You shoot her :(");
      delay(4000);
      task1=true;
    }
    else if((input[0]=='T' or input[0]=='t') and input[1]=='a' and 
    input[2]=='l' and input[3]=='k'){
      lcd.clear();
      lcd.println("You talk to");
      delay(2000);
      
      lcd.clear();
      lcd.println("the woman");
      delay(3000);
      
      lcd.clear();
      lcd.println("Woman: Hello, do");
      delay(2000);
      
      lcd.clear();
      lcd.println("either of you");
      delay(2000);
      
      lcd.clear();
      lcd.println("have an umbrella?");
      delay(2000);
      
      while(gaveUmb==false){
      recvOneChar();
      if((input[0]=='Y' or input[0]=='y') 
      and input[1]=='e' and input[2]=='s' 
      and hasUmb==true){
        gaveUmb=true;
        lcd.clear();
        lcd.println("Woman: Thank you");
        delay(2000);
        
        lcd.clear();
        lcd.println("The woman flies");
        delay(2000);
        
        lcd.clear();
        lcd.println("away with the");
        delay(2000);
        
        lcd.clear();
        lcd.println("umbrella");
        delay(2000);
        
        task1=true;
      }
      else if((input[0]=='Y' or input[0]=='y') 
      and input[1]=='e' and input[2]=='s' 
      and hasUmb==false){
        lcd.clear();
        lcd.println("The woman saw right");
        delay(2000);
        
        lcd.clear();
        lcd.println("through your lie");
        delay(2000);
        
        lcd.clear();
        lcd.println("and was immedi-");
        delay(2000);
        
        lcd.clear();
        lcd.println("ately ashamed.");
        delay(2000)
        ;
        gameOver();
      }
      else if((input[0]=='N' or input[0]=='n') and input[1]=='o'){
        lcd.clear();
        lcd.println("Woman: oh.");
        delay(3000);
        
        lcd.clear();
        lcd.println("The woman walks");
        delay(2000);
        
        lcd.clear();
        lcd.println("away. Dejected");
        delay(3000);
        
        task1=true;
        gaveUmb=true;
        }
      }
    }
  }
  toTheTop();
}

void pathRight(){
  lcd.clear();
  lcd.println("you go right");
  delay(3000);
lcd.clear();
  lcd.println("You walk until");
  delay(2000);
  
  lcd.clear();
  lcd.println("you see a man");
  delay(2000);
  
  lcd.clear();
  lcd.println("Standing in");
  delay(2000);
  lcd.clear();
  lcd.println("your path");
  delay(500);
  
  while(task1==false){
    recvOneChar();
    delay(5000);
    if((input[0]=='S' or input[0]=='s') and input[1]=='h' and 
    input[2]=='o' and input[3]=='o' and input[4]=='t' and hasGun==true){
      aquaman=false;
      lcd.clear();
      lcd.println("You shoot him :(");
      delay(4000);
      task1=true;
    }
    else if((input[0]=='T' or input[0]=='t') and input[1]=='a' and 
    input[2]=='l' and input[3]=='k'){
      lcd.clear();
      lcd.println("You talk to");
      delay(2000);
      
      lcd.clear();
      lcd.println("the man");
      delay(3000);
      
      lcd.clear();
      lcd.println("Man: Sup, Bro?");
      delay(2000);
      
      lcd.clear();
      lcd.println("either of you 2");
      delay(2000);
      
      lcd.clear();
      lcd.println("have an umbrella?");
      delay(2000);

      lcd.clear();
      lcd.println("It might rain");
      delay(2000);
      
      while(gaveUmb==false){
      recvOneChar();
      if((input[0]=='Y' or input[0]=='y') 
      and input[1]=='e' and input[2]=='s' 
      and hasUmb==true){
        gaveUmb=true;
        lcd.clear();
        lcd.println("Man: Thanks!");
        delay(2000);
        
        lcd.clear();
        lcd.println("The man jumps");
        delay(2000);
        
        lcd.clear();
        lcd.println("into the ocean w");
        delay(2000);
        
        lcd.clear();
        lcd.println("ith the umbrella");
        delay(2000);
        
        task1=true;
      }
      else if((input[0]=='Y' or input[0]=='y') 
      and input[1]=='e' and input[2]=='s' 
      and hasUmb==false){
        lcd.clear();
        lcd.println("The man saw");
        delay(2000);
        
        lcd.clear();
        lcd.println("through your lie");
        delay(2000);
        
        lcd.clear();
        lcd.println("and stabbed you");
        delay(2000);
        
        lcd.clear();
        lcd.println("with a quindent");
        delay(2000)
        ;
        gameOver();
      }
      else if((input[0]=='N' or input[0]=='n') and input[1]=='o'){
        lcd.clear();
        lcd.println("Man: Oh.");
        delay(3000);
        
        lcd.clear();
        lcd.println("The man walks");
        delay(2000);
        
        lcd.clear();
        lcd.println("away. Dejected");
        delay(3000);
        
        task1=true;
        gaveUmb=true;
        }
      }
    }
  }
  toTheTop();
}
void gameOver(){
  lcd.clear();
  lcd.println("GAME OVER");
  recvOneChar();
  if((input[0]=='R' or input[0]=='r') 
      and input[1]=='e' and input[2]=='s' 
      and input[3]=='t' and input[4]=='a'
      and input[5]=='r' and input[6]=='t'){
        beginGame();
      }
}

void thatWasInteresting(){
  lcd.clear();
  lcd.println("That was weird");
  delay(2000);

  lcd.clear();
  lcd.println("Want to keep");
  delay(2000);

  lcd.clear();
  lcd.println("going?");
  delay(2000);

  while(answered==false){
    recvOneChar();
    if(input[0]=='Y' or input[0]=='y'){
      lcd.clear();
      lcd.println("Let's go");
      delay(2000);
      toTheTop();
    }
    else if((input[0]=='N' or input[0]=='n') and input[1]=='o'){
      lcd.clear();
      lcd.println("Too bad. Lets go");
      delay(2000);
      toTheTop();
    }
    
  }
}

void toTheTop(){
  lcd.clear();
  lcd.println("You arrive at");
  delay(2000);

  lcd.clear();
  lcd.println("the top of the");
  delay(2000);

  lcd.clear();
  lcd.println("volcano");
  delay(2000);

  lcd.clear();
  lcd.println("Brown: Ok dude,");
  delay(2000);

  lcd.clear();
  lcd.println("The cano is like");
  delay(2000);

  lcd.clear();
  lcd.println("Super spicy hot");
  delay(2000);

  lcd.clear();
  lcd.println("It will erupt");
  delay(2000);

  lcd.clear();
  lcd.println("unless we cool");
  delay(2000);

  lcd.clear();
  lcd.println("it down!");
  delay(2000);

  while(savedTheDay==false){
    recvOneChar();
    if((input[0]=='S' or input[0] == 's') and input[1]=='h' and input[2]=='o' and input[3]=='o'
    and input[4]=='o' and input[5]=='t' and (aquaman==false or mary==false) and haveYouTriedShootingIt==false){
      haveYouTriedShootingIt=true;
      lcd.clear();
      lcd.println("Brown: You can't");
      delay(2000);

      lcd.clear();
      lcd.println("just shoot your");
      delay(2000);

      lcd.clear();
      lcd.println("way out of all");
      delay(2000);

      lcd.clear();
      lcd.println("problems! Try");
      delay(2000);

      lcd.clear();
      lcd.println("something else!");
      delay(2000);
    }
    else if((input[0]=='S' or input[0] == 's') and input[1]=='h' and input[2]=='o' and input[3]=='o'
    and input[4]=='t' and haveYouTriedShootingIt==false){
      haveYouTriedShootingIt=true;
      lcd.clear();
      lcd.println("Brown: Did you");
      delay(2000);

      lcd.clear();
      lcd.println("try shooting a ");
      delay(2000);

      lcd.clear();
      lcd.println("a volcano?! How");
      delay(2000);

      lcd.clear();
      lcd.println("would that solve");
      delay(2000);

      lcd.clear();
      lcd.println("anything?! Try");
      delay(2000);

      lcd.clear();
      lcd.println("something else!");
      delay(2000);
    }

    else if((input[0]=='T' or input[0] == 't') and input[1]=='h' and input[2]=='r' and input[3]=='o'
    and input[4]=='w' and input[5]==' ' and (input[6]=='i' or input[6]=='I') and input[7]=='c'
    and input[8]=='e' and input[9]==' ' and (input[10]=='C' or input[10]=='c') and input[11]=='u'
    and input[12]=='b' and input[13]=='e'){
      savedTheDay=true;
      lcd.clear();
      lcd.println("You throw the ice");
      delay(2000);

      lcd.clear();
      lcd.println("cube into the");
      delay(2000);

      lcd.clear();
      lcd.println("volcano. It cools");
      delay(2000);

      lcd.clear();
      lcd.println("it down so it");
      delay(2000);

      lcd.clear();
      lcd.println("doesn't erupt. You");
      delay(2000);

      lcd.clear();
      lcd.println("did it!");
      delay(2000);

      if(aquaman==false or mary==false){
      lcd.clear();
      lcd.println("The Police come");
      delay(2000);

      lcd.clear();
      lcd.println("and arrest you");
      delay(2000);
      }
      
    }
  }
  gameOver();
}

 
 


