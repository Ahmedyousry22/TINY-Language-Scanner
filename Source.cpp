#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define start 0
#define comment 1
#define number 2
#define id 3
#define assign 4


string Token;
int state;
ofstream outputFile;
int index=0;
char currentChar;


int main(){
//Read the tiny language file into a string
	
	int outputCounter=1;
	
					fstream readFile;
	//ofstream writefile;
	bool again=false;

	
		cout<<"All input files should be in the project directory."<<endl;








			do{
				string input,line,fileName;

	cout<<"Enter the name of the input file."<<endl;
	while(1){
	cin>>fileName;
	//ifstream readFile (fileName,ios::trunc);
	readFile.open(fileName);
		if(readFile.is_open()){

			while(!readFile.eof())
			{
				getline(readFile,line);
				input+=" ";
				input+=line;
			}
				

              input +=' ';
			break;




		}
		else{cout<<"Please type a correct file name."<<endl;}

	}
	/*
	if(outputCounter==1) writefile.open("output1.txt");
	else if(outputCounter==2) writefile.open("output2.txt");
	else if(outputCounter==3) writefile.open("output3.txt");
	else if(outputCounter==4) writefile.open("output4.txt");
	else if(outputCounter==5) writefile.open("output5.txt");
	else if(outputCounter==6) writefile.open("output6.txt");
	else if(outputCounter==7) writefile.open("output7.txt");
	else if(outputCounter==8) writefile.open("output8.txt");
	else writefile.open("output.txt");
	*/
	//writefile.open("output.txt");
	ofstream writefile("output.txt", ios_base::app);
		cout<<"An output file is created in the same directory."<<endl;
		writefile<<"output of file "<<outputCounter++<<"\n";
		//writefile.flush();

		//loop through the input string
	
	state = start;
	for(index = 0;index < input.length(); index++)
	{
		currentChar = input[index];
		if(currentChar == ' ' && state != comment)
		{
          state = start;
		}
		else if(currentChar == '{' && state != comment)
		{
			Token=currentChar;

          state= comment;
	      

		}
		
		else if(state == start){
           if(isdigit(currentChar)){
			   Token="";
			   state=number;
			   if(isalpha(input[index+1])) {cout<<"An error occured. Numbers and identifiers should be seperated by a space."<<endl<<"Scanning has stopped"<<endl;break;}
			        else if(isdigit(input[index+1]))
					{state=number;Token+=currentChar;}
					else {Token=currentChar;writefile<<Token<<", number"<<endl;state=start;}
			   
		   }
		   
		  else if(isalpha(currentChar)){
			   Token="";
			   if(isdigit(input[index+1])) {cout<<"An error occured. Numbers and identifiers should be seperated by a space."<<endl<<"Scanning has stopped"<<endl;break;}
			   if(input[index] == 'i' && input[index+1] == 'f' && input[index+2] == ' ')
			   {
				   writefile<<input[index]<<input[index+1]<<", IF"<<endl;
				   state=start;
		           index++;
		   }
		   else    if(input[index] == 't' && input[index+1] == 'h' && input[index+2] == 'e' && input[index+3] == 'n' && input[index+4] == ' ')
			   {
				   writefile<<"then"<<", THEN"<<endl;
				   state=start;
		           index+=3;
		   }
		   		   else    if(input[index] == 'e' && input[index+1] == 'l' && input[index+2] == 's' && input[index+3] == 'e' && input[index+4] == ' ')
			   {
				   writefile<<"else"<<", ELSE"<<endl;
				   state=start;
		           index+=3;
		   }
		   		   else    if(input[index] == 'e' && input[index+1] == 'n' && input[index+2] == 'd' && input[index+3] == ' ')
			   {
				   writefile<<"end"<<", END"<<endl;
				   state=start;
		           index+=2;
		   }
		   		   else    if(input[index] == 'r' && input[index+1] == 'e' && input[index+2] == 'p' && input[index+3] == 'e' && input[index+4] == 'a' && input[index+5] == 't' && input[index+6] == ' ')
			   {
				   writefile<<"repeat"<<", REPEAT"<<endl;
				   state=start;
		           index+=5;
		   }
		    		   else    if(input[index] == 'u' && input[index+1] == 'n' && input[index+2] == 't' && input[index+3] == 'i' && input[index+4] == 'l' && input[index+5] == ' ')
			   {
				   writefile<<"until"<<", UNTIL"<<endl;
				   state=start;
		           index+=4;
		   }
		   		    else    if(input[index] == 'w' && input[index+1] == 'r' && input[index+2] == 'i' && input[index+3] == 't' && input[index+4] == 'e' && input[index+5] == ' ')
			   {
				   writefile<<"write"<<", WRITE"<<endl;
				   state=start;
		           index+=4;
		   }
		    		   else    if(input[index] == 'r' && input[index+1] == 'e' && input[index+2] == 'a' && input[index+3] == 'd' && input[index+4] == ' ')
			   {
				   writefile<<"read"<<", READ"<<endl;
				   state=start;
		           index+=3;
		   }
		   else {
			   state=id;
			        if(isalpha(input[index+1]))
					{state=id;Token+=currentChar;}
					else {Token=currentChar;writefile<<Token<<", identifier"<<endl;state=start;}
			   
			   
			   
			   
		   }
			       
			   
		   }
   else if(currentChar == ':' && input[index+1] == '='){
	   writefile << ":=, ASSIGN"<<endl;
	   state=start;
	   index++;
   }

    else if(currentChar == ':' && input[index+1] != '='){
	   writefile << "syntax error! ':' is not part of the tiny language."<<endl;
	   //state=error;
	   	   	cout<<"File scanning has stopped due to an error. "<<":"<<" is not part of the Tiny Language."<<endl;
	   	cout<<"File scanning has stopped."<<endl;
			break;
   }
   
   else if(currentChar == '+'){
	   writefile << "+, PLUS"<<endl;
	   state=start;
   }
    else if(currentChar == '-'){
	   writefile << "-, MINUS"<<endl;
	   state=start;
   }
    else if(currentChar == '*'){
	   writefile << "*, MUL"<<endl;
	   state=start;
   }
    else if(currentChar == '/'){
	   writefile << "/, DIVISION"<<endl;
	   state=start;
   }
    else if(currentChar == '='){
	   writefile << "=, EQUAL"<<endl;
	   state=start;
   }
    else if(currentChar == '<'){
	   writefile << "<, SMALLERTHAN"<<endl;
	   state=start;
   }
	   else if(currentChar == '>'){
	   writefile << "<, GREATERTHAN"<<endl;
	   state=start;
   }
    else if(currentChar == ';'){
	   writefile << ";, SEMICOLON"<<endl;
	   state=start;
   }
    else if(currentChar == '('){
	   writefile << "(, LEFTBRACKET"<<endl;
	   state=start;
   }
    else if(currentChar == ')'){
	   writefile << "), RIGHTBRACKET"<<endl;
	   state=start;
   }
//handling the case of wrong symbol
   		
		else {
	   
	   Token=currentChar;
	   writefile << "Syntax error! "<<Token<< " is not part of the tiny language"<<endl;
	   	cout<<"File scanning has stopped due to an error. "<<Token<<" is not part of the Tiny Language."<<endl;
			break;
	   //state = error;
	   
   }

		}


		
		else if(state == comment){
			Token+=currentChar;
		if (currentChar =='}') 
		{state=start;}
		else {state=comment;
			if(index == input.length()-1)
			{cout<<"An error occurred. Comments should be enclosed betweeen {}"<<endl;break;}
			}




		}
		
		else if(state == number){
			Token+=currentChar;
			if(isalpha(input[index+1])) {cout<<"An error occured. Numbers and identifiers should be seperated by a space."<<endl<<"Scanning has stopped"<<endl;break;}
          if(isdigit(input[index+1])){
			  
			  
		  state=number;}
           else {writefile<<Token<<", number"<<endl;state=start;}


		}
		
		else if(state == id){

          Token+=currentChar;
		  if(isdigit(input[index+1])) {cout<<"An error occured. Numbers and identifiers should be seperated by a space."<<endl<<"Scanning has stopped"<<endl;break;}
          if(isalpha(input[index+1])){
			  
			  
		  state=id;}
           else {writefile<<Token<<", identifier"<<endl;state=start;}




		}
	


	}//this belongs to for loop braces



	for(int nn=0;nn<10;nn++)
	writefile<<endl;

		readFile.close();
			writefile.close();

		cout<<"If you want to scan a new file type YES, otherwise type NO."<<endl;
		
		do{
		string answer;
		cin>>answer;
		if(answer == "YES") {again = true;break;}
		else if (answer == "NO") {again = false;break;}
		else {cout<<"Please type a proper answer."<<endl;}

		}while(1);
} while(again==true);











/*




	readFile.open("test.txt");
		if(readFile.is_open()){

			do
			{
				readFile>>line;
				//input+=" ";
				input+=line;
			}
				while(!readFile.eof());

              input +=' ';
			




		}
		//ofstream writefile;
		writefile.open("output.txt");





		*/


	










	return 0;
}