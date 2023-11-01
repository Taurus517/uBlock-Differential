#include <fstream>
#include <unistd.h> 
#include <string.h>  
#include <string>
#include <iostream>
using namespace std;

int ROUNDS = 7; //

int main(){



    FILE *fp = NULL; 
    fp = popen("g++ nus_Pr.cpp -o test", "r"); //
    pclose(fp);

    FILE *fp0 = NULL; 
    fp0 = popen("./test", "r");
    pclose(fp0);

    FILE *fp1 = NULL; 
    FILE *fp2 = NULL; 
    fp1 = popen("stp 7R_2-8_nus_Pr.cvc", "r"); //
    
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
    
        ifstream fr;
        fr.open("result.txt", ios::in); 

        string read;
        int pos1, pos2;
    
        while (!fr.eof()){  
            getline(fr, read);
            string cc = "ASSERT( total_Pr = 0x"; //
            pos1 = read.find(cc);
            pos2 = read.find("0x");
            if(pos1 >= 0){
                str = read.substr(pos2+2, 3); //
            }
        }
        fr.close();
        
        
        
        ifstream OriginalCVC;
        OriginalCVC.open("7R_2-8_nus_Pr.cvc", ios::in); //
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
        OriginalCVC1.open("7R_2-8_nus_Pr.cvc", ios::out); //
        while(getline(TempCVC1, del)){
            OriginalCVC1 << del << endl;
        }
        OriginalCVC1.close();
        TempCVC1.close();


        ofstream OriginalCVC2;
        OriginalCVC2.open("7R_2-8_nus_Pr.cvc", ios::app); //

        string strc = "ASSERT NOT(total_Pr = 0hex" + str + ");"; //
        OriginalCVC2 << strc;
        OriginalCVC2 << endl << del1 << endl << del2 << endl;
        OriginalCVC2.close();



        FILE *Refresh = NULL; 
        FILE *fh1=NULL;
        Refresh = popen("stp 7R_2-8_nus_Pr.cvc", "r"); //
        
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
