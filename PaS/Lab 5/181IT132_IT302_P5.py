import xlrd

loc = ("./Test-Cases-IT302-Lab-Program-5.xlsx")
wb = xlrd.open_workbook(loc)
sheet = wb.sheet_by_index(0)

c = []
for i in range(0, sheet.nrows):
	for j in range(0, sheet.ncols):
		if sheet.cell_value(i, j) == "f(x,y)":
			c.append([i, j])
			break
r = []
r2 = []
check = 0
for c1 in c:
	check = 0
	for i in range(c1[1]+2, sheet.ncols):
		if sheet.cell(c1[0]+1, i).value == xlrd.empty_cell.value:
			r.append([c1[1]+2, i])
			check = 1
			break
	if check == 0:
		r.append([c1[1]+2, i+1])
for c1 in c:
	check = 0
	for i in range(c1[0]+2, sheet.nrows):
		if sheet.cell(i, c1[1]+1).value == xlrd.empty_cell.value:
			r2.append([c1[0]+2, i])
			check = 1
			break
	if check == 0:
		r2.append([c1[0]+2, i+1])

l = len(r)
for tc in range(l):
	f = {}
	outp = open(f"181IT132_IT302_P5_Output_TC{tc+1}.txt", "a")
	for i in range(r[tc][0], r[tc][1]):
		for j in range(r2[tc][0], r2[tc][1]):
	   		f[str(int(sheet.cell_value(r2[tc][0]-1, i)))+"," +
			      str(int(sheet.cell_value(j, r[tc][0]-1)))] = sheet.cell_value(j, i)
	
	print(f"\nf(x,y) for TC {tc+1}: ", f)
	for i in f:
		if f[i] > 1:
			outp.write(f"\n Invalid! f({i}): "+str(f[i])+" is greater than 1")
			break
		print(f"f({i}) = {str(f[i])}")
		outp.write(f"f({i}) = {str(f[i])}\n")
	
	e = 0
	Mx = 0
	My = 0
	in_step=""
	mean_x=""
	mean_y=""
	for i in f:
		xy=i.split(",")
		x=int(xy[0])
		y=int(xy[1])
		ir=2*x*y*f[i]
		Mx+=x*f[i]
		My+=y*f[i]
		if in_step:
			in_step+=" + 2*"+str(x)+"*"+str(y)+"*"+str(f[i])
			mean_x+=" + "+str(x)+"*"+str(f[i])
			mean_y+=" + "+str(y)+"*"+str(f[i])
		else:
			in_step+="2*"+ str(x)+"*"+str(y)+"*"+str(f[i])
			mean_x+=str(x)+"*"+str(f[i])
			mean_y+=str(y)+"*"+str(f[i])
		e+=ir

	print(f"Expected value of X = {mean_x}")
	outp.write(f"Expected value of X = {mean_x}")
	print(f"Expected value of Y = {mean_y}")
	outp.write(f"\nExpected value of Y = {mean_y}")
	print("μX : "+str(Mx))
	outp.write(f"\nμX : "+str(Mx))
	print("μY : "+str(My))
	outp.write(f"\nμY : "+str(My))

	print(f"Expected value of g(X,Y) = {in_step}")
	outp.write(f"\nExpected value of g(X,Y) = {in_step}")
	print(f"Expected value of g(X,Y) = 2*X*Y = "+str(e))
	outp.write(f"\nExpected value of g(X,Y) = 2*X*Y = "+str(e))
	
	outp.close()
