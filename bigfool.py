import curses, os
def lol(win):
	key=''
	x = "I am a big fool. "
	i = 0
	while 1:
		key = win.getkey()
		win.clear()			
		win.addstr(x*int(i/len(x))+x[:int(i%len(x))])
		i = i + 1
		if key == os.linesep:
			print()

try:
	curses.wrapper(lol)
except KeyboardInterrupt:
	print("\nHence while proved, you are a big fool.\n")
