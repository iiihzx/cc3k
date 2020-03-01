#include "floor.h"
using namespace std;

void Floor::setlevel(){
    level += 1;
    resetFloor();
}

void Floor::setmapdefault(bool ismapdefault) {
    mapdefault = ismapdefault;
}

void Floor::genstair(){
    srand(time(NULL));
    vector<int> temp {0,0};
    sroom = rand() % 5;
    stairpos = allchamber[sroom]->RandomPos('.',temp);
}

void Floor::genChamber(){
    for (int i = 0; i < 5; ++i) {
        auto newChamber = make_shared<Chamber> (i, textdisplay);  
        allchamber.emplace_back(newChamber);
    }
}


void Floor::genPC(string name) {
    srand(time(NULL));
    int proom = 0;
    while(1){
        proom = rand() % 5;
        if(proom != sroom){
            break;
        }  
    }
    vector<int> pos = allchamber[proom]->RandomPos('@',stairpos);
    if (name=="h"){
        user = make_shared<Human> (pos);
    } else if (name=="d"){
        user = make_shared<Dwarf> (pos);
    } else if (name=="e"){
        user = make_shared<Elves> (pos);
    } else if (name=="o"){
        user =make_shared<Orc> (pos);
    }
    if (name == "s" && DLC == true) {
        user = make_shared<Student> (pos);
    }
}

void Floor::genEnemy() {
    srand(time(NULL));
    int proom = 0;
    int com_e = rand() % 16;
    for(int i = 0; i < 18; i++){
        if(i < 4){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('W',stairpos);
            auto newenemy=make_shared<Werewolf> (pos);
            allenemy.emplace_back(newenemy);
        } else if(i>=4 && i<7){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('V',stairpos);
            auto newenemy=make_shared<Vampire> (pos);
            allenemy.emplace_back(newenemy);
        } else if(i>=7 && i<12){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('N',stairpos);
            auto newenemy=make_shared<Goblin> (pos);
            allenemy.emplace_back(newenemy);
        } else if(i>=12 && i<14){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('T',stairpos);
            auto newenemy=make_shared<Troll> (pos);
            allenemy.emplace_back(newenemy);
        } else if(i>=14 && i<16){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('X',stairpos);
            auto newenemy=make_shared<Phoenix> (pos);
            allenemy.emplace_back(newenemy);
        } else if(i>=16 && i<18){
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('M',stairpos);
            auto newenemy=make_shared<Merchant> (pos);
            allenemy.emplace_back(newenemy);
        }
        if(i==com_e && !DLC){
            allenemy.back()->setcompass();
        }
    }
    if (DLC) {
        if (level == 1) {
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('a',stairpos);
            auto newenemy=make_shared<AS> (pos);
            allenemy.emplace_back(newenemy);
        }
        if (level == 2) {
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('q',stairpos);
            auto newenemy=make_shared<QUIZ> (pos);
            allenemy.emplace_back(newenemy);
        }
        if (level == 3) {
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('t',stairpos);
            auto newenemy=make_shared<TEST> (pos);
            allenemy.emplace_back(newenemy);
        }
        if (level == 4) {
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('m',stairpos);
            auto newenemy=make_shared<MIDTERM> (pos);
            allenemy.emplace_back(newenemy);
        }
        if (level == 5) {
            proom=rand()%5;
            vector<int> pos=allchamber[proom]->RandomPos('f',stairpos);
            auto newenemy=make_shared<FINAL> (pos);
            allenemy.emplace_back(newenemy);
        }
    }
}

