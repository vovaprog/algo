#!/usr/bin/python3

def read_ints():
    return list(map(int, input().split()))

bookCount, topicCount = read_ints()

books = {}

for book in read_ints():    
    books[book] = books.get(book,0) + 1 
    
result = 0    
i = 0

for curBooks in books.values():
    result += curBooks * (bookCount - curBooks)
    bookCount -= curBooks
    i += 1
    
print(result)

