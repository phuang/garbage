class Dot:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

class Stroke:
    def __init__(self):
        self.__dots = []

    def add(self, dot):
        self.__dots.append(dot)

class Charater:
    def __init__(self, width, height):
        self.__width = width
        self.__height = height
        self.__strokes = []

    def add(self, stroke):
        self.__strokes.append(stroke)

input = '''
    (character (width 1000)(height 1000)
        (strokes ((243 273)(393 450))
                 ((700 253)(343 486)(280 716)(393 866)(710 880))
        )
    )'''