void Floor::genGold() {
    srand(time(NULL));
    int groom=0;
    if (DLC) {
        groom=rand()%5;
        vector<int> pos=allchamber[groom]->RandomPos('R',stairpos);
        auto newgold= make_shared<Gold> (pos,"Review",'R',1,5);
        allgold.emplace_back(newgold);
    }
    for (int i=0; i<10;i++){
        if(i>=8){
            groom=rand()%5;
            vector<int> pos{-1,-1};
            auto newgold= make_shared<Gold> (pos,"Merchant Hoard",'G',1,4);
            allgold.emplace_back(newgold);
        } else if(i>=1 && i<6){
            groom=rand()%5;
            vector<int> pos=allchamber[groom]->RandomPos('G',stairpos);
            auto newgold=make_shared<Gold> (pos, "NormalGold", 'G', 1, 1);
            allgold.emplace_back(newgold);
        } else if(i>=6 && i<8){
            groom=rand()%5;
            vector<int> pos=allchamber[groom]->RandomPos('G',stairpos);
            auto newgold=make_shared<Gold> (pos, "SmallGold", 'G', 1, 2);
            allgold.emplace_back(newgold);
        } else if(i==0){
            int m=0;
            if(level==bslevel){
                m=2;
            } else{
                m=1;
            }
            for(int j=0;j<m;j++){
                vector<int> pos;
                if(j==0){
                groom=rand()%5;
                pos=allchamber[groom]->RandomPos('G',stairpos);
                auto newgold=make_shared<Gold> (pos, "Dhorde", 'G', 0, 6);
                allgold.emplace_back(newgold);
                int grow=pos.front();
                int gcol=pos.back();
                int srow=stairpos.front();
                int scol=stairpos.back();
                vector<int> dpos;
                if(textdisplay[grow-1][gcol]=='.' && (grow-1!=srow || gcol!=scol)){
                    dpos={grow-1,gcol};
                } else if(textdisplay[grow][gcol+1]=='.' && (grow!=srow || gcol+1!=scol)){
                    dpos={grow,gcol+1};
                }  else if(textdisplay[grow+1][gcol]=='.' && (grow+1!=srow || gcol!=scol)){
                    dpos={grow+1,gcol};
                }   else if(textdisplay[grow][gcol-1]=='.' && (grow!=srow || gcol-1!=scol)){
                    dpos={grow,gcol-1};
                }
                auto newdragon=make_shared<Dragon> (dpos,newgold);
                textdisplay[dpos.front()][dpos.back()]='D';
                allenemy.emplace_back(newdragon);
                } else{ 
                    groom=rand()%5;
                    pos=allchamber[groom]->RandomPos('B',stairpos);
                    auto newgold=make_shared<Gold>(pos,"BS",'B', 0,0);
                    allgold.emplace_back(newgold);
                    int grow=pos.front();
                    int gcol=pos.back();
                    int srow=stairpos.front();
                    int scol=stairpos.back();
                    vector<int> dpos;
                    if(textdisplay[grow-1][gcol]=='.' && (grow-1!=srow || gcol!=scol)){
                        dpos={grow-1,gcol};
                    } else if(textdisplay[grow][gcol+1]=='.' && (grow!=srow || gcol+1!=scol)){
                        dpos={grow,gcol+1};
                    }  else if(textdisplay[grow+1][gcol]=='.' && (grow+1!=srow || gcol!=scol)){
                        dpos={grow+1,gcol};
                    }   else if(textdisplay[grow][gcol-1]=='.' && (grow!=srow || gcol-1!=scol)){
                        dpos={grow,gcol-1};
                    }
                    auto newdragon=make_shared<Dragon> (dpos,newgold);
                    textdisplay[dpos.front()][dpos.back()]='D';
                    allenemy.emplace_back(newdragon);
                }
            }
        }
    }
}

