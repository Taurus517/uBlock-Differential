#include <fstream>
#include <unistd.h> 
#include <string.h>  
#include <string>
#include <iostream>
using namespace std;

int ROUNDS = 7; //

int main(){



    FILE *fp = NULL; 
    fp = popen("g++ nus_trail.cpp -o test", "r"); //
    pclose(fp);

    FILE *fp0 = NULL; 
    fp0 = popen("./test", "r");
    pclose(fp0);

    FILE *fp1 = NULL; 
    FILE *fp2 = NULL; 
    fp1 = popen("stp 7R_2-8_112_nus_trail.cvc", "r"); //
    
    char buff;
    buff = getc(fp1);
    fp2 = fopen("result.txt", "w");
    while (buff != EOF)  
    {
        fputc(buff, fp2);
        buff = getc(fp1);
    }
    pclose(fp1); 
    fclose(fp2);


    
    ifstream ModifyRes;
    ModifyRes.open("result.txt", ios::in);
    string str_read;                
    getline(ModifyRes, str_read);
    ModifyRes.close();

    while(str_read.compare("Valid.") != 0){
        string str;

        for(int i = 0; i < ROUNDS-1; i++){ // 
        for(int j = 1; j < 16; j+=2){ //

        ifstream fr;
        fr.open("result.txt", ios::in); 

        string read;
        int pos1, pos2;
    
        while (!fr.eof()){  
            getline(fr, read);
            string cc = "ASSERT( x1_" + to_string(i) + "_R_" + to_string(j) + " = 0x"; //
            pos1 = read.find(cc);
            pos2 = read.find("0x");
            if(pos1 >= 0){
                str += read.substr(pos2+2, 1); //
            }
        }
        fr.close();

        }}
        
        
        
        ifstream OriginalCVC;
        OriginalCVC.open("7R_2-8_112_nus_trail.cvc", ios::in); //
        ofstream TempCVC;
        TempCVC.open("temp.cvc", ios::out); 

        string del1 = "QUERY FALSE;";
        string del2 = "COUNTEREXAMPLE;";
        string del;
        while(getline(OriginalCVC, del)){
            if(del.compare(del1)!=0){
            if(del.compare(del2)!=0){
                TempCVC << del << endl;
            }}
        }
        OriginalCVC.close();
        TempCVC.close();

        ifstream TempCVC1;
        TempCVC1.open("temp.cvc", ios::in);
        ofstream OriginalCVC1;
        OriginalCVC1.open("7R_2-8_112_nus_trail.cvc", ios::out); //
        while(getline(TempCVC1, del)){
            OriginalCVC1 << del << endl;
        }
        OriginalCVC1.close();
        TempCVC1.close();


        ofstream OriginalCVC2;
        OriginalCVC2.open("7R_2-8_112_nus_trail.cvc", ios::app); //

        //
        string str0 = "";
        for(int round = 0; round < ROUNDS-1; round++){  
            for(int state = 0; state < 16; state++){
                if( (state==1)||(state==3)||(state==5)||(state==7)||(state==9)||(state==11)||(state==13)||(state==15) ){
                    if((round == ROUNDS-2)&&(state == 15)){
                        str0 += ("x1_" + to_string(round) + "_R_" + to_string(state));
                    }
                    else{
                        str0 += ("x1_" + to_string(round) + "_R_" + to_string(state) + "@");
                    }
                }
            }
        }  

        string strc = "ASSERT NOT(" + str0 + " = 0hex" + str + ");";
        OriginalCVC2 << strc;
        OriginalCVC2 << endl << del1 << endl << del2 << endl;
        OriginalCVC2.close();



        FILE *Refresh = NULL; 
        FILE *fh1=NULL;
        Refresh = popen("stp 7R_2-8_112_nus_trail.cvc", "r"); //
        
        char buff1;
        buff1 = getc(Refresh);
        fh1 = fopen("result.txt", "w");  
        while (buff1 != EOF)  
        {
            fputc(buff1, fh1);
            buff1 = getc(Refresh);
        }
        pclose(Refresh); 
        fclose(fh1);
        


        ifstream ModifyRes1;
        ModifyRes1.open("result.txt",ios::in); 
        getline(ModifyRes1, str_read);
        ModifyRes1.close();
    }       



    return 0;
}
