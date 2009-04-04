import copy

class ExDict:
	def __init__(self, _dict=None):
		self._del = set()
		self._dict = {}
		self._dict_ref = _dict
		self._dict["depend"] = copy.deepcopy(_dict["depend"])

 	def keys(self):
 		ks1 = set(self._dict.keys())
 		ks2 = set(self._dict_ref.keys())
 		ks = (ks1 | ks2) - self._del
 		return list(ks)
 
 	def __setitem__(self, i, v):
 		if i in self._del:
 			self._del.remove(i)
		self._dict[i] = v
 
 	def get(self, i, dv):
		if i in self._del:
			return dv
		if i in self._dict:
			return self._dict[i]
		else:
			return self._dict_ref.get(i, dv)

 	def __getitem__(self, i):
 		if i in self._del:
 			raise KeyError, i
		if i in self._dict:
			return self._dict[i]
		else:
 			return self._dict_ref[i]
 
 	def __iter__(self, i):
 		return iter(self.keys())
 
 	def __str__(self):
 		return self.__repr__()
 
 	def __repr__(self):
 		return "(%s, %s)" % (repr(self._dict), repr(self._dict_ref))
 
 	def __len__(self):
 		return len(self.keys())
 	
