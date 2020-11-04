class Person(object):
	""" This class allows to add persons in our program. """

	# ---------------class attributes---------------

	__persons = []


	# ---------------dunder methods-----------------

	def __init__(self, first, last):
		self.__first = first
		self.__last = last
		Person.__persons.append((self.__first, self.__last))

	def __str__(self):
		""" Return our object into a printable state. """
		return self.fullname

	def __del__(self):
		""" Used at the end of the program when memory is liberated. """
		print(f"Deleting {self}")
		self = None


	# -----------------private methods-----------------

	@property
	def first(self):
		return self.__first

	@first.setter
	def first(self, value):
		if value and isinstance(value, str):
			self.__first = value.capitalize().strip()
		else:
			raise Exception("Please enter a correct new first name")

	@first.deleter
	def first(self):
		print(f"Deleting {self.__first}")
		self.__first = None


	@property
	def last(self):
		return self.__last

	@last.setter
	def last(self, value):
		if value and isinstance(value, str):
			self.__last = value.capitalize().strip()
		else:
			raise Exception("Please enter a correct new last name")

	@last.deleter
	def last(self):
		print(f"Deleting {self.__last}")
		self.__last = None


	@property
	def fullname(self):
		return f"{self.__first} {self.__last}"

	@fullname.setter
	def fullname(self, name):
		try:
			assert isinstance(name, str)
			first, last = self.parse_name(name)
		except Exception as e:
			print(f"You didn't enter the correct name format : {e}")
		else:
			if first and last:
				self.__first = first.capitalize().strip()
				self.__last = last.capitalize().strip()
			else:
				raise Exception("Please enter a correct new fullname")

	@fullname.deleter
	def fullname(self):
		print(f"Deleting {self.__first} and {self.__last}")
		self.__first = None
		self.__last = None


	# -------------public methods--------------------

	@classmethod
	def get_persons(cls):
		""" Return a immutable tuple of each person created"""
		return tuple(cls.__persons)

	@staticmethod
	def parse_name(name):
		""" If the user want to directly add a fullname instead of a first + last, then this function extract the first and the last. """
		first,last = name.split(' ')
		return first, last


class Details(Person):

	# ---------------dunder methods-----------------

	def __init__(self, first, last, weight, length, age):
		super().__init__(first, last)
		self.__weight = weight
		self.__length = length
		self.__age = age
		print(self.first)

	def __str__(self):
		""" Return our object into a printable state. """
		return self.fullname

	def __del__(self):
		""" Used at the end of the program when memory is liberated. """
		print(f"Deleting {self}")
		self = None


	# -----------------private methods-----------------

	@property
	def email(self):
		""" Create an email for each new person """
		return self.first + '.' + self.last + "@gmail.com"

	@property
	def weight(self):
		return self.__weight

	@weight.setter
	def weight(self, value):
		if value and isinstance(value, int):
			self.__weight = value
		else:
			raise Exception("Please enter a correct new weight")

	@weight.deleter
	def weight(self):
		print(f"Deleting {self.__weight}")
		self.__weight = None	

	@property
	def length(self):
		return self.__length

	@length.setter
	def length(self, value):
		if value and isinstance(value, int):
			self.__length = value
		else:
			raise Exception("Please enter a correct new length")

	@length.deleter
	def length(self):
		print(f"Deleting {self.__length}")
		self.__length = None	

	@property
	def age(self):
		return self.__age

	@age.setter
	def age(self, value):
		if value and isinstance(value, int):
			self.__age = value
		else:
			raise Exception("Please enter a correct new age")

	@age.deleter
	def age(self):
		print(f"Deleting {self.__age}")
		self.__age = None	



"""
class Test(object):
	def __init__(self, a):
		self.__a = a

	@property
	def a(self):
		return self.__a

	@a.setter
	def a(self, new):
		self.__a = new

class Test2(Test):
	def __init__(self, a, b):
		Test.__init__(a)
		self.b = b

i = Test2(3, 4)
i = Test2(3, 4)
i = Test2(3, 4)
i = Test2(3, 4)"""


class Enibien(object):
	def __init__(self, name):
		self.__name = name
		self.__girlfriend = None
		self.__temp_girl_friend = None

	def __str__(self):
		return f"I'm the enibien {self.__name} and I hang out with {self.__girlfriend}"

	@property
	def name(self):
		return self.__name

	@property
	def girlfriend(self):
		return self.__girlfriend

	@girlfriend.setter
	def girlfriend(self, new_girlfriend):
		""" new_girlfriend is an instance """
		if not self.__temp_girl_friend:
			self.__temp_girl_friend = new_girlfriend


		else:
			if new_girlfriend.name != self.__girlfriend:
				self.__temp_girl_friend.boyfriend = Esiabienne("none")
				self.__temp_girl_friend = new_girlfriend

		if new_girlfriend.name != self.__girlfriend:
			self.__girlfriend = new_girlfriend.name
			new_girlfriend.boyfriend = self
	

