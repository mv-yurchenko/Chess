# -*- coding: utf-8 -*-

"""
Class stores Queen on the board

| rank
| 7 8 ║♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
| 6 7 ║♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
| 5 6 ║… … … … … … … …
| 4 5 ║… … … … … … … …
| 3 4 ║… … … … … … … …
| 2 3 ║… … … … … … … …
| 1 2 ║♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
| 0 1 ║♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖
| ----╚═══════════════
| ——---a b c d e f g h
| -----0 1 2 3 4 5 6 7
| ------file

| Copyright © 2018 Maxim Yurchenko. All rights reserved.
"""

import itertools

from .piece import Piece
from .rook import Rook
from .bishop import Bishop
from ..core import color


class Queen(Bishop, Piece):
    def __init__(self, input_color, location):
        Piece.__init__(self, input_color, location)

    def _symbols(self):
        return {color.white: "♛", color.black: "♕"}

    def __str__(self):
        return "Q"

    def possible_moves(self, position):
        for move in itertools.chain(Rook.possible_moves(self, position),
                                    Bishop.possible_moves(self, position)):
            yield move
