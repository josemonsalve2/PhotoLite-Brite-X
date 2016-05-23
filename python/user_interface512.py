import serial
import os.path
from time import time
from time import sleep
from PIL import Image
from System_Interface512 import *


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

def combine_colors(pixel) :
	return (pixel[0] << 16) + (pixel[1] << 8) + (pixel[2])


if __name__ == "__main__":
	
	print "Initializing FPGA interface"
	s = SDK_System_interface512(serial_port="/dev/ttyUSB0", baud_rate=9600,read_timeout = 1)		#115200
#	s = SDK_System_interface512(serial_port="/dev/ttyUSB0", baud_rate=115200,read_timeout = 1)		#115200
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
	AVG_INTERVAL_S  = 0.5
	
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
				image = None
				print "\n\n!!! Invalid image height. Must be 143 pixels tall."
				
			
			# Get time interval
			leds_distance = image_path_dist[1]
			leds_time = width * AVG_INTERVAL_S
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
#				for column in range(width) :
#					for row in range(height) :
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
				for column in range(width) :  # width = 256, height = 143
					
					# Transmit 143 pixels (143*4 bytes)

					s.send_packet(">144I",                 # 144 * 4 bytes of data (command + 143 pixels)
					              1,                       # Command (Transmitting first batch of pixels)
					              
					              combine_colors(pixels[column, 0]),    # Pixel 1
					              combine_colors(pixels[column, 1]),
					              combine_colors(pixels[column, 2]),
					              combine_colors(pixels[column, 3]),
					              combine_colors(pixels[column, 4]),
					              combine_colors(pixels[column, 5]),
					              combine_colors(pixels[column, 6]),
					              combine_colors(pixels[column, 7]),
					              combine_colors(pixels[column, 8]),
					              combine_colors(pixels[column, 9]),    # Pixel 10
					              combine_colors(pixels[column, 10]),
					              combine_colors(pixels[column, 11]),
					              combine_colors(pixels[column, 12]),
					              combine_colors(pixels[column, 13]),
					              combine_colors(pixels[column, 14]),
					              combine_colors(pixels[column, 15]),
					              combine_colors(pixels[column, 16]),
					              combine_colors(pixels[column, 17]),
					              combine_colors(pixels[column, 18]),
					              combine_colors(pixels[column, 19]),   # Pixel 20
					              combine_colors(pixels[column, 20]),
					              combine_colors(pixels[column, 21]),
					              combine_colors(pixels[column, 22]),
					              combine_colors(pixels[column, 23]),
					              combine_colors(pixels[column, 24]),
					              combine_colors(pixels[column, 25]),
					              combine_colors(pixels[column, 26]),
					              combine_colors(pixels[column, 27]),
					              combine_colors(pixels[column, 28]),
					              combine_colors(pixels[column, 29]),   # Pixel 30
					              combine_colors(pixels[column, 30]),
					              combine_colors(pixels[column, 31]),
					              combine_colors(pixels[column, 32]),
					              combine_colors(pixels[column, 33]),
					              combine_colors(pixels[column, 34]),
					              combine_colors(pixels[column, 35]),
					              combine_colors(pixels[column, 36]),
					              combine_colors(pixels[column, 37]),
					              combine_colors(pixels[column, 38]),
					              combine_colors(pixels[column, 39]),   # Pixel 40
					              combine_colors(pixels[column, 40]),
					              combine_colors(pixels[column, 41]),
					              combine_colors(pixels[column, 42]),
					              combine_colors(pixels[column, 43]),
					              combine_colors(pixels[column, 44]),
					              combine_colors(pixels[column, 45]),
					              combine_colors(pixels[column, 46]),
					              combine_colors(pixels[column, 47]),
					              combine_colors(pixels[column, 48]),
					              combine_colors(pixels[column, 49]),   # Pixel 50
					              combine_colors(pixels[column, 50]),
					              combine_colors(pixels[column, 51]),
					              combine_colors(pixels[column, 52]),
					              combine_colors(pixels[column, 53]),
					              combine_colors(pixels[column, 54]),
					              combine_colors(pixels[column, 55]),
					              combine_colors(pixels[column, 56]),
					              combine_colors(pixels[column, 57]),
					              combine_colors(pixels[column, 58]),
					              combine_colors(pixels[column, 59]),   # Pixel 60
					              combine_colors(pixels[column, 60]),
					              combine_colors(pixels[column, 61]),
					              combine_colors(pixels[column, 62]),
					              combine_colors(pixels[column, 63]),
					              combine_colors(pixels[column, 64]),
					              combine_colors(pixels[column, 65]),
					              combine_colors(pixels[column, 66]),
					              combine_colors(pixels[column, 67]),
					              combine_colors(pixels[column, 68]),
					              combine_colors(pixels[column, 69]),   # Pixel 70
					              combine_colors(pixels[column, 70]),
					              combine_colors(pixels[column, 71]),
					              combine_colors(pixels[column, 72]),
					              combine_colors(pixels[column, 73]),
					              combine_colors(pixels[column, 74]),
					              combine_colors(pixels[column, 75]),
					              combine_colors(pixels[column, 76]),
					              combine_colors(pixels[column, 77]),
					              combine_colors(pixels[column, 78]),
					              combine_colors(pixels[column, 79]),   # Pixel 80
					              combine_colors(pixels[column, 80]),
					              combine_colors(pixels[column, 81]),
					              combine_colors(pixels[column, 82]),
					              combine_colors(pixels[column, 83]),
					              combine_colors(pixels[column, 84]),
					              combine_colors(pixels[column, 85]),
					              combine_colors(pixels[column, 86]),
					              combine_colors(pixels[column, 87]),
					              combine_colors(pixels[column, 88]),
					              combine_colors(pixels[column, 89]),   # Pixel 90
					              combine_colors(pixels[column, 90]),
					              combine_colors(pixels[column, 91]),
					              combine_colors(pixels[column, 92]),
					              combine_colors(pixels[column, 93]),
					              combine_colors(pixels[column, 94]),
					              combine_colors(pixels[column, 95]),
					              combine_colors(pixels[column, 96]),
					              combine_colors(pixels[column, 97]),
					              combine_colors(pixels[column, 98]),
					              combine_colors(pixels[column, 99]),   # Pixel 100
					              combine_colors(pixels[column, 100]),
					              combine_colors(pixels[column, 101]),
					              combine_colors(pixels[column, 102]),
					              combine_colors(pixels[column, 103]),
					              combine_colors(pixels[column, 104]),
					              combine_colors(pixels[column, 105]),
					              combine_colors(pixels[column, 106]),
					              combine_colors(pixels[column, 107]),
					              combine_colors(pixels[column, 108]),
					              combine_colors(pixels[column, 109]),  # Pixel 110
					              combine_colors(pixels[column, 110]),
					              combine_colors(pixels[column, 111]),
					              combine_colors(pixels[column, 112]),
					              combine_colors(pixels[column, 113]),
					              combine_colors(pixels[column, 114]),
					              combine_colors(pixels[column, 115]),
					              combine_colors(pixels[column, 116]),
					              combine_colors(pixels[column, 117]),
					              combine_colors(pixels[column, 118]),
					              combine_colors(pixels[column, 119]),   # Pixel 120
					              combine_colors(pixels[column, 120]),
					              combine_colors(pixels[column, 121]),
					              combine_colors(pixels[column, 122]),
					              combine_colors(pixels[column, 123]),
					              combine_colors(pixels[column, 124]),
					              combine_colors(pixels[column, 125]),
					              combine_colors(pixels[column, 126]),
					              combine_colors(pixels[column, 127]),
					              combine_colors(pixels[column, 128]),
					              combine_colors(pixels[column, 129]),  # Pixel 130
					              combine_colors(pixels[column, 130]),
					              combine_colors(pixels[column, 131]),
					              combine_colors(pixels[column, 132]),
					              combine_colors(pixels[column, 133]),
					              combine_colors(pixels[column, 134]),
					              combine_colors(pixels[column, 135]),
					              combine_colors(pixels[column, 136]),
					              combine_colors(pixels[column, 137]),
					              combine_colors(pixels[column, 138]),
					              combine_colors(pixels[column, 139]),  # Pixel 140
					              combine_colors(pixels[column, 140]),
					              combine_colors(pixels[column, 141]),
					              combine_colors(pixels[column, 142]) )
					
					end = time()
					elapsed = end - start + leftover
					if elapsed > AVG_INTERVAL_S :
						print "UART took too long."
						#leftover = elapsed - AVG_INTERVAL_S
					else :
						leftover = 0
						sleep(AVG_INTERVAL_S - elapsed)  # Sleep for amount of seconds left in pixel interval
						start = time()
					#print "elapsed=", elapsed  # for debugging. Averages 460 ms
					
				# end of for loop
				final = time()
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
	
