#include <fstream>
#include <cmath>
using namespace std;

//uBlock-256
//probability of non-uniform step differential trail

int Sbox[16] = {0x7, 0x4, 0x9, 0xc, 0xb, 0xa, 0xd, 0x8,
                0xf, 0xe, 0x1, 0x6, 0x0, 0x3, 0x2, 0x5};
int DDT[16][16] = {0};


string tobits(int num, int bit_num){ 
	string res = "";
	
	for(int pos = 0; pos < bit_num; pos++)
	{
		res = to_string(num % 2) + res;  
		num /= 2;
	}
	
	return res;
}

int ROUNDS = 8; //
int In = 2; //
int Out = 8; //
int totalPr = 384; //

int main(){


    for(int indc = 0; indc < 16; indc++){
		for(int outdc = 0; outdc < 16; outdc++){
			for(int input = 0; input < 16; input++){
				if ((Sbox[input] ^ Sbox[input^indc]) == outdc){
				    DDT[indc][outdc]++;
                }
			}
        }
    }
    for (int indc = 0; indc < 16; indc++){
		for (int outdc = 0; outdc < 16; outdc++){
            if(DDT[indc][outdc] != 0){
                DDT[indc][outdc] = -(log(DDT[indc][outdc])/log(2)-4);  
            }
            else{
                DDT[indc][outdc] = 1;  
            }
        }
    }

    FILE *fp;
    char filename[100];
    sprintf(filename, "./%dR_%d-%d_nus_Pr.cvc", ROUNDS, In, Out);
    fp = fopen(filename, "w");

/*************************************** variable **********************************************/
       
    //X_rounds_L/R_state
    for(int round = 0; round < ROUNDS+1; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "X_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "X_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "X_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "X_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //x1_rounds_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "x1_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "x1_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "x1_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "x1_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //a_round_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "a_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "a_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "a_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "a_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //a1_round_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "a1_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "a1_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "a1_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "a1_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //b_round_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "b_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "b_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "b_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "b_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //b1_round_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "b1_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "b1_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "b1_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "b1_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");
    //c_round_L/R_state
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "c_%d_L_%d, ", round, state);                
        }
        fprintf(fp, "c_%d_L_%d : BITVECTOR(4);\n", round, 31);
        for(int state = 0; state < 32-1; state++){
            fprintf(fp, "c_%d_R_%d, ", round, state);                
        }
        fprintf(fp, "c_%d_R_%d : BITVECTOR(4);\n", round, 31);                
    }
    fprintf(fp, "\n");

