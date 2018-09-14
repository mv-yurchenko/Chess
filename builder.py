import os

def add_file(command, filename):
    return command + " " + str(filename)

os_command = "g++ main.cpp"

os_command = add_file(os_command, "Game/*.cpp")

os_command = add_file(os_command, "Figures/*.cpp")

os_command = add_file(os_command, "LogsWriter/*.cpp")

os_command = add_file(os_command, "Desk.cpp")

os_command = add_file(os_command, "Move.cpp")

os_command = add_file(os_command, "Coordinates.cpp")

os_command = os_command + " -lsfml-graphics -lsfml-window -lsfml-system"

os.system(os_command)
