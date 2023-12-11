#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <windows.h>
#include <ctime> 
#include <cstdlib> 
//#include <graphics.h>
#include <math.h>
//#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "termcolor\termcolor.hpp"
using namespace std;

vector<vector<char> > CHARforest;
const int size = 30 ; 
const int Ssize = 5;
const int Tsize = size + 2 ;
int CharMat[size][size];
char matrix[size][size];
int StabMat[size][size];
int backupMat[Tsize][Tsize];
int backupMat2[Tsize][Tsize];
int blocMat[size][size];
int tubeMat[size][size];
int bateauMat[size][size];
int rucheMat[size][size];
int homefoneMat[size][size];
void FilltheMatman();
void Printthemat();
void FilltheMatrand();
void IntTochar();
void PrinttheCHARmat();
int NieghborTest(int i , int j);
void UpdateMatrix(); 
void Backup();
void backup2();
void PrintBackupMat();
void Bloc(int randi,int randj);
void Tube(int randi,int randj);
void Bateau(int randi,int randj); 
void Ruche(int randi,int randj); 
void Homefone(int randi,int randj); 
void showMat(int mat[size][size]);
void backup3(int mats[size][size]);
int NieghborTest2(int i , int j);
void UpdateMatrix2(int mats[size][size]); 
int TestStab(int mat[size][size],int mat2 [size][size]);
void Copy();

int choix = 0;
int stab = 0;
int number = 0;
int count = 0;
int gen = 0;
int gen1 = 0;
int n= 0 ;
int n1= 0 ;
int percent = 0;


int main(){
	
	a : printf("Please choise you option : \n");
	printf("1 - Fill the matrix randomly \n");
	printf("2 - Fill the matrix Manualy \n");
	printf("3 - Show Stabilisation Matrices \n");
	printf("0 - Exit \n");
	cin >> choix ; 
	if(choix == 1){
		
		printf("How much you want to Fill ? \n");
	    cin >> percent ; 
		number = ((size*size)*percent)/100;
		FilltheMatrand();
	}

	if(choix == 2){
		printf("Go ahead and fill the matrix");
		printf("PS : 0 --> black spot |  1 --> white spot");
		FilltheMatman();
	}
	if(choix ==3){
	printf("1 - show BLOC \n");
	printf("2 - show TUBE \n");
	printf("3 - show BATEAU  \n");
	printf("4 - show RUCHE  \n");
	printf("5 - show HOMEFONE  \n");
	cin >> stab;
	n1 = 0;
	if(stab == 1){
		srand (time(0));
		int randi=rand()%size;
		int randj=rand()%size;
		printf(" How many generation you want to Print !! \n ");
	cin >> gen1 ; 
	while(n1 != gen1){
		printf("GENERATION NUMBER %d",n1);
		Bloc(randi,randj);
		backup3(blocMat);
		UpdateMatrix2(blocMat);
		showMat(blocMat);
			 n1++;
	}
		goto a;
	}
	if(stab == 2){
			srand (time(0));
		int randi=rand()%size;
		int randj=rand()%size;
		printf(" How many generation you want to Print !! \n ");
	cin >> gen1 ; 
	while(n1 != gen1){
		printf("GENERATION NUMBER %d",n1);
		Tube(randi,randj);
		backup3(tubeMat);
		UpdateMatrix2(tubeMat);
		showMat(tubeMat);
				 n1++;
	}
		goto a;
	}
	if(stab == 3){
			srand (time(0));
		int randi=rand()%size;
		int randj=rand()%size;
		printf(" How many generation you want to Print !! \n ");
	cin >> gen1 ; 
	while(n1 != gen1){
		printf("GENERATION NUMBER %d",n1);
		Bateau(randi,randj);
		backup3(bateauMat);
		UpdateMatrix2(bateauMat);
		showMat(bateauMat);
					 n1++;
	}
		goto a;
	}
	if(stab == 4){
				srand (time(0));
		int randi=rand()%size;
		int randj=rand()%size;
		printf(" How many generation you want to Print !! \n ");
	cin >> gen1 ; 
	while(n1 != gen1){
		printf("GENERATION NUMBER %d",n1);
		Ruche(randi,randj);
		backup3(rucheMat);
		UpdateMatrix2(rucheMat);
		showMat(rucheMat);
				 n1++;
	}
		goto a;
	}
	if(stab == 5){
					srand (time(0));
		int randi=rand()%size;
		int randj=rand()%size;
		printf(" How many generation you want to Print !! \n ");
	cin >> gen1 ; 
	while(n1 != gen1){
		printf("GENERATION NUMBER %d",n1);
		Homefone(randi,randj);
		backup3(homefoneMat);
		UpdateMatrix2(homefoneMat);
		showMat(homefoneMat);
			 n1++;
	}
		goto a;
	}

	}

	if(choix ==0){
		return 0 ;
	}

	printf(" How many generation you want to Print !! \n ");
	cin >> gen ; 
	while(n != gen){
		printf("GENERATION NUMBER %d",n);
	 //Backup();
		backup2();
		Copy();
	
	 //Printthemat();
	 IntTochar();
	 //PrintBackupMat();
	 PrinttheCHARmat();
	 UpdateMatrix();

	 int val = TestStab(CharMat,StabMat);
	 if(val == (size*size)){
		 printf("GENERATION NUMBER %d",n+1);
		 IntTochar();
		 PrinttheCHARmat();
		 cout << "\n" << "is stable at generation :  " <<n << "\n";
		 goto b; 
	 }
	 n++;
	}
	b:
	goto a;
	//return 0 ;
}

