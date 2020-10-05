def q0(i) :
	print(' --> q0', end = '')
	if i == len(a) :
		end(1, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q5(i+1)
	else :
		q1(i+1)

def q1(i) :
	print(' --> q1', end = '')
	if i == len(a) :
		end(1, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q2(i+1)
	else :
		q0(i+1)

def q2(i) :
	print(' --> q2', end = '')
	if i == len(a) :
		end(0, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q3(i+1)
	else :
		q4(i+1)

def q3(i) :
	print(' --> q3', end = '')
	if i == len(a) :
		end(1, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q3(i+1)
	else :
		q3(i+1)

def q4(i) :
	print(' --> q4', end = '')
	if i == len(a) :
		end(0, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q3(i+1)
	else :
		q4(i+1)

def q5(i) :
	print(' --> q5', end = '')
	if i == len(a) :
		end(0, i)
	if a[i] != '0' and a[i] != '1' :
		end(2, i)
	if a[i] == '1' :
		q3(i+1)
	else :
		q4(i+1)

def end(flag, i) :
	print('\n', end = '         ')
	for c in a[:i] :
		print(c, end = '      ')
	if flag == 0 :
		print('\n\nACCEPT')
	elif flag == 1 :
		print('\n\nREJECT')
	else :
		print('\n\nINVALID')
	exit()

a = input("Enter the string: ")
print()
q0(0)