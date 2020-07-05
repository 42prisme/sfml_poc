CXX = clang++

NAME = a.out

SRC = ../external/ImGui/imgui-SFML.cpp \
      ../external/ImGui/imgui.cpp \
      ../external/ImGui/imgui_demo.cpp \
      ../external/ImGui/imgui_draw.cpp \
      \
      main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE_SFML_FLAGS =
INCLUDE_OTHER_FLAGS = -I.. -I../external/ -I../external/ImGui


WARNING_FLAGS = -Wall -Wextra -Wno-comment
CXXFLAGS =  $(WARNING_FLAGS) $(INCLUDE_OTHER_FLAGS) $(INCLUDE_SFML_FLAGS) -DIMGUI

LD_SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
LD_IMGUI_FLAGS = -lGL
LDFLAGS = $(LD_IMGUI_FLAGS) $(LD_SFML_FLAGS) 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f imgui.ini imgui_log.txt

re : clean all