void Floor::genPotion() { // 0 - RH, 1 - BA, 2 - BD, 3 - PH, 4 - WA, 5 - WD
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int num_room = rand() % 5;
        int which_potion = rand() % 6;
        vector<int> potion_pos = allchamber[num_room]->RandomPos('P',stairpos);
        if (which_potion == 0) {
            auto newpotion = make_shared<RH> (potion_pos);
            allpotion.emplace_back(newpotion);
        } else if (which_potion == 1) {
            auto newpotion = make_shared<BA> (potion_pos);
            allpotion.emplace_back(newpotion);
        } else if (which_potion == 2) {
            auto newpotion = make_shared<BD> (potion_pos);
            allpotion.emplace_back(newpotion);
        } else if (which_potion == 3) {
            auto newpotion = make_shared<PH> (potion_pos);
            allpotion.emplace_back(newpotion);
        } else if (which_potion == 4) {
            auto newpotion = make_shared<WA> (potion_pos);
            allpotion.emplace_back(newpotion);
        } else {
            auto newpotion = make_shared<WD> (potion_pos);
            allpotion.emplace_back(newpotion);
        }
    }
    if (DLC == true) {
        int wp_room = rand() % 5;
        vector<int> wp_pos = allchamber[wp_room]->RandomPos('%',stairpos);
        auto newwp = make_shared<WP> (wp_pos);
        allpotion.emplace_back(newwp);
        int sh_room = rand() % 5;
        vector<int> sh_pos = allchamber[sh_room]->RandomPos('&',stairpos);
        auto newsh = make_shared<SH> (sh_pos);
        allpotion.emplace_back(newsh);
    }
}

void Floor::prettyprint(string s) {
    for (size_t i = 0; i < textdisplay.size(); i++)  {
        for (size_t j = 0; j < textdisplay[i].size(); j++) {
            if(textdisplay[i][j]=='G'|| textdisplay[i][j]=='R'){
            cout<< "\033[1m\033[33m"<<textdisplay[i][j]<<"\033[0m";
            } else if(textdisplay[i][j]=='V'||textdisplay[i][j]=='D'||
                textdisplay[i][j]=='T'||textdisplay[i][j]=='X'||textdisplay[i][j]=='N'||
                textdisplay[i][j]=='M'||textdisplay[i][j]=='W') {
                cout<<"\033[1m\033[31m"<<textdisplay[i][j]<<"\033[0m";
            } else if(textdisplay[i][j]=='|'||textdisplay[i][j]=='+'||textdisplay[i][j]=='-'){
                cout<<"\033[1m\033[37m"<<textdisplay[i][j]<<"\033[0m";
            } else if(textdisplay[i][j]=='P'){
                cout<<"\033[32m"<<textdisplay[i][j]<<"\033[0m";
            } else if (textdisplay[i][j]=='C'){
                cout<<"\033[1m\033[34m"<<textdisplay[i][j]<<"\033[0m";
            } else if (textdisplay[i][j]=='B'){
                cout<<"\033[1m\033[96m" << textdisplay[i][j] << "\033[0m";
            } else if (textdisplay[i][j]=='@'){
                cout<<"\033[1m\033[95m" << textdisplay[i][j] << "\033[0m";  
            } else if (textdisplay[i][j]=='\\'){
                cout<<"\033[1m\033[37m" << textdisplay[i][j] << "\033[0m" ;
            } else if (textdisplay[i][j]=='%'){
                cout<<"\033[1m\033[96m" << textdisplay[i][j] << "\033[0m" ;
            } else if (textdisplay[i][j]=='&'){
                cout<<"\033[1m\033[96m" << textdisplay[i][j] << "\033[0m" ;
            } else if (textdisplay[i][j]=='a'||textdisplay[i][j]=='t'||textdisplay[i][j]=='q'||
            textdisplay[i][j]=='m'||textdisplay[i][j]=='f') {
                cout<<"\033[1m\033[96m" << textdisplay[i][j] << "\033[0m" ;
            } else {
                cout<<"\033[37m" << textdisplay[i][j] << "\033[0m";
            }
        }
        cout << endl;
    }
    cout << "\033[95m" << "Race: " << user->getname() << "          Gold: " << user->getGold();
    for (int i = 0; i < 40; ++i) {
        cout << " ";
    }
    cout << "Floor " << level << endl;
    cout << "HP: " << user->getHP() << endl;
    cout << "Atk: " << user->getAtk() << endl;
    cout << "Def: " << user->getDef() << endl;
    cout << "Action: " << "\033[0m" << endl;
    cout << s;
}



