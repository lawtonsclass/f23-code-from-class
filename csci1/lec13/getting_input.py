resp = input('Enter your name: ')
print(type(resp))
print('Hi, ' + resp + '!')
print('Hi,', resp, '!') # print can take as many args as you want
                        # it space-separates them when it outputs

num = input('Enter your favorite number: ')
print(type(num))
# print(num * 2)
num_as_int = int(num) # num is only a str--we must convert it to an int
print(num_as_int * 2)
