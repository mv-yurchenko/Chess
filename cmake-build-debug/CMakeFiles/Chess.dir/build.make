# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = P:\Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = P:\Chess\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess.dir/flags.make

CMakeFiles/Chess.dir/main.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\main.cpp.obj -c P:\Chess\main.cpp

CMakeFiles/Chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\main.cpp > CMakeFiles\Chess.dir\main.cpp.i

CMakeFiles/Chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\main.cpp -o CMakeFiles\Chess.dir\main.cpp.s

CMakeFiles/Chess.dir/Figures/Bishop.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Bishop.cpp.obj: ../Figures/Bishop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chess.dir/Figures/Bishop.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Bishop.cpp.obj -c P:\Chess\Figures\Bishop.cpp

CMakeFiles/Chess.dir/Figures/Bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Bishop.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Bishop.cpp > CMakeFiles\Chess.dir\Figures\Bishop.cpp.i

CMakeFiles/Chess.dir/Figures/Bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Bishop.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Bishop.cpp -o CMakeFiles\Chess.dir\Figures\Bishop.cpp.s

CMakeFiles/Chess.dir/Figures/Castle.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Castle.cpp.obj: ../Figures/Castle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Chess.dir/Figures/Castle.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Castle.cpp.obj -c P:\Chess\Figures\Castle.cpp

CMakeFiles/Chess.dir/Figures/Castle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Castle.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Castle.cpp > CMakeFiles\Chess.dir\Figures\Castle.cpp.i

CMakeFiles/Chess.dir/Figures/Castle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Castle.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Castle.cpp -o CMakeFiles\Chess.dir\Figures\Castle.cpp.s

CMakeFiles/Chess.dir/Figures/Figure.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Figure.cpp.obj: ../Figures/Figure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Chess.dir/Figures/Figure.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Figure.cpp.obj -c P:\Chess\Figures\Figure.cpp

CMakeFiles/Chess.dir/Figures/Figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Figure.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Figure.cpp > CMakeFiles\Chess.dir\Figures\Figure.cpp.i

CMakeFiles/Chess.dir/Figures/Figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Figure.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Figure.cpp -o CMakeFiles\Chess.dir\Figures\Figure.cpp.s

CMakeFiles/Chess.dir/Figures/King.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/King.cpp.obj: ../Figures/King.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Chess.dir/Figures/King.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\King.cpp.obj -c P:\Chess\Figures\King.cpp

CMakeFiles/Chess.dir/Figures/King.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/King.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\King.cpp > CMakeFiles\Chess.dir\Figures\King.cpp.i

CMakeFiles/Chess.dir/Figures/King.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/King.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\King.cpp -o CMakeFiles\Chess.dir\Figures\King.cpp.s

CMakeFiles/Chess.dir/Figures/Knight.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Knight.cpp.obj: ../Figures/Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Chess.dir/Figures/Knight.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Knight.cpp.obj -c P:\Chess\Figures\Knight.cpp

CMakeFiles/Chess.dir/Figures/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Knight.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Knight.cpp > CMakeFiles\Chess.dir\Figures\Knight.cpp.i

CMakeFiles/Chess.dir/Figures/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Knight.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Knight.cpp -o CMakeFiles\Chess.dir\Figures\Knight.cpp.s

CMakeFiles/Chess.dir/Figures/Pawn.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Pawn.cpp.obj: ../Figures/Pawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Chess.dir/Figures/Pawn.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Pawn.cpp.obj -c P:\Chess\Figures\Pawn.cpp

CMakeFiles/Chess.dir/Figures/Pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Pawn.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Pawn.cpp > CMakeFiles\Chess.dir\Figures\Pawn.cpp.i

CMakeFiles/Chess.dir/Figures/Pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Pawn.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Pawn.cpp -o CMakeFiles\Chess.dir\Figures\Pawn.cpp.s

CMakeFiles/Chess.dir/Figures/Queen.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Figures/Queen.cpp.obj: ../Figures/Queen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Chess.dir/Figures/Queen.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Figures\Queen.cpp.obj -c P:\Chess\Figures\Queen.cpp

CMakeFiles/Chess.dir/Figures/Queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Figures/Queen.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Figures\Queen.cpp > CMakeFiles\Chess.dir\Figures\Queen.cpp.i

CMakeFiles/Chess.dir/Figures/Queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Figures/Queen.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Figures\Queen.cpp -o CMakeFiles\Chess.dir\Figures\Queen.cpp.s

CMakeFiles/Chess.dir/Coordinates.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Coordinates.cpp.obj: ../Coordinates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Chess.dir/Coordinates.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Coordinates.cpp.obj -c P:\Chess\Coordinates.cpp

CMakeFiles/Chess.dir/Coordinates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Coordinates.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Coordinates.cpp > CMakeFiles\Chess.dir\Coordinates.cpp.i

CMakeFiles/Chess.dir/Coordinates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Coordinates.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Coordinates.cpp -o CMakeFiles\Chess.dir\Coordinates.cpp.s

CMakeFiles/Chess.dir/Desk.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Desk.cpp.obj: ../Desk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Chess.dir/Desk.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Desk.cpp.obj -c P:\Chess\Desk.cpp

