# -*- coding: utf-8 -*-

"""
Included class for human interaction via console.
Prints position and takes move written in algebraic notation as string input

| Copyright © 2018 Maxim Yurchenko. All rights reserved.
"""

from Chess.core.algebraic import converter
from Chess.players.player import Player

try:
    input = raw_input
except NameError:
    pass


class Human(Player):
    def __init__(self, input_color):
        """
        Creates interface for human player.

        :type: input_color: Color
        """
        super(Human, self).__init__(input_color)

    def generate_move(self, position):
        """
        Returns valid and legal move given position

        :type: position: Board
        :rtype: Move
        """
        while True:
            print(position)
            raw = input(str(self.color) + "\'s move \n")
            move = converter.short_alg(raw, self.color, position)

            if move is None:
                continue

            return move
