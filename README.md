# Chess

## Installation

To use as a immediately start up a game between two human players in the console, navigate inside the root directory of the package and run main.py. 

```bash
python main.py
```

To install package  

### ``pip`` (*Recommended*)
```bash
pip install chess_py
```

### Or manually
```bash
python setup.py install
```

## (*An Example*)

Chess_py has the capability of creating games between players, either human, or AI 

```python
import chess_py
from chess_py import Game, Human, color

""" Creates a Game with 2 humans. 
When run, this will open the console,"""
new_game = Game(Human(color.white), Human(color.black))

""" After game is completed, outcome will be stored in result.
The integer result will be one of three values. 
white wins - 0, black wins - 1, draw - 0.5 """
result = new_game.play()
```

To build a chess engine on with chess_py, inherit Player and implement generate_move() 

```python
import chess_py
from chess_py import Game, Human, color

# Engine which plays the move with the highest immediate material advantage
class MyEngine(chess_py.Player):
    def __init__(self, input_color):
    
      # Creates piece value scheme to specify value of each piece.
      self.piece_values = chess_py.PieceValues.init_manual(PAWN_VALUE=1,
                                                            KNIGHT_VALUE=3,
                                                            BISHOP_VALUE=3,
                                                            ROOK_VALUE=5,
                                                            QUEEN_VALUE=9)
      
      # Super call to
      super(chess_py.Player, self).__init__(input_color)
    
    def generate_move(self, position):
      # position parameter is an object of type Board
        
      # Finds all possible moves I can play.
      moves = position.all_possible_moves(self.color)
      
      # Initalizes best move and advantage after it has been played to dummy values.
      best_move = None
      best_move_advantage = -99
      
      # Loops through possible moves
      for move in moves:
        """ advantage_as_result(move, piece_values) finds numerical advantage
        as specified by piece value scheme above. Returns negative values for
        positions of disadvantage. Returns +/-99 for checkmate. """
        advantage = position.advantage_as_result(move, self.piece_values)
        
        # If this move is better than best move, it is the best move.
        if advantage >= best_move_advantage:
            best_move = move
            best_move_advantage = advantage
      
      return best_move

# If file is run as script, a Game is set up between My_engine and Human and result is printed.
if __name__ == "__main__":
    new_game = Game(MyEngine(color.white), Human(color.black))
    
    # white wins - 0, black wins - 1, draw - 0.5 
    print("Result: ", new_game.play())
```

