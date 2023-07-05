CHAINPREFIX= /opt/miyoo
CROSS_COMPILE=$(CHAINPREFIX)/bin/arm-buildroot-linux-musleabi-
CC = $(CROSS_COMPILE)g++
CPPFLAG = -static -lstdc++ -lSDL -lasound -D SDL -D RGNANO
LIBS = 
INCDIR = 
LIBDIR = 
TARGET = KemonoRogue_anbernic

OBJS = main.o \
Cerulean.o \
Ending.o \
Enemy.o \
FloorMap.o \
Game.o \
GameData.o \
Global.o \
Item.o \
Kaban.o \
MainLoop.o \
Maze.o \
Object.o \
Player.o \
Popup.o \
Resource.o \
Resume.o \
Serval.o \
Sound.o \
Toki.o \
Tsuchinoko.o \
AdpcmDecorder.o \
Mathmatics.o \
Report.o \
SoundMixer.o \
SoundPlayer.o \
Controller.o \
Screen.o \
SoundStream.o \
TinyFile.o \
RingBuffer.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET)/$(TARGET) $^ $(CPPFLAG) $(LIBDIR) $(LIBS)

main.o: ../../src/TinyLibrary/SDL/main.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Cerulean.o: ../../src/Cerulean.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Ending.o: ../../src/Ending.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Enemy.o: ../../src/Enemy.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

FloorMap.o: ../../src/FloorMap.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Game.o: ../../src/Game.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

GameData.o: ../../src/GameData.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Global.o: ../../src/Global.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Item.o: ../../src/Item.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Kaban.o: ../../src/Kaban.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

MainLoop.o: ../../src/MainLoop.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Maze.o: ../../src/Maze.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Object.o: ../../src/Object.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Player.o: ../../src/Player.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Popup.o: ../../src/Popup.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Resource.o: ../../src/Resource.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Resume.o: ../../src/Resume.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Serval.o: ../../src/Serval.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Sound.o: ../../src/Sound.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Toki.o: ../../src/Toki.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Tsuchinoko.o: ../../src/Tsuchinoko.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

AdpcmDecorder.o: ../../src/TinyLibrary/AdpcmDecorder.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Mathmatics.o: ../../src/TinyLibrary/Mathmatics.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Report.o: ../../src/TinyLibrary/Report.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

SoundMixer.o: ../../src/TinyLibrary/SoundMixer.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

SoundPlayer.o: ../../src/TinyLibrary/SoundPlayer.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Controller.o: ../../src/TinyLibrary/SDL/Controller.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

Screen.o: ../../src/TinyLibrary/SDL/Screen.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

SoundStream.o: ../../src/TinyLibrary/SDL/SoundStream.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

TinyFile.o: ../../src/TinyLibrary/SDL/TinyFile.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

RingBuffer.o: ../../src/TinyLibrary/SDL/RingBuffer.cpp
	$(CC) -c $(CPPFLAG) $(INCDIR) $<

clean:
	-rm -f $(OBJS) $(TARGET) *.d
