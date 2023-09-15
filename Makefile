CC = C:/msys64/ucrt64/bin/g++.exe

ifeq ($(OS),Windows_NT)
	CC = C:/msys64/ucrt64/bin/g++.exe
else        
	UNAMEOS = $(shell uname)
	ifeq ($(UNAMEOS),Linux)
		CC = /usr/bin/g++
	endif
endif

CFLAGS = -fdiagnostics-color=always -std=c++17 -g -Wall

# Include directories
IDFLAGS  = -I "$(CURDIR)/vendor/vk/include"
IDFLAGS += -I "$(CURDIR)/vendor/raylib/include"

# Library directories
LDFLAGS  = -L "$(CURDIR)/vendor/vk/lib"
ifeq ($(OS),Windows_NT)
	LDFLAGS += -L "$(CURDIR)/vendor/raylib/lib/win64"
else
	LDFLAGS += -L "$(CURDIR)/vendor/raylib/lib/amd64"
endif

# Libraries
LDLIBS  = -l:vk.lib
LDLIBS += -l:libraylib.a
ifeq ($(OS),Windows_NT)
	LDLIBS += -lopengl32
	LDLIBS += -lgdi32
	LDLIBS += -lwinmm
else	
	LDLIBS += -lGL
	LDLIBS += -lm
	LDLIBS += -lpthread
	LDLIBS += -ldl
	LDLIBS += -lrt
	LDLIBS += -lX11
endif

ifeq ($(OS),Windows_NT)
	OUTPUT_PATH=$(CURDIR)/build/win64
	OUTPUT_FILENAME=raylib.exe
else
	OUTPUT_PATH=$(CURDIR)/build/linux
	OUTPUT_FILENAME=raylib
endif

all: raylib

raylib: main.cpp
	$(CC) $(CFLAGS) $(CURDIR)/main.cpp $(IDFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OUTPUT_PATH)/$(OUTPUT_FILENAME)