void Copy(){

	for(int i = 0;i<size; i++){
		for(int j=0;j<size ; j++){

			StabMat[i][j] = CharMat[i][j];
		}

	}
}

void backup2(){

	
	
    int border = 0;	
    int iCount = 0;
    int jCount = 0;
    
    for (int i = 0; i < Tsize; i++) {
        for (int j = 0; j < Tsize; j++) {
            if ((i == 0 && (j >= 0 || j == Tsize-1)) || ( i >= 0 && (j == 0 || j == Tsize-1)) || (i == Tsize-1 && j >= 0)) {
                backupMat[i][j] = border;
            } else {
                backupMat[i][j] = CharMat[iCount][jCount];
                jCount++;
            }
        }
        
        if (i != 0 && i != Tsize-1) {
            iCount++;
            jCount = 0;
        }
    }

}

void backup3(int mats[size][size]){

	
    int border = 0;	
    int iCount = 0;
    int jCount = 0;
    
    for (int i = 0; i < Tsize; i++) {
        for (int j = 0; j < Tsize; j++) {
            if ((i == 0 && (j >= 0 || j == Tsize-1)) || ( i >= 0 && (j == 0 || j == Tsize-1)) || (i == Tsize-1 && j >= 0)) {
                backupMat2[i][j] = border;
            } else {
                backupMat2[i][j] = mats[iCount][jCount];
                jCount++;
            }
        }
        
        if (i != 0 && i != Tsize-1) {
            iCount++;
            jCount = 0;
        }
    }

}

/*int NieghborTest(int i , int j ){
	int cou = 0 ; 

	cou = backupMat[i+1][j] + backupMat[i+1][j+1] + backupMat[i][j+1] + backupMat[i-1][j+1] + backupMat[i-1][j] + backupMat[i-1][j-1] + backupMat[i][j-1] + backupMat[i+1][j-1] ; 
		return cou;
	if(cou>=2 && cou <=3){
		return 7;}
	if(cou<2 && cou >3){
		return 8;}
	
	if(cou == 3){
		return 9;}
	//cout << cou ; 
}*/

