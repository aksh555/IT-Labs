from PIL import Image
im=Image.open('Kitten.jpg','r')
pix_val=list(im.getdata())
print(pix_val)
pix_val_flat=[x for sets in pix_val for x in sets]
f=open("KittenRGB.txt","w")
count=0
for i in pix_val_flat:
     f.write("%d " %i)
#f=open("EarthRGB.txt","r")
#fl=f.readlines()
#for x in fl:
    #print(x)
     
