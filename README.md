
# Virtual Machine NL-1

## **NL-1** is a simple virtual machine on C

## Instructions
* **0** - Stop virtual machine
* **1** - Loading value into register
* **2** - Adding values
* **3** - Subtract values
* **4** - Multiply values
* **5** - Divide values
* **6** - Reset memory

## Example

1. **0x1032** - Loading value 50 to first register
2. **0x11C8** - Loading value 200 to second register
3. **0x2201** - Adds the values of first register and second register and loads the result in third register
4. **0x3120** - Subtract the values of third register and first register and loads the result in second register 
5. **0x4112** - Multiply the values of second register and third register and loads the result in second register
6. **0x5212** - Divide the values of second register and third register and loads the result in third register 
7. **0x6000** - Reset memory
8. **0x0000** - Stop virtual machine

## Authors

midaef - [midaef.ru](http://midaef.ru)

stdian - [stdian.ru](http://stdian.ru)
