from pygame.locals import *
import pygame, sys, math, random, time
import matplotlib.pyplot as plt
import itertools

pygame.init()
XX = 1300
YY = 600
scr = pygame.display.set_mode((XX, YY))
pygame.display.set_caption("Fitts' Test")
#white = 215,215,250
white = 119,229,196
times = []
dist = []
width = []
count = 0

total = 22
xx = random.sample(range(5,XX-5), total+1)
yy = random.sample(range(5,YY-5), total+1)
rr = random.sample(range(5,80), total+1)

def plot(x, z, y):
    nx1, ny1 = zip(*sorted(zip(x, y)))
    nx2, ny2 = zip(*sorted(zip(z, y)))
    plt.subplot(1, 2, 1)
    plt.plot(nx1, ny1, "-ro")    
    plt.title('Response Time vs Target Dist')
    plt.xlabel("Target Dist")
    plt.ylabel("Response time (s)")
    plt.subplot(1, 2, 2)
    plt.plot(nx2, ny2, "-bo")
    plt.xlabel("Target Width")
    plt.title('Response Time vs Target Size')
    plt.savefig("Response times.png")
    
def tgt_distance(x,y,mx,my):
    return math.sqrt((x - mx)**2 + (y - my)**2)

def add_circle(count,mx,my):
    scr.fill(white)
    x = xx[count]
    y = yy[count]
    r = rr[count]
    color = (random.randint(5,200),random.randint(1,200),random.randint(1,200))
    D = tgt_distance(x,y,mx,my)
    pygame.draw.circle(scr, color, (x,y), r)
    pygame.display.update()
    start = time.time()
    return D, r, color, start

mx, my = pygame.mouse.get_pos()
D, r, cid, start = add_circle(count,mx,my)

while True:
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONDOWN:
            click = scr.get_at(pygame.mouse.get_pos()) == cid
            if click:
                times.append(time.time() - start)
                dist.append(D)
                width.append(2*r)                
                mx, my = pygame.mouse.get_pos()
                count+=1
                D, r , cid, start = add_circle(count,mx,my)
    
        if count==total or event.type == QUIT:
            plot(dist[1:], width[1:], times[1:])
            pygame.quit()
            sys.exit()
