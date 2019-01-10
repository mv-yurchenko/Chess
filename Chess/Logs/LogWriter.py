from Chess.core.algebraic.move import Move


class LogWriter:
    def __init__(self, player1: str, player2: str):
        self.log_file = open(player1 + "_VS_" + player2 + ".txt", "w")

    def write_move_log(self, move: Move, side: str):
        self.log_file.write(self.__compile_move_log__(move, side))
        self.__print_new_line__()

    @staticmethod
    def __compile_move_log__(move: Move, side: str)-> str:
        return move.__str__() + " : " + side

    def __print_new_line__(self):
        self.log_file.write("\n")


def main():
    obj = LogWriter("player1", "player2")


if __name__ == '__main__':
    main()