string Floor::move(string direction){
    string s;
    vector<int> next_pos = user->nextpos(direction);
    if (next_pos.front() == stairpos.front() && next_pos.back() == stairpos.back()) {
        if (level == 5) {
            win();
        } else {
            setlevel();
            ostringstream s_level;
           s_level << "\033[31m" << level << "\033[0m";
            s += "HEY! YOU ARE ON THE FLOOR " + s_level.str() +  "!\n";
        }
    } else {
        if (textdisplay[next_pos.front()][next_pos.back()] == 'C') {
            textdisplay[next_pos.front()][next_pos.back()] = '.';
            textdisplay[stairpos.front()][stairpos.back()] = '\\';
        } else if (textdisplay[next_pos.front()][next_pos.back()] == 'B') {
            for (size_t i = 0; i < allgold.size(); ++ i) {
                if (allgold[i]->getitempos().front() == next_pos.front() && allgold[i]->getitempos().back() == next_pos.back()) {
                    if (allgold[i]->getpickable() == true) {
                        textdisplay[next_pos.front()][next_pos.back()] = '.';
                        user->setBS();
                        allgold[i]->setitempos(-1, -1);
                        s += "\033[31mWOW! GOT BARRIER SUIT! DAMAGE TO YOU WILL BE HALF!\033[0m\n";
                    } else {
                        s += "Unpickable!\n";
                    }
                }
            }
        }
        s += user->move(direction, textdisplay, allgold, DLC);
        int row = next_pos.front();
        int col = next_pos.back();
        int num_po = 0;
        if (textdisplay[row-1][col]=='P') ++num_po;
        if (textdisplay[row-1][col+1]=='P') ++ num_po;
        if (textdisplay[row][col+1]=='P') ++ num_po;
        if (textdisplay[row+1][col+1]=='P') ++ num_po;
        if (textdisplay[row+1][col]=='P') ++ num_po;
        if (textdisplay[row+1][col-1]=='P') ++ num_po;
        if (textdisplay[row][col-1]=='P') ++ num_po;
        if (textdisplay[row-1][col-1]=='P') ++ num_po;
        if (num_po > 0) {
            ostringstream temp;
            temp << num_po;
            s += "Found " + temp.str() + " unknown potion(s)!\n";
        }
        for (size_t j = 0; j < allenemy.size(); ++j) {
            s += allenemy[j]->move(textdisplay, stairpos, user,DLC);
        }
        if (DLC) {
            int num_M=0;
            if (textdisplay[row-1][col]=='M') ++num_M;
            if (textdisplay[row-1][col+1]=='M') ++ num_M;
            if (textdisplay[row][col+1]=='M') ++ num_M;
            if (textdisplay[row+1][col+1]=='M') ++ num_M;
            if (textdisplay[row+1][col]=='M') ++ num_M;
            if (textdisplay[row+1][col-1]=='M') ++ num_M;
            if (textdisplay[row][col-1]=='M') ++ num_M;
            if (textdisplay[row-1][col-1]=='M') ++ num_M;
            if(num_M>0 && user->getAttM() == false){
                s+="See a Merchant! Do you want to buy superpotion to boost your ability?\n";
                s+="Enter b to buy superpotion, which will cost you 5 gold.\n";
            }
        }
        if(user->getdead() == true) throw s;
    }
    return s;
}

void Floor::setFloor(string name, string mapfile) {
    level = 1;
    if (mapdefault == true) {
        srand(time(NULL));
        bslevel = rand() % 5 + 1;
        readFloor(name, mapfile);
        genstair();
        genPC(name);
        genEnemy();
        genGold();
        genPotion();
    } else {
        readFloor(name, mapfile);
    }
}

void Floor::resetFloor(){
    srand(time(NULL));
    cleanFloor();
    if (mapdefault == true) {
        readFloor("@", mapfilename);
        genstair();
        genEnemy();
        genGold();
        genPotion();
        int proom = 0;
        while (true) {
            srand(time(NULL));
            proom = rand() % 5;
            if (proom != sroom) {
                break;
            }
        }
        vector<int> pos = allchamber[proom]->RandomPos('@',stairpos);
        user->setPos(pos.front(), pos.back());
        string name = user->getname();
        if (name == "Human") {
            user->setAtk(20);
            user->setDef(20);
        } else if (name == "Dwarf") {
            user->setAtk(20);
            user->setDef(30);
        } else if (name == "Elves") {
            user->setAtk(30);
            user->setDef(10);
        } else {
            user->setAtk(30);
            user->setDef(25);
        }
    } else {
        readFloor("@", mapfilename);
    }
}

