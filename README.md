
# Virtual Machine NL-1

## **NL-1** is a simple virtual machine on C

## Instructions
* **0** - Stop virtual machine
* **1** - Loading value into register
* **2** - Adding values
* **3** - Subtract values

## Example

1. **0x1032** - Loading value 50 to **r0**
2. **0x11C8** - Loading value 200 to **r1**
3. **0x2201** - Adds the values of **r0** and **r1** and loads the result in **r2** 
4. **0x3202** - Subtract the values of **r0** and **r1** and loads the result in **r2** 
5. **0x0000** - Stop virtual machine

## Authors

midaef - [midaef.ru](http://midaef.ru)

stdian - [stdian.ru](http://stdian.ru)