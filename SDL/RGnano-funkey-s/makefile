CC = arm-funkey-linux-musleabihf-gcc.br_real
CPPFLAG = -lSDL -D SDL -D RGNANO -lstdc++
LIBS = 
INCDIR = 
LIBDIR = 
TARGET = KemonoRogue_funkey-s

SRCS    = ../../src/Boss1.cpp \
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
../../src/Tsuchinoko.cpp \
../../src/TinyLibrary/AdpcmDecorder.cpp \
../../src/TinyLibrary/Mathmatics.cpp \
../../src/TinyLibrary/Report.cpp \
../../src/TinyLibrary/SoundMixer.cpp \
../../src/TinyLibrary/SoundPlayer.cpp \
../../src/TinyLibrary/SDL/Controller.cpp \
../../src/TinyLibrary/SDL/main.cpp \
../../src/TinyLibrary/SDL/Screen.cpp \
../../src/TinyLibrary/SDL/SoundStream.cpp \
../../src/TinyLibrary/SDL/TinyFile.cpp \
../../src/TinyLibrary/SDL/RingBuffer.cpp

OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
    $(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
    $(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
    -rm -f $(OBJS) $(TARGET) *.d