void Floor::cleanFloor(){
    stairpos.clear();
    for (size_t i = 0; i < textdisplay.size(); ++i) {
        textdisplay[i].clear();
    }
    textdisplay.clear();
    allenemy.clear();
    allchamber.clear();
    allpotion.clear();
    allgold.clear();
}

string Floor::use(string direction){
    string s = user->usepotion(direction, textdisplay, allpotion, DLC);
    for (size_t i = 0; i < allenemy.size(); ++i) {
        s += allenemy[i]->move(textdisplay, stairpos, user,DLC);
        if (DLC) {
            int num_M=0;
            int row = user->getPos().front();
            int col = user->getPos().back();
            if (textdisplay[row-1][col]=='M') ++num_M;
            if (textdisplay[row-1][col+1]=='M') ++ num_M;
            if (textdisplay[row][col+1]=='M') ++ num_M;
            if (textdisplay[row+1][col+1]=='M') ++ num_M;
            if (textdisplay[row+1][col]=='M') ++ num_M;
            if (textdisplay[row+1][col-1]=='M') ++ num_M;
            if (textdisplay[row][col-1]=='M') ++ num_M;
            if (textdisplay[row-1][col-1]=='M') ++ num_M;
            if(num_M>0 && user->getAttM() == false){
                s+="See a Merchant! Do you want to buy superpotion to boost your ability?\n";
                s+="Enter b to buy superpotion, which will cost you 5 gold.\n";
            }
        }
        if (user->getdead() == true) throw s;
    }
    return s;
}

string Floor::attack(string direction){
    string s;
    int nexty = user->nextpos(direction).front();
    int nextx = user->nextpos(direction).back();
    bool noenemy = true;
    for (size_t i = 0; i < allenemy.size(); i++) {
        int ey = allenemy[i]->getPos().front();
        int ex = allenemy[i]->getPos().back();
        if (nexty == ey && nextx == ex) {
            s += user->attack(allenemy[i],DLC);
            noenemy = false;
            if (allenemy[i]->getdead()) {
                if (allenemy[i]->getname() != "Merchant") {
                    textdisplay[ey][ex] = '.';
                    s += user->addgold(allenemy[i]->getGold());
                } else {                    
                    textdisplay[ey][ex] = 'G';
                    for (size_t j = 0; j < allgold.size(); j++) {
                        if (allgold[j]->getitemname() == "Merchant Hoard" && allgold[j]->getitempos().front() == -1) {
                            allgold[j]->setitempos(ey, ex);
                            break;
                        }
                    }
                }
                if(allenemy[i]->getcompass()==1){
                    textdisplay[ey][ex]='C';
                }
                allenemy.erase(allenemy.begin() + i);
            } else {
                s += allenemy[i]->attack(user,DLC);
            }
            break;
        } else {
            s += allenemy[i]->move(textdisplay, stairpos, user,DLC);
        }
    }
    if (noenemy) {
        s += "Invalid action! Please try again :)\n";
    }
    if (DLC) {
        int num_M=0;
        int row = user->getPos().front();
        int col = user->getPos().back();
        if (textdisplay[row-1][col]=='M') ++num_M;
        if (textdisplay[row-1][col+1]=='M') ++ num_M;
        if (textdisplay[row][col+1]=='M') ++ num_M;
        if (textdisplay[row+1][col+1]=='M') ++ num_M;
        if (textdisplay[row+1][col]=='M') ++ num_M;
        if (textdisplay[row+1][col-1]=='M') ++ num_M;
        if (textdisplay[row][col-1]=='M') ++ num_M;
        if (textdisplay[row-1][col-1]=='M') ++ num_M;
        if(num_M>0 && user->getAttM() == false){
            s+="See a Merchant! Do you want to buy superpotion to boost your ability?\n";
            s+="Enter b to buy superpotion, which will cost you 5 gold.\n";
        }
    }
    if(user->getdead() == true) throw s;
    return s;
}

