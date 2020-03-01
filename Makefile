CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k+
OBJECTS = main.o student.o as.o quiz.o test.o midterm.o final.o weapon.o shield.o ba.o bd.o chamber.o character.o dragon.o dwarf.o elves.o enemy.o floor.o goblin.o gold.o human.o item.o merchant.o orc.o pc.o ph.o phoenix.o potion.o rh.o troll.o vampire.o wa.o wd.o werewolf.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lcurses

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}

