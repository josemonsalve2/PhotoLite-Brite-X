import serial
import os.path
from time import time
from time import sleep
from PIL import Image
from System_Interface import *


def promptCommand():
	"""
		Prompt user for command
	"""
	probe = -1
	while probe < 0 or probe > 2 :
		print "\n0 - Select image and distance"
		print "1 - Start"
		print "2 - Exit"
		probe = int(raw_input("\nPick a number [0,2]: "))
		if probe < 0 or probe > 2 :
			print "\n\n!!! Bad input... try again !!!"
	return probe

def promptImageDist():
	"""
		Prompt user for image
	"""
	image_path = "null"
	while not os.path.isfile(image_path) :
		image_path = raw_input("\nEnter the path to your image: ")
		if not os.path.isfile(image_path) :
			print "\n\n!!! No such file... try again !!!"
	probe = -1
	while probe < 1 or probe > 70 :
		probe = int(raw_input("\nSelect a distance in meters [1,70]: "))
		if probe < 1 or probe > 70 :
			print "\n\n!!! Bad input... try again !!!"
	return (image_path, probe)


if __name__ == "__main__":
	
	print "Initializing FPGA interface"
#	s = SDK_System_interface(serial_port="/dev/ttyUSB0", baud_rate=9600,read_timeout = 1)		#115200
	s = SDK_System_interface(serial_port="/dev/ttyUSB0", baud_rate=115200,read_timeout = 1)		#115200
	s.port.flushInput()
	
	print "Resetting C Land's pixel buffer"
	s.send_packet(">0B");  # 0 bytes of data
	
	image = None
	width = None
	height = None
	
	# Define constants
	PROBE_IMAGE_DIST  = 0
	PROBE_START       = 1
	PROBE_EXIT        = 2
	RATIO_16x9    = 16/9
	IMAGE_HEIGHT  = 143
	AVG_INTERVAL_MS  = 58.59  # 256columns * 58.59milliseconds = 14.999seconds
	
	while 1 :
		
		# Prompt user for command
		probe = promptCommand()
		
		# User chose to select image
		if probe == PROBE_IMAGE_DIST :
			
			# Get pixels of image
			image_path_dist = promptImageDist()
			image_path = image_path_dist[0]
			image = Image.open(image_path)  # image.size[0] = width, image.size[1] = height
			width  = image.size[0]
			height = image.size[1]
			print "The image's dimensions are ", width, " by ", height, " (width by height)."
			
			if width/height != RATIO_16x9 :
				image = None
				print "\n\n!!! Invalid image aspect ratio. Must be 16:9."
			elif height != IMAGE_HEIGHT :
				#image = None
				print "\n\n!!! Invalid image height. Must be 143 pixels tall."
				

			# Get time interval
			leds_distance = image_path_dist[1]
			leds_time = width * AVG_INTERVAL_MS * 1000
			leds_speed = leds_distance / leds_time
			print "The distance for the LEDs stick to travel is ", leds_distance, " meters."
			print "It must take ", leds_time, " seconds to travel this distance."
			print "Therefore, the LEDs stick must travel at ", leds_speed, "m/s."
			
		elif probe == PROBE_START :
			
			if image is None :
				print "\n\n!!! You have not selected a valid image yet."
			else :
				# Start sending 
				pixels = image.load()
#				old_pixels = image.load()
#				img = Image.new("RGB", (width, height), "black")
#				pixels = img.load()
				for column in range(width) :
					for row in range(height) :
						if pixels[column,row][0] < 0 or pixels[column,row][0] > 255 :
							print "Pixel[",  column, ", ", row, "]'s Red is out of range (", pixels[column,row][0], "."
						if pixels[column,row][1] < 0 or pixels[column,row][1] > 255 :
							print "Pixel[",  column, ", ", row, "]'s Green is out of range (", pixels[column,row][0], "."
						if pixels[column,row][2] < 0 or pixels[column,row][2] > 255 :
							print "Pixel[",  column, ", ", row, "]'s Blue is out of range (", pixels[column,row][0], "."
