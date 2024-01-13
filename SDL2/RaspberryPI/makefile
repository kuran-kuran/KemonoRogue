CC = g++
CFLAGS = `sdl2-config --cflags --libs` -D SDL2
TARGET = KemonoRogue_exe
SRCS = \
../../src/TinyLibrary/AdpcmDecorder.cpp \
../../src/TinyLibrary/Mathmatics.cpp \
../../src/TinyLibrary/SoundMixer.cpp \
../../src/TinyLibrary/SoundPlayer.cpp \
../../src/TinyLibrary/Report.cpp \
../../src/TinyLibrary/SDL2/Controller.cpp \
../../src/TinyLibrary/SDL2/main.cpp \
../../src/TinyLibrary/SDL2/Screen.cpp \
../../src/TinyLibrary/SDL2/SoundStream.cpp \
../../src/TinyLibrary/SDL2/TinyFile.cpp \
../../src/TinyLibrary/SDL2/RingBuffer.cpp \
../../src/Cerulean.cpp \
../../src/Ending.cpp \
../../src/Enemy.cpp \
../../src/FloorMap.cpp \
../../src/Game.cpp \
../../src/GameData.cpp \
../../src/Global.cpp \
../../src/Item.cpp \
../../src/Kaban.cpp \
../../src/MainLoop.cpp \
../../src/Maze.cpp \
../../src/Object.cpp \
../../src/Player.cpp \
../../src/Popup.cpp \
../../src/Resource.cpp \
../../src/Resume.cpp \
../../src/Serval.cpp \
../../src/Sound.cpp \
../../src/Toki.cpp \
../../src/Tsuchinoko.cpp

OBJS3    = $(SRCS:../../src/%.cpp=./%.o)
OBJS2    = $(OBJS3:./TinyLibrary/%.o=./%.o)
OBJS    = $(OBJS2:./SDL2/%.o=./%.o)

INCDIR  = 

LIBDIR  = 

LIBS    = 

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
