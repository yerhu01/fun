class Trie:

    def __init__(self):
        self.root = {}
        self.stopSymbol = "*"
        

    def insert(self, word: str) -> None:
        node = self.root
        for letter in word:
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node[self.stopSymbol] = True
        

    def search(self, word: str) -> bool:
        node = self.root
        for letter in word:
            if letter in node:
                node = node[letter]
            else:
                return False
        if self.stopSymbol in node:
            return True
        

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for letter in prefix:
            if letter in node:
                node = node[letter]
            else:
                return False
        return True