void Floor::readFloor(string name, string mapfile) {
    mapfilename = mapfile;
    ifstream file{mapfilename};
    genChamber();
    char c;
    vector<int> fakepos{-1,-1};
    auto fakegold = make_shared<Gold> (fakepos, "NormalGold", 'G', 1, 1);
    vector< shared_ptr<Dragon> > alldragon;

    if (mapdefault == false && level != 1) {
        for (int i = 0; i < (level - 1) * 25; ++i) {
            string s;
            getline(file, s);
        }
    }

    for (int row = 0; row < 25; ++row) {
        vector<char> rowdisplay;
        file.get(c);
        for (int col = 0; c != '\n'; file.get(c), ++col) {
            vector<int> pos {row, col};

            if (c == '0') {
                auto newpotion = make_shared<RH> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '1') {
                auto newpotion = make_shared<BA> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '2') {
                auto newpotion = make_shared<BD> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '3') {
                auto newpotion = make_shared<PH> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '4') {
                auto newpotion = make_shared<WA> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '5') {
                auto newpotion = make_shared<WD> (pos);
                allpotion.emplace_back(newpotion);
                rowdisplay.emplace_back('P');
            } else if (c == '6') {
                auto newgold=make_shared<Gold> (pos, "NormalGold", 'G', 1, 1);
                allgold.emplace_back(newgold);
                rowdisplay.emplace_back('G');
            } else if (c == '7') {
                auto newgold=make_shared<Gold> (pos, "SmallGold", 'G', 1, 2);
                allgold.emplace_back(newgold);
                 rowdisplay.emplace_back('G');
            } else if (c == '8') {
                vector<int> pos_gold {-1, -1};
                auto newenemy=make_shared<Merchant> (pos);
                auto newgold = make_shared<Gold> (pos_gold, "Merchant Hoard", 'G', 1, 4);
                allenemy.emplace_back(newenemy);
                allgold.emplace_back(newgold);
                rowdisplay.emplace_back('M');
            } else if (c == '9') {
                auto newgold = make_shared<Gold> (pos, "Dhorde",'G', 0, 6);
                allgold.emplace_back(newgold);
                rowdisplay.emplace_back('G');
            } else if (c == '@') {
                if (level == 1) {
                    if (name == "h") {
                        user = make_shared<Human> (pos);
                    } else if (name == "d") {
                        user = make_shared<Dwarf> (pos);
                    } else if (name == "e") {
                        user = make_shared<Elves> (pos);
                    } else {
                        user = make_shared<Orc> (pos);
                    }
                } else {
                    if (user->getname() == "Human") {
                        user->setAtk(20);
                        user->setDef(20);
                    } else if (user->getname() == "Dwarf") {
                        user->setAtk(20);
                        user->setDef(30);
                    } else if (user->getname() == "Elves") {
                        user->setAtk(30);
                        user->setDef(10);
                    } else {
                        user->setAtk(30);
                        user->setDef(25);
                    }
                    user->setPos(pos.front(), pos.back());
                }
                rowdisplay.emplace_back(c);
            } else if (c == 'D') {
                auto newenemy=make_shared<Dragon> (pos, fakegold);
                allenemy.emplace_back(newenemy);
                alldragon.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'W') {
                auto newenemy=make_shared<Werewolf> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'V') {
                auto newenemy=make_shared<Vampire> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'N') {
                auto newenemy=make_shared<Goblin> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'M') {
                auto newenemy=make_shared<Merchant> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'X') {
                auto newenemy=make_shared<Phoenix> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'T') {
                auto newenemy=make_shared<Troll> (pos);
                allenemy.emplace_back(newenemy);
                rowdisplay.emplace_back(c);
            } else if (c == 'B') {
                auto newgold=make_shared<Gold> (pos, "BS", 'B', 0, -1);
                allgold.emplace_back(newgold);
                rowdisplay.emplace_back(c);
            } else if (c == '\\') {
                stairpos.emplace_back(pos.front());
                stairpos.emplace_back(pos.back());
                rowdisplay.emplace_back('.');
            } else {
                rowdisplay.emplace_back(c);
            }
        }
        textdisplay.emplace_back(rowdisplay);
    }


    if (mapdefault == false) {
            
        for(size_t i=0; i<alldragon.size();i++){

            vector<int> dpos=alldragon.at(i)->getPos();
            int row = dpos.front();
            int col = dpos.back();
            vector<vector<int>> gpos;
            vector<int> newgold;
            if(textdisplay[row-1][col]=='G'||textdisplay[row-1][col]=='B'){
                newgold={row-1,col};
                gpos.emplace_back(newgold);
            } else if(textdisplay[row-1][col+1]=='G'||textdisplay[row-1][col+1]=='B'){
                newgold={row-1,col+1};
                gpos.emplace_back(newgold);
            } else if (textdisplay[row][col+1]=='G'||textdisplay[row][col+1]=='B'){
                newgold={row,col+1};
                gpos.emplace_back(newgold);
            } else if (textdisplay[row+1][col+1]=='G'||textdisplay[row+1][col+1]=='B'){
                newgold={row+1,col+1};
                gpos.emplace_back(newgold);
            } else if (textdisplay[row+1][col]=='G'||textdisplay[row+1][col]=='B'){
                newgold={row+1,col};
                gpos.emplace_back(newgold);
            } else if (textdisplay[row+1][col-1]=='G'||textdisplay[row+1][col-1]=='B'){
                newgold={row+1,col-1};
                gpos.emplace_back(newgold); 
            } else if (textdisplay[row][col-1]=='G'||textdisplay[row][col-1]=='B'){
                newgold={row,col-1};
                gpos.emplace_back(newgold); 
            } else if (textdisplay[row-1][col-1]=='G'||textdisplay[row-1][col-1]=='B'){
                newgold={row-1,col-1};
                gpos.emplace_back(newgold);
            }

            for(size_t j=0; j<allgold.size(); j++){
                if(allgold.at(j)->getitemname()=="Dhorde"|| allgold.at(j)->getitemname()=="BS"){
                    vector<int> ng=allgold.at(j)->getitempos();
                    for(size_t k=0;k<gpos.size();k++){
                        vector<int> now_g;
                        now_g=gpos.at(k);
                        if(now_g==ng){
                            alldragon.at(i)->setgptr(allgold.at(j));
                        }
                    }   
                }
            }
        }
        srand(time(NULL));
        while (true) {
            int pos = rand() % allenemy.size();
            if (allenemy[pos]->getname() != "Merchant" && allenemy[pos]->getname() != "Dragon") {
                allenemy[pos]->setcompass();
                break;
            }
        }
    }
}

int Floor::score() {
    int finalscore = 0;
    string s = user->getname();
    if(s == "Human"){
      finalscore = 2 * user->getGold();
    } else{
      finalscore = user->getGold();   
    }
    return finalscore;
}


void Floor::win(){
    string s = "win";
    throw s;
}

void Floor::setdlc(){
    DLC=true;
}

string Floor::sp(){
    int row = user->getPos().front();
    int col = user->getPos().back();
    if (textdisplay[row-1][col]=='M' || textdisplay[row-1][col+1]=='M' || textdisplay[row][col+1]=='M' || textdisplay[row+1][col+1]=='M' ||
        textdisplay[row+1][col]=='M' || textdisplay[row+1][col-1]=='M' || textdisplay[row][col-1]=='M' || textdisplay[row-1][col-1]=='M')
        if (user->getAttM() == true) {
            return "You are the enemy of all the merchants. They do not want sell anything to you.\n";
    } else {
        return user->superpower();
    } else {
        return "Invalid action! No merchant nearby.\n";
    }
}

