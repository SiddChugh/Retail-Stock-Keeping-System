#flags passed to the g++ compiler
CXXFLAGS += -g -std=c++17
SOURCE_FILE += redblacktree.cpp stockitem.cpp stocksystem.cpp

all:
  $(CXX) $(CXXFLAGS) -c $(SOURCE_FILE)
