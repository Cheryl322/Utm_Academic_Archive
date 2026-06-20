TITLE Project COA
; Author: Lau Yee Wen, Cheryl Cheong Kah Voon, Tan Zhi Ming, Chau Ying Jia
; Date: 1 / 7 / 2024

INCLUDE Irvine32.inc

.data

prompt1 BYTE "Welcome to CPU Benchmark Program", 0Dh, 0Ah, 0
prompt2 BYTE "Benchmark CPU time Using Equation y = 2*x^3 + 14*x^2 + 18*x + 22", 0Dh, 0Ah,
"(with delay coef1,coef2,coef3,coef4 = 2,14,18,22 msec)", 0Dh, 0Ah, 0
prompt4 BYTE "Enter Number of Looping (N) = ", 0
prompt5 BYTE "CPU time Stress Test in progress...", 0Dh, 0Ah, 0
prompt6 BYTE "Result:", 0Dh, 0Ah, 0
prompt7 BYTE "First Capture Execution time in millisecond: ", 0
prompt8 BYTE "Second Capture Execution time in millisecond: ", 0
prompt9 BYTE "Different Execution time in millisecond: ", 0
prompt10 BYTE "Value of Sum from the Stress Test (polynomial) = ", 0
prompt11 BYTE "Press 'y' to continue or 'n' to exit the benchmark: ", 0
msgBye BYTE "Thank you... BYE!!", 0DH, 0AH, 0

coef1 DWORD 2
coef2 DWORD 14
coef3 DWORD 18
coef4 DWORD 22

N DWORD ? ; number of loops
x DWORD 1
sum DWORD 0
start_time DWORD ?
end_time DWORD ?
elapsed_time DWORD ?

.code
main PROC
; Display welcome message
call Clrscr
mov edx, OFFSET prompt1
call WriteString
call Crlf

; Display the algorithm
mov edx, OFFSET prompt2
call WriteString
call Crlf

; Prompt for max loop value
mov edx, OFFSET prompt4
call WriteString
call ReadDec
mov N, eax

; Display progress message
mov edx, OFFSET prompt5
call WriteString
call Crlf

; Capture time before starting the loop
call GetMseconds
mov start_time, eax

; Initialize sum to 0
mov sum, 0

mov ecx, N; Set loop counter
mov ebx, 1; Initialize x to 1

calc_loop:
; Calculate y = (coef1 * x ^ 3) + (coef2 * x ^ 2) + (coef3 * x) + coef4

; coef1* x ^ 3
mov eax, coef1
call Delay; Introduce a delay
imul eax, x; Multiply eax by x
imul eax, x; Multiply eax by x again(eax = 2 * x ^ 2)
imul eax, x; Multiply eax by x again(eax = 2 * x ^ 3)
mov edx, eax; Move the result into edx(edx = 2 * x ^ 3)


; coef2* x ^ 2
mov eax, coef2
call Delay
imul eax, x
imul eax, x
add edx, eax; Add eax to edx(edx = 2 * x ^ 3 + 14 * x ^ 2)

; coef3* x
mov eax, coef3
call Delay
imul eax, x
add edx, eax; add previous result

; coef4
add edx, coef4; Add coef4(22) to edx(edx = 2 * x ^ 3 + 14 * x ^ 2 + 18 * x + 22)

; Add y to sum
add sum, edx

; Increment loop counter
inc x; Increment x by 1
loop calc_loop; Decrement ecx by 1 and loop if ecx != 0

; Capture time after completing the loop
call GetMseconds
mov end_time, eax

; Calculate elapsed time
mov eax, end_time
sub eax, start_time
mov elapsed_time, eax

; Display results
mov edx, OFFSET prompt6
call WriteString
call Crlf

mov edx, OFFSET prompt7
call WriteString
mov eax, start_time
call WriteDec
call Crlf

mov edx, OFFSET prompt8
call WriteString
mov eax, end_time
call WriteDec
call Crlf

mov edx, OFFSET prompt9
call WriteString
mov eax, elapsed_time
call WriteDec
call Crlf

mov edx, OFFSET prompt10
call WriteString
mov eax, sum
call WriteDec
call Crlf

; Prompt to continue or exit
mov edx, OFFSET prompt11
call WriteString
call ReadChar

cmp al, 'y'
je main

mov edx, offset msgBye
call WriteString


exit

main ENDP

END main