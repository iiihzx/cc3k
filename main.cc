#include "floor.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <curses.h>
using namespace std;

int main(int argc, char *argv[]) {
    Floor f;
    bool dlc = false;
    if (argc == 2) {
        string fname = argv[1];
        if (fname == "dlc") {
            dlc = true;
            f.setdlc();
        }
    }

    if (dlc == false) {
        while (true) {

            ifstream ss("welcome.txt");
            string temp;

            while (getline(ss, temp)) {
                cout << temp << endl;
            }

            string name;

            while (cin >> name) {
                if (name != "h" && name != "d" && name != "e" && name != "o" && name != "q") {
                    cout << "Invalid input! Please try again :)" << endl;
                } else if (name == "q") {
                    ifstream ssss("bye.txt");
                    while (getline(ssss, temp)) {
                        cout << temp << endl;
                    }
                    return 0;
                } else {
                    break;
                }
            }

            if (argc == 1) {
                f.setmapdefault(true);
                f.setFloor(name, "map.txt");
            } else {
                string fname = argv[1];
                f.setmapdefault(false);
                f.setFloor(name, fname);
            }

            string start_info = "Please enter a valid command:\n    Change directions: no, so, we, ea, ne, se, sw, nw\n    Use Potion: u <direction>\n    Attack enemy: a <direction>\n    Reset the game : r\n    Quit: q\n";
            f.prettyprint(start_info);

            while (true) {
                string info;
                string dir;
                cin >> dir;
                try {
                    if (dir == "q") {
                        ifstream ssss("bye.txt");

                        while (getline(ssss, temp)) {
                            cout << temp << endl;
                        }

                        return 0;

                    } else if (dir == "r") {
                        f.cleanFloor();
                        break;
                    } else if (dir == "a") {
                        if (cin >> dir) {
                            if (dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                                info += f.attack(dir);
                            } else {
                                info += "Invalid direction! Please try again :)";
                            }
                        } else {
                            info += "No direction entered! Please try again :)";
                        }
                    } else if (dir == "u") {
                        if (cin >> dir) {
                            if (dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                                info += f.use(dir);
                            } else {
                                info += "No direction entered! Please try again :)\n";
                            }
                        } else {
                            info += "No direction entered! Please try again :)\n";
                        }
                    } else if (dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                        info += f.move(dir);
                    } else {
                        info += "No direction entered! Please try again :)\n";
                    }
                }
                catch (string n) {
                    if (n != "win") {
                        f.prettyprint(n);
                        ifstream sss("dead.txt");
                        int linenum = 0;
                        while (getline(sss, temp)) {
                            linenum++;
                            if (linenum == 34) {
                                cout <<  "|                    GOOD GAME! YOUR FINAL SCORE IS " << setfill(' ') << setw(3) << f.score() << " !                      |" << endl;
                            } else {
                                cout <<  temp <<  endl;
                            }
                        }
                    } else {
                        int lnum = 0;
                        ifstream sssss("win.txt");
                        string temp;
                        while (getline(sssss, temp)) {
                            lnum++;
                            if (lnum == 13) {
                                cout << "|                        YOUR FINAL SCORE IS " << setfill(' ') << setw(3) << f.score() << " !!!                          |" << endl;
                            } else {
                                cout << temp << endl;
                            }
                        }
                    }
                    while (true) {
                        cin >> temp;
                        if (temp == "r") {
                            f.cleanFloor();
                            break;
                        } else if (temp == "q") {
                            ifstream ssss("bye.txt");
                            while (getline(ssss, temp)) {
                                cout << temp << endl;
                            }
                            return 0;
                        } else {
                            cout << "Invalid action! Please try again :)" << endl;
                            //throw n;
                            continue;
                        }
                    }
                    if (temp == "r") {
                        break;
                    }
                }
                f.prettyprint(info);
            }
        } 
    } else {
        while (true) {

            ifstream ss("welcomebonus.txt");
            string temp;

            while (getline(ss, temp)) {
                cout << temp << endl;
            }

            string name;

            while (cin >> name) {
                if (name != "h" && name != "d" && name != "e" && name != "o" && name != "s" && name != "q") {
                    cout << "Invalid input! Please try again :)" << endl;
                } else if (name == "q") {
                    ifstream ssss("bye.txt");
                    while (getline(ssss, temp)) {
                        cout << temp << endl;
                    }
                    return 0;
                } else {
                    break;
                }
            }


            f.setmapdefault(true);
            f.setFloor(name, "map.txt");


            string start_info = "Please enter a valid command:\n    Change directions: e(no), d(so), f(ea), s(we), ne, se, sw, nw\n    Use Potion: u <direction>\n    Attack enemy: a <direction>\n    Reset the game : r\n    Quit: q\n";

            f.prettyprint(start_info);

            while (true) {

                string info;
                string tempdir;
                string dir;
                cin >> tempdir;
                try {
                    if (tempdir == "q") {
                        ifstream ssss("bye.txt");

                        while (getline(ssss, temp)) {
                            cout << temp << endl;
                        }

                        return 0;

                    } else if (tempdir == "r") {
                        f.cleanFloor();
                        break;
                    } else if (tempdir == "b") {
                        info += f.sp();
                    } else if (tempdir == "a") {
                        if (cin >> tempdir) {
                            if(tempdir=="e") dir="no";
                            if(tempdir=="s") dir="we";
                            if(tempdir=="d") dir="so";
                            if(tempdir=="f") dir="ea";
                            if(tempdir=="ne") dir="ne";
                            if(tempdir=="nw") dir="nw";
                            if(tempdir=="sw") dir="sw";
                            if(tempdir=="se") dir="se";
                            if (dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                                info += f.attack(dir);
                            } else {
                               info += "No direction entered! Please try again :)";
                            }
                        } else {
                            info += "No direction entered! Please try again :)";
                        }
                    } else if (tempdir == "u") {
                        if (cin >> tempdir) {
                            if(tempdir=="e") dir="no";
                            if(tempdir=="s") dir="we";
                            if(tempdir=="d") dir="so";
                            if(tempdir=="f") dir="ea";
                            if(tempdir=="ne") dir="ne";
                            if(tempdir=="nw") dir="nw";
                            if(tempdir=="sw") dir="sw";
                            if(tempdir=="se") dir="se";
                            if (dir == "no" || dir == "so" || dir == "ea"|| dir=="we" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                                info += f.use(dir);
                            } else {
                                info += "No direction entered! Please try again :)\n";
                            }
                        } else {
                            info += "No direction entered! Please try again :)\n";
                        }
                    } else if (tempdir == "e" || tempdir == "d" || tempdir == "s" ||tempdir=="f"|| tempdir == "ne" || tempdir == "nw" || tempdir == "se" || tempdir == "sw") {
                            if(tempdir=="e") dir="no";
                            if(tempdir=="s") dir="we";
                            if(tempdir=="d") dir="so";
                            if(tempdir=="f") dir="ea";
                            if(tempdir=="ne") dir="ne";
                            if(tempdir=="nw") dir="nw";
                            if(tempdir=="sw") dir="sw";
                            if(tempdir=="se") dir="se";
                        info += f.move(dir);
                    } else {
                        info += "No direction entered! Please try again :)\n";
                    }
                }
                catch (string n) {
                    if (n != "win") {
                        f.prettyprint(n);
                        ifstream sss("dead.txt");
                        int linenum = 0;
                        while (getline(sss, temp)) {
                            linenum++;
                            if (linenum == 34) {
                                cout <<  "|                    GOOD GAME! YOUR FINAL SCORE IS " << setfill(' ') << setw(3) << f.score() << " !                     |" << endl;
                            } else {
                                cout <<  temp <<  endl;
                            }
                        }
                    } else {
                        int lnum = 0;
                        ifstream sssss("win.txt");
                        string temp;
                        while (getline(sssss, temp)) {
                            lnum++;
                            if (lnum == 13) {
                                cout << "|                        YOUR FINAL SCORE IS " << setfill(' ') << setw(3) << f.score() << " !!!                          |" << endl;
                            } else {
                                cout << temp << endl;
                            }
                        }
                    }
                    while(true) {
                        cin >> temp;
                        if (temp == "r") {
                            f.cleanFloor();
                            break;
                        } else if (temp == "q") {
                            ifstream ssss("bye.txt");
                            while (getline(ssss, temp)) {
                                cout << temp << endl;
                            }
                            return 0;
                        } else {
                            cout << "Invalid action! Please try again :)" << endl;
                            //throw n;
                            continue;
                        }
                    }
                    if (temp == "r") {
                        break;
                    }
                }
                f.prettyprint(info);
            }
        }
    }
}