/*************************************** round function **********************************************/

    for(int round = 0; round < ROUNDS; round++){
    
    fprintf(fp, "%%/************************************ round = %d ************************************/\n\n", round+1);

    //X_round_L/R_state -> Sbox -> x1_round_L_state
    for(int state = 0; state < 32; state++){
        fprintf(fp, "ASSERT (IF X_%d_L_%d = 0bin0000 THEN x1_%d_L_%d = 0bin0000 ELSE BVGT(x1_%d_L_%d, 0bin0000) ENDIF);\n", round, state, round, state, round, state);
        fprintf(fp, "ASSERT (IF X_%d_R_%d = 0bin0000 THEN x1_%d_R_%d = 0bin0000 ELSE BVGT(x1_%d_R_%d, 0bin0000) ENDIF);\n", round, state, round, state, round, state);
    }
        fprintf(fp, "\n");

    //x1_round_L_state + x1_round_R_state = a_round_R_state
        for(int state = 0; state < 32; state++) {
            fprintf(fp, "ASSERT a_%d_R_%d = BVXOR(x1_%d_L_%d, x1_%d_R_%d);\n", round, state, round, state, round, state);  
        }
        fprintf(fp, "\n");

    //a_round_R_state <<<4 = a1_round_R_state
        for(int state = 0; state < 8; state++) {
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, state, round, (state+1)%8);
        }
        for(int state = 8; state < 16-1; state++) {
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, state, round, (state+1)%16);
        }
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, 15, round, 8);
        for(int state = 16; state <24-1; state++) {
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, state, round, (state+1)%24);
        }
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, 23, round, 16);
        for(int state = 24; state < 32-1; state++) {
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, state, round, (state+1)%32);
        }
                fprintf(fp, "ASSERT a1_%d_R_%d = a_%d_R_%d;\n", round, 31, round, 24);
        fprintf(fp, "\n");

    //x1_round_L_state + a1_round_R_state = a_round_L_state
        for (int state = 0; state < 32; state++){ 
            fprintf(fp, "ASSERT a_%d_L_%d = BVXOR(x1_%d_L_%d, a1_%d_R_%d);\n", round, state, round, state, round, state);  
        }    
        fprintf(fp, "\n");

    //a_round_L_state <<<8 = a1_round_L_state
        for(int state = 0; state < 8; state++) {
                fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, state, round, (state+2)%8);
        }
        for(int state = 8; state < 16-2; state++) {
                fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, state, round, (state+2)%16);
        }  
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 14, round, 8);
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 15, round, 9);
        for(int state = 16; state < 24-2; state++) {
                fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, state, round, (state+2)%24);
        }  
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 22, round, 16);
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 23, round, 17);
        for(int state = 24; state < 32-2; state++) {
                fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, state, round, (state+2)%32);
        }  
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 30, round, 24);
            fprintf(fp, "ASSERT a1_%d_L_%d = a_%d_L_%d;\n", round, 31, round, 25);
        fprintf(fp, "\n");

    //a1_round_L_state + a_round_R_state = b_round_R_state
        for(int state = 0; state < 32; state++){ 
            fprintf(fp, "ASSERT b_%d_R_%d = BVXOR(a1_%d_L_%d, a_%d_R_%d);\n", round, state, round, state, round, state); 
        } 
        fprintf(fp, "\n");

    //b_round_R_state <<<8 = b1_round_R_state
        for(int state = 0; state < 8; state++) {
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, state, round, (state+2)%8);
        }
        for(int state = 8; state < 16-2; state++) {
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, state, round, (state+2)%16);
        } 
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 14, round, 8);
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 15, round, 9);
        for(int state = 16; state < 24-2; state++) {
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, state, round, (state+2)%24);
        } 
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 22, round, 16);
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 23, round, 17);
        for(int state = 24; state < 32-2; state++) {
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, state, round, (state+2)%32);
        } 
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 30, round, 24);
                fprintf(fp, "ASSERT b1_%d_R_%d = b_%d_R_%d;\n", round, 31, round, 25);
        fprintf(fp, "\n");

    //a_round_L_state + b1_round_R_state = b_round_L_state
        for(int state = 0; state < 32; state++){ 
            fprintf(fp, "ASSERT b_%d_L_%d = BVXOR(a_%d_L_%d, b1_%d_R_%d);\n", round, state, round, state, round, state);   
        }   
        fprintf(fp, "\n");
    
    //b_round_L_state <<<20 = b1_round_L_state
        for(int state = 0; state < 8; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state, round, (state+5)%8);
        }
        for(int state = 8; state < 16-5; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state, round, (state+5)%16);
        }
        for(int state = 8; state < 13; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state+3, round, state);
        }
        for(int state = 16; state < 24-5; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state, round, (state+5)%24);
        }
        for(int state = 16; state < 21; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state+3, round, state);
        }

        for(int state = 24; state < 32-5; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state, round, (state+5)%32);
        }
        for(int state = 24; state < 29; state++) {
                fprintf(fp, "ASSERT b1_%d_L_%d = b_%d_L_%d;\n", round, state+3, round, state);
        }
        fprintf(fp, "\n");

    //b1_round_L_state + b_round_R_state = c_round_R_state
        for(int state = 0; state < 32; state++){ 
            fprintf(fp, "ASSERT c_%d_R_%d = BVXOR(b1_%d_L_%d, b_%d_R_%d);\n", round, state, round, state, round, state);   
        } 
        fprintf(fp, "\n");
    
    //b_round_L_state + c_round_R_state = c_round_L_state
        for(int state = 0; state < 32; state++){ 
            fprintf(fp, "ASSERT c_%d_L_%d = BVXOR(b_%d_L_%d, c_%d_R_%d);\n", round, state, round, state, round, state);
        }
        fprintf(fp, "\n");
    
    //X_round+1_L_state = PL(c_round_L_state)
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 0, round, 4);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 1, round, 5);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 2, round, 14);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 3, round, 15);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 4, round, 16);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 5, round, 17);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 6, round, 26);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 7, round, 27);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 8, round, 6);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 9, round, 7);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 10, round, 12);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 11, round, 13);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 12, round, 18);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 13, round, 19);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 14, round, 24);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 15, round, 25);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 16, round, 2);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 17, round, 3);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 18, round, 8);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 19, round, 9);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 20, round, 30);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 21, round, 31);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 22, round, 20);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 23, round, 21);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 24, round, 28);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 25, round, 29);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 26, round, 22);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 27, round, 23);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 28, round, 10);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 29, round, 11);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n", round+1, 30, round, 0);
        fprintf(fp, "ASSERT X_%d_L_%d = c_%d_L_%d;\n\n", round+1, 31, round, 1);

    //X_round+1_R_state = PR(c_round_R_state)
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 0, round, 12);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 1, round, 13);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 2, round, 22);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 3, round, 23);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 4, round, 2);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 5, round, 3);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 6, round, 24);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 7, round, 25);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 8, round, 18);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 9, round, 19);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 10, round, 8);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 11, round, 9);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 12, round, 4);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 13, round, 5);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 14, round, 30);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 15, round, 31);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 16, round, 14);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 17, round, 15);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 18, round, 0);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 19, round, 1);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 20, round, 26);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 21, round, 27);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 22, round, 20);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 23, round, 21);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 24, round, 28);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 25, round, 29);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 26, round, 6);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 27, round, 7);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 28, round, 16);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 29, round, 17);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n", round+1, 30, round, 10);
        fprintf(fp, "ASSERT X_%d_R_%d = c_%d_R_%d;\n\n", round+1, 31, round, 11);
    }
        