int NieghborTest(int i , int j ){
	int cou =0;
	if(backupMat[i+1][j] == 1 ){
		cou += 1 ;}
	if(backupMat[i+1][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat[i][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat[i-1][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat[i-1][j] == 1 ){
		cou += 1 ;}
	if(backupMat[i-1][j-1] == 1 ){
		cou += 1 ;}
	if(backupMat[i][j-1] == 1 ){
		cou += 1 ;}
	if(backupMat[i+1][j-1] == 1 ){
		cou += 1 ;}

	return cou ; 
	//cout << " "  << cou << " " ;
/*	if(cou>=2 && cou <=3){
		return 7;}
	if(cou<2 && cou >3){
		return 8;}
	
	if(cou == 3){
		return 9;}
		*/


}

int NieghborTest2(int i , int j ){
	int cou =0;
	if(backupMat2[i+1][j] == 1 ){
		cou += 1 ;}
	if(backupMat2[i+1][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat2[i][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat2[i-1][j+1] == 1 ){
		cou += 1 ;}
	if(backupMat2[i-1][j] == 1 ){
		cou += 1 ;}
	if(backupMat2[i-1][j-1] == 1 ){
		cou += 1 ;}
	if(backupMat2[i][j-1] == 1 ){
		cou += 1 ;}
	if(backupMat2[i+1][j-1] == 1 ){
		cou += 1 ;}

	return cou ; 
	//cout << " "  << cou << " " ;
/*	if(cou>=2 && cou <=3){
		return 7;}
	if(cou<2 && cou >3){
		return 8;}
	
	if(cou == 3){
		return 9;}
		*/


}

void UpdateMatrix(){
	int test = 0 ;
	for(int i =0 ; i<size ; i++){
		for(int j = 0 ; j<size ; j++){
			test = NieghborTest(i+1 ,j+1 ); 
			//cout << test << "\n";
			if(CharMat[i][j] == 1){
				if (test>=2 || test <=3){	
				CharMat[i][j] = 1;		
				}
				if(test<2 || test >3){
					CharMat[i][j] = 0;
				}
			}
			if(CharMat[i][j] == 0 ){
				if( test == 3){
				CharMat[i][j] = 1;
				}
			}
		}
	}
}

void UpdateMatrix2(int mats[size][size]){
	int test = 0 ;
	for(int i =0 ; i<size ; i++){
		for(int j = 0 ; j<size ; j++){
			test = NieghborTest2(i+1 ,j+1 ); 
			//cout << test << "\n";
			if(mats[i][j] == 1){
				if (test>=2 || test <=3){	
				mats[i][j] = 1;		
				}
				if(test<2 || test >3){
					mats[i][j] = 0;
				}
			}
			if(mats[i][j] == 0 ){
				if( test == 3){
				mats[i][j] = 1;
				}
			}
		}
	}
}

void Backup(){

	for(int i =0 ; i<size;i++){
		for(int j = 0 ; j<size ; j++){
			 backupMat[i][j] =  CharMat[i][j] ;
		}
	}

}
void FilltheMatrand(){
	boolean same = false ; 
	int ran1 = 0;
	int ran2 = 0 ;
	for(int i = 0 ; i< size; i++){
		for(int j = 0 ; j <size; j++){
			//cin >> CharMat[i][j];
			CharMat[i][j] = 0;

		}
	}

		for(int count =0 ; count < number ; count ++ ){
			
			  srand (time(0));
			 ran1  = rand()%size; 
			 ran2  = rand()%size; 
			//cout <<ran1<<"  " <<ran2 ;
			while(CharMat[ran1][ran2] == 1){
				ran1 = rand()%size; 
				ran2  = rand()%size; 
			// cout << ran1 << ran2 ;
			
			}
	         	CharMat[ran1][ran2] = 1;
			}

}

void FilltheMatman(){

	for(int i = 0 ; i< size; i++){
		for(int j = 0 ; j <size; j++){
			cin >> CharMat[i][j];
			

		}
	}
}

void Printthemat(){
	for(int i = 0 ; i< size; i++){
		//cout << " -- " << endl << endl;
		cout << "\n" ; 
		for(int j = 0 ; j <size; j++){

			//SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x5B );
			cout << " | " <<  CharMat[i][j]   ; 
			//cout << endl;
		}
		cout << " | " << endl << endl;
	}
	//cout << " " << endl << endl;

}

void IntTochar(){

	for(int i = 0 ; i< size; i++){
		for(int j=0;j<size ; j++){
			if(CharMat[i][j] == 0){
				matrix[i][j] = 'B';
			}
			if(CharMat[i][j] == 1){
				matrix[i][j] = 'W';
			}
		}
	}
}


void PrinttheCHARmat(){
	for(int i = 0 ; i< size; i++){
		//cout << " -- " << endl << endl;
		cout << "\n";
		for(int j = 0 ; j <size; j++){
			//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if(matrix[i][j] == 'B'){
              //SetConsoleTextAttribute(hConsole, 0);

				cout  << termcolor::white << " | " << termcolor::white << matrix[i][j]  ;
			}
			if(matrix[i][j] == 'W'){
              //SetConsoleTextAttribute(hConsole, 255);
			cout  << termcolor::white << " | " << termcolor::red <<  matrix[i][j]  ;
			}
			//SetConsoleTextAttribute(hConsole , DEFAULT_PITCH);

			//cout << endl;
		}
		cout << termcolor::white << " |";
		
	//	cout << " | " << endl << endl;
	}
	cout << "\n";
	//cout << " " << endl << endl;

}

void PrintBackupMat(){

	for(int i = 0 ; i<Tsize; i++){
		cout << "\n";
		for(int j = 0 ; j<Tsize; j++){
			cout << " " << backupMat[i][j]; 
		}
	}
}

void Bloc(int randi, int randj){
	
		for(int i = 0 ; i<size; i++){
			for(int j = 0 ; j<size; j++){
			blocMat[i][j] = 0;
		}
			
			/*blocMat[randi][randj] = 1;
			blocMat[randi+1][randj] = 1;
			blocMat[randi+1][randj+1] = 1;
			blocMat[randi][randj+1] = 1;*/
	}

			//blocMat[size/2-1][size/2] = 1;
			blocMat[15][15] = 1;
			blocMat[16][15] = 1;
			blocMat[17][15] = 1;
			blocMat[18][15] = 1;
			//blocMat[18][15] = 1;
			//blocMat[size/2+3][size/2] = 1;
		


}

void Tube(int randi, int randj){
	
		for(int i = 0 ; i<size; i++){
			for(int j = 0 ; j<size; j++){
			tubeMat[i][j] = 0;
		}
			}
		/*	tubeMat[randi+1][randj] = 1;
			tubeMat[randi+2][randj+1] = 1;
			tubeMat[randi+1][randj+2] = 1;
			tubeMat[randi][randj+1] = 1;
			*/
			tubeMat[size/2][size/2-1] = 1;
			tubeMat[size/2+1][size/2] = 1;
			tubeMat[size/2-1][size/2] = 1;
			tubeMat[size/2][size/2+1] = 1;
	


}

void Bateau(int randi, int randj){
	
		for(int i = 0 ; i<size; i++){
			for(int j = 0 ; j<size; j++){
			bateauMat[i][j] = 0;
		}
		
	}
		/*	bateauMat[randi+1][randj] = 1;
			bateauMat[randi+2][randj+1] = 1;
			bateauMat[randi+1][randj+2] = 1;
			bateauMat[randi][randj+1] = 1;
			bateauMat[randi][randj] = 1;*/
			bateauMat[size/2][size/2-1] = 1;
			bateauMat[size/2+1][size/2] = 1;
			bateauMat[size/2-1][size/2] = 1;
			bateauMat[size/2][size/2+1] = 1;
			bateauMat[size/2-1][size/2-1] = 1;

}

void Ruche(int randi, int randj){
	
		for(int i = 0 ; i<size; i++){
			for(int j = 0 ; j<size; j++){
			rucheMat[i][j] = 0;
		}
			
	}
			/*rucheMat[randi+1][randj-1] = 1;
			rucheMat[randi+2][randj] = 1;
			rucheMat[randi+2][randj+1] = 1;
			rucheMat[randi][randj+1] = 1;
			rucheMat[randi+1][randj+2] = 1;
			rucheMat[randi][randj] = 1;*/

			rucheMat[size/2][size/2-1] = 1;
			rucheMat[size/2+1][size/2-1] = 1;
			rucheMat[size/2+1][size/2] = 1;
			rucheMat[size/2+1][size/2+1] = 1;
			rucheMat[size/2][size/2+1] = 1;
			rucheMat[size/2-1][size/2] = 1;

}

void Homefone(int randi, int randj){
	
		for(int i = 0 ; i<size; i++){
			for(int j = 0 ; j<size; j++){
			homefoneMat[i][j] = 0;
		}
			
	}
		 /*   homefoneMat[randi+1][randj] = 1;
			homefoneMat[randi+1][randj+1] = 1;
			homefoneMat[randi+1][randj+2] = 1;
			homefoneMat[randi+2][randj+3] = 1;
			homefoneMat[randi+3][randj+3] = 1;
			homefoneMat[randi][randj] = 1;
			homefoneMat[randi+3][randj+2] = 1;*/

			homefoneMat[size/2-2][size/2-1] = 1;
			homefoneMat[size/2-2][size/2] = 1;
			homefoneMat[size/2-1][size/2] = 1;
			homefoneMat[size/2][size/2] = 1;
			homefoneMat[size/2+1][size/2+1] = 1;
			homefoneMat[size/2+1][size/2+2] = 1;
			homefoneMat[size/2][size/2+2] = 1;
			
			
			

}

void showMat(int mat[size][size]){

		for(int i = 0 ; i< size; i++){
		//cout << " -- " << endl << endl;
		cout << "\n";
		for(int j = 0 ; j <size; j++){
			//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if(mat[i][j] == 0){
              //SetConsoleTextAttribute(hConsole, 0);

				cout  << termcolor::white << " | " << termcolor::white << 'B'  ;
			}
			if(mat[i][j] == 1){
              //SetConsoleTextAttribute(hConsole, 255);
			cout  << termcolor::white << " | " << termcolor::red <<  'W'  ;
			}
			//SetConsoleTextAttribute(hConsole , DEFAULT_PITCH);

			//cout << endl;
		}
		cout << termcolor::white << " |";
		
	//	cout << " | " << endl << endl;
	}
	cout << "\n";
	//cout << " " << endl << endl;


}

int TestStab(int mat[size][size],int mat2 [size][size]){

	int conteur= 0 ; 
	for(int i = 0 ; i<size ; i++){
		for(int j = 0 ; j<size ; j++){

	if( mat[i][j] ==  mat2[i][j]){
		conteur++;
	}
	}
	}

	return conteur ;
}