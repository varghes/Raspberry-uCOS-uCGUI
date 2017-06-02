# Raspberry-uCOS-uCGUI


Note : This software is given here purely for academic purpose , So Kindly contact sales@micrium.com   , If you decided to use uC/OS or uC/GUI in your product, refer their license terms ..   The work I have done (Raspberry Porting ) is distributed under MIT license ..  This software is given here with the intention that it can useful to learn both these products.  


What is working  (Raspberry B+ BCM2835 only)

1. Kernel 
2. GUI  
3. You can access  peripherals(I2C/SPI/GPIO ) using Baremetal code
4. SPI-Touch  - planned , but not implemented 
5. USB -Mouse ( included csud driver - not working fully)
6. Repaint of screen requires some fix

Compiling it on Windows 

1.download  gcc-arm-none-eabi-4_7-2013q3-20130916-win32.exe  ( I am using this version)
while installing uncheck environment variable option . 
2.  Go to  C:\Program Files (x86)\GNU Tools ARM Embedded\4.7 2013q3\bin     " gccvar.bat"  run this file .
3. cd "project directory"   then "make " 
4.image size defined here is  uCGUI\Config\LCDConf.h   800x480 , change is according to your screen

Running 

Copy the kernel.img to SD code & replace the existing one .
