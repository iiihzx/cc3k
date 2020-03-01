#include <vector>
#include <string>
#include <memory>
#include "chamber.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int Chamber::getRow() const{
    return RowNum;
}

int Chamber::getCol() const{
    return ColNum;
}

vector<int>  Chamber::getLeftCor() const{
    return leftCorner;
}

Chamber::Chamber(int RoomNum,std::vector<std::vector<char> >& textdisplay):RoomNum{RoomNum},textdisplay{textdisplay}{
    if(RoomNum==0){//the topleft chamber
    leftCorner={3,3};
      RowNum=4;
      ColNum=26;
    } else if (RoomNum==1){//the topright chamber(abnormal)
     leftCorner ={3,39};
        RowNum=10;
        ColNum=37;
    } else if (RoomNum==2){//the middle chamber
    leftCorner={10,38};
        RowNum=3;
        ColNum=12;
    } else if (RoomNum==3){//the bottom left chamber
        leftCorner = {15,4};
            RowNum=7;
            ColNum=21;
    } else if (RoomNum==4){//the bottom right chamber(fake leftCorner)
        leftCorner ={16,37};
            RowNum=6;
            ColNum=39;
    }
}

Chamber::~Chamber(){}

int Chamber::ValidTile(vector<int> pos){
    int row=pos.front();
    int col=pos.back();
    int myr=leftCorner.front();
    int myc=leftCorner.back();
    char now=textdisplay[row][col];
    if(now=='.'||now=='@'){
        if(RoomNum!=1){
            if(row<=myr+RowNum && row>=myr && col<=myc+ColNum && col>=myc){
                if(now=='.'){
                    return 1;
                } else if(now=='@'){
                    return 2;
                }else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (RoomNum==1){
                if ((row<=myr+3 && row>=myr && col<=myc+ColNum && col>=myc)||
                    (col>=61 && col<=myc+ColNum && row<=myr+RowNum && row>myr+3)){
                    if(now=='.'){
                    return 1;
                    } else if(now=='@'){
                        return 2;
                    } else {
                    return 0;
                    }
                } else {
                    return 0;
            }
        }
    }
    return 0;
}

vector<int> Chamber::RandomPos(char display,vector<int> pos){
    srand(time(NULL));
    int srow=pos.front();
    int scol=pos.back();
    vector<int> temp;
    int mrow=leftCorner.front();
    int mcol=leftCorner.back();
    int nrow=0;//nrow&ncol will be stored the coordinate for the randompos
    int ncol=0;
    while(1){
        nrow=rand()%RowNum+mrow;
        ncol=rand()%ColNum+mcol;
        temp.emplace_back(nrow);
        temp.emplace_back(ncol);
        if(ValidTile(temp) && textdisplay[nrow][ncol]=='.' && (srow!=nrow || scol!=ncol)){
            textdisplay[nrow][ncol]=display;
            return temp;
        }
        temp.clear();
    }
}

