'''
 Banner function implemented on Python.

 Given a captical letter as input and produces as output an array of characters
 that graphically depicts that letter.

 Author: Minchiuan Gao<mqgao@outlook.com>
 Date: 2015-Oct-4
'''


class Line:
    def __init__(self):
        self.chars = []
        self.number = []


class CharGraph:
    def __init__(self, character):
        self.character = character
        self.lines = []

    def append(self, line):
        self.lines.append(line)

    def __print_one_line(self, line):
        for index, c in enumerate(line.chars):
            for i in range(line.number[index]):
                print(c),

    def draw(self):
        for line in self.lines:  # each line is number[], char[]
            self.__print_one_line(line)
            print('')


def test():
    graph_file = file('word_graph.data', 'r')

    char_graphs = []
    for line in graph_file.xreadlines():
        if line[0].isupper():
            char_graph = CharGraph(line[0])
            char_graphs.append(char_graph)
        else:
            one_line = Line()
            for c in line:
                if c.isalnum():
                    one_line.number.append(int(c))
                elif c != '\n':
                    one_line.chars.append(c)
            char_graph.append(one_line)

    char_graphs[0].draw()


if __name__ == '__main__':
    test()
