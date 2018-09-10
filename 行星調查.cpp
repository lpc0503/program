#include<iostream>
#include<cstring>
 
using namespace std;
 
//jungle = 0 ocean = 1 ICE = 2
 
int main(void){
 
    #ifdef DEBUG
    freopen("1.in","r", stdin);
    freopen("2.out", "w", stdout);
    #endif
 
    int lenght, width;//M&N
    int survery_number;
 
    scanf("%d %d", &lenght, &width);
    scanf("%d", &survery_number);
    int ICE[lenght+1][width+1], jungle[lenght+1][width+1], ocean[lenght+1][width+1];
    int A, B, C, D;
    char tmp;
    int tmp_j = 0, tmp_o = 0, tmp_i = 0;
     
    memset(ICE,0,sizeof(ICE));
    memset(jungle,0,sizeof(jungle));
    memset(ocean,0,sizeof(ocean));
 
    for(int i = 1 ; i <= lenght ; i++){
 
        tmp_j = 0;
        tmp_i = 0;
        tmp_o = 0;
        for(int j = 1 ; j <= width ; j++){
 
            cin >> tmp;
            if(tmp == 'J'){
 
                tmp_j++;
            }
            else if(tmp == 'O'){
 
                tmp_o++;
            }
            else{
 
                tmp_i++;
            }
        jungle[i][j] = jungle[i][j] + tmp_j + jungle[i-1][j];
        ocean[i][j] = ocean[i][j] + tmp_o + ocean[i-1][j];
        ICE[i][j] = ICE[i][j] + tmp_i + ICE[i-1][j];
        }
    }
 
    while(survery_number--){
 
        int ans_J = 0, ans_O = 0, ans_I = 0;
        scanf("%d %d %d %d", &A, &B, &C, &D);
 
        ans_J = jungle[C][D] - jungle[C][B-1] - jungle[A-1][D] + jungle[A-1][B-1];
        ans_O = ocean[C][D] - ocean[C][B-1] - ocean[A-1][D] + ocean[A-1][B-1];
        ans_I = ICE[C][D] - ICE[C][B-1] - ICE[A-1][D] + ICE[A-1][B-1];
        printf("%d %d %d\n", ans_J, ans_O, ans_I);
    }
}