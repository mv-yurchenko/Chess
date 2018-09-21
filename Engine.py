import os

def get_info_about_desk(desk_filename = "LogsFiles/Desk.txt" ):
    data = open(desk_filename).read().split()
    num = 0
    figures_coordinate = []
    figures_names = []
    figures_side = []
    for  info in data:
        if (num == 0):
            figures_coordinate.append(info)
        if (num == 1):
            figures_names.append(info)
        if (num == 2):
            figures_side.append(info)
        num += 1
        if (num == 3):
            num = 0
    figures = [ ]
    for figure in zip(figures_coordinate, figures_names, figures_side):
        if figure[1] == "NoFigure"

get_info_about_desk()