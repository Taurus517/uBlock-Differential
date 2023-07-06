#include<iostream>
using namespace std;

//uBlock-128
//minimum number of active S-boxes

int main(){
    int count = 32, count2 = 64, count3 = 96, count4 = 128, count5 = 160, count6 = 192, count7 = 224, count8 = 256;
   
    for(int in0 = 0; in0 <= 1; in0++){
    for(int in1 = 0; in1 <= 1; in1++){
    for(int in2 = 0; in2 <= 1; in2++){
    for(int in3 = 0; in3 <= 1; in3++){
    for(int in4 = 0; in4 <= 1; in4++){
    for(int in5 = 0; in5 <= 1; in5++){
    for(int in6 = 0; in6 <= 1; in6++){
    for(int in7 = 0; in7 <= 1; in7++){
    for(int in8 = 0; in8 <= 1; in8++){
    for(int in9 = 0; in9 <= 1; in9++){
    for(int in10 = 0; in10 <= 1; in10++){
    for(int in11 = 0; in11 <= 1; in11++){
    for(int in12 = 0; in12 <= 1; in12++){
    for(int in13 = 0; in13 <= 1; in13++){
    for(int in14 = 0; in14 <= 1; in14++){
    for(int in15 = 0; in15 <= 1; in15++){
    for(int in16 = 0; in16 <= 1; in16++){
    for(int in17 = 0; in17 <= 1; in17++){
    for(int in18 = 0; in18 <= 1; in18++){
    for(int in19 = 0; in19 <= 1; in19++){
    for(int in20 = 0; in20 <= 1; in20++){
    for(int in21 = 0; in21 <= 1; in21++){
    for(int in22 = 0; in22 <= 1; in22++){
    for(int in23 = 0; in23 <= 1; in23++){
    for(int in24 = 0; in24 <= 1; in24++){
    for(int in25 = 0; in25 <= 1; in25++){
    for(int in26 = 0; in26 <= 1; in26++){
    for(int in27 = 0; in27 <= 1; in27++){
    for(int in28 = 0; in28 <= 1; in28++){
    for(int in29 = 0; in29 <= 1; in29++){
    for(int in30 = 0; in30 <= 1; in30++){
    for(int in31 = 0; in31 <= 1; in31++){
    
    bool x[32] = {bool(in0),bool(in1),bool(in2),bool(in3),bool(in4),bool(in5),bool(in6),bool(in7),bool(in8),bool(in9),bool(in10),bool(in11),bool(in12),bool(in13),bool(in14),bool(in15),bool(in16),bool(in17),bool(in18),bool(in19),bool(in20),bool(in21),bool(in22),bool(in23),bool(in24),bool(in25),bool(in26),bool(in27),bool(in28),bool(in29),bool(in30),bool(in31)};

    bool A[32][32] = { {1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0},
                      {0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0},
                      {1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0},
                      {0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1},
                      {0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1},
                      {0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
                      {0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0},
                      {0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0},
                      {1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0},
                      {1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0},
                      {1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1},
                      {0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1},
                      {0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1},
                      {0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0},
                      {0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0},
                      {1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0},
                      {0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1},
                      {0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0},
                      {0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0},
                      {1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0},
                      {1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
                      {1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
                      {1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1},
                      {0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1},
                      {0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1},
                      {0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1},
                      {0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
                      {1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0} };
    bool A2[32][32] = { {1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,1,0},
                        {1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,1},
                        {1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1},
                        {1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,0},
                        {1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0},
                        {0,0,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0},
                        {0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1},
                        {1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1},
                        {0,1,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1},
                        {0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0},
                        {0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0},
                        {0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1},
                        {1,1,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,1},
                        {0,0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,0},
                        {0,1,1,1,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1},
                        {1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1},
                        {1,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0},
                        {0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,1},
                        {1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1},
                        {1,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,0,1,0,0},
                        {0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1},
                        {1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1},
                        {0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1},
                        {1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1},
                        {0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1},
                        {0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
                        {0,0,0,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0},
                        {0,1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
                        {1,0,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
                        {0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1} };
    bool A3[32][32] = { {0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,1},
                        {0,1,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0},
                        {0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,0,0,1,0,1,0},
                        {0,1,1,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1,1,0,0,1,0},
                        {1,0,1,0,0,0,1,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0},
                        {1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,0,1},
                        {0,1,0,1,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,0,0},
                        {0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0},
                        {0,1,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,1},
                        {1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,1,0,1},
                        {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1},
                        {1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0},
                        {0,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1},
                        {0,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1},
                        {0,0,0,1,0,1,0,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,1,0,1,1,1,0},
                        {0,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1},
                        {1,1,1,1,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,0,1,0,1,1,1,0,0},
                        {1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0},
                        {1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                        {1,0,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,1,0},
                        {1,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,1},
                        {1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,0,0,0},
                        {1,0,1,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1},
                        {0,0,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0},
                        {0,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1},
                        {0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0},
                        {0,1,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1},
                        {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,0,1},
                        {0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0},
                        {0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,0,0,0},
                        {0,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1}};
    bool A4[32][32] = { {1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,1,0,1,0,0},
                        {0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1},
                        {0,1,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                        {0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,0,1},
                        {1,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0},
                        {1,0,1,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1},
                        {1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,1},
                        {1,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,1,0},
                        {0,1,0,0,1,0,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0},
                        {1,1,0,0,1,0,1,1,0,1,0,1,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0},
                        {0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0},
                        {0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1},
                        {1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1},
                        {1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,1,0,0,0},
                        {0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1},
                        {1,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,0,0},
                        {0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,0,0},
                        {1,0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0},
                        {0,1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1},
                        {1,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,1,0,1,1,1,1,1,0},
                        {1,1,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0},
                        {1,0,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,1,1,1},
                        {1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0},
                        {1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0},
                        {0,1,1,1,1,1,1,0,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1},
                        {0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
                        {0,1,0,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,1,1,0,0,1},
                        {1,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                        {1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1},
                        {0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,1,0,1,1,1,0},
                        {1,0,1,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1}};
    bool A5[32][32] = { {0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0},
                        {1,1,1,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1},
                        {1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0},
                        {0,1,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1},
                        {1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,0,1,1},
                        {1,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1},
                        {0,1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1},
                        {1,1,0,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,0,0,1,1,0},
                        {1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,0,1,0},
                        {1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1},
                        {1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1},
                        {0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0},
                        {0,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,0},
                        {1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1},
                        {1,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,1,1,1},
                        {1,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1},
                        {1,1,1,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,1},
                        {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1,1,0},
                        {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0},
                        {1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1},
                        {1,1,0,1,1,0,0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0},
                        {0,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,1,0},
                        {0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0},
                        {1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,0,0,1},
                        {1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,1,1},
                        {0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,0,0,0,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1},
                        {1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,1,0},
                        {1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,0,1,0,0,0},
                        {0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1},
                        {0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,1},
                        {1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1}};
    bool A6[32][32] = { {1,1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,0,1},
                        {0,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1},
                        {1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,0,1,1},
                        {1,0,0,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0},
                        {0,1,1,0,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,1,0,1,1,1,0,0},
                        {1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,1},
                        {0,1,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,1},
                        {1,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0},
                        {0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,0,0,0},
                        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1},
                        {0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0},
                        {1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,0,1},
                        {1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1},
                        {0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1},
                        {0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0,1,1,1,0,0},
                        {1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,1},
                        {1,1,1,1,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0},
                        {1,0,1,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,1},
                        {0,0,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},
                        {1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,1},
                        {0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0},
                        {0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1},
                        {1,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1},
                        {0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0},
                        {1,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0},
                        {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,1,1},
                        {0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
                        {0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0},
                        {1,0,1,0,1,1,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,1,0},
                        {1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
                        {0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0},
                        {0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0}};
    bool A7[32][32] = { {1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1,1,1,1},
                        {1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,0,1,1,1,0,1},
                        {0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0},
                        {1,0,0,1,1,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,0},
                        {0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,1},
                        {0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,0},
                        {1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1},
                        {1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0},
                        {1,1,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0},
                        {1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,0},
                        {0,1,0,1,0,1,1,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0},
                        {0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1},
                        {1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1},
                        {1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                        {1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0},
                        {1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,0,1,1},
                        {0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1},
                        {0,1,0,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,0},
                        {0,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1},
                        {0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0},
                        {1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                        {1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,1,0},
                        {1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0},
                        {0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,0},
                        {1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0},
                        {0,1,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0},
                        {1,1,0,1,1,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,1,0},
                        {1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0},
                        {0,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0,1,0,1},
                        {0,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0},
                        {0,0,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0},
                        {0,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,1}};

    bool Ax[32] = {}, A2x[32] = {}, A3x[32] = {}, A4x[32] = {}, A5x[32] = {}, A6x[32] = {}, A7x[32] = {};
    
    for(int i = 0; i <32; i++){
        for(int j = 0; j < 32; j++){
            Ax[i] ^= A[i][j]&x[j];
            A2x[i] ^= A2[i][j]&x[j];
            A3x[i] ^= A3[i][j]&x[j];
            A4x[i] ^= A4[i][j]&x[j];
            A5x[i] ^= A5[i][j]&x[j];
            A6x[i] ^= A6[i][j]&x[j];
            A7x[i] ^= A7[i][j]&x[j];
        }
    }
    

    int c = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
    
    for(int i = 0; i < 32; i++){
        if(x[i] != 0){
            c++;
        }
        if(Ax[i] != 0){
            c2++;
        }
        if(A2x[i] != 0){
            c3++;
        }
        if(A3x[i] != 0){
            c4++;
        }
        if(A4x[i] != 0){
            c5++;
        }
        if(A5x[i] != 0){
            c6++;
        }
        if(A6x[i] != 0){
            c7++;
        }
        if(A7x[i] != 0){
            c8++;
        }
    }

        
        
    if((c > 0) && (c < count)){
        count = c;
    }
    if(((c + c2) > 0) && (c + c2) < count2){
        count2 = (c + c2);
    }
    if(((c + c2 + c3) > 0) && (c + c2 + c3) < count3){
        count3 = (c + c2 + c3);
    }
    if(((c + c2 + c3 + c4) > 0) && (c + c2 + c3 + c4) < count4){
        count4 = (c + c2 + c3 + c4);
    }
    if(((c + c2 + c3 + c4 + c5) > 0) && (c + c2 + c3 + c4 + c5) < count5){
        count5 = (c + c2 + c3 + c4 + c5);
    }
    if(((c + c2 + c3 + c4 + c5 + c6) > 0) && (c + c2 + c3 + c4 + c5 + c6) < count6){
        count6 = (c + c2 + c3 + c4 + c5 + c6);
    }
    if(((c + c2 + c3 + c4 + c5 + c6+ c7) > 0) && (c + c2 + c3 + c4 + c5 + c6 + c7) < count7){
        count7 = (c + c2 + c3 + c4 + c5 + c6 + c7);
    }

    if(((c + c2 + c3 + c4 + c5 + c6+ c7 + c8) > 0) && (c + c2 + c3 + c4 + c5 + c6 + c7 + c8) < count8){
        count8 = (c + c2 + c3 + c4 + c5 + c6 + c7 + c8);
    }
    


    if(c == 1){
        cout << "1Round = 1ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2) == 8){
        cout << "2Round = 8ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3) == 13){
        cout << "3Round = 13ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3 + c4) == 26){
        cout << "4Round = 26ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3 + c4 + c5) == 37){
        cout << "5Round = 37ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3 + c4 + c5 + c6) == 48){
        cout << "6Round = 48ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3 + c4 + c5 + c6 + c7) == 56){
        cout << "7Round = 56ASbox: ";
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    if((c + c2 + c3 + c4 + c5 + c6 + c7 + c8) == 64){
        cout << "8Round = " << (c + c2 + c3 + c4 + c5 + c6 + c7 + c8) << "ASbox: ";  
        for(int i = 0; i < 32; i++){
            if(i == 31){
                cout << x[i] << endl;
            }
            else{
                cout << x[i] << ", ";
            }
        }
    }
    

    }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


     cout << "count = " << count << endl;
     cout << "count2 = " << count2 << endl;
     cout << "count3 = " << count3 << endl;
     cout << "count4 = " << count4 << endl;
     cout << "count5 = " << count5 << endl;
     cout << "count6 = " << count6 << endl;
     cout << "count7 = " << count7 << endl;
     cout << "count8 = " << count8 << endl;
     
     
     return 0; 
}
    
