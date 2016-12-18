# STM32F429-Nucleo LWIP FREERTOS TrueSTUDIO STM32CubeMX
This is a template lwIP and FreeRTOS project for the STM32F429-Nucleo (NUCLEO-F429ZI) board using STM32CubeMX and TrueSTUDIO.
The website example I found on: http://www.carminenoviello.com/2016/01/22/getting-started-stm32-nucleo-f746zg
Software versions I used (all on windows):
* Atollic TrueSTUDIO 7.0.0
* STM32CubeMX Version 4.18.0
* STM32CubeF4 Firmware Package V1.14.0
## Tutorial:
In STM32CubeMX:
* New project
* Select STM32f429 Nucleo board (and also select "Initialize all IP with their default mode")
* Generate the project
* On pinout tab: click on pin PB0 and select "GPIO_Output", right click the same pin -> enter user label and name it: "LD1 [Green]"
* Add FreeRTOS and LWIP
* opt: On config tab select LWIP and change (in General Settings tab) DHCP from Enabled to Disabled and set the IP address settings to the correct values. (I used 192.168.2.81 255.255.255.0 192.168.2.254)
* On config tab select LWIP and add (in User Constants tab) a constant "LWIP_TIMEVAL_PRIVATE" with value "0" (both without quotation marks)
* You can now generate the code. (If using Truestudio I put the code directly into my workspace)
    Settings I change:
    - Toolchain/IDE -> Truestudio
    - Turn on "Generate peripheral initialization as a pair of '.c/.h' files per peripheral"
* After generating the code STM32CubeMX asks if you want to open the project, click open project.

In Atollic Truestudio:
* Build project, if everything is set correctly build finishes without errors or warnings.
* Start debug/program the code into your board. (Don't forget to run the code if you use debugger)
* You should now be able to ping the board. (example on windows: open cmd and type: ping 192.168.2.81)
* add httpserver-netconn.c and temp.c to src folder
* add httpserver-netconn.h and temp.h to inc folder
* in Src/freertos.c:
    - Add #include "httpserver-netconn.h" just after USER CODE BEGIN Includes (line 50)
    - Add http_server_netconn_init(); just after USER CODE BEGIN StartDefaultTask (line 112)
* In the root folder add the folder webpages with the files index.c and index.html in it.
* Project should build again without errors.
* Now navigate to "IP-address"/index.html (example: http://192.168.2.81/index.html) the website should be working now. If you used DHCP use a tool like Advanced IP Scanner to find the correct IP-address

## Notes:
* Leave all "USER CODE BEGIN" and "USER CODE END" comments and place your code only between these. This allows you to regenerate your code within STMcubeMX without losing your code.
* When generating the code STMcubeMX asks if you want to use systick with FreeRTOS, this is possible but you can change this on pinout tab: sys -> Timebase Source: (choose whatever timer is available)
* I am working on a Python script to convert html/css/js/ico files to a c string file.
