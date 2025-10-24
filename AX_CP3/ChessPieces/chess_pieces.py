# AX Chess Game

from abc import ABC, abstractmethod



class ChessPiece(ABC):
    def __init__(self, color: str, position: str):
        self.color = color # white or black
        self.position = position # ex. a1

    def getPosition(self) -> str:
        return self.position
    
    @abstractmethod
    def canMoveTo(self, newPos: str) -> bool:
        pass

    def getSymbol(self) -> str:
        pass


class Pawn(ChessPiece):
    def canMoveTo(self, newPos: str):
        #Pawns move one forward space
        #The column and row of that pawn before
        col, row = self.position[0], int(self.position[1])
        #The updated colum and row
        new_col, new_row = newPos[0], int(newPos[1])
        if self.color == "white":
            direction = 1
        else:
            direction -=1
        return col == new_col and new_row == row + direction

    def getSymbol(self):
        return "P"


class Rook(ChessPiece):
    def canMoveTo(self, newPos: str):
        #Moves in straight lines
        # The first one is up and down the same column and the second one is left or right the same row
        return self.position[0] == newPos[0] or self.position[1] == newPos[1]

    def getSymbol(self):
        return "R"

class Knight(ChessPiece):
    def canMoveTo(self, newPos: str):
        #still kinda confused
        # makes it so that the letters are corresponding with the numbers
        columns = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4,
            'e': 5, 'f': 6, 'g': 7, 'h': 8
        }
        #Finds the current position
        start_col = columns[self.position[0]]
        start_row = columns[self.position[1]]

        #Finds the target position
        end_col = columns[newPos[0]]
        end_row = columns[newPos[1]]

        #calculates how much the piece moved
        col_diff = abs(start_col - end_col)
        row_diff = abs(start_row - end_row)

        #returns the l shape(2 by 1 or 1 by 2)
        return (col_diff, row_diff) in [(1,2), (2,1)]

    def getSymbol(self):
        return "K"

class Bishop(ChessPiece):
    def canMoveTo(self, newPos: str):
        #Moves diagonally
        columns = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4,
            'e': 5, 'f': 6, 'g': 7, 'h': 8
        }
        start_col = columns[self.position[0]]
        start_row = columns[self.position[1]]

        #Finds the target position
        end_col = columns[newPos[0]]
        end_row = columns[newPos[1]]

        #calculates how much the piece moved
        col_diff = abs(start_col - end_col)
        row_diff = abs(start_row - end_row)

        #Bishop moves diagonally which means that it has the same number of steps in both directions
        return col_diff == row_diff


    def getSymbol(self):
        return "B"

class Queen(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):
        return "Q"

class King(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):
        return "K"



class ChessGame:
    def __init__(self):
        self.whitePieces = []
        self.blackPieces = []
    
    def movePiece(self, piece: ChessPiece, NewPos:str) -> bool:


    def removePiece(self, piece: ChessPiece):
        if piece.color() == "white":
            self.whitePieces.remove(piece)
        else:
            self.blackPieces.remove(piece)

    def getPiecesLeft(self, color: str) -> list:
        if color == "white":
            return self.whitePieces
        else:
            return self.blackPieces
        
    def getPiecesAt(self, position: str) -> ChessPiece:


