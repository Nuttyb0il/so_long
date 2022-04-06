from tkinter import *
from PIL import Image, ImageTk
import os

images = [
	"images/madeline.png",
	"images/seed.png",
	"images/berry.png",
	"images/ice.png",
	"images/wall.png",
]

size = input("Size of the map (NxN): ")
height = int(size.split("x")[0])
width = int(size.split("x")[1])

# create a gui
root = Tk()
root.title("Create a {} Map".format(size))
root.geometry("{}x{}".format(135 + (width * 64), 350 + (height * 64)))

SELECTED_IMAGE = None
MAP_CANVAS = None
def map_coord(x, y):
	"""
	Take a click on the window
	:param x: x coordinate of the click
	:param y: y coordinate of the click
	:return: the map coordinates of the click
	"""
	return int(x / 64), int(y / 64)

def select_ice(event):
	global SELECTED_IMAGE
	SELECTED_IMAGE = "images/ice.png"

def select_wall(event):
	global SELECTED_IMAGE
	SELECTED_IMAGE = "images/wall.png"

def select_seed(event):
	global SELECTED_IMAGE
	SELECTED_IMAGE = "images/seed.png"

def select_madeline(event):
	global SELECTED_IMAGE
	SELECTED_IMAGE = "images/madeline.png"

def select_berry(event):
	global SELECTED_IMAGE
	SELECTED_IMAGE = "images/berry.png"

def set_sprite(event):
	global SELECTED_IMAGE, MAP_CANVAS
	x, y = map_coord(event.x, event.y)
	print("Clicked on {}".format((x, y)))
	# render image on canvas x, y
	print(SELECTED_IMAGE, x * 64, y * 64)
	MAP_CANVAS.create_image(x * 64, y * 64, image=ImageTk.PhotoImage(Image.open(SELECTED_IMAGE)))
	MAP_CANVAS.update()

# add 5 buttons with images, add text
for i in range(len(images)):
	img = PhotoImage(file=images[i])
	btn = Button(root, image=img)
	btn.image = img
	btn.grid(row=i, column=0)
	# text
	txt = Label(root, text=os.path.basename(images[i]).split(".")[0].title())
	txt.grid(row=i, column=1)
	# btn click
	if i == 0:
		btn.bind("<Button-1>", select_madeline)
	elif i == 1:
		btn.bind("<Button-1>", select_seed)
	elif i == 2:
		btn.bind("<Button-1>", select_berry)
	elif i == 3:
		btn.bind("<Button-1>", select_ice)
	elif i == 4:
		btn.bind("<Button-1>", select_wall)

# add a canvas where user can draw
canvas = Canvas(root, width=width * 64, height=height * 64)
canvas.grid(row=0, column=2, rowspan=5)
MAP_CANVAS = canvas

# fill canvas with images/ice.png
ice = PhotoImage(file="images/ice.png")
wall = PhotoImage(file="images/wall.png")
for i in range(1, height):
	for j in range(1, width):
		print(i*64, j*64)
		if i == 1 or i == height - 1 or j == 1 or j == width - 1:
			canvas.create_image(i*64, j*64, image=wall)
		else:
			canvas.create_image(i*64, j*64, image=ice)

# bind click on canvas
canvas.bind("<Button-1>", set_sprite)
# show the gui
root.mainloop()