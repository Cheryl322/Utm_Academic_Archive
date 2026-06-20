TITLE lab3 p2
; Author:LAU YEE WEN, CHERYL CHEONG KAH VOON
; Date:

include Irvine32.inc


.data
message1 BYTE "Calculate SUM (unsign INT) index (Odd or Even) in array Hello[6] :", 0dh, 0ah, 0
message2 BYTE "Interger Input : ", 0
message3 BYTE "Result Sum Hello[index] : ", 0
message4 BYTE "Sum Hello[even] index location : ", 0
message5 BYTE "Sum Hello[odd] index location : ", 0
HELLO dword 6 dup(0)
TotalEVEN dword ?
TotalODD dword ?

.code

main proc

startProg :

call Clrscr
mov edx, offset message1
call WriteString
call crlf
mov ecx,6
mov esi, offset HELLO

Loop1:
	mov edx, offset message2
	call WriteString
	call ReadDec
	mov[esi], eax					; move the eax into address in esi
	add esi, 4						; our array is 0,4,8,12,16,20
	LOOP Loop1

	mov esi, offset HELLO
	mov ecx, 3
	mov eax, 0

Loop2:	; addeven
	add eax, [esi]					; add the value of eax into address in esi
	add esi, 8
	LOOP Loop2
	mov TotalEVEN, eax

	mov esi, offset HELLO
	mov ecx, 3
	mov eax, 0
	add esi, 4

Loop3:    ;addodd
	add eax, [esi]
	add esi, 8
	LOOP Loop3
	mov TotalODD, eax

	call crlf
	mov edx, offset message3
	call WriteString
	call crlf
	call crlf

	mov edx, offset message4
	call WriteString
	mov eax, TotalEVEN
	call WriteDec
	call crlf

	mov edx, offset message5
	call WriteString
	mov eax, TotalODD
	call WriteDec
	call crlf


	exit

	main ENDP

	END main