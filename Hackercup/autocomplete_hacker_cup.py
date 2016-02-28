#Trie as an FSM
class Trie:
	def __init__(self):
		self.edges = {0 : {}}
		self.words_below = {0 : 0}	
		self.total_states = 1
		
	def add_word(self, word):
		current_state = 0
		self.words_below[current_state] += 1
		for i in word:
			if i not in self.edges[current_state]:
				self.edges[current_state][i] = self.total_states
				self.edges[self.total_states] = {}
				self.words_below[self.total_states] = 0
				self.total_states += 1
			current_state = self.edges[current_state][i]
			self.words_below[current_state] += 1
		
			
	def search_prefix(self, word):
		current_state = 0
		count = 0
		for i in word:
			if current_state != 0 and self.words_below[current_state] == 1:
				return count
			current_state = self.edges[current_state][i]
			count += 1
		return count
		
		
t = input()
for u in range(t):
	trie = Trie()
	res = 0
	n = input()
	for _ in range(n):
		word = raw_input()
		trie.add_word(word)
		res += trie.search_prefix(word)	
	print 'Case #' + str(u + 1) + ': ' + str(res)