CMakeFiles/Chess.dir/Desk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Desk.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Desk.cpp > CMakeFiles\Chess.dir\Desk.cpp.i

CMakeFiles/Chess.dir/Desk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Desk.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Desk.cpp -o CMakeFiles\Chess.dir\Desk.cpp.s

CMakeFiles/Chess.dir/Move.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Move.cpp.obj: ../Move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Chess.dir/Move.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Move.cpp.obj -c P:\Chess\Move.cpp

CMakeFiles/Chess.dir/Move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Move.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Move.cpp > CMakeFiles\Chess.dir\Move.cpp.i

CMakeFiles/Chess.dir/Move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Move.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Move.cpp -o CMakeFiles\Chess.dir\Move.cpp.s

CMakeFiles/Chess.dir/Game/Game.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Game/Game.cpp.obj: ../Game/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Chess.dir/Game/Game.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Game\Game.cpp.obj -c P:\Chess\Game\Game.cpp

CMakeFiles/Chess.dir/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Game/Game.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Game\Game.cpp > CMakeFiles\Chess.dir\Game\Game.cpp.i

CMakeFiles/Chess.dir/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Game/Game.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Game\Game.cpp -o CMakeFiles\Chess.dir\Game\Game.cpp.s

CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.obj: ../Game/PVP_GAME.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Game\PVP_GAME.cpp.obj -c P:\Chess\Game\PVP_GAME.cpp

CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Game\PVP_GAME.cpp > CMakeFiles\Chess.dir\Game\PVP_GAME.cpp.i

CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Game\PVP_GAME.cpp -o CMakeFiles\Chess.dir\Game\PVP_GAME.cpp.s

CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.obj: ../LogsWriter/FiguresPossibleMovesWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\LogsWriter\FiguresPossibleMovesWriter.cpp.obj -c P:\Chess\LogsWriter\FiguresPossibleMovesWriter.cpp

CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\LogsWriter\FiguresPossibleMovesWriter.cpp > CMakeFiles\Chess.dir\LogsWriter\FiguresPossibleMovesWriter.cpp.i

CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\LogsWriter\FiguresPossibleMovesWriter.cpp -o CMakeFiles\Chess.dir\LogsWriter\FiguresPossibleMovesWriter.cpp.s

CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.obj: ../LogsWriter/GameLogsWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\LogsWriter\GameLogsWriter.cpp.obj -c P:\Chess\LogsWriter\GameLogsWriter.cpp

CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\LogsWriter\GameLogsWriter.cpp > CMakeFiles\Chess.dir\LogsWriter\GameLogsWriter.cpp.i

CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\LogsWriter\GameLogsWriter.cpp -o CMakeFiles\Chess.dir\LogsWriter\GameLogsWriter.cpp.s

CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.obj: ../Graphics/ChessGraphic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess.dir\Graphics\ChessGraphic.cpp.obj -c P:\Chess\Graphics\ChessGraphic.cpp

CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E P:\Chess\Graphics\ChessGraphic.cpp > CMakeFiles\Chess.dir\Graphics\ChessGraphic.cpp.i

CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S P:\Chess\Graphics\ChessGraphic.cpp -o CMakeFiles\Chess.dir\Graphics\ChessGraphic.cpp.s

# Object files for target Chess
Chess_OBJECTS = \
"CMakeFiles/Chess.dir/main.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Bishop.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Castle.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Figure.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/King.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Knight.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Pawn.cpp.obj" \
"CMakeFiles/Chess.dir/Figures/Queen.cpp.obj" \
"CMakeFiles/Chess.dir/Coordinates.cpp.obj" \
"CMakeFiles/Chess.dir/Desk.cpp.obj" \
"CMakeFiles/Chess.dir/Move.cpp.obj" \
"CMakeFiles/Chess.dir/Game/Game.cpp.obj" \
"CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.obj" \
"CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.obj" \
"CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.obj" \
"CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.obj"

# External object files for target Chess
Chess_EXTERNAL_OBJECTS =

Chess.exe: CMakeFiles/Chess.dir/main.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Bishop.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Castle.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Figure.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/King.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Knight.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Pawn.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Figures/Queen.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Coordinates.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Desk.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Move.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Game/Game.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Game/PVP_GAME.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/LogsWriter/FiguresPossibleMovesWriter.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/LogsWriter/GameLogsWriter.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/Graphics/ChessGraphic.cpp.obj
Chess.exe: CMakeFiles/Chess.dir/build.make
Chess.exe: CMakeFiles/Chess.dir/linklibs.rsp
Chess.exe: CMakeFiles/Chess.dir/objects1.rsp
Chess.exe: CMakeFiles/Chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=P:\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess.dir/build: Chess.exe

.PHONY : CMakeFiles/Chess.dir/build

CMakeFiles/Chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chess.dir/clean

CMakeFiles/Chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" P:\Chess P:\Chess P:\Chess\cmake-build-debug P:\Chess\cmake-build-debug P:\Chess\cmake-build-debug\CMakeFiles\Chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chess.dir/depend

