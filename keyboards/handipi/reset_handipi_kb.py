import RPi.GPIO
import time

reset = 16
bootloader = 18

GPIO.setmode(GPIO.BOARD)
GPIO.setup(reset, GPIO.OUT)
GPIO.setup(bootloader, GPIO.OUT)

GPIO.output(reset, GPIO.LOW)
time.sleep(1)
GPIO.output(bootloader, GPIO.LOW)
time.sleep(1)
GPIO.output(reset, GPIO.HIGH)
time.sleep(1)