#						pixels[column, row] = ( (int('{:08b}'.format(old_pixels[column, row][0])[::-1], 2)),
#								(int('{:08b}'.format(old_pixels[column, row][1])[::-1], 2)),
#								(int('{:08b}'.format(old_pixels[column, row][2])[::-1], 2)) )
				
				"""
					Traverses each column in the image.
						Transmits 84 pixels then 69 pixels (144 pixels) for each column.
						Waits for some specified amoutn of time (1 second for now)
							 before moving on to the next column.
					
				"""
				initial = time()
				start = time()
				leftover = 0
				for column in reversed(range(width)) :  # width = 256, height = 143
					
					# Transmit 80 pixels (240 bytes)
					s.send_packet(">241B",               # 241 bytes of data (command + 80 pixels)
					              1,                     # Command (Transmitting first batch of pixels)
					              pixels[column, 0][0],   # Read Pixel 1's Red Value
					              pixels[column, 0][1],   # Read Pixel 1's Green Value
					              pixels[column, 0][2],   # Read Pixel 1's Blue Value
					              pixels[column, 1][0],   #  R
					              pixels[column, 1][1],   #  G
					              pixels[column, 1][2],   #  B
					              pixels[column, 2][0],   #   R
					              pixels[column, 2][1],   #   G
					              pixels[column, 2][2],   #   B
					              pixels[column, 3][0],   #    R
					              pixels[column, 3][1],   #    G
					              pixels[column, 3][2],   #    B
					              pixels[column, 4][0],   #     R
					              pixels[column, 4][1],   #     G
					              pixels[column, 4][2],   #     B
					              pixels[column, 5][0],   #      R
					              pixels[column, 5][1],   #      G
					              pixels[column, 5][2],   #      B
					              pixels[column, 6][0],   #       R
					              pixels[column, 6][1],   #       G
					              pixels[column, 6][2],   #       B
					              pixels[column, 7][0],   #        R
					              pixels[column, 7][1],   #        G
					              pixels[column, 7][2],   #        B
					              pixels[column, 8][0],   #         R
					              pixels[column, 8][1],   #         G
					              pixels[column, 8][2],   #         B
					              pixels[column, 9][0],   #          R
					              pixels[column, 9][1],   #          G
					              pixels[column, 9][2],   #          B
					              
					              pixels[column, 10][0],  # R
					              pixels[column, 10][1],  # G
					              pixels[column, 10][2],  # B
					              pixels[column, 11][0],  #  R
					              pixels[column, 11][1],  #  G
					              pixels[column, 11][2],  #  B
					              pixels[column, 12][0],  #   R
					              pixels[column, 12][1],  #   G
					              pixels[column, 12][2],  #   B
					              pixels[column, 13][0],  #    R
					              pixels[column, 13][1],  #    G
					              pixels[column, 13][2],  #    B
					              pixels[column, 14][0],  #     R
					              pixels[column, 14][1],  #     G
					              pixels[column, 14][2],  #     B
					              pixels[column, 15][0],  #      R
					              pixels[column, 15][1],  #      G
					              pixels[column, 15][2],  #      B
					              pixels[column, 16][0],  #       R
					              pixels[column, 16][1],  #       G
					              pixels[column, 16][2],  #       B
					              pixels[column, 17][0],  #        R
					              pixels[column, 17][1],  #        G
					              pixels[column, 17][2],  #        B
					              pixels[column, 18][0],  #         R
					              pixels[column, 18][1],  #         G
					              pixels[column, 18][2],  #         B
					              pixels[column, 19][0],  #          R
					              pixels[column, 19][1],  #          G
					              pixels[column, 19][2],  #          B
					              
					              pixels[column, 20][0],  # R
					              pixels[column, 20][1],  # G
					              pixels[column, 20][2],  # B
					              pixels[column, 21][0],  #  R
					              pixels[column, 21][1],  #  G
					              pixels[column, 21][2],  #  B
					              pixels[column, 22][0],  #   R
					              pixels[column, 22][1],  #   G
					              pixels[column, 22][2],  #   B
					              pixels[column, 23][0],  #    R
					              pixels[column, 23][1],  #    G
					              pixels[column, 23][2],  #    B
					              pixels[column, 24][0],  #     R
					              pixels[column, 24][1],  #     G
					              pixels[column, 24][2],  #     B
					              pixels[column, 25][0],  #      R
					              pixels[column, 25][1],  #      G
					              pixels[column, 25][2],  #      B
					              pixels[column, 26][0],  #       R
					              pixels[column, 26][1],  #       G
					              pixels[column, 26][2],  #       B
					              pixels[column, 27][0],  #        R
					              pixels[column, 27][1],  #        G
					              pixels[column, 27][2],  #        B
					              pixels[column, 28][0],  #         R
					              pixels[column, 28][1],  #         G
					              pixels[column, 28][2],  #         B
					              pixels[column, 29][0],  #          R
					              pixels[column, 29][1],  #          G
					              pixels[column, 29][2],  #          B
					              
					              pixels[column, 30][0],  # R
					              pixels[column, 30][1],  # G
					              pixels[column, 30][2],  # B
					              pixels[column, 31][0],  #  R
					              pixels[column, 31][1],  #  G
					              pixels[column, 31][2],  #  B
					              pixels[column, 32][0],  #   R
					              pixels[column, 32][1],  #   G
					              pixels[column, 32][2],  #   B
					              pixels[column, 33][0],  #    R
					              pixels[column, 33][1],  #    G
					              pixels[column, 33][2],  #    B
					              pixels[column, 34][0],  #     R
					              pixels[column, 34][1],  #     G
					              pixels[column, 34][2],  #     B
					              pixels[column, 35][0],  #      R
					              pixels[column, 35][1],  #      G
					              pixels[column, 35][2],  #      B
					              pixels[column, 36][0],  #       R
					              pixels[column, 36][1],  #       G
					              pixels[column, 36][2],  #       B
					              pixels[column, 37][0],  #        R
					              pixels[column, 37][1],  #        G
					              pixels[column, 37][2],  #        B
					              pixels[column, 38][0],  #         R
					              pixels[column, 38][1],  #         G
					              pixels[column, 38][2],  #         B
					              pixels[column, 39][0],  #          R
					              pixels[column, 39][1],  #          G
					              pixels[column, 39][2],  #          B
					              
					              pixels[column, 40][0],  # R
					              pixels[column, 40][1],  # G
					              pixels[column, 40][2],  # B
					              pixels[column, 41][0],  #  R
					              pixels[column, 41][1],  #  G
					              pixels[column, 41][2],  #  B
					              pixels[column, 42][0],  #   R
					              pixels[column, 42][1],  #   G
					              pixels[column, 42][2],  #   B
					              pixels[column, 43][0],  #    R
					              pixels[column, 43][1],  #    G
					              pixels[column, 43][2],  #    B
					              pixels[column, 44][0],  #     R
					              pixels[column, 44][1],  #     G
					              pixels[column, 44][2],  #     B
					              pixels[column, 45][0],  #      R
					              pixels[column, 45][1],  #      G
					              pixels[column, 45][2],  #      B
					              pixels[column, 46][0],  #       R
					              pixels[column, 46][1],  #       G
					              pixels[column, 46][2],  #       B
					              pixels[column, 47][0],  #        R
					              pixels[column, 47][1],  #        G
					              pixels[column, 47][2],  #        B
					              pixels[column, 48][0],  #         R
					              pixels[column, 48][1],  #         G
					              pixels[column, 48][2],  #         B
					              pixels[column, 49][0],  #          R
					              pixels[column, 49][1],  #          G
					              pixels[column, 49][2],  #          B
					              
					              pixels[column, 50][0],  # R
					              pixels[column, 50][1],  # G
					              pixels[column, 50][2],  # B
					              pixels[column, 51][0],  #  R
					              pixels[column, 51][1],  #  G
					              pixels[column, 51][2],  #  B
					              pixels[column, 52][0],  #   R
					              pixels[column, 52][1],  #   G
					              pixels[column, 52][2],  #   B
					              pixels[column, 53][0],  #    R
					              pixels[column, 53][1],  #    G
					              pixels[column, 53][2],  #    B
					              pixels[column, 54][0],  #     R
					              pixels[column, 54][1],  #     G
					              pixels[column, 54][2],  #     B
					              pixels[column, 55][0],  #      R
					              pixels[column, 55][1],  #      G
					              pixels[column, 55][2],  #      B
					              pixels[column, 56][0],  #       R
					              pixels[column, 56][1],  #       G
					              pixels[column, 56][2],  #       B
					              pixels[column, 57][0],  #        R
					              pixels[column, 57][1],  #        G
					              pixels[column, 57][2],  #        B
					              pixels[column, 58][0],  #         R
					              pixels[column, 58][1],  #         G
					              pixels[column, 58][2],  #         B
					              pixels[column, 59][0],  #          R
					              pixels[column, 59][1],  #          G
					              pixels[column, 59][2],  #          B
					              
					              pixels[column, 60][0],  # R
					              pixels[column, 60][1],  # G
					              pixels[column, 60][2],  # B
					              pixels[column, 61][0],  #  R
					              pixels[column, 61][1],  #  G
					              pixels[column, 61][2],  #  B
					              pixels[column, 62][0],  #   R
					              pixels[column, 62][1],  #   G
					              pixels[column, 62][2],  #   B
					              pixels[column, 63][0],  #    R
					              pixels[column, 63][1],  #    G
					              pixels[column, 63][2],  #    B
					              pixels[column, 64][0],  #     R
					              pixels[column, 64][1],  #     G
					              pixels[column, 64][2],  #     B
					              pixels[column, 65][0],  #      R
					              pixels[column, 65][1],  #      G
					              pixels[column, 65][2],  #      B
					              pixels[column, 66][0],  #       R
					              pixels[column, 66][1],  #       G
					              pixels[column, 66][2],  #       B
					              pixels[column, 67][0],  #        R
					              pixels[column, 67][1],  #        G
					              pixels[column, 67][2],  #        B
					              pixels[column, 68][0],  #         R
					              pixels[column, 68][1],  #         G
					              pixels[column, 68][2],  #         B
					              pixels[column, 69][0],  #          R
					              pixels[column, 69][1],  #          G
					              pixels[column, 69][2],  #          B
					              
					              pixels[column, 70][0],  # R
					              pixels[column, 70][1],  # G
					              pixels[column, 70][2],  # B
					              pixels[column, 71][0],  #  R
					              pixels[column, 71][1],  #  G
					              pixels[column, 71][2],  #  B
					              pixels[column, 72][0],  #   R
					              pixels[column, 72][1],  #   G
					              pixels[column, 72][2],  #   B
					              pixels[column, 73][0],  #    R
					              pixels[column, 73][1],  #    G
					              pixels[column, 73][2],  #    B
					              pixels[column, 74][0],  #     R
					              pixels[column, 74][1],  #     G
					              pixels[column, 74][2],  #     B
					              pixels[column, 75][0],  #      R
					              pixels[column, 75][1],  #      G
					              pixels[column, 75][2],  #      B
					              pixels[column, 76][0],  #       R
					              pixels[column, 76][1],  #       G
					              pixels[column, 76][2],  #       B
					              pixels[column, 77][0],  #        R
					              pixels[column, 77][1],  #        G
					              pixels[column, 77][2],  #        B
					              pixels[column, 78][0],  #         R
					              pixels[column, 78][1],  #         G
					              pixels[column, 78][2],  #         B
					              pixels[column, 79][0],  #          R
					              pixels[column, 79][1],  #          G
					              pixels[column, 79][2])  #          B
					 
					#s.send_packet(">0B");  # 0 bytes of data
					sleep(0.005)

					#s.port.flushInput()
					# Transmit 63 pixels (189 bytes)
					s.send_packet(">190B",                 # 190 bytes of data (command + 63 pixels)
					              2,                       # Command (Transmitting first batch of pixels)
					              pixels[column, 80][0],   # Read Pixel 83's Red Value
					              pixels[column, 80][1],   # Read Pixel 83's Green Value
					              pixels[column, 80][2],   # Read Pixel 83's Blue Value
					              pixels[column, 81][0],   #  R
					              pixels[column, 81][1],   #  G
					              pixels[column, 81][2],   #  B
					              pixels[column, 82][0],   #   R
					              pixels[column, 82][1],   #   G
					              pixels[column, 82][2],   #   B
					              pixels[column, 83][0],   #    R
					              pixels[column, 83][1],   #    G
					              pixels[column, 83][2],   #    B
					              pixels[column, 84][0],   #     R
					              pixels[column, 84][1],   #     G
					              pixels[column, 84][2],   #     B
					              pixels[column, 85][0],   #      R
					              pixels[column, 85][1],   #      G
					              pixels[column, 85][2],   #      B
					              pixels[column, 86][0],   #       R
					              pixels[column, 86][1],   #       G
					              pixels[column, 86][2],   #       B
					              pixels[column, 87][0],   #        R
					              pixels[column, 87][1],   #        G
					              pixels[column, 87][2],   #        B
					              pixels[column, 88][0],   #         R
					              pixels[column, 88][1],   #         G
					              pixels[column, 88][2],   #         B
					              pixels[column, 89][0],   #          R
					              pixels[column, 89][1],   #          G
					              pixels[column, 89][2],   #          B
					              
					              pixels[column, 90][0],   # R
					              pixels[column, 90][1],   # G
					              pixels[column, 90][2],   # B
					              pixels[column, 91][0],   #  R
					              pixels[column, 91][1],   #  G
					              pixels[column, 91][2],   #  B
					              pixels[column, 92][0],   #   R
					              pixels[column, 92][1],   #   G
					              pixels[column, 92][2],   #   B
					              pixels[column, 93][0],   #    R
					              pixels[column, 93][1],   #    G
					              pixels[column, 93][2],   #    B
					              pixels[column, 94][0],   #     R
					              pixels[column, 94][1],   #     G
					              pixels[column, 94][2],   #     B
					              pixels[column, 95][0],   #      R
					              pixels[column, 95][1],   #      G
					              pixels[column, 95][2],   #      B
					              pixels[column, 96][0],   #       R
					              pixels[column, 96][1],   #       G
					              pixels[column, 96][2],   #       B
					              pixels[column, 97][0],   #        R
					              pixels[column, 97][1],   #        G
					              pixels[column, 97][2],   #        B
					              pixels[column, 98][0],   #         R
					              pixels[column, 98][1],   #         G
					              pixels[column, 98][2],   #         B
					              pixels[column, 99][0],   #          R
					              pixels[column, 99][1],   #          G
					              pixels[column, 99][2],   #          B
					              
					              pixels[column, 100][0],  # R
					              pixels[column, 100][1],  # G
					              pixels[column, 100][2],  # B
					              pixels[column, 101][0],  #  R
					              pixels[column, 101][1],  #  G
					              pixels[column, 101][2],  #  B
					              pixels[column, 102][0],  #   R
					              pixels[column, 102][1],  #   G
					              pixels[column, 102][2],  #   B
					              pixels[column, 103][0],  #    R
					              pixels[column, 103][1],  #    G
					              pixels[column, 103][2],  #    B
					              pixels[column, 104][0],  #     R
					              pixels[column, 104][1],  #     G
					              pixels[column, 104][2],  #     B
					              pixels[column, 105][0],  #      R
					              pixels[column, 105][1],  #      G
					              pixels[column, 105][2],  #      B
					              pixels[column, 106][0],  #       R
					              pixels[column, 106][1],  #       G
					              pixels[column, 106][2],  #       B
					              pixels[column, 107][0],  #        R
					              pixels[column, 107][1],  #        G
					              pixels[column, 107][2],  #        B
					              pixels[column, 108][0],  #         R
					              pixels[column, 108][1],  #         G
					              pixels[column, 108][2],  #         B
					              pixels[column, 109][0],  #          R
					              pixels[column, 109][1],  #          G
					              pixels[column, 109][2],  #          B
					              
					              pixels[column, 110][0],  # R
					              pixels[column, 110][1],  # G
					              pixels[column, 110][2],  # B
					              pixels[column, 111][0],  #  R
					              pixels[column, 111][1],  #  G
					              pixels[column, 111][2],  #  B
					              pixels[column, 112][0],  #   R
					              pixels[column, 112][1],  #   G
					              pixels[column, 112][2],  #   B
					              pixels[column, 113][0],  #    R
					              pixels[column, 113][1],  #    G
					              pixels[column, 113][2],  #    B
					              pixels[column, 114][0],  #     R
					              pixels[column, 114][1],  #     G
					              pixels[column, 114][2],  #     B
					              pixels[column, 115][0],  #      R
					              pixels[column, 115][1],  #      G
					              pixels[column, 115][2],  #      B
					              pixels[column, 116][0],  #       R
					              pixels[column, 116][1],  #       G
					              pixels[column, 116][2],  #       B
					              pixels[column, 117][0],  #        R
					              pixels[column, 117][1],  #        G
					              pixels[column, 117][2],  #        B
					              pixels[column, 118][0],  #         R
					              pixels[column, 118][1],  #         G
					              pixels[column, 118][2],  #         B
					              pixels[column, 119][0],  #          R
					              pixels[column, 119][1],  #          G
					              pixels[column, 119][2],  #          B
					              
					              pixels[column, 120][0],  # R
					              pixels[column, 120][1],  # G
					              pixels[column, 120][2],  # B
					              pixels[column, 121][0],  #  R
					              pixels[column, 121][1],  #  G
					              pixels[column, 121][2],  #  B
					              pixels[column, 122][0],  #   R
					              pixels[column, 122][1],  #   G
					              pixels[column, 122][2],  #   B
					              pixels[column, 123][0],  #    R
					              pixels[column, 123][1],  #    G
					              pixels[column, 123][2],  #    B
					              pixels[column, 124][0],  #     R
					              pixels[column, 124][1],  #     G
					              pixels[column, 124][2],  #     B
					              pixels[column, 125][0],  #      R
					              pixels[column, 125][1],  #      G
					              pixels[column, 125][2],  #      B
					              pixels[column, 126][0],  #       R
					              pixels[column, 126][1],  #       G
					              pixels[column, 126][2],  #       B
					              pixels[column, 127][0],  #        R
					              pixels[column, 127][1],  #        G
					              pixels[column, 127][2],  #        B
					              pixels[column, 128][0],  #         R
					              pixels[column, 128][1],  #         G
					              pixels[column, 128][2],  #         B
					              pixels[column, 129][0],  #          R
					              pixels[column, 129][1],  #          G
					              pixels[column, 129][2],  #          B
					              
					              pixels[column, 130][0],  # R
					              pixels[column, 130][1],  # G
					              pixels[column, 130][2],  # B
					              pixels[column, 131][0],  #  R
					              pixels[column, 131][1],  #  G
					              pixels[column, 131][2],  #  B
					              pixels[column, 132][0],  #   R
					              pixels[column, 132][1],  #   G
					              pixels[column, 132][2],  #   B
					              pixels[column, 133][0],  #    R
					              pixels[column, 133][1],  #    G
					              pixels[column, 133][2],  #    B
					              pixels[column, 134][0],  #     R
					              pixels[column, 134][1],  #     G
					              pixels[column, 134][2],  #     B
					              pixels[column, 135][0],  #      R
					              pixels[column, 135][1],  #      G
					              pixels[column, 135][2],  #      B
					              pixels[column, 136][0],  #       R
					              pixels[column, 136][1],  #       G
					              pixels[column, 136][2],  #       B
					              pixels[column, 137][0],  #        R
					              pixels[column, 137][1],  #        G
					              pixels[column, 137][2],  #        B
					              pixels[column, 138][0],  #         R
					              pixels[column, 138][1],  #         G
					              pixels[column, 138][2],  #         B
					              pixels[column, 139][0],  #          R
					              pixels[column, 139][1],  #          G
					              pixels[column, 139][2],  #          B
					              
					              pixels[column, 140][0],  # R
					              pixels[column, 140][1],  # G
					              pixels[column, 140][2],  # B
					              pixels[column, 141][0],  #  R
					              pixels[column, 141][1],  #  G
					              pixels[column, 141][2],  #  B
					              pixels[column, 142][0],  #   R
					              pixels[column, 142][1],  #   G
					              pixels[column, 142][2])  #   B
					
					sleep(0.005)
					
					end = time()
					elapsed = end - start
					if (elapsed * 1000) > AVG_INTERVAL_MS :
						print "UART took too long."
				#		#leftover = elapsed - AVG_INTERVAL_S
					else :
		#			#	leftover = 0
						sleep((AVG_INTERVAL_MS - (elapsed * 1000)) / 1000 )  # Sleep for amount of seconds left in pixel interval
					start = time()
					print "elapsed=", (elapsed * 1000)  # for debugging. Averages 460 ms
					
				# end of for loop
				final = time()
				print "transmission time=", (final-initial)
				print "average transmission=", (final-initial)/width
				s.send_packet(">0B");  # 0 bytes of data
			# end of else
		elif probe == PROBE_EXIT :
			# Exit python script
			break;
			
		else :
			print "\n\n!!! Invalid input (undefined behavior) !!!"
			
		
	
	# Reset C Land's pixel buffer
	s.send_packet(">0B");  # 0 bytes of data
	