/*************************************** DDT **********************************************/
       
    fprintf(fp, "DDT : ARRAY BITVECTOR(8) OF BITVECTOR(4);\n");
    for(int indc = 0; indc < 16; indc++){
        for(int outdc = 0; outdc < 16; outdc++){
            fprintf(fp, "ASSERT DDT[0bin%s%s] = 0bin%s;\n", tobits(indc,4).c_str(), tobits(outdc,4).c_str(), tobits(DDT[indc][outdc],4).c_str());
        }
    }
    fprintf(fp, "\n");
    

    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32; state++){
            fprintf(fp, "Pr_%d_L_%d", round, state);
            if(state == 31){
                fprintf(fp, " : BITVECTOR(4);\n");
            }
            else{
                fprintf(fp, ", ");
            }
        }
        for(int state = 0; state < 32; state++){
            fprintf(fp, "Pr_%d_R_%d", round, state);
            if(state == 31){
                fprintf(fp, " : BITVECTOR(4);\n");
            }
            else{
                fprintf(fp, ", ");
            }
        }
    } 
    fprintf(fp, "\n");

    
    for(int round = 0; round < ROUNDS; round++){
        for(int state = 0; state < 32; state++){
            fprintf(fp, "ASSERT (IF X_%d_L_%d = 0bin0000 THEN Pr_%d_L_%d = 0bin0000 ELSE Pr_%d_L_%d = DDT[X_%d_L_%d @ x1_%d_L_%d] ENDIF);\n", round, state, round, state, round, state, round, state, round, state);
            fprintf(fp, "ASSERT NOT(DDT[X_%d_L_%d @ x1_%d_L_%d] = 0bin0001);\n", round, state, round, state);
            fprintf(fp, "ASSERT (IF X_%d_R_%d = 0bin0000 THEN Pr_%d_R_%d = 0bin0000 ELSE Pr_%d_R_%d = DDT[X_%d_R_%d @ x1_%d_R_%d] ENDIF);\n", round, state, round, state, round, state, round, state, round, state);
            fprintf(fp, "ASSERT NOT(DDT[X_%d_R_%d @ x1_%d_R_%d] = 0bin0001);\n", round, state, round, state);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");

/*************************************** Pr_nus **********************************************/

    int total_Pr_length = 12;  
    string str_zero = "0bin";
    string str_Pr = "";

    for(int length = 0; length < total_Pr_length-4; length++){
        str_zero += "0";
    }

    for(int round = 0; round < ROUNDS; round++){  
        for(int state = 0; state < 32; state++){
            if( (state==1)||(state==3)||(state==5)||(state==7)||(state==9)||(state==11)||(state==13)||(state==15)||(state==17)||(state==19)||(state==21)||(state==23)||(state==25)||(state==27)||(state==29)||(state==31) ){
                if((round == ROUNDS-1)&&(state == 31)){
                    str_Pr += (str_zero + "@Pr_" + to_string(round) + "_R_" + to_string(state));
                }
                else{
                    str_Pr += (str_zero + "@Pr_" + to_string(round) + "_R_" + to_string(state) + ", ");
                }
            }
        }
    }

    fprintf(fp, "total_Pr : BITVECTOR(%d);\n", total_Pr_length);
    fprintf(fp, "ASSERT total_Pr = BVPLUS(%d, %s);\n", total_Pr_length, str_Pr.c_str());
    fprintf(fp, "ASSERT BVLE(total_Pr, 0bin%s);\n\n", tobits(totalPr,12).c_str()); 

/*************************************** fix **********************************************/

    //head difference
    for(int state = 0; state < 32; state++){
        if( (state==1)||(state==3)||(state==5)||(state==7)||(state==9)||(state==11)||(state==13)||(state==15)||(state==17)||(state==19)||(state==21)||(state==23)||(state==25)||(state==27)||(state==29)||(state==31) ){
            fprintf(fp, "ASSERT X_0_R_%d = 0bin%s;\n", state, tobits(In,4).c_str());  
        }
    } 
    fprintf(fp, "\n");
    
    //tail difference
    for(int state = 0; state < 32; state++){
        if( (state==1)||(state==3)||(state==5)||(state==7)||(state==9)||(state==11)||(state==13)||(state==15)||(state==17)||(state==19)||(state==21)||(state==23)||(state==25)||(state==27)||(state==29)||(state==31) ){
            fprintf(fp, "ASSERT x1_%d_R_%d = 0bin%s;\n", ROUNDS-1, state, tobits(Out,4).c_str()); 
        }
    } 
    fprintf(fp, "\n");

    //fix active pattern
    for(int round = 0; round < ROUNDS; round++){ 
        for(int state = 0; state < 32; state++){
            fprintf(fp, "ASSERT Pr_%d_L_%d = 0bin0000;\n", round, state);
        }
        for(int state = 0; state < 32; state=state+2){
            fprintf(fp, "ASSERT Pr_%d_R_%d = 0bin0000;\n", round, state);
            fprintf(fp, "ASSERT BVGT(Pr_%d_R_%d, 0bin0000);\n", round, state+1);
        }
    }
    
    //non-uniform step
    string strAll = ""; 
    for(int round = 0; round < ROUNDS-1; round++){ 
        string str = ""; 
        for(int state = 0; state < 32; state++){
            if( (state==1)||(state==3)||(state==5)||(state==7)||(state==9)||(state==11)||(state==13)||(state==15)||(state==17)||(state==19)||(state==21)||(state==23)||(state==25)||(state==27)||(state==29) ){
                if(state == 29){
                    str += ("(x1_" + to_string(round) + "_R_" + to_string(state) + " = " + "x1_" + to_string(round) + "_R_" + to_string(state+2) + ")");
                }
                else{
                    str += ("(x1_" + to_string(round) + "_R_" + to_string(state) + " = " + "x1_" + to_string(round) + "_R_" + to_string(state+2) + ") AND ");
                }
            }
        }
        if(round == ROUNDS-2){
            strAll += "(NOT(" + str + "))";
        }
        else{
            strAll += "(NOT(" + str + ")) OR ";
        }
    }   
    fprintf(fp, "ASSERT (%s);\n\n", strAll.c_str());






fprintf(fp, "QUERY FALSE;\n");
fprintf(fp, "COUNTEREXAMPLE;");
fclose(fp); 
return 0;}