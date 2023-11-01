#include<iostream>
using namespace std;

//uBlock-256
//inverse matrix of linear layer

int main(){
  
    bool A[64][64] = {{0,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,1,0,0,  0,0,0,0,0,1,0,0,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0},                      
                      {1,0,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  0,0,0,0,1,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  0,0,0,0,0,1,0,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  0,0,0,0,1,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0},
                      {1,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,1,0,0,0,0,  0,0,0,1,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  0,0,0,0,1,1,0,0,  0,0,1,0,0,0,0,0,  0,0,1,0,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0},
                      {0,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,0,0,0,  0,0,0,0,1,1,0,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0},                                                                                       
                      {0,0,1,1,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1},
                      {0,0,0,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,0,1,0,0,  1,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0},                      
                      {0,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,1,0,0,0,  0,1,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},
                      {0,0,1,0,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},              
                      {0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0,  0,0,0,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},
                      {0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},                     
                      {0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1},                      
                      {0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0},                      
                      {0,0,0,0,1,0,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0},
                      {0,0,0,0,1,1,0,0,  0,0,0,0,0,1,0,0,  0,0,0,0,0,0,1,0,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0},                     
                      {0,0,0,0,1,1,0,0,  0,0,0,0,1,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,  0,0,0,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0},                      
                      {0,0,0,0,0,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,1,  0,0,1,0,0,0,0,0,  0,0,1,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0},                    
                      {0,0,0,0,0,0,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,1,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0},                                     
                      {0,0,0,0,1,0,0,0,  0,0,0,0,0,1,0,0,  0,0,0,0,0,0,1,1,  0,0,0,1,0,0,0,0,  0,0,1,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0},                     
                      {0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0},                                                            
                      {0,0,0,0,0,1,0,0,  0,0,0,0,1,0,0,0,  0,0,0,0,0,0,0,1,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0},                                                         
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  0,1,0,0,0,0,0,0},  
                      {0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  1,0,0,0,0,0,0,0},                    
                      {0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0},                                                             
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,1,  0,0,0,0,1,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,0,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0},   
                      {0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0},               
                      {0,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  0,0,0,0,1,0,0,0,  0,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0},
                      {1,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  0,0,0,0,1,1,0,0,  0,0,1,0,0,0,0,0,  0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,  0,0,0,0,1,1,0,0,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0},
                      {1,0,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  0,0,0,0,0,1,0,0,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,1,0,0,  0,0,0,0,1,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0},                    
                      {1,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,1,0,0,0,  0,0,0,0,1,1,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,0,0,0,0},
                      {1,1,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,1,0,0,  0,0,0,1,0,0,0,0,  0,0,1,0,0,0,0,0},                    
                      {0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,0,1,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},
                      {0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1},
                      {0,0,0,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0},
                      {0,0,1,0,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0,  0,0,0,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0},
                      {0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0,  0,0,1,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},
                      {0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1},                     
                      {0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,0},
                      {0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,1,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1},
                      {0,0,0,0,1,1,0,0,  0,0,0,0,0,1,0,0,  0,0,0,0,0,0,0,1,  0,0,1,1,0,0,0,0,  0,0,1,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,0,0},
                      {0,0,0,0,1,1,0,0,  0,0,0,0,1,0,0,0,  0,0,0,0,0,0,1,0,  0,0,1,1,0,0,0,0,  0,0,0,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0},
                      {0,0,0,0,1,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,1,  0,0,0,1,0,0,0,0,  0,0,1,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0},
                      {0,0,0,0,1,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,1,0,  0,0,1,0,0,0,0,0,  0,0,1,1,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,1,0,0},
                      {0,0,0,0,0,1,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,1,1,  0,0,0,1,0,0,0,0,  0,0,1,1,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,1,0,0,0},
                      {0,0,0,0,1,0,0,0,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,1,1,  0,0,1,0,0,0,0,0,  0,0,0,1,0,0,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0},
                      {0,0,0,0,0,1,0,0,  0,0,0,0,0,1,0,0,  0,0,0,0,0,0,1,1,  0,0,1,1,0,0,0,0,  0,0,0,0,0,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0},
                      {0,0,0,0,1,0,0,0,  0,0,0,0,1,0,0,0,  0,0,0,0,0,0,1,1,  0,0,1,1,0,0,0,0,  0,0,1,0,0,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,1,0,0},
                      {0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,1,  0,0,0,0,0,1,0,0,  0,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,0,0,  1,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  1,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,  0,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,1,  0,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,1,  0,0,0,0,1,1,0,0,  0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,0,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,1,  0,0,0,0,0,1,0,0,  1,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,1,  0,0,0,0,0,0,0,1,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,  0,0,0,0,1,0,0,0,  1,1,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,0,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  1,1,0,0,0,0,0,0,  0,0,0,0,0,0,0,1,  0,0,0,0,0,0,1,0,  0,0,0,0,1,1,0,0,  0,1,0,0,0,0,0,0}};

    bool A2[64][64] = {}, A3[64][64] = {}, A4[64][64] = {}, A5[64][64] = {}, A6[64][64] = {}, A7[64][64] = {};

    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A2[i][j] ^= A[i][k]&A[k][j];
            }
        }
    }
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A3[i][j] ^= A[i][k]&A2[k][j];
            }
        }
    }
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A4[i][j] ^= A[i][k]&A3[k][j];
            }
        }
    }
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A5[i][j] ^= A[i][k]&A4[k][j];
            }
        }
    }
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A6[i][j] ^= A[i][k]&A5[k][j];
            }
        }
    }
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            for(int k = 0; k < 64; k++){
                A7[i][j] ^= A[i][k]&A6[k][j];
            }
        }
    }
    
    
   
    for(int i = 0; i < 64; i++){
        cout << "{";
        for(int j = 0; j < 64; j++){
            if(j == 63){
                cout << A2[i][j] << "},"; //
            }
            else{
                cout << A2[i][j] << ","; //
            }
        }
        cout << endl;
    }


     return 0; 
}
    
