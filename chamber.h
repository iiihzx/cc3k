#ifndef CHAMBER_H_
#define CHAMBER_H_
#include<vector>
#include<string>


class Chamber{
    int RoomNum;
    std::vector<int> leftCorner;
    int RowNum;
    int ColNum;
    std::vector<std::vector<char> >& textdisplay;
  public:
    int getRow() const;
    int getCol() const;
    std::vector<int> getLeftCor() const;
    Chamber(int RoomNum,std::vector<std::vector<char> >& textdisplay);
    ~Chamber();
    int ValidTile(std::vector<int> pos);
    std::vector<int> RandomPos(char display,std::vector<int> pos);
};


#endif

