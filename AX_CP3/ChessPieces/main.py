# AX Main Function for chess game

'''
EXAMPLE OUTPUT:
White Knight 1, Symbol K  is at B1

Black Pawn 5, Symbol P is at D7

White Pawn 4, Symbol P is at D2

Black Bishop 2, Symbol B is at C8

White Rook 1, Symbol R is at A1

***After moves***

White Knight 1, Symbol K  is at C3

Black Pawn 5, Symbol P is at D5

White Pawn 4, Symbol P is at D3

Black Bishop 2, Symbol B is at F5

White Rook 1 cannot move to A4
'''

from chess_pieces import *


#prints the info in the way we want the output to be
def printPiece(label: str, piece, number: int):
    if piece:
        print(f"{label} {piece.__class__.__name__} {number}, Symbol {piece.getSymbol()} is at {piece.getPosition()}")

def main():
    #To run the game
    game = ChessGame()

    #p for p is looping through each piece of the whole board game of that color and specifies its type and index
    white_knight1 = [p for p in game.whitePieces if isinstance(p, Knight)][0]  # B1
    black_pawn5 = [p for p in game.blackPieces if isinstance(p, Pawn)][4]      # D7
    white_pawn4 = [p for p in game.whitePieces if isinstance(p, Pawn)][3]      # D2
    black_bishop2 = [p for p in game.blackPieces if isinstance(p, Bishop)][1]  # C8
    white_rook1 = [p for p in game.whitePieces if isinstance(p, Rook)][0]      # A1

    # Initial positions
    printPiece("White", white_knight1, 1)
    printPiece("Black", black_pawn5, 5)
    printPiece("White", white_pawn4, 4)
    printPiece("Black", black_bishop2, 2)
    printPiece("White", white_rook1, 1)

    print("\n***After moves***\n")

    # Move Knight from B1 to C3
    game.movePiece(white_knight1, "c3")
    printPiece("White", white_knight1, 1)

    # Move Black Pawn 5 from D7 to D5
    game.movePiece(black_pawn5, "d5")
    printPiece("Black", black_pawn5, 5)

    # Move White Pawn 4 from D2 to D3
    game.movePiece(white_pawn4, "d3")
    printPiece("White", white_pawn4, 4)

    # Move Black Bishop 2 from C8 to F5
    game.movePiece(black_bishop2, "f5")
    printPiece("Black", black_bishop2, 2)

    # Try to move White Rook 1 from A1 to A4 (blocked by pawn at A2)
    if game.movePiece(white_rook1, "a4"):
        printPiece("White", white_rook1, 1)
    else:
        print("White Rook 1 cannot move to A4")

main()

 