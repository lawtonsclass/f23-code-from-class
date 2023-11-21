class Counter:
    # constructors in python are called __init__
    # every method takes an explicit "self" parameter first
    # (but it's automatically passed when you call a method)
    def __init__(self, count=0):
        # let's make a field called "count"
        # all fields get made in the constructor
        self.count = count # <-- the member var gets made right here! 

    def inc(self):
        self.count += 1

    def getCount(self):
        return self.count

c = Counter()
c.inc()  # gets translated into inc(c)
c.inc()
c.inc()
print(c.getCount()) # 3

c2 = Counter(42)
c2.inc()
c2.inc()
print(c2.getCount()) # 44
