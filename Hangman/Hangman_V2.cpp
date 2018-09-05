#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
#include<windows.h>
#include<conio.h>
#include<fstream>

using namespace std;
const int title_row=30;
const int title_col=60;
const int options_row=6;
const int options_col=12;
const int empty_row=1;
const int empty_col=20;
const int man_row=24;
const int man_col=24;
const int width=52;

class Hangman{
   private:

   char options[options_row][options_col]=
   {
      {'#','#','#','#','#','#','#','#','#','#','#','#'},
      {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
      {'#',' ','N','e','w',' ','G','a','m','e',' ','#'},
      {'#',' ',' ',' ','E','x','i','t',' ',' ',' ','#'},
      {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
      {'#','#','#','#','#','#','#','#','#','#','#','#'},
   };

   char emptySpaces[empty_row][empty_col] =
   {
      {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
   };

   char the_man[man_row][man_col]=

   {   {'F',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',','U'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','7','b','b','b','b','b','b','b','8',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ','@',' ','@',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ','@',' ','@',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ','!','!','|','&','&',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ','$',' ','#',' ','^',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ','$',' ','#',' ','^',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ','(','#',')',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ',' ',' ',' ','*',' ','%',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ','4','2','2','2','2','2','3',' ',' ',' ','*',' ','%',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ','1',' ',' ',' ',' ',' ','1',' ',' ',' ','*',' ','%',' ',' ',' ',' ','.'},
      {'.',' ',' ','4','2','2','2','2','2','2','2','2','2','3',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ','5','2','2','2','2','2','2','2','2','2','6',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'},
      {'K',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',',','C'},
   };

   char title[title_row][title_col]=
   {
      {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#','#','#','#','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ','#','#',' ',' ',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#',' ','#','#','#','#','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
   };

   char upORdown;
   int arrow_row=2,arrow_col=1;
   char player_move;
   int number_from_list;
   string gameword,used_letters;
   int Length_of_the_word;
   int number_of_wrong_guesses=0;
   char letter_input;
   bool ValidORNotUsed,exists;
   bool GameOver=false;
   bool BadHint;
   bool already_entered_letter=false;
   int word_length=0;
   int hints=2;
   int HintNum;
   char HintAlph;
   int text=0;
   string name;

   public:
   void printTitle();
   void printOptions();
   void playerChoosesOptions();
   void computerChoosesWord();
   string theWord(int);
   void UsedLetters();
   void encryption(string);
   void printEmptySpaces(int, int);
   void checkLetter(string, int);
   void takeInput();
   void drawMan(int);
   void checkGameOver(bool,int);
   void Hint();
   void askName();
   void PrintInfo(string);
   void ClearEverything();
};

void Hangman::printTitle(){
   system("Color 4F");
   for(int i=0;i<title_row;i++){
      cout << setw(42);
      for(int j=0;j<title_col;j++){
         if(title[i][j]=='#'){
            cout << (char)219;
         }else{
            cout << (char)32;
         }
      }cout << endl;
   }
}

void Hangman::printOptions(){
   for(int i=0;i<options_row;i++){
      cout << setw(58);
      for(int j=0;j<options_col;j++){
         if(i==arrow_row && j==arrow_col){
            cout << (char)26;
         }else if(options[i][j]=='#'){
            cout << (char)178;
         }else if(options[i][j]==' '){
            cout << (char)32;
         }else{
            cout << options[i][j];
         }

      }cout << endl;
   }
}

void Hangman::playerChoosesOptions(){
   while(1){
      if(kbhit()){
         player_move=getch();
         if(arrow_row==2 && arrow_col==1 && player_move==13){
            system("CLS");
            askName();
            computerChoosesWord();
         }else if(arrow_row==3 && arrow_col==1 && player_move==13){
            exit(0);
         }else if(player_move==-32){
            upORdown=getch();
            switch (upORdown){
               case 80:
               arrow_row++;
               if(arrow_row > 3){
                  arrow_row--;
               }
               break;
               case 72:
               arrow_row--;
               if(arrow_row < 2){
                  arrow_row++;
               }
               break;
            }
            system("CLS");
            printTitle();
            printOptions();
         }
      }
   }
}

void Hangman::askName(){
   system("Color 0A");
   bool lessthanorgreaterthan4;
   do{
      lessthanorgreaterthan4=false;
      for(int i=0;i<18;i++){
         cout << endl;
      }cout << setw(75) << "Enter a name of 5 characters only: ";
      getline(cin,name);
      if(name.size() < 5 || name.size() > 5){
         lessthanorgreaterthan4 = true;
         system("CLS");
      }else{
         PrintInfo(name);
         break;
      }
   }while(lessthanorgreaterthan4==true);

}

void Hangman::PrintInfo(string name){
   cout << (char)218;
   for(int i=0;i<120;i++){
      cout << (char)196;
   }cout << (char)191 << endl;
   cout << (char)179 << "Player Name: " << name << setw(39) << (char)1 << "HANGMAN" << (char)2 << setw(54) << "Hints Left: " << hints << (char)179 << endl;
   cout << (char)192;
   for(int i=0;i<120;i++){
      cout << (char)196;
   }cout << (char)217 << endl;
}

void Hangman::computerChoosesWord(){
   int SW=0;
   bool sameword;
   srand(time(0));
   do{
      sameword=false;
      number_from_list=rand()%118;
      if(number_from_list==SW){
         sameword=true;
      }else{
         break;
      }
   }while(sameword==true);
   SW=number_from_list;
   theWord(number_from_list);
}

string Hangman::theWord(int w){
   ifstream wordfile;

   wordfile.open("HangManWordList1.txt");

   if(!wordfile){
      cout << "Error Reading File.";
   }

   while(w!=0){
      wordfile >> gameword;
      w--;
   }
   encryption(gameword);
   wordfile.close();
}

void Hangman::encryption(string word){
   cout << word << endl;
   Length_of_the_word=word.size();
   drawMan(number_of_wrong_guesses);
}

void Hangman::drawMan(int wrong_guess){
   system("CLS");
   system("Color F4");
   PrintInfo(name);
   cout << endl << setw(82) << "Enter a letter or press '?' for a hint: " << endl << endl;
   for(int i=0;i<man_row;i++){
      cout << setw(51);
      for(int j=0;j<man_col;j++){
         if(the_man[i][j]=='F' || (wrong_guess>=1 && the_man[i][j]=='4') || (wrong_guess>=2 && the_man[i][j]=='7')){
            cout << (char)201;
         }else if(the_man[i][j]=='U' || (wrong_guess>=1 && the_man[i][j]=='3') || (wrong_guess>=2 && the_man[i][j]=='8')){
            cout << (char)187;
         }else if(the_man[i][j]=='C' || (wrong_guess>=1 && the_man[i][j]=='6')){
            cout << (char)188;
         }else if(the_man[i][j]=='K' || (wrong_guess>=1 && the_man[i][j]=='5')){
            cout << (char)200;
         }else if(the_man[i][j]=='.' || (wrong_guess>=1 && the_man[i][j]=='1') || (wrong_guess>=2 && the_man[i][j]=='a')){
            cout << (char)186;
         }else if(the_man[i][j]==',' || (wrong_guess>=1 && the_man[i][j]=='2') || (wrong_guess>=2 && the_man[i][j]=='b')){
            cout << (char)205;
         }else if((wrong_guess>=3 && the_man[i][j]=='@') || (wrong_guess>=4 && the_man[i][j]=='#')){
            cout << (char)219;
         }else if(wrong_guess>=4 && the_man[i][j]=='|'){
            cout << (char)179;
         }else if((wrong_guess>=5 && the_man[i][j]=='!') ||( wrong_guess>=6 && the_man[i][j]=='&')
         ||  (wrong_guess>=7 && the_man[i][j]=='(') || (wrong_guess>=8 && the_man[i][j]==')')){
            cout << (char)220;
         }else if((wrong_guess>=5 && the_man[i][j]=='$') || (wrong_guess>=6 && the_man[i][j]=='^')
         ||   (wrong_guess>=7 && the_man[i][j]=='*') || (wrong_guess>=8 && the_man[i][j]=='%')){
            cout << (char)219;
         }else{
            cout << (char)32;
         }
      }cout << endl;
   }
   printEmptySpaces(Length_of_the_word,width);
   checkGameOver(GameOver,word_length);
   takeInput();
}


void Hangman::printEmptySpaces(int WL , int width){
   if(WL==3)width+=6;
   else if(WL==4)width+=5;
   else if(WL==5)width+=4;
   else if(WL==6)width+=2.5;
   else if(WL==7)width+=1;
   else if(WL==8)width-=0.5;
   else if(WL==9)width-=1.5;
   else if(WL>9)width-=3;
   for(int i=0;i<empty_row;i++){
      cout << setw(width);
      for(int j=0;j<WL;j++){
         if(emptySpaces[i][j]==' '){
            cout << (char)205 << (char)205 << " ";
         }else {
            cout << emptySpaces[i][j] << " ";
         }
      }
   }cout << endl;
}

void Hangman::takeInput(){
   do{
      ValidORNotUsed=true;
      cin >> letter_input;
      for(int i=0;i<used_letters.size();i++){
         if(used_letters[i]==letter_input){
            cout << setw(95) << "Whoops!! It seems like you have already used that letter before!" << endl;
            Sleep(2000);
            drawMan(number_of_wrong_guesses);
            ValidORNotUsed=false;
         }
      }

      if(letter_input=='?' && hints > 0){
         cout << setw(75) << "You pressed the hint button.";
         Sleep(2000);
         hints--;
         Hint();
      }else if(letter_input >='a' && letter_input <='z'){
         used_letters+=letter_input;
      }else if(letter_input=='?' && hints==0){
         cout << setw(78) << "Sorry, no more hints available :(" << endl;
         Sleep(2000);
         drawMan(number_of_wrong_guesses);
      }else if((letter_input < 'a' || letter_input > 'z') || (letter_input!='?')){
         cout << setw(68) << "Invalid Input!" << endl;
         Sleep(2000);
         drawMan(number_of_wrong_guesses);
         ValidORNotUsed=false;
      }


      if(ValidORNotUsed==true && letter_input!='?'){
         checkLetter(gameword,Length_of_the_word);
      }


   }while(ValidORNotUsed==false);
}

void Hangman::Hint(){
   bool found;
   do{
      found=false;
      srand(time(0));
      HintNum=rand()%gameword.size();
      HintAlph=gameword[HintNum];
      if(emptySpaces[0][HintNum]==' '){
         emptySpaces[0][HintNum]=HintAlph;
         used_letters+=HintAlph;
         word_length++;
         break;
      }else{
         found=false;
      }

   }while(found==false);

   drawMan(number_of_wrong_guesses);
}

void Hangman::checkLetter(string hide_word, int WL2){
   bool letter_found;
   int a=0;
   for(int i=0;i<WL2;i++){
      if(hide_word[i]==letter_input && emptySpaces[0][i]==' '){
         letter_found=true;
         if(a==0){
            cout << setw(73) << "This letter does exist!" << endl << endl;
         }a++;
         emptySpaces[0][i]=letter_input;
         word_length++;
      }
   }

   if(letter_found==false){
      cout << setw(80) << "Sorry, this letter does not exist :(" << endl << endl;
      number_of_wrong_guesses++;
      if(number_of_wrong_guesses==8){
         GameOver=true;
      }
   }
   Sleep(1500);
   drawMan(number_of_wrong_guesses);
}

void Hangman::checkGameOver(bool isGameOver, int word_length){
   if(isGameOver==true){
      system("CLS");
      for(int i=0;i<19;i++){
         cout << endl;
      }
      cout << endl << setw(55) << "You lost." << " The word was: '" << gameword << "'.";
      for(int i=0;i<14;i++){
         cout << endl;
      } Sleep(3000);
      ClearEverything();
   }
   if(word_length==gameword.size()){
      system("CLS");
      for(int i=0;i<19;i++){
         cout << endl;
      }
      cout << endl << setw(76) << "Yep, thats correct!!! The word was: '" << gameword << "'." << endl << endl << endl << endl;
      for(int i=0;i<14;i++){
         cout << endl;
      }Sleep(3000);
      ClearEverything();
   }

}

void Hangman::ClearEverything(){
   for(int i=0;i<empty_row;i++){
      for(int j=0;j<empty_col;j++){
         if(emptySpaces[i][j]!=' '){
            emptySpaces[i][j]=' ';
         }
      }
   }
   GameOver=false;
   number_of_wrong_guesses=0;
   word_length=0;
   hints=2;
   used_letters=("");
   system("CLS");
   printTitle();
   printOptions();
   playerChoosesOptions();
}

int main(){
   Hangman h;
   h.printTitle();
   h.printOptions();
   h.playerChoosesOptions();
   return 0;
}
