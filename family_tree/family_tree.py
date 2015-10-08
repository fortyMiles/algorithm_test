'''
    Test Family tree data tructrue. Implement the family tree's CRUD.
    Author: Minchiuan Gao <mqgao@outlook.com>
    Date: 2015-Oct-8
'''


class Home:
    def __init__(self, ID):
        self.ID = ID
        self.persons = []

    def add_a_person(self, Person):
        self.persons.append(Person)


class Person:
    def __init__(self, ID, systemIndex=None, name=None, nickname=None,
                 gender=None, parents_home=None):
        self.child_num = 0
        self.slide_num = 0
        self.first_child = None
        self.first_sibling = None
        self.children = []  # define the none children list
        self.siblings = []
        self.ID = ID
        self.systemIndex = systemIndex
        self.name = name
        self.nickname = nickname
        self.gender = gender
        self.parents_home = parents_home

    def setFirstSlibing(self, silbing):
        '''
        sets this person's first slibing
        Args: silbing -> Person
        '''
        self.first_silbing = silbing

    def setFirstChild(self, child):
        '''
        sets this person's first slibing
        Args: silbing -> Person
        '''
        self.first_child = child

    def save(self):
        '''
        save this person information in database
        '''
        pass


class RelationPrecessor:
    '''
    precess the relation between different people
    '''
    pass

