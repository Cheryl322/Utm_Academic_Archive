TITLE lab3 p1
; Author: LAU YEE WEN, CHERYL CHEONG KAH VOON
; Date: 

include Irvine32.inc


.data
message1 BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions) :", 0dh, 0ah,0
message2 BYTE "Input Hexagon 1 (side length) : ",0
message3 BYTE "Input Hexagon 2 (side length) : ", 0
message4 BYTE "Result of Perimeter Hexagon 1 and 2 :  ", 0dh, 0ah,0
message5 BYTE "Total Perimeter Hexagon 1 and 2 : ",0
sideHex1 dword ?
sideHex2 dword ?
Perimeter_hexagon1 dword ?
Perimeter_hexagon2 dword ?
TotalPerimeter dword ?

.code

main proc

startProg:

call Clrscr              ; Clears the screen by writing blanks to all positions.
mov edx, offset message1
call WriteString         ; Writes a null - terminated string to standard output.
call crlf                ; Writes a carriage return / linefeed sequence(0Dh, 0Ah) to standard output.

mov edx, offset message2
call WriteString
call ReadDec
mov sideHex1, eax


mov edx, offset message3
call WriteString
call ReadDec
mov sideHex2, eax

; loop
mov eax, 0
mov ecx, 6               ; haxagon have 6 side so we have six loop to add each other
Loop1:
	add eax,sideHex1
	LOOP Loop1
	mov Perimeter_hexagon1, eax
	mov ebx, 0
	mov ecx, 6
		
Loop2:
	add ebx, sideHex2
	LOOP Loop2
	mov Perimeter_hexagon2, ebx

	add eax, ebx
	mov TotalPerimeter, eax
	call crlf
	mov edx, offset message4
	call WriteString

	mov eax, Perimeter_hexagon1
	call WriteDec
	call crlf
	
	mov eax, Perimeter_hexagon2
	call WriteDec
	call crlf
	call crlf

	mov edx, offset message5
	call WriteString
	mov eax, TotalPerimeter
	call WriteDec
	call crlf



exit

main ENDP

END main