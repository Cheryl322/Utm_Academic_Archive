TITLE lab3
; Author: LAU YEE WEN, CHERYL CHEONG KAH VOON
; Date: 23 June 2023

include Irvine32.inc

; 0dh = carriage return
; 0ah = line feed

.data
mainMenu BYTE "Welcome to Simple Math Activities", 0dh, 0ah, 0dh, 0ah,
	"Main Menu", 0dh, 0ah, 0dh, 0ah,
	"1. To calculate Perimeter Hexagon (LOOP and ADD instructions)", 0dh, 0ah,
	"2. To calculate SUM (unsign int) index (Odd or Even) in an Array Hello[6]", 0dh, 0ah, 0dh, 0ah,
	"Select your input: ", 0

promptMessage BYTE "Press 'y' to return to Main Menu or 'n' to Exit the benchmark: ", 0dh, 0ah, 0
byeMessage BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

message1_peri BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions):", 0dh, 0ah, 0
message2_peri BYTE "Input Hexagon 1 (side length): ", 0
message3_peri BYTE "Input Hexagon 2 (side length): ", 0
message4_peri BYTE "Result of Perimeter Hexagon 1 and 2:", 0dh, 0ah, 0
message5_peri BYTE "Total Perimeter Hexagon 1 and 2: ", 0

sideHex1 dword ?
sideHex2 dword ?
Perimeter_hexagon1 dword ?
Perimeter_hexagon2 dword ?
TotalPerimeter dword ?

message1_sum BYTE "Calculate SUM (unsigned INT) index (Odd or Even) in array Hello[6]:", 0dh, 0ah, 0
message2_sum BYTE "Integer Input: ", 0
message3_sum BYTE "Result Sum Hello[index]: ", 0
message4_sum BYTE "Sum Hello[even] index location: ", 0
message5_sum BYTE "Sum Hello[odd] index location: ", 0

HELLO dword 6 dup(0)
TotalEVEN dword ?
TotalODD dword ?

select dword ?
char_in BYTE ?

.code
main proc

mainloop :
	call Clrscr						; clear the screen
	mov edx, offset mainMenu
	call WriteString				; display main menu
	call crlf						; new line

	call ReadDec					; read an integer input from the userand stores it in the EAX
	mov select, eax					; move the value from EAX to select variable

	cmp select, 1					; compare 'select' with 1
	je periHex_loopAdd				; jump to Perimeter Hexagon calculation if input is 1

	cmp select, 2					; compare 'select' with 2
	je calSum_oddeven				; jump to SUM calculation if input is 2

	jmp mainloop					; loop back to main menu for invalid input

periHex_loopAdd :
	call Clrscr
	mov edx, offset message1_peri
	call WriteString
	call crlf

	mov edx, offset message2_peri
	call WriteString
	call ReadDec
	mov sideHex1, eax				; Reads the user input and stores it in sideHex1.

	mov edx, offset message3_peri
	call WriteString
	call ReadDec
	mov sideHex2, eax				; Reads the user input and stores it in sideHex2.

; loop to calculate the perimeter of hexagon 1
	mov eax, 0
	mov ecx, 6

Loop1:
	add eax, sideHex1
	loop Loop1
	mov Perimeter_hexagon1, eax		; Stores the result in Perimeter_hexagon1

; loop to calculate the perimeter of hexagon 2
	mov ebx, 0
	mov ecx, 6

Loop2:
	add ebx, sideHex2
	loop Loop2
	mov Perimeter_hexagon2, ebx		; Stores the result in Perimeter_hexagon2

; calculate total perimeter
	add eax, ebx
	mov TotalPerimeter, eax			; Stores the total perimeter in TotalPerimeter.
	call crlf
	mov edx, offset message4_peri
	call WriteString

	mov eax, Perimeter_hexagon1
	call WriteDec					; display in unsigned decimal
	call crlf

	mov eax, Perimeter_hexagon2
	call WriteDec					; display in unsigned decimal
	call crlf
	call crlf

	mov edx, offset message5_peri
	call WriteString
	mov eax, TotalPerimeter
	call WriteDec; display the numeric results
	call crlf

	jmp continuePrompt				; jump to continuePrompt to ask user for next action

calSum_oddeven :
	call Clrscr
	mov edx, offset message1_sum
	call WriteString
	call crlf
	mov ecx, 6
	mov esi, offset HELLO

Loop1_sum :
	mov edx, offset message2_sum
	call WriteString
	call ReadDec
	mov[esi], eax
	add esi, 4
	loop Loop1_sum

; calculate sum of even index elements
	mov esi, offset HELLO
	mov ecx, 3						; (0, 2, 4).
	mov eax, 0						; store the sum

Loop2_sum :							; add even
	add eax, [esi]
	add esi, 8
	loop Loop2_sum
	mov TotalEVEN, eax

; calculate sum of odd index elements
	mov esi, offset HELLO
	mov ecx, 3
	mov eax, 0
	add esi, 4
Loop3_sum:							; add odd
	add eax, [esi]
	add esi, 8
	loop Loop3_sum
	mov TotalODD, eax

	call crlf
	mov edx, offset message3_sum
	call WriteString
	call crlf
	call crlf

	mov edx, offset message4_sum
	call WriteString
	mov eax, TotalEVEN
	call WriteDec
	call crlf

	mov edx, offset message5_sum
	call WriteString
	mov eax, TotalODD
	call WriteDec
	call crlf

	continuePrompt :
	call crlf						; new line
	mov edx, offset promptMessage
	call WriteString				; display promptMessage
	call crlf						; new line
	call ReadChar					;  wait for user to press a key, store ASCII value in AL  input character 'y' or 'n'
	mov char_in, al					; move the ASCII value from AL to char_in variable

	cmp char_in, 'y'				; compare char_in with 'y'
	je mainloop						; if 'y', jump to mainloop(return to main menu)

	cmp char_in, 'n'				; compare char_in with 'n'
	je exitProgram					; if 'n', jump to exitProgram(exit the program)

	jmp continuePrompt				; if input is invalid, prompt again

exitProgram :
	mov edx, offset byeMessage
	call WriteString				; display goodbye message
	call crlf

exit

main ENDP

END main