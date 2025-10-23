# AX Chess Game

from abc import ABC, abstractmethod



class ChessPiece(ABC):
    def __init__(self, color: str, position: str):
        self.color = color
        self.position = position

    def getPosition(self) -> str:
        return self.position
    
    @abstractmethod
    def canMoveTo(self, newPos: str) -> bool:
        pass

    def getSymbol(self) -> str:
        pass


class Pawn(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):


class Rook(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):

class Knight(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):

class Bishop(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):

class Queen(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):

class King(ChessPiece):
    def canMoveTo(self, newPos: str):

    def getSymbol(self):



class ChessGame:
    def __init__(self):
        self.whitePieces = []
        self.blackPieces = []
    
    def movePiece(self, piece: ChessPiece, NewPos:str) -> bool:


    def removePlace(self, piece: ChessPiece):
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