class Esiabienne(object):
	def __init__(self, name):
		self.__name = name
		self.__boyfriend = None
		self.__temp_boy_friend = None

	def __str__(self):
		return f"I'm the esiabienne {self.__name} and I hangout with {self.__boyfriend}"

	@property
	def name(self):
		return self.__name


	@property
	def boyfriend(self):
		return self.__boyfriend

	@boyfriend.setter
	def boyfriend(self, new_boyfriend):
		""" new_boyfriend is an instance. """
		
		if not self.__temp_boy_friend:
			self.__temp_boy_friend = new_boyfriend


		else:
			if new_boyfriend.name != self.__boyfriend:
				self.__temp_boy_friend.girlfriend = Enibien("none")
				self.__temp_boy_friend = new_boyfriend

		if new_boyfriend.name != self.__boyfriend:
			self.__boyfriend = new_boyfriend.name
			new_boyfriend.boyfriend = self


















import random

class Ligue1(object):
	def __init__(self, equipe= None, capital = 0):
		self.__equipe = equipe
		self.__capital = capital

	def __str__(self):
		return f"L'équipe {self.__equipe} a un capital de {self.__capital} millions d'euros."

	def __del__(self):
		print(f"Suppression de {self.__equipe}")
		self = None

	@property
	def equipe(self):
		return self.__equipe
	@equipe.setter
	def equipe(self, new_team):
		if new_team:
			self.__equipe = new_team

	@property
	def capital(self):
		return self.__capital
	@capital.setter
	def capital(self, new_capital):
		if new_capital and new_capital >= 0:
			self.__capital = new_capital

	def raise_capital(self, raise_amount):
		if raise_amount:
			self.__capital *= (1+raise_amount/100)
		print(f"Le capital monte ! Voici la nouvelle valeur : {self.__capital} millions d'euros.")

	@staticmethod
	def play(team1, team2):
		raise NotImplementedError("The team must play itself")

class Team(Ligue1):
	def __init__(self, equipe = None, position_class = 20, capital = 0):
		super().__init__(equipe, capital)
		self.__position_class = position_class
		self.__recruit = set()
		print(self)

	@property
	def position_class(self):
		return self.__position_class
	@position_class.setter
	def position_class(self, new_position_class):
		if new_position_class and new_position_class > 0 and new_position_class <= 20:
			self.__position_class = new_position_class

	def new_season(self, raise_amount):
		super().raise_capital(raise_amount)

	@property
	def recruit(self):
		return self.__recruit
	@recruit.setter
	def recruit(self, new_recruit):
		if new_recruit:
			self.__recruit.add(new_recruit)
	
	@staticmethod
	def play(team1, team2):
		opposants = [team1, team2]
		winner = random.choice(opposants)
		print(f"{winner.equipe} a gagné.")

class Player(Team):
	def __init__(self, name, age, team):
		self.__name = name
		self.__age = age
		self.__team = team
		self.__team.recruit.add(self)
		print(self)

	def __str__(self):
		return f"Je suis {self.__name}, j'ai {self.__age} ans et voici mon équipe actuelle : {self.__team.equipe}."

	def __del__(self):
		print(f"suppression de {self.__name}")
		self = None

	@property
	def name(self):
		return self.__name
	@name.setter
	def name(self, new_name):
		if new_name:
			self.__name = new_name
	@property
	def age(self):
		return self.__age
	@age.setter
	def age(self, new_age):
		if new_age:
			self.__age = new_age

	@property
	def team(self):
		return self._team

	def change_team(self, new_team):
		if new_team:
			if self.__team.recruit:
				self.__team.recruit.remove(self)
			print(f"{self.__name} -> {new_team.equipe}")
			self.__team = new_team
			self.__team.recruit = self




	


if __name__ == "__main__":
	print("~~~~ Start ~~~~\n")

	"""persons = [("Ewan Carrée", 65, 172, 20), ("Lou-Anne LeBras", 50, 164, 20), ("Léo Carrée", 70, 172, 17)]
	p = []
	for person in persons:
		first, last = Person.parse_name(person[0])
		p.append(Details(first, last, person[1], person[2], person[3]))
	print(Person.get_persons())

	print(p[0].weight)"""


	"""e1 = Enibien("Patrick")

	e2 = Esiabienne("Marine")
	

	e1.girlfriend = e2
	e2.boyfriend = e1

	print(e1)
	print(e2)

	e3 = Esiabienne("Céline")

	e1.girlfriend = e3
	e2.boyfriend = e1

	print(e1)
	print(e2)"""

	lorient = Team("fcl", 1, 20)
	rennes = Team("sfrc", 2, 70)
	camavinga = Player("Camavinga", 17, rennes)
	le_goff = Player("Le Goff", 30, lorient)

	print()

	lorient.raise_capital(20)

	print()

	for player in lorient.recruit:
		print(f"Effectif Lorient : {player.name}")
	for player in rennes.recruit:
		print(f"Effectif Rennes : {player.name}")

	camavinga.change_team(lorient)
	le_goff.change_team(rennes)

	for player in lorient.recruit:
		print(f"Effectif Lorient : {player.name}")
	for player in rennes.recruit:
		print(f"Effectif Rennes : {player.name}")

	print()

	Team.play(lorient, rennes)



	
	print("\n~~~~ End ~~~~\